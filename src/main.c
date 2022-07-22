#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include "server.h"

#define version "1.0.0"

void init(Server *server, char *string);
Words *init_words_word(char *string);
 
int main(int argnum, char **args) {
  char *usr_string = NULL;
  
  //printf("argnum = %d\n", argnum);
  //printf("args[1] = %s\n", args[1]);
  for(int i=0; i<argnum; i++){

    if(!strcmp(args[i], "--help")){
      printf(" kahias version: %s\n made by Abdelilah Majid\n program execution example in windows            kahias.exe \"عبد الاله مجيد\"\n program execution example in linux              ./kahias \"عبد الاله مجيد\"\n ", version);
      return 0;
    }

    if(argnum > 1)
		usr_string = args[1];
    else{
      printf("SORRY YOU HAVE PASSED NO STRING TO THIS PROGRME!!!!!!!\n USE --help FOR MORE HELP\n");
      return 0;
    }
  } 
  

  printf("PLEASE WAIT, THIS WILL TAKE JUST SECONDS\n");
  
  Server *server = malloc(sizeof(Server));
  memset(server, 0, sizeof(Server));
  server->words_structs = malloc(sizeof(Words) * 168);
  memset(server->words_structs, 0, sizeof(Words) * 168);
  server->size = 168; //168 files

   init(server, usr_string);
  //init(server, "عبد الاله مجيد\0");


  
  return 0;
}




void init(Server *server, char *string) {

  DIR *d;
  struct dirent *dir;
  d = opendir("./ArabicMots3-8Litter-Json/\0");
  if (d)
    {
      unsigned int i=0;
      unsigned int run_num = 0;
      while ((dir = readdir(d)) != NULL && run_num < server->size)
        {
	  if(!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
	    continue;
	  unsigned int j=0;
	  unsigned int char_num = 0;
	  
	  while (dir->d_name[j] != '\0') {
	    char_num += 3 * (dir->d_name[j] == '3');
	    char_num += 4 * (dir->d_name[j] == '4');
	    char_num += 5 * (dir->d_name[j] == '5');
	    char_num += 6 * (dir->d_name[j] == '6');
	    char_num += 7 * (dir->d_name[j] == '7');
	    char_num += 8 * (dir->d_name[j] == '8');

	    j++;
	  }

	  char * path= concat("./ArabicMots3-8Litter-Json/\0", dir->d_name);
	  
	  server->words_structs[i].words = load_arabic_words( path, char_num, &server->words_structs[i].size);
	  calculate_values(&server->words_structs[i]);
	   printf("%s\n", dir->d_name);
	  char_num = 0;
	  i++;
	  run_num++;
	}
      closedir(d);
    }
  
  Words *words = init_words_word(string);
  
  for(unsigned int i=0; i<words->size; i++){
    printf("word.string = %s, words.value = %u, word.char_num = %u\n", words->words[i].string, words->words[i].name_value, words->words[i].number_of_chars);
    }
  

   Words *result = ilm_asmaa_comparison_same_word_size(words, server->words_structs, server->size);
   Words *result_2 = ilm_asmaa_comparison_all_word_sizes(words, server->words_structs, server->size);

   /*
   unsigned int lines_num = 0;
   for(unsigned int i=0; i<words->size; i++){
     lines_num+=result[i].size;
   }
   
   unsigned int buffer_size = ((strlen(string)) * lines_num);
   char *file_data = malloc(buffer_size);
   memset(file_data, 0, buffer_size);

   unsigned int index = 0;

   for(unsigned int i=0; i<words->size; i++){
     for(unsigned int j=0; j<result[i].size; j++){
     	 
	 strcpy(&file_data[index], result[i].words[j].string);

	 index+=(result[i].words[j].number_of_chars);
	 file_data[index] = ' ';
	 index++;
	 
       }
	 file_data[index] = '\n';
	 index++;
     } 
   file_data[index++] = '\0';
   file_data = realloc(file_data, index);
   
  FILE *result_file = fopen("result", "w");
  fwrite(file_data, buffer_size, 1, result_file);
  
  printf("%s\n", file_data);
   
   */
  
   /* for(unsigned int i=0; i<words->size; i++){
    for(unsigned int j=0; j<result[i].size; j++){
      printf("result[%u].words[%u] = {string = %s, name_value = %u}\n", i, j, result[i].words[j].string, result[i].words[j].name_value);
    }
	}*/
  
  

   

   //write_ilm_asmaa_final_result(final_result, "result\0");
   formate_ilm_asmaa_normal(result, words->size, "النتيجة_علم_الاسماء_نفس_عدد_الحروف", string);
   formate_ilm_asmaa_normal(result_2, words->size, "النتيجة_علم_الاسماء_كل_اعداد_الاحرف", string);

   printf("SUCCESS: CHECK THE FILE: النتيجة_علم_الاسماء_نفس_عدد_الحروف \n");
   printf("SUCCESS: CHECK THE FILE: النتيجة_علم_الاسماء_كل_اعداد_الاحرف \n");
   
   
} 


Words *init_words_word(char *string) {
  Words *result = malloc(sizeof(Words));
  memset(result, 0, sizeof(Words));
  result->words = malloc(sizeof(Word)*256);
  memset(result->words, 0, sizeof(Word) * 256);
  unsigned int i=0;
  unsigned int words_index = 0;
  unsigned int string_index = 0;
  unsigned int string_index_foo = 0;
  bool is_equal_space = false;
  while (string[i] != '\0') {
    is_equal_space = string[i] == ' ';
    result->words[words_index].string[string_index] = string[i] * (!is_equal_space) + '\0' * (is_equal_space);
    if(is_equal_space)
      printf("%c", string[i]              );
    string_index += !is_equal_space;
    result->words[words_index].number_of_chars = string_index;
    
    i++;
    //string_index_foo = string_index;
    string_index = string_index * (!is_equal_space);
    //string_index = string_index_foo * (string[i] == '\0') + string_index * !(string[i] == '\0');
    words_index += is_equal_space;
   
  }
  result->words[words_index].string[string_index] = '\0';
  words_index++;
  result->size = words_index;
  
  //strcpy(result->words->string, string);
  //result->words->number_of_chars = n*2;

  calculate_values(result);

  result->words = realloc(result->words, sizeof(Word)*words_index);
  
  
  return result;
}
 
