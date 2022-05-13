#include "simd.h"
#include <emmintrin.h>
#include <immintrin.h>

void calculate_values_sse_sse2(Words *words) {

  __m128i  words_half_1_simd = {0};
  __m128i  words_half_2_simd = {0};
  __m128i  letter_1_simd = {0};
  __m128i  letter_2_simd = {0};

  __m128i  letters_equal_1_simd = {0};
  __m128i  letters_equal_2_simd = {0};
  __m128i  letters_final_equal_simd = {0};


  for (unsigned int i = 0; i < words->size; i++) {

    char *string = words->words[i].string;    
    words_half_1_simd = _mm_set_epi8(' ', ' ', ' ', ' ', string[22], string[20], string[18], string[16], string[14], string[12], string[10], string[8], string[6], string[4], string[2], string[0]);

    words_half_2_simd = _mm_set_epi8( ' ', ' ', ' ', ' ', string[23], string[21], string[19], string[17], string[15], string[13], string[11], string[9], string[7], string[5], string[3], string[1]);





    
    
    
    
      // الف
    
    letter_1_simd = _mm_set1_epi8("ا"[0]);
    letter_2_simd = _mm_set1_epi8("ا"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += الف * ((char*)&letters_final_equal_simd)[j];
    }
    
    letter_1_simd = _mm_set1_epi8("أ"[0]);
    letter_2_simd = _mm_set1_epi8("أ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += الف * ((char*)&letters_final_equal_simd)[j];
    }
    
    letter_1_simd = _mm_set1_epi8("ء"[0]);
    letter_2_simd = _mm_set1_epi8("ء"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += الف * ((char*)&letters_final_equal_simd)[j];
    }
    
    
    letter_1_simd = _mm_set1_epi8("ؤ"[0]);
    letter_2_simd = _mm_set1_epi8("ؤ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += الف * ((char*)&letters_final_equal_simd)[j];
    }
    
    letter_1_simd = _mm_set1_epi8("ئ"[0]);
    letter_2_simd = _mm_set1_epi8("ئ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += الف * ((char*)&letters_final_equal_simd)[j];
    }
    
    
    letter_1_simd = _mm_set1_epi8("آ"[0]);
    letter_2_simd = _mm_set1_epi8("آ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += الف * ((char*)&letters_final_equal_simd)[j];
    }
    
    letter_1_simd = _mm_set1_epi8("ى"[0]);
    letter_2_simd = _mm_set1_epi8("ى"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += الف * ((char*)&letters_final_equal_simd)[j];
    }
    
    
    letter_1_simd = _mm_set1_epi8("ﻻ"[0]);
    letter_2_simd = _mm_set1_epi8("ﻻ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ( الف + لام) * ((char*)&letters_final_equal_simd)[j];
    }
    
    letter_1_simd = _mm_set1_epi8("ﻵ"[0]);
    letter_2_simd = _mm_set1_epi8("ﻵ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ( الف + لام) * ((char*)&letters_final_equal_simd)[j];
    }
    
    letter_1_simd = _mm_set1_epi8("ﻷ"[0]);
    letter_2_simd = _mm_set1_epi8("ﻷ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ( الف + لام) * ((char*)&letters_final_equal_simd)[j];
    }
       
      // الف
    
      // باء
    letter_1_simd = _mm_set1_epi8("ب"[0]);
    letter_2_simd = _mm_set1_epi8("ب"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += باء * ((char*)&letters_final_equal_simd)[j];
    }
    // باء
    
      // جيم
    letter_1_simd = _mm_set1_epi8("ج"[0]);
    letter_2_simd = _mm_set1_epi8("ج"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += جيم * ((char*)&letters_final_equal_simd)[j];
    }
      // جيم
      
      // دال
    letter_1_simd = _mm_set1_epi8("د"[0]);
    letter_2_simd = _mm_set1_epi8("د"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += دال * ((char*)&letters_final_equal_simd)[j];
    }
     // دال
      
      // هاء
    letter_1_simd = _mm_set1_epi8("ه"[0]);
    letter_2_simd = _mm_set1_epi8("ه"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += هاء * ((char*)&letters_final_equal_simd)[j];
    }
     // هاء
      
      // واو
    letter_1_simd = _mm_set1_epi8("و"[0]);
    letter_2_simd = _mm_set1_epi8("و"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += واو * ((char*)&letters_final_equal_simd)[j];
    }
    // واو
      
      // زاي
    letter_1_simd = _mm_set1_epi8("ز"[0]);
    letter_2_simd = _mm_set1_epi8("ز"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += زاي * ((char*)&letters_final_equal_simd)[j];
    }
    // زاي
      
      // حاء
    letter_1_simd = _mm_set1_epi8("ح"[0]);
    letter_2_simd = _mm_set1_epi8("ح"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += حاء * ((char*)&letters_final_equal_simd)[j];
    }
    // حاء
      
      // طاء
    letter_1_simd = _mm_set1_epi8("ط"[0]);
    letter_2_simd = _mm_set1_epi8("ط"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += طاء * ((char*)&letters_final_equal_simd)[j];
    }
     // طاء
      
      // ياء
    letter_1_simd = _mm_set1_epi8("ي"[0]);
    letter_2_simd = _mm_set1_epi8("ي"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ياء * ((char*)&letters_final_equal_simd)[j];
    }
     // ياء
      
      // كاف
    letter_1_simd = _mm_set1_epi8("ك"[0]);
    letter_2_simd = _mm_set1_epi8("ك"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += كاف * ((char*)&letters_final_equal_simd)[j];
    }
     // كاف
      
      // لام
    letter_1_simd = _mm_set1_epi8("ل"[0]);
    letter_2_simd = _mm_set1_epi8("ل"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += لام * ((char*)&letters_final_equal_simd)[j];
    }
    // لام

      // ميم
    letter_1_simd = _mm_set1_epi8("م"[0]);
    letter_2_simd = _mm_set1_epi8("م"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ميم * ((char*)&letters_final_equal_simd)[j];
    }
     // ميم
      
      // نون
    letter_1_simd = _mm_set1_epi8("ن"[0]);
    letter_2_simd = _mm_set1_epi8("ن"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += نون * ((char*)&letters_final_equal_simd)[j];
    }
     // نون

      // سين
    letter_1_simd = _mm_set1_epi8("س"[0]);
    letter_2_simd = _mm_set1_epi8("س"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += سين * ((char*)&letters_final_equal_simd)[j];
    } 
     // سين

      // عين
    letter_1_simd = _mm_set1_epi8("ع"[0]);
    letter_2_simd = _mm_set1_epi8("ع"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += عين * ((char*)&letters_final_equal_simd)[j];
    } 
      // عين

      // فاء
    letter_1_simd = _mm_set1_epi8("ف"[0]);
    letter_2_simd = _mm_set1_epi8("ف"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += فاء * ((char*)&letters_final_equal_simd)[j];
    } 
      // فاء

      // صاد
    letter_1_simd = _mm_set1_epi8("ص"[0]);
    letter_2_simd = _mm_set1_epi8("ص"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += صاد * ((char*)&letters_final_equal_simd)[j];
    } 
     // صاد

      // قاف
    letter_1_simd = _mm_set1_epi8("ق"[0]);
    letter_2_simd = _mm_set1_epi8("ق"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += قاف * ((char*)&letters_final_equal_simd)[j];
    } 
     // قاف

      // راء
    letter_1_simd = _mm_set1_epi8("ر"[0]);
    letter_2_simd = _mm_set1_epi8("ر"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += راء * ((char*)&letters_final_equal_simd)[j];
    } 
     // راء

      // شين
    letter_1_simd = _mm_set1_epi8("ش"[0]);
    letter_2_simd = _mm_set1_epi8("ش"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += شين * ((char*)&letters_final_equal_simd)[j];
    } 
     // شين

      // تاء
    letter_1_simd = _mm_set1_epi8("ت"[0]);
    letter_2_simd = _mm_set1_epi8("ت"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += تاء * ((char*)&letters_final_equal_simd)[j];
    } 
     // تاء

      // ثاء
    letter_1_simd = _mm_set1_epi8("ث"[0]);
    letter_2_simd = _mm_set1_epi8("ث"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ثاء * ((char*)&letters_final_equal_simd)[j];
    } 
     // ثاء

      // خاء
    letter_1_simd = _mm_set1_epi8("خ"[0]);
    letter_2_simd = _mm_set1_epi8("خ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += خاء * ((char*)&letters_final_equal_simd)[j];
    } 
      // خاء

      // ذال
    letter_1_simd = _mm_set1_epi8("ذ"[0]);
    letter_2_simd = _mm_set1_epi8("ذ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ذال * ((char*)&letters_final_equal_simd)[j];
    } 
      // ذال

      // ضاد
    letter_1_simd = _mm_set1_epi8("ض"[0]);
    letter_2_simd = _mm_set1_epi8("ض"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ضاد * ((char*)&letters_final_equal_simd)[j];
    } 
    // ضاد

      // ظاء
    letter_1_simd = _mm_set1_epi8("ظ"[0]);
    letter_2_simd = _mm_set1_epi8("ظ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += ظاء * ((char*)&letters_final_equal_simd)[j];
    } 
     // ظاء

      // غين
    letter_1_simd = _mm_set1_epi8("غ"[0]);
    letter_2_simd = _mm_set1_epi8("غ"[1]);
    letters_equal_1_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_1_simd, letter_1_simd), _mm_set1_epi8(1));
    letters_equal_2_simd = _mm_and_si128(_mm_cmpeq_epi8(words_half_2_simd, letter_2_simd), _mm_set1_epi8(1));
    letters_final_equal_simd =  _mm_and_si128(letters_equal_1_simd, letters_equal_2_simd);
    for(unsigned int j=0; j< 12; j++){
      words->words[i].name_value += غين * ((char*)&letters_final_equal_simd)[j];
    }
    // غين
      

      }
  
}
