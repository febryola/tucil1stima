#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ADT_HEADER/mesinkarakter.h"
#include "ADT_HEADER/mesinkata.h"
#include "ADT_HEADER/bool.h"
#include "ADT_HEADER/listpoint.h"
#include "ADT_HEADER/listpos.h"
#include "ADT_FILEC/pencarian.c"

void pengecekanKarakter (int baris, int kolom, char* word,char words[baris][kolom]){
    Titik P;
    bool cocok = false;
    int i = 0;
    int j = 0;
    int count = 0;
    for (i = 0; i < baris; i++){
        count++;
        for(j = 0; j < kolom;j++){
            count++;
            if (words[i][j] == word[0]) {
                P.x = i;
                P.y = j;
                cocok = true;
                cariKiridanKanan(count,baris,kolom,words,word,P);
                cariAtasdanBawah(count,baris,kolom,words,word,P);
                carikeKiriAtasdanKananBawah(count,baris,kolom,words,word,P);
                carikeKiriBawahdanKananAtas(count,baris,kolom,words,word,P);
            }
        }
    }
}

char* balikString(char *string)
{
    int panjang = strlen(string);
    char* balik = (char*)malloc((panjang+1) * sizeof(char));
    for(int i=0;i<panjang;i++)
    {
      balik[(panjang-1)-i]=string[i];
    }
    balik[panjang] = '\0';
    return balik;
}

int main (){
    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("--------------------------------------Selamat Datang di Program Word Search Puzzle-------------------------------------------\n");
    printf(".............................................................................................................................\n\n");
    printf("PPPPPPPPPPPPPPPPP   UUUUUUUU     UUUUUUUUZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZLLLLLLLLLLL             EEEEEEEEEEEEEEEEEEEEEE\n");
    printf("P::::::::::::::::P  U::::::U     U::::::UZ:::::::::::::::::ZZ:::::::::::::::::ZL:::::::::L             E::::::::::::::::::::E\n");
    printf("P::::::PPPPPP:::::P U::::::U     U::::::UZ:::::::::::::::::ZZ:::::::::::::::::ZL:::::::::L             E::::::::::::::::::::E\n");
    printf("PP:::::P     P:::::PUU:::::U     U:::::UUZ:::ZZZZZZZZ:::::Z Z:::ZZZZZZZZ:::::Z LL:::::::LL             EE::::::EEEEEEEEE::::E\n");
    printf("  P::::P     P:::::P U:::::U     U:::::U ZZZZZ     Z:::::Z  ZZZZZ     Z:::::Z    L:::::L                 E:::::E       EEEEEE\n");
    printf("  P::::P     P:::::P U:::::D     D:::::U         Z:::::Z            Z:::::Z      L:::::L                 E:::::E             \n");
    printf("  P::::PPPPPP:::::P  U:::::D     D:::::U        Z:::::Z            Z:::::Z       L:::::L                 E::::::EEEEEEEEEE   \n");
    printf("  P:::::::::::::PP   U:::::D     D:::::U       Z:::::Z            Z:::::Z        L:::::L                 E:::::::::::::::E   \n");
    printf("  P::::PPPPPPPPP     U:::::D     D:::::U      Z:::::Z            Z:::::Z         L:::::L                 E:::::::::::::::E   \n");
    printf("  P::::P             U:::::D     D:::::U     Z:::::Z            Z:::::Z          L:::::L                 E::::::EEEEEEEEEE   \n");
    printf("  P::::P             U:::::D     D:::::U    Z:::::Z            Z:::::Z           L:::::L                 E:::::E             \n");
    printf("  P::::P             U::::::U   U::::::U ZZZ:::::Z     ZZZZZZZZ:::::Z     ZZZZZ  L:::::L         LLLLLL  E:::::E       EEEEEE\n");
    printf("PP::::::PP           U:::::::UUU:::::::U Z::::::ZZZZZZZZ:::ZZ::::::ZZZZZZZZ:::ZLL:::::::LLLLLLLLL:::::LEE::::::EEEEEEEE:::::E\n");
    printf("P::::::::P            UU:::::::::::::UU  Z:::::::::::::::::ZZ:::::::::::::::::ZL::::::::::::::::::::::LE::::::::::::::::::::E\n");
    printf("P::::::::P              UU:::::::::UU    Z:::::::::::::::::ZZ:::::::::::::::::ZL::::::::::::::::::::::LE::::::::::::::::::::E\n");
    printf("PPPPPPPPPP                UUUUUUUUU      ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZLLLLLLLLLLLLLLLLLLLLLLLLEEEEEEEEEEEEEEEEEEEEEE\n\n");
    printf("Petunjuk bermain:\n");
    printf("1. Silakan Masukkan nama file dibawah ini dan program akan langsung mulai\n");
    printf("2. File anda harus berisikan puzzle kata dan kata yang akan dicari\n");
    printf("3. Setiap puzzle dipisahkan oleh spasi dalam 1 baris tiap karakternya\n");
    printf("4. Di akhir puzzle berikan 1 line kosong sebagai pertanda akhir dari puzzle\n");
    printf("5. Di akhir kata berikan tanda titik sebagai penanda akhir dari file Anda\n\n");
    printf("           ....................SELAMAT MENCOBA..................          \n\n");
    char* inputanFile;
    printf("Masukkan nama file (dalam format.txt): ");
    scanf("%s",inputanFile);
    int baris = 0;
    int kolom = 0;
    int hitungKarakter = 0;
    int hitungWord = 0;
    startWord(inputanFile);
    if (!fileDitemukan) {
        printf("file tidak ditemukan");
        return 0;
    }
    while (currentKarakter != NEWLINE && eot != 1 && currentKarakter != MARK) {
        hitungKarakter++;
        advWord();
        if (currentKarakter == NEWLINE) {
            skipNewline();
            baris++;
        }
    }
    kolom = hitungKarakter/baris;
    printf("jumlah baris: %d\n",baris);
    printf("jumlah kolom: %d\n",kolom);
    printf("Berikut adalah word puzzle yang akan digunakan:\n\n");
    char words[baris][kolom];
    startWord(inputanFile);
    int i = 0; int j = 0;
    while (currentKarakter != NEWLINE){
        advWord();
        words[i][j] = KataToChar(currentKata);
        if (currentKarakter == NEWLINE) {
            skipNewline();
            j = 0;
            i++;
        } else {
            j++;
        }
    }

    for (i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            printf("%c ", words[i][j]);
        }
        printf("\n");
    }
    skipNewline();
    advWord();
    ListPos word;
    ListPoint listTitik;
    CreateListPoint(&listTitik);
    CreateListPos(&word);
    while (currentKarakter != MARK){
        hitungWord++;
        insertLast(&word, KataToString(currentKata));
        insertLast(&word, balikString(KataToString(currentKata)));
        if (currentKarakter == NEWLINE) {
            skipNewline();
        }
        advWord();
    }
    printf("\nJumlah Kata yang Akan Dicari: %d\n", hitungWord);
    printf("\n");
    printf("Berikut Proses Pencarian Setiap Kata\n\n");
    clock_t mulaiWaktu = clock();
    for (i = 0; i < length(word);i++){
        pengecekanKarakter(baris,kolom,word.contents[i],words);
    }
    clock_t akhirWaktu = clock();
    float waktu =  (float)(akhirWaktu - mulaiWaktu) / CLOCKS_PER_SEC;
    printf("Waktu Eksekusi Program : %f s\n\n", waktu);
    printf(".........................................................................................\n");
    printf("......................................Program selesai....................................\n");
    printf(".........................Silakan mencoba kembali di lain waktu...........................\n");
    return 0;
}

