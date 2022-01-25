#include <stdio.h>
#include <stdlib.h>
#include "../ADT_HEADER/mesinkarakter.h"
#include "../ADT_HEADER/mesinkata.h"
#include "../ADT_HEADER/bool.h"
bool akhirKata;
Kata currentKata;

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentKarakter sembarang 
   F.S. : currentKarakter ≠ BLANK atau currentKarakter = MARK */
{
   if (currentKarakter == BLANK ) {
      adv();
   }
}

void skipNewline(){
/* Melakukan skip jika menemui newline*/
   if (currentKarakter == NEWLINE){
      adv();
   }
}

void startWord(char *filename)
/* I.S. : currentKarakter sembarang 
   F.S. : akhirKata = true, dan currentKarakter = MARK; 
          atau akhirKata = false, currentKata adalah kata yang sudah diakuisisi,
          currentKarakter karakter pertama sesudah karakter terakhir kata */
{
   start(filename);
   akhirKata = false;
   if(currentKarakter == MARK) {
      akhirKata = true;
   } else {
      ignoreBlank();
      copyWord();
   }
}

void advWord()
/* I.S. : currentKarakter adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentKata adalah kata terakhir yang sudah diakuisisi, 
          currentKarakter adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentKarakter = MARK, akhirKata = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
   akhirKata =false;
   if (currentKarakter == MARK){
      akhirKata = true;
   } else {
      copyWord();
      ignoreBlank();
   }
}

void copyWord()
/* Mengakuisisi kata, menyimpan dalam currentKata
   I.S. : currentKarakter adalah karakter pertama dari kata
   F.S. : currentKata berisi kata yang sudah diakuisisi; 
          currentKarakter = BLANK atau currentKarakter = MARK; 
          currentKarakter adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{

   int i = 0;
   while (currentKarakter != MARK && currentKarakter != BLANK && currentKarakter != NEWLINE && i< CAPACITY){
      currentKata.contents[i] = currentKarakter;
      adv();
      i++;
   }
   currentKata.length = i;
}

char KataToChar (Kata K)
{
      if (K.length > 1) {
         return '@';
      } else {
         return (K.contents[0]);
      }
}
/* mengembalikan karakter dimana kata diubah menjadi karakter*/

char* KataToString (Kata K){
   char* perkata = (char*)malloc(sizeof(char)*(CAPACITY)); 
   int i = 0;
   for (i = 0; i < K.length; i++) {
         perkata[i] = K.contents[i];
   }
   perkata[i] = '\0';
   return perkata;
}
/* mengembalikan karakter dimana kata diubah menjadi string*/

