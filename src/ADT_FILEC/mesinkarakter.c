#include <stdio.h>
#include "../ADT_HEADER/mesinkarakter.h"

static FILE * namaFile;
static int asign;
bool fileDitemukan;
char currentKarakter;
bool eot;

void start(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentKarakter adalah karakter pertama pada pita
          Jika currentKarakter != MARK maka EOP akan padam (false)
          Jika currentKarakter = MARK maka EOP akan menyala (true) */

   if ((namaFile = fopen(filename,"r")) == NULL) {
      eot = true;
      fileDitemukan = false;
   } else {
      eot = false;
      fileDitemukan = true;
      adv();
   }
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentKarakter, currentKarakter != MARK
   F.S. : currentKarakter adalah karakter berikutnya dari currentKarakter yang lama, 
          currentKarakter mungkin = MARK
		      Jika  currentKarakter = MARK maka EOP akan menyala (true) */
	asign = fscanf(namaFile,"%c",&currentKarakter);
	eot = (currentKarakter == MARK);
	if (eot) {
       fclose(namaFile);
 	}
}
