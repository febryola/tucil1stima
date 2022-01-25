#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "../ADT_HEADER/bool.h"
#include "listpoint.c"
#include "listpos.c"


void displayHasil(ListPoint L, int baris, int kolom,char words[baris][kolom]){
    int i; int j;
    for (i = 0; i < baris; i++){
        for (j = 0; j<kolom; j++){
            if (dalamList(L, i,j)){
                printf(" %c ", words[i][j]);
            } else {
                printf(" - ");
            }
        } printf("\n");
    }
    printf("\n \n");
}

void carikeKiriAtasdanKananBawah (int count,int baris, int kolom,char words[baris][kolom], char* word, Titik P){
    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (a + strlen(word) -1 < baris && b + strlen(word) -1 < kolom){
        bool sama = true;
        while (a < (P.x + strlen(word))&& b < (P.y + strlen(word)) && sama){
            if (words[a][b] == word[c]){
                insertLastPoint(&l,buatTitik(a,b));
                a++; c++; b++;
            } else {
                sama = false;
            }
            count++;
        }
        if (sama){
            printf("Total perbandingan Huruf Yang Dilakukan: %d\n", count);
            displayHasil(l,baris,kolom,words);
        }
    }
}

void carikeKiriBawahdanKananAtas (int count, int baris, int kolom,char words[baris][kolom], char* word, Titik P){

    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (a - strlen(word) +1 <= 0 && b + strlen(word) -1 <= kolom){
        bool sama = true;
        while (a >= (P.x - strlen(word) + 1)&& b < (P.y + strlen(word)) && sama){
            if (words[a][b] == word[c]){
                insertLastPoint(&l,buatTitik(a,b));
                a--; c++; b++;
            } else {
                sama = false;
            }
            count++;
        }
        if (sama){
            printf("Total perbandingan Huruf Yang Dilakukan: %d\n", count);
            displayHasil(l,baris,kolom,words);
        }
        
    }
}

void cariKiridanKanan (int count, int baris,int kolom,char words[baris][kolom], char* word, Titik P){

    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (b + strlen(word) -1 < kolom ){
        bool sama = true;
        while (b < (P.y + strlen(word)) && sama){
            if (words[a][b] == word[c]){
                insertLastPoint(&l,buatTitik(a,b));
                b++; c++;
            } else {
                sama = false;
            }
            count++;
        }
        if (sama){
            printf("Total perbandingan Huruf Yang Dilakukan: %d\n", count);
            displayHasil(l,baris,kolom,words);
        }
    }
}

void cariAtasdanBawah (int count, int baris, int kolom,char words[baris][kolom], char* word, Titik P){
    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (a + strlen(word) -1 < baris ){
        bool sama = true;
        while (a < (P.x + strlen(word)) && sama){
            if (words[a][b] == word[c]){
                insertLastPoint(&l,buatTitik(a,b));
                a++; c++;
            } else {
                sama = false;
            }
            count++;
        }
        if (sama){
            printf("Total perbandingan Huruf Yang Dilakukan: %d\n", count);
            displayHasil(l,baris,kolom,words);
        }
    }
}

