#pragma once

#define الف 1
#define باء 2
#define جيم 3
#define دال 4
#define هاء 5
#define واو 6
#define زاي 7
#define حاء 8
#define طاء 9
#define ياء 10
#define كاف 20
#define لام 30
#define ميم 40
#define نون 50
#define سين 60
#define عين 70
#define فاء 80
#define صاد 90
#define قاف 100
#define راء 200
#define شين 300
#define تاء 400
#define ثاء 500
#define خاء 600
#define ذال 700
#define ضاد 800
#define ظاء 900
#define غين 1000








#pragma pack(push, 1)
typedef struct {
  char string[12*2];
  unsigned int name_value;
  unsigned short number_of_chars;
} Word;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
  Word *words;
  unsigned int index;
  unsigned int size;
}Words;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
  Words *words_structs;
  unsigned int size;
}Server;
#pragma pack(pop)

Word *load_arabic_words(char *path, unsigned short number_of_characters, unsigned int *result_size);
void calculate_values(Words *words);
Words *ilm_asmaa_comparison_same_word_size(Words *words, Words *assets, unsigned int assets_n);
char* concat(const char *s1, const char *s2);


Server *WARRNING_HUG_MEMORY_CONSUMPTION_format_and_store_ilm_asmaa(Words *result, unsigned int result_size);
void write_ilm_asmaa_final_result(Server *final_data, char *path, char *name);
void formate_ilm_asmaa_normal(Words *result, unsigned int result_size, char *path, char *name);