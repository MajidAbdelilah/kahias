
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h>
#include <stdbool.h>

#include <SDL2/SDL_image.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_rect.h>
 
typedef struct{ 
  SDL_Renderer *renderer;
  }Renderer;

typedef struct {
  SDL_Rect rect;
  float angel;
  SDL_Texture *image;
}Image;

Image create_image(Renderer *renderer, unsigned int w, unsigned int h, unsigned int x,
                  unsigned int y, unsigned int color) {

  SDL_Rect rect = {0};
  rect.w = w;
  rect.h = h;
  rect.x = x;
  rect.y = y;
  
  Image result = (Image){rect, 0.0f, (SDL_Texture*)SDL_CreateTexture(renderer->renderer, SDL_PIXELFORMAT_ABGR32, SDL_TEXTUREACCESS_STREAMING, w,  h)};
 
  return result;
}

Image load_image(Renderer *renderer, char *path) {

  Image result = {0};
  SDL_Surface *temp = IMG_Load(path);
  result.rect = temp->clip_rect;
  result.image = SDL_CreateTextureFromSurface(renderer->renderer, temp);
  
  return result;
  
}

void set_image_size(Image *image, unsigned int w, unsigned int h) {

  image->rect.w = w;
  image->rect.h = h;
  
}

void draw_image(Renderer *renderer, Image *image) {

  SDL_RenderCopyEx(renderer->renderer, image->image, NULL, &image->rect, image->angel, NULL, SDL_FLIP_NONE);
  
}

int main(int argnum, char **args) {
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  SDL_Window * window = SDL_CreateWindow("يس", 128, 128, 1400, 800, SDL_WINDOW_SHOWN);
  SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);
  Renderer renderer = (Renderer){rend};
  Image image = load_image(&renderer, "image.png");//create_image(100, 100, 100, 100, 0x0000FF);
  
  set_image_size(&image, 1000 , 500);
  image.angel = 45.0f;
  
  bool run = true;

  SDL_Event events = {0};

  bool key_is_down = false;

  unsigned short speed_scaler = 10;
  
  while(run){

    while(SDL_PollEvent(&events)){
      run = !( events.type == SDL_QUIT );
      key_is_down = ( events.type == SDL_KEYDOWN );
      image.rect.x += ( key_is_down * ( events.key.keysym.sym == SDLK_d) ) * speed_scaler;
      image.rect.x -= ( key_is_down * ( events.key.keysym.sym == SDLK_q) ) * speed_scaler;
      image.rect.y -= ( key_is_down * ( events.key.keysym.sym == SDLK_z) ) * speed_scaler;
      image.rect.y += ( key_is_down * ( events.key.keysym.sym == SDLK_s) ) * speed_scaler;
    }

    //SDL_FillRect(rend, NULL , 0xFFFFFF);
    draw_image(&renderer, &image);
    SDL_RenderPresent(renderer.renderer);
    
    SDL_Delay((1.0f/30.0f)*1000);
    }
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
  
  return 0;  
}



