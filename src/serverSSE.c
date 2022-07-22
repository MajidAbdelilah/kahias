#include "server.h"
#include <emmintrin.h>
#include <immintrin.h>
#include <stdio.h>
void calculate_valuesSSE(Words *words) {
	
	for (unsigned int i = 0; i < words->size; i++) {
		
		__m128i word_m = _mm_set_epi8(
									  words->words[i].string[15], words->words[i].string[14],
									  words->words[i].string[13], words->words[i].string[12],
									  words->words[i].string[11], words->words[i].string[10],
									  words->words[i].string[9], words->words[i].string[8],
									  words->words[i].string[7], words->words[i].string[6],
									  words->words[i].string[5], words->words[i].string[4],
									  words->words[i].string[3], words->words[i].string[2],
									  words->words[i].string[1], words->words[i].string[0]);
		
		__m128i alf_mval = _mm_set1_epi16(alf);
		__m128i lam_mval = _mm_set1_epi16(lam);
		
		__m128i alf0_m0 = _mm_set1_epi8("ا"[0]);
		__m128i alf0_m1 = _mm_set1_epi8("ا"[1]);
      __m128i alf1_m0 = _mm_set1_epi8("أ"[0]);
      __m128i alf1_m1 = _mm_set1_epi8("أ"[1]);
      __m128i alf2_m0 = _mm_set1_epi8("ء"[0]);
      __m128i alf2_m1 = _mm_set1_epi8("ء"[1]);
      __m128i alf3_m0 = _mm_set1_epi8("ؤ"[0]);
      __m128i alf3_m1 = _mm_set1_epi8("ؤ"[1]);
      __m128i alf4_m0 = _mm_set1_epi8("ئ"[0]);
      __m128i alf4_m1 = _mm_set1_epi8("ئ"[1]);
      __m128i alflam0_m0 = _mm_set1_epi8("ﻻ"[0]);
      __m128i alflam0_m1 = _mm_set1_epi8("ﻻ"[1]);
      __m128i alflam1_m0 = _mm_set1_epi8("ﻵ"[0]);
      __m128i alflam1_m1 = _mm_set1_epi8("ﻵ"[1]);
      __m128i alflam2_m0 = _mm_set1_epi8("ﻷ"[0]);
      __m128i alflam2_m1 = _mm_set1_epi8("ﻷ"[1]);

	  __m128i val_m = _mm_set1_epi8(0);
	    
      // الف
      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, alf0_m0),
																	   _mm_cmpeq_epi8(word_m, alf0_m1)), _mm_set1_epi16(-1)), alf_mval), val_m);
	  /*	  
	  for (unsigned short j = 0; j < 8; j++) {
		  // words->words[i].name_value += ((unsigned short *)&val_m)[j];
		  printf("val_m[%u] = %d\n", j, ((short *)&val_m)[j]);
	  }
	  */
	  
      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, alf1_m0),
																	   _mm_cmpeq_epi8(word_m, alf1_m1)), _mm_set1_epi16(-1)), alf_mval), val_m);
      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, alf2_m0),
																	   _mm_cmpeq_epi8(word_m, alf2_m1)), _mm_set1_epi16(-1)), alf_mval), val_m);
      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, alf3_m0),
																	   _mm_cmpeq_epi8(word_m, alf3_m1)), _mm_set1_epi16(-1)), alf_mval), val_m);
      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, alf4_m0),
																	   _mm_cmpeq_epi8(word_m, alf4_m1)), _mm_set1_epi16(-1)), alf_mval), val_m);
      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, alflam0_m0),
																	   _mm_cmpeq_epi8(word_m, alflam0_m1)), _mm_set1_epi16(-1)),
										  _mm_add_epi16(lam_mval, alf_mval)), val_m);
	  
      // alf

      // باء
      __m128i baa_mval = _mm_set1_epi16(baa);
      __m128i baa_m0 = _mm_set1_epi8("ب"[0]);
      __m128i baa_m1 = _mm_set1_epi8("ب"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, baa_m0),
																	   _mm_cmpeq_epi8(word_m, baa_m1)), _mm_set1_epi16(-1)), baa_mval), val_m);
      // باء

      // جيم

      __m128i jim_mval = _mm_set1_epi16(jim);
      __m128i jim_m0 = _mm_set1_epi8("ج"[0]);
      __m128i jim_m1 = _mm_set1_epi8("ج"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, jim_m0),
																	   _mm_cmpeq_epi8(word_m, jim_m1)), _mm_set1_epi16(-1)), jim_mval), val_m);
      // جيم

      // دال

      __m128i dal_mval = _mm_set1_epi16(dal);
      __m128i dal_m0 = _mm_set1_epi8("د"[0]);
      __m128i dal_m1 = _mm_set1_epi8("د"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, dal_m0),
																	   _mm_cmpeq_epi8(word_m, dal_m1)), _mm_set1_epi16(-1)), dal_mval), val_m);
      // دال

      // هاء
      __m128i haa_mval = _mm_set1_epi16(haa);
      __m128i haa_m0 = _mm_set1_epi8("ه"[0]);
      __m128i haa_m1 = _mm_set1_epi8("ه"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, haa_m0),
																	   _mm_cmpeq_epi8(word_m, haa_m1)), _mm_set1_epi16(-1)), haa_mval), val_m);
      // هاء

      // واو
      __m128i waw_mval = _mm_set1_epi16(waw);
      __m128i waw_m0 = _mm_set1_epi8("و"[0]);
      __m128i waw_m1 = _mm_set1_epi8("و"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, waw_m0),
																	   _mm_cmpeq_epi8(word_m, waw_m1)), _mm_set1_epi16(-1)), waw_mval), val_m);
      // واو

      // زاي
      __m128i zay_mval = _mm_set1_epi16(zay);
      __m128i zay_m0 = _mm_set1_epi8("ز"[0]);
      __m128i zay_m1 = _mm_set1_epi8("ز"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, zay_m0),
																	   _mm_cmpeq_epi8(word_m, zay_m1)), _mm_set1_epi16(-1)), zay_mval), val_m);
      // زاي

      // حاء
      __m128i hha_mval = _mm_set1_epi16(hha);
      __m128i hha_m0 = _mm_set1_epi8("ح"[0]);
      __m128i hha_m1 = _mm_set1_epi8("ح"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, hha_m0),
																	   _mm_cmpeq_epi8(word_m, hha_m1)), _mm_set1_epi16(-1)), hha_mval), val_m);
      // حاء

      // طاء
      __m128i tta_mval = _mm_set1_epi16(tta);
      __m128i tta_m0 = _mm_set1_epi8("ط"[0]);
      __m128i tta_m1 = _mm_set1_epi8("ط"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, tta_m0),
																	   _mm_cmpeq_epi8(word_m, tta_m1)), _mm_set1_epi16(-1)), tta_mval), val_m);
      // طاء

      // ياء
      __m128i yaa_mval = _mm_set1_epi16(yaa);
      __m128i yaa_m0 = _mm_set1_epi8("ي"[0]);
      __m128i yaa_m1 = _mm_set1_epi8("ي"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, yaa_m0),
																	   _mm_cmpeq_epi8(word_m, yaa_m1)), _mm_set1_epi16(-1)), yaa_mval), val_m);
      // ياء

      // كاف
      __m128i kaf_mval = _mm_set1_epi16(kaf);
      __m128i kaf_m0 = _mm_set1_epi8("ك"[0]);
      __m128i kaf_m1 = _mm_set1_epi8("ك"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, kaf_m0),
																	   _mm_cmpeq_epi8(word_m, kaf_m1)), _mm_set1_epi16(-1)), kaf_mval), val_m);
      // كاف

      // lam
      __m128i lam_m0 = _mm_set1_epi8("ل"[0]);
      __m128i lam_m1 = _mm_set1_epi8("ل"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, lam_m0),
																	   _mm_cmpeq_epi8(word_m, lam_m1)), _mm_set1_epi16(-1)), lam_mval), val_m);
      // lamy

      // ميم
      __m128i mim_mval = _mm_set1_epi16(mim);
      __m128i mim_m0 = _mm_set1_epi8("م"[0]);
      __m128i mim_m1 = _mm_set1_epi8("م"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, mim_m0),
																	   _mm_cmpeq_epi8(word_m, mim_m1)), _mm_set1_epi16(-1)), mim_mval), val_m);
      // ميم

      // نون
      __m128i non_mval = _mm_set1_epi16(non);
      __m128i non_m0 = _mm_set1_epi8("ن"[0]);
      __m128i non_m1 = _mm_set1_epi8("ن"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, non_m0),
																	   _mm_cmpeq_epi8(word_m, non_m1)), _mm_set1_epi16(-1)), non_mval), val_m);

      // نون

      // سين
      __m128i sin_mval = _mm_set1_epi16(sin);
      __m128i sin_m0 = _mm_set1_epi8("س"[0]);
      __m128i sin_m1 = _mm_set1_epi8("س"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, sin_m0),
																	   _mm_cmpeq_epi8(word_m, sin_m1)), _mm_set1_epi16(-1)), sin_mval), val_m);
      // سين

      // عين
      __m128i ain_mval = _mm_set1_epi16(ain);
      __m128i ain_m0 = _mm_set1_epi8("ع"[0]);
      __m128i ain_m1 = _mm_set1_epi8("ع"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, ain_m0),
																	   _mm_cmpeq_epi8(word_m, ain_m1)), _mm_set1_epi16(-1)), ain_mval), val_m);
      // عين

      // فاء
      __m128i faa_mval = _mm_set1_epi16(faa);
      __m128i faa_m0 = _mm_set1_epi8("ف"[0]);
      __m128i faa_m1 = _mm_set1_epi8("ف"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, faa_m0),
																	   _mm_cmpeq_epi8(word_m, faa_m1)), _mm_set1_epi16(-1)), faa_mval), val_m);
      // فاء

      // صاد
      __m128i sad_mval = _mm_set1_epi16(sad);
      __m128i sad_m0 = _mm_set1_epi8("ص"[0]);
      __m128i sad_m1 = _mm_set1_epi8("ص"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, sad_m0),
																	   _mm_cmpeq_epi8(word_m, sad_m1)), _mm_set1_epi16(-1)), sad_mval), val_m);
      // صاد

      // قاف
      __m128i qaf_mval = _mm_set1_epi16(qaf);
      __m128i qaf_m0 = _mm_set1_epi8("ق"[0]);
      __m128i qaf_m1 = _mm_set1_epi8("ق"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, qaf_m0),
																	   _mm_cmpeq_epi8(word_m, qaf_m1)), _mm_set1_epi16(-1)), qaf_mval), val_m);
      // قاف

      // راء
      __m128i raa_mval = _mm_set1_epi16(raa);
      __m128i raa_m0 = _mm_set1_epi8("ر"[0]);
      __m128i raa_m1 = _mm_set1_epi8("ر"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, raa_m0),
																	   _mm_cmpeq_epi8(word_m, raa_m1)), _mm_set1_epi16(-1)), raa_mval), val_m);
      // راء

      // شين
      __m128i shn_mval = _mm_set1_epi16(shn);
      __m128i shn_m0 = _mm_set1_epi8("ش"[0]);
      __m128i shn_m1 = _mm_set1_epi8("ش"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, shn_m0),
																	   _mm_cmpeq_epi8(word_m, shn_m1)), _mm_set1_epi16(-1)), shn_mval), val_m);
      // شين

      // تاء
      __m128i taa_mval = _mm_set1_epi16(taa);
      __m128i taa_m0 = _mm_set1_epi8("ت"[0]);
      __m128i taa_m1 = _mm_set1_epi8("ت"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, taa_m0),
																	   _mm_cmpeq_epi8(word_m, taa_m1)), _mm_set1_epi16(-1)), taa_mval), val_m);
      // تاء

      // ثاء
      __m128i tha_mval = _mm_set1_epi16(tha);
      __m128i tha_m0 = _mm_set1_epi8("ث"[0]);
      __m128i tha_m1 = _mm_set1_epi8("ث"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, tha_m0),
																	   _mm_cmpeq_epi8(word_m, tha_m1)), _mm_set1_epi16(-1)), tha_mval), val_m);
      // ثاء

      // خاء
      __m128i kha_mval = _mm_set1_epi16(kha);
      __m128i kha_m0 = _mm_set1_epi8("خ"[0]);
      __m128i kha_m1 = _mm_set1_epi8("خ"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, kha_m0),
																	   _mm_cmpeq_epi8(word_m, kha_m1)), _mm_set1_epi16(-1)), kha_mval), val_m);
      // خاء

      // ذال
      __m128i zal_mval = _mm_set1_epi16(zal);
      __m128i zal_m0 = _mm_set1_epi8("ذ"[0]);
      __m128i zal_m1 = _mm_set1_epi8("ذ"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, zal_m0),
																	   _mm_cmpeq_epi8(word_m, zal_m1)), _mm_set1_epi16(-1)), zal_mval), val_m);
      // ذال

      // ضاد
      __m128i dad_mval = _mm_set1_epi16(dad);
      __m128i dad_m0 = _mm_set1_epi8("ض"[0]);
      __m128i dad_m1 = _mm_set1_epi8("ض"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, dad_m0),
																	   _mm_cmpeq_epi8(word_m, dad_m1)), _mm_set1_epi16(-1)), dad_mval), val_m);
      // ضاد

      // ظاء
      __m128i zaa_mval = _mm_set1_epi16(zaa);
      __m128i zaa_m0 = _mm_set1_epi8("ظ"[0]);
      __m128i zaa_m1 = _mm_set1_epi8("ظ"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, zaa_m0),
																	   _mm_cmpeq_epi8(word_m, zaa_m1)), _mm_set1_epi16(-1)), zaa_mval), val_m);
      // ظاء

      // غين
      __m128i ghn_mval = _mm_set1_epi16(ghn);
      __m128i ghn_m0 = _mm_set1_epi8("غ"[0]);
      __m128i ghn_m1 = _mm_set1_epi8("غ"[1]);

      val_m = _mm_add_epi16(_mm_and_si128(_mm_cmpeq_epi16(_mm_or_si128(_mm_cmpeq_epi8(word_m, ghn_m0),
																	   _mm_cmpeq_epi8(word_m, ghn_m1)), _mm_set1_epi16(-1)), ghn_mval), val_m);
      // غين
    

    words->words[i].name_value = 0;
    for (unsigned short j = 0; j < 8; j++) {
      words->words[i].name_value += ((unsigned short *)&val_m)[j];
    }
	//words->words[i].name_value /= 2;
  }
}
