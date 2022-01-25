#include "bool.h"
#ifndef LISTPOINT_H
#define LISTPOINT_H
#define KAPASITI 1000
#define IDX_UNDEF -1
#define VALUE_UNDEF -999
#define ELMTP(l, i) (l).contents[(i)]
#define ELMT_X(l, i) (l).contents[(i)].x
#define ELMT_Y(l, i) (l).contents[(i)].y

typedef struct {
   int x; /* MENYIMPAN NILAI X*/
   int y; /* MENYIMPAN NILAI Y*/
} Titik;

typedef Titik EltypePoint; 
typedef struct {
   Titik contents[KAPASITI];
} ListPoint;

void CreateListPoint(ListPoint *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas KAPASITI */
/* Proses: Inisialisasi semua elemen List l dengan VALUE_UNDEF */

void CreatePoint(Titik *P, int x, int y);
/* Membuat titik dari komponen x dan y*/

Titik buatTitik(int x,int y);
/* mengembalikan titik yang berkomponenkan x dan y */

int panjangTitik(ListPoint l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void insertLastPoint(ListPoint *l, EltypePoint val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

bool dalamList (ListPoint l, int x, int y);
/*mengembalikan true jika titik berada di dalam list*/

#endif