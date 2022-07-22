#pragma once

#define alf 1// الف 1
#define baa 2// باء 2
#define jim 3// جيم 3
#define dal 4// دال 4
#define haa 5// هاء 5
#define waw 6// واو 6
#define zay 7// زاي 7
#define hha 8// حاء 8
#define tta 9// طاء 9
#define yaa 10// ياء 10
#define kaf 20// كاف 20
#define lam 30// لام 30
#define mim 40// ميم 40
#define non 50// نون 50
#define sin 60// سين 60
#define ain 70// عين 70
#define faa 80// فاء 80
#define sad 90// صاد 90
#define qaf 100// قاف 100
#define raa 200// راء 200
#define shn 300// شين 300
#define taa 400// تاء 400
#define tha 500// ثاء 500
#define kha 600// خاء 600
#define zal 700// ذال 700
#define dad 800// ضاد 800
#define zaa 900// ظاء 900
#define ghn 1000// غين 1000








#pragma pack(push, 1)
typedef struct {
  char string[12*2+2];
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
void calculate_valuesSSE(Words *words);
Words *ilm_asmaa_comparison_same_word_size(Words *words, Words *assets, unsigned int assets_n);
Words *ilm_asmaa_comparison_all_word_sizes(Words *words, Words *assets, unsigned int assets_n);

char* concat(const char *s1, const char *s2);


Server *WARRNING_HUG_MEMORY_CONSUMPTION_format_and_store_ilm_asmaa(Words *result, unsigned int result_size);
void write_ilm_asmaa_final_result(Server *final_data, char *path, char *name);
void formate_ilm_asmaa_normal(Words *result, unsigned int result_size, char *path, char *name);
