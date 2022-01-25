#include "bool.h"
#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H
#define MARK '.'

extern char currentKarakter;
extern bool eot;
bool fileDitemukan;

void start();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentKarakter adalah karakter pertama pada pita
          Jika currentKarakter != MARK maka EOP akan padam (false)
          Jika currentKarakter = MARK maka EOP akan menyala (true) */

void adv();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentKarakter, currentKarakter != MARK
   F.S. : currentKarakter adalah karakter berikutnya dari currentKarakter yang lama, 
          currentKarakter mungkin = MARK
          Jika  currentKarakter = MARK maka EOP akan menyala (true) */

#endif
