#include <string.h>
#include <stdio.h>
#include "../ADT_HEADER/bool.h"
#include "../ADT_HEADER/listpos.h"

void CreateListPos(ListPos *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas KAPASITAS */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
   for (int i = 0; i < KAPASITAS; i++){
      (*l).contents[(i)] = VAL_UNDEF;
   }

}

int length(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
   bool benar = false;
   int hitung = 0;
   int i = 0;
   while (!benar && i<KAPASITAS)
   {
      if ((l).contents[(i)] != VAL_UNDEF){
         hitung++;
         i++;
      } else {
         benar = true;
      }
   }
   return hitung;
}

bool isIdxValid(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   return(i>=0 && i<KAPASITAS);
}

bool isIdxEff(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
   return(i>=0 && i<=(length(l)-1));
}

bool isEmpty(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
   bool kosong = true;
   int i = 0;
   while(kosong && (i < KAPASITAS)){
      if ((l).contents[(i)] != VAL_UNDEF){
         kosong = false;
      } else 
      {
         i++;
      }
   }

   return kosong;
}

bool isFull(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
   bool penuh = true;
   int i = 0;
   while (penuh && (i < KAPASITAS))
   {
      if ((l).contents[(i)] == VAL_UNDEF){
         penuh = false;
      } else {
         i++;
      }
   }
   return penuh;
   
}

void displayList(ListPos l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
   int i;
   if (isEmpty(l)) {
      printf("\n");
   } else {
   
      for (i = 0; i < length(l); i++){
         if(i == length(l)-1){
            printf("%s", (l).contents[(i)]);
         } else {
            printf("%s,",(l).contents[(i)]);
         }
      }
      printf("\n");
   }
}

bool isListEqual(ListPos l1, ListPos l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
   int i = 0;
   bool sama = true;
   if (length(l1) == length(l2)){
      while (sama && i <length(l1))
      {
         if (l1.contents[i] != l2.contents[i]) {
            sama = false;
         }
         else {
            i++;
         }
      }  
   } else {
      sama = false;
   }
   return sama;
}

int indexOf(ListPos l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
   bool ketemu = false;
   int i = 0;
   int idx;
   while ( !ketemu && i < length(l) ){
      if (l.contents[i] == val){
         ketemu = true;
      } else {
         i++;
      }
   }
   if (ketemu){
      idx = i;
   } else {
      idx = IDX_UNDEF;
   }

   return idx;
}

void insertLast(ListPos *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   (*l).contents[(length(*l))] = val;
}

void deleteLast(ListPos *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = (*l).contents[length(*l)-1];
   (*l).contents[(length(*l))-1] = VAL_UNDEF;
}
