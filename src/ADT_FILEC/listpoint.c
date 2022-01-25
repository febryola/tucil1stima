#include <string.h>
#include <stdio.h>
#include "../ADT_HEADER/bool.h"
#include "../ADT_HEADER/listpoint.h"

void CreateListPoint(ListPoint *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas KAPASITI */
/* Proses: Inisialisasi semua elemen List l dengan VALUE_UNDEF */
{
   for (int i = 0; i < KAPASITI; i++){
      (*l).contents[(i)].x = VALUE_UNDEF;
      (*l).contents[(i)].y = VALUE_UNDEF;
   }

}

int panjangTitik(ListPoint l){
   int i = 0;
   bool ketemu = false;
   int hitung = 0;
   while (!ketemu && i<KAPASITI)
   {
      if ((l).contents[(i)].x != VALUE_UNDEF && (l).contents[(i)].y != VALUE_UNDEF){
         hitung++;
         i++;
      } else {
         ketemu = true;
      }
   }
   return hitung;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void CreatePoint(Titik *P, int a, int b){
    P->x = a;
    P->y = b;
}
/* membuat titik yang berkomponenkan a dan b*/

Titik buatTitik(int x, int y){
    Titik P;
    P.x = x;
    P.y = y;
    return P;
}
/*mengembalikan titik yang berkomponenkan a dan b*/

void insertLastPoint(ListPoint *l, EltypePoint val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   (*l).contents[(panjangTitik(*l))] = val;
}

bool dalamList (ListPoint l, int x, int y){
    bool ketemu = false;
    int i =0;
    while (i < panjangTitik(l) && !ketemu){
        if ((l).contents[(i)].x == x && (l).contents[(i)].y == y){
            ketemu = true;
        } else {
            i++;
        }
    }
    return ketemu;
}
/*mengembalikan true jika titik berada di dalam list*/