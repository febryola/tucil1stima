#include "bool.h"
#include "mesinkarakter.h"
#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H
#define CAPACITY 100
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Kata;

extern bool akhirKata;
extern Kata currentKata;

void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void skipNewline();
/* melakukan skip jika terdapat newline*/

void startWord(char *filename);
/* I.S. : currentChar sembarang 
   F.S. : akhirKata = true, dan currentChar = MARK; 
          atau akhirKata = false, currentKata adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentKata adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, akhirKata = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord();
/* Mengakuisisi kata, menyimpan dalam currentKata
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentKata berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

char KataToChar (Kata K);
/* mengembalikan karakter dimana kata diubah menjadi karakter*/

char* KataToString (Kata K);
/* mengembalikan karakter dimana kata diubah menjadi string*/

#endif

