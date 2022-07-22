#include "server.h"
#include "cJSON.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

Words *ilm_asmaa_comparison_all_word_sizes(Words *words, Words *assets,
                                           unsigned int assets_n) {

  Words *result = malloc(sizeof(Words) * words->size);
  memset(result, 0, sizeof(Words) * words->size);

  unsigned int result_size;
  result_size = words->size;

  for (unsigned int i = 0; i < words->size; i++) {
    result[i].size = 4096 * 6;
    result[i].words = malloc(sizeof(Word) * result[i].size);
    memset(result[i].words, 0, sizeof(Word) * result[i].size);
	result[i].index = 0;
  }
  for (unsigned int a = 0; a < words->size; a++) {
    for (unsigned int b = 0; b < assets_n; b++) {
      for (unsigned int c = 0; c < assets[b].size; c++) {

        if (words->words[a].name_value == assets[b].words[c].name_value) {
          strcpy(result[a].words[result[a].index].string,
                 assets[b].words[c].string);
          result[a].words[result[a].index].name_value =
              assets[b].words[c].name_value;
          result[a].words[result[a].index].number_of_chars =
              assets[b].words[c].number_of_chars;

          result[a].index++;
          if (result[a].index == result[a].size)
            printf(
                "HELP!!!!!!!!!!!!!\nHELP: a buffer_overflow:  "
                "result_secend_full_indexes_n[a] == result_secend_size[a]\n");
        }
      }
    }
  }

  for (unsigned int a = 0; a < words->size; a++) {
    result[a].size = result[a].index;
    result[a].words = realloc(result[a].words, sizeof(Word) * result[a].size);
  }

  return result;
}

void formate_ilm_asmaa_normal(Words *result, unsigned int result_size,
                              char *path, char *name) {

  Server *server_result = malloc(sizeof(Server));

  server_result->size = result_size;
  server_result->words_structs = result;

  write_ilm_asmaa_final_result(server_result, path, name);
}

void write_ilm_asmaa_final_result(Server *final_data, char *path, char *name) {

  unsigned int size = 0;

  char *space = "       \0";
  unsigned short space_size = strlen(space);

  char *word_space = "  \0";
  unsigned int word_space_size = strlen(word_space);

  for (unsigned int i = 0; i < final_data->size; i++) {

    for (unsigned int j = 0; j < final_data->words_structs[i].size; j++) {
      size += space_size + 32;
      size += word_space_size + 32;
      size += final_data->words_structs[i].words[j].number_of_chars +
              final_data->size + 32;
    }
  }

  char *result = malloc(sizeof(char) * size);
  memset(result, 0, sizeof(char) * size);
  unsigned int result_index = 0;

  unsigned int max_size = 0;
  for (unsigned int i = 0; i < final_data->size; i++) {
    max_size = final_data->words_structs[i].size *
                   (final_data->words_structs[i].size > max_size) +
               max_size * !(final_data->words_structs[i].size > max_size);
  }

  strcpy(result, space);
  result_index += space_size;
  strcpy(result + result_index, name);
  result_index += strlen(name);
  result[result_index] = '\n';
  result_index++;

  for (unsigned int j = 0; j < max_size; j++) {
    strcpy(result + result_index, space);
    result_index += space_size;
    for (unsigned int a = 0; a < final_data->size; a++) {

      if (final_data->words_structs[a].size > 0) {
        strcpy(result + (result_index),
               final_data->words_structs[a]
                   .words[j * (j < final_data->words_structs[a].size)]
                   .string);
        result_index +=
            strlen(final_data->words_structs[a]
                       .words[j * (j < final_data->words_structs[a].size)]
                       .string);
      } else {
        strcpy(result + (result_index), word_space);
        result_index += word_space_size;
      }
      result[result_index] = ' ';
      result_index++;
    }
    result[result_index] = '\n';
    result_index++;
  }

  result = realloc(result, sizeof(char) * result_index);

  FILE *file = fopen(path, "w");

  fwrite(result, sizeof(char) * result_index, 1, file);
}

/*
void recursive_formating(Words *result, unsigned int result_size, int
loops_left, Words *data_result, unsigned long *data_index, Word *current_set) {

  for(unsigned int i=0; i< result[loops_left].size; i++){
    if(loops_left>0){
      recursive_formating(result, result_size, loops_left-1, data_result,
data_index, current_set);
    }

    memcpy( current_set+loops_left, result[loops_left].words+i, sizeof(Word));

    memcpy(data_result[*data_index].words, current_set, sizeof(Word) *
result_size);
    (*data_index)++;


      printf("recursive(%d) = ", loops_left);
    for(unsigned int i=0; i< result_size; i++){
      printf("%s ", data_result[data_index].words[i].string);
    }
    printf("\n");


  }


}


Server *WARRNING_HUG_MEMORY_CONSUMPTION_format_and_store_ilm_asmaa(Words
*result, unsigned int result_size) {


  Word *current_set = malloc(sizeof(Word) * result_size);
  memset(current_set, 0, sizeof(Word) * result_size);

  unsigned long int data_result_size = 1;
  for(unsigned int i=0; i<result_size; i++){
    data_result_size *= (result[i].size) * (result[i].size > 0) + 1 *
!(result[i].size > 0);
  }


  Words *data_result = malloc(sizeof(Words) * data_result_size);

  for(unsigned int i=0; i<data_result_size; i++){
    data_result[i].words = malloc(sizeof(Word) * result_size);
    memset(data_result[i].words, 0, sizeof(Word) * result_size);
    data_result[i].size = result_size;
  }

  for(unsigned int i=result_size; i > -1 ; i--)
    memcpy(current_set+i, result[i].words, sizeof(Word));

  unsigned long *size = malloc(sizeof(unsigned long));
  memset(size, 0, sizeof(unsigned long));
  recursive_formating(result, result_size, result_size-1, data_result, size,
current_set);


  data_result = realloc(data_result, sizeof(Words) * (*size));

  Server *result_result = malloc(sizeof(Server));

  result_result->size = *size;
  result_result->words_structs = data_result;

  return result_result;

}
*/

Words *ilm_asmaa_comparison_same_word_size(Words *words, Words *assets,
                                           unsigned int assets_n) {
  Words *result = malloc(sizeof(Words) * words->size);
  memset(result, 0, sizeof(Words) * words->size);

  unsigned int result_size;
  result_size = words->size;

  for (unsigned int i = 0; i < words->size; i++) {
    result[i].size = 4096 * 2;
    result[i].words = malloc(sizeof(Word) * result[i].size);
    memset(result[i].words, 0, sizeof(Word) * result[i].size);
  }
  for (unsigned int a = 0; a < words->size; a++) {
    for (unsigned int b = 0; b < assets_n; b++) {
      for (unsigned int c = 0; c < assets[b].size; c++) {
        if (words->words[a].number_of_chars !=
            assets[b].words[c].number_of_chars) {
          break;
        }

        if (words->words[a].name_value == assets[b].words[c].name_value) {
          strcpy(result[a].words[result[a].index].string,
                 assets[b].words[c].string);
          result[a].words[result[a].index].name_value =
              assets[b].words[c].name_value;
          result[a].words[result[a].index].number_of_chars =
              assets[b].words[c].number_of_chars;

          result[a].index++;
          if (result[a].index == result[a].size)
            printf(
                "HELP!!!!!!!!!!!!!\nHELP: a buffer_overflow:  "
                "result_secend_full_indexes_n[a] == result_secend_size[a]\n");
        }
      }
    }
  }

  for (unsigned int a = 0; a < words->size; a++) {
    result[a].size = result[a].index;
    result[a].words = realloc(result[a].words, sizeof(Word) * result[a].size);
  }

  return result;
}

Word *load_arabic_words(char *path, unsigned short number_of_characters,
                        unsigned int *result_size) {
  FILE *file = fopen(path, "r");
  fseek(file, 0, SEEK_END);
  unsigned int file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  // printf("file: %s, size: %u\n", path, file_size);

  char *file_data = malloc(sizeof(unsigned char) * file_size);

  fread(file_data, file_size, 1, file);

  cJSON *json = cJSON_ParseWithLength(file_data, file_size);

  cJSON *json_current = json;

  Word *words = malloc(sizeof(Word) * (file_size / 5));
  memset(words, 0, sizeof(Word) * (file_size / 5));
  unsigned int words_size = 0;

  if (json_current->child != NULL)
    json_current = json_current->child;
  else
    json_current = json_current;

  while (json_current->next != NULL) {

    words[words_size].number_of_chars = number_of_characters * 2;

    strcpy(words[words_size].string, json_current->child->valuestring);

    words[words_size].string[words[words_size].number_of_chars] = '\0';
    // for (unsigned int i = 0; i < strlen(json_current->child->valuestring);
    // i++) printf("equal ain = %d", words[words_size].string[1] == "ع"[1]);

    // printf("strlen = %lu", strlen(json_current->child->valuestring));

    // printf("json: %s\n", words[words_size].string);
    json_current = json_current->next;
    words_size++;
  }

  words = realloc(words, sizeof(Word) * (words_size + 1));
  *result_size = words_size;
  // Words calc_words = (Words){0};
  // calculate_values(&calc_words, words_size);

  // for(unsigned int i=0; i<words_size; i++)
  //   printf("word = %s, ism_value = %d\n", words.words[i].string,
  //   words.words[i].name_value);

  cJSON_free(json);

  fclose(file);

  //  FILE *result = fopen("result", "w");

  // fwrite(&words, sizeof(Word) * words_size, 1, result);

  return words;
}

void calculate_values(Words *words) {
	return calculate_valuesSSE(words);
	
  for (unsigned int i = 0; i < words->size; i++) {
    for (unsigned int j = 0; j < words->words[i].number_of_chars; j++) {
      // الف
      words->words[i].name_value +=
          alf * (words->words[i].string[j * 2] == "ا"[0] &&
                 words->words[i].string[j * 2 + 1] == "ا"[1]);
      words->words[i].name_value +=
          alf * (words->words[i].string[j * 2] == "أ"[0] &&
                 words->words[i].string[j * 2 + 1] == "أ"[1]);
      words->words[i].name_value +=
          alf * (words->words[i].string[j * 2] == "ء"[0] &&
                 words->words[i].string[j * 2 + 1] == "ء"[1]);
      words->words[i].name_value +=
          alf * (words->words[i].string[j * 2] == "ؤ"[0] &&
                 words->words[i].string[j * 2 + 1] == "ؤ"[1]);
      words->words[i].name_value +=
          alf * (words->words[i].string[j * 2] == "ئ"[0] &&
                 words->words[i].string[j * 2 + 1] == "ئ"[1]);
      words->words[i].name_value +=
          alf * (words->words[i].string[j * 2] == "آ"[0] &&
                 words->words[i].string[j * 2 + 1] == "آ"[1]);
      words->words[i].name_value +=
          alf * (words->words[i].string[j * 2] == "ى"[0] &&
                 words->words[i].string[j * 2 + 1] == "ى"[1]);
      words->words[i].name_value +=
          (alf + lam) * (words->words[i].string[j * 2] == "ﻻ"[0] &&
                         words->words[i].string[j * 2 + 1] == "ﻻ"[1]);
      words->words[i].name_value +=
          (alf + lam) * (words->words[i].string[j * 2] == "ﻵ"[0] &&
                         words->words[i].string[j * 2 + 1] == "ﻵ"[1]);
      words->words[i].name_value +=
          (alf + lam) * (words->words[i].string[j * 2] == "ﻷ"[0] &&
                         words->words[i].string[j * 2 + 1] == "ﻷ"[1]);
      // alf

      // باء
      words->words[i].name_value +=
          baa * (words->words[i].string[j * 2] == "ب"[0] &&
                 words->words[i].string[j * 2 + 1] == "ب"[1]);
      // باء

      // جيم
      words->words[i].name_value +=
          jim * (words->words[i].string[j * 2] == "ج"[0] &&
                 words->words[i].string[j * 2 + 1] == "ج"[1]);
      // جيم

      // دال
      words->words[i].name_value +=
          dal * (words->words[i].string[j * 2] == "د"[0] &&
                 words->words[i].string[j * 2 + 1] == "د"[1]);
      // دال

      // هاء
      words->words[i].name_value +=
          haa * (words->words[i].string[j * 2] == "ه"[0] &&
                 words->words[i].string[j * 2 + 1] == "ه"[1]);
      // هاء

      // واو
      words->words[i].name_value +=
          waw * (words->words[i].string[j * 2] == "و"[0] &&
                 words->words[i].string[j * 2 + 1] == "و"[1]);
      // واو

      // زاي
      words->words[i].name_value +=
          zay * (words->words[i].string[j * 2] == "ز"[0] &&
                 words->words[i].string[j * 2 + 1] == "ز"[1]);
      // زاي

      // حاء
      words->words[i].name_value +=
          hha * (words->words[i].string[j * 2] == "ح"[0] &&
                 words->words[i].string[j * 2 + 1] == "ح"[1]);
      // حاء

      // طاء
      words->words[i].name_value +=
          tta * (words->words[i].string[j * 2] == "ط"[0] &&
                 words->words[i].string[j * 2 + 1] == "ط"[1]);
      // طاء

      // ياء
      words->words[i].name_value +=
          yaa * (words->words[i].string[j * 2] == "ي"[0] &&
                 words->words[i].string[j * 2 + 1] == "ي"[1]);
      // ياء

      // كاف
      words->words[i].name_value +=
          kaf * (words->words[i].string[j * 2] == "ك"[0] &&
                 words->words[i].string[j * 2 + 1] == "ك"[1]);
      // كاف

      // lam
      words->words[i].name_value +=
          lam * (words->words[i].string[j * 2] == "ل"[0] &&
                 words->words[i].string[j * 2 + 1] == "ل"[1]);
      // lamy

      // ميم
      words->words[i].name_value +=
          mim * (words->words[i].string[j * 2] == "م"[0] &&
                 words->words[i].string[j * 2 + 1] == "م"[1]);
      // ميم

      // نون
      words->words[i].name_value +=
          non * (words->words[i].string[j * 2] == "ن"[0] &&
                 words->words[i].string[j * 2 + 1] == "ن"[1]);
      // نون

      // سين
      words->words[i].name_value +=
          sin * (words->words[i].string[j * 2] == "س"[0] &&
                 words->words[i].string[j * 2 + 1] == "س"[1]);
      // سين

      // عين
      words->words[i].name_value +=
          ain * (words->words[i].string[j * 2] == "ع"[0] &&
                 words->words[i].string[j * 2 + 1] == "ع"[1]);
      // عين

      // فاء
      words->words[i].name_value +=
          faa * (words->words[i].string[j * 2] == "ف"[0] &&
                 words->words[i].string[j * 2 + 1] == "ف"[1]);
      // فاء

      // صاد
      words->words[i].name_value +=
          sad * (words->words[i].string[j * 2] == "ص"[0] &&
                 words->words[i].string[j * 2 + 1] == "ص"[1]);
      // صاد

      // قاف
      words->words[i].name_value +=
          qaf * (words->words[i].string[j * 2] == "ق"[0] &&
                 words->words[i].string[j * 2 + 1] == "ق"[1]);
      // قاف

      // راء
      words->words[i].name_value +=
          raa * (words->words[i].string[j * 2] == "ر"[0] &&
                 words->words[i].string[j * 2 + 1] == "ر"[1]);
      // راء

      // شين
      words->words[i].name_value +=
          shn * (words->words[i].string[j * 2] == "ش"[0] &&
                 words->words[i].string[j * 2 + 1] == "ش"[1]);
      // شين

      // تاء
      words->words[i].name_value +=
          taa * (words->words[i].string[j * 2] == "ت"[0] &&
                 words->words[i].string[j * 2 + 1] == "ت"[1]);
      // تاء

      // ثاء
      words->words[i].name_value +=
          tha * (words->words[i].string[j * 2] == "ث"[0] &&
                 words->words[i].string[j * 2 + 1] == "ث"[1]);
      // ثاء

      // خاء
      words->words[i].name_value +=
          kha * (words->words[i].string[j * 2] == "خ"[0] &&
                 words->words[i].string[j * 2 + 1] == "خ"[1]);
      // خاء

      // ذال
      words->words[i].name_value +=
          zal * (words->words[i].string[j * 2] == "ذ"[0] &&
                 words->words[i].string[j * 2 + 1] == "ذ"[1]);
      // ذال

      // ضاد
      words->words[i].name_value +=
          dad * (words->words[i].string[j * 2] == "ض"[0] &&
                 words->words[i].string[j * 2 + 1] == "ض"[1]);
      // ضاد

      // ظاء
      words->words[i].name_value +=
          zaa * (words->words[i].string[j * 2] == "ظ"[0] &&
                 words->words[i].string[j * 2 + 1] == "ظ"[1]);
      // ظاء

      // غين
      words->words[i].name_value +=
          ghn * (words->words[i].string[j * 2] == "غ"[0] &&
                 words->words[i].string[j * 2 + 1] == "غ"[1]);
      // غين
    }
  }
}

char *concat(const char *s1, const char *s2) {
  char *result =
      malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  // in real code you would check for errors in malloc here
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}
