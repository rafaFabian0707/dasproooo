#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UKURAN_PETA 5
#define JUMLAH_MONSTER 11  // 6 lama + 3 + 2 = 11

// fungsi cetak peta
void cetak_peta(int posisi_pemain_x, int posisi_pemain_y, int posisi_monster_x[], int posisi_monster_y[], char simbol_monster[]) {
    for (int y = 0; y < UKURAN_PETA; y++) {
        for (int x = 0; x < UKURAN_PETA; x++) {
            int dicetak = 0;
            if (x == posisi_pemain_x && y == posisi_pemain_y) {
                printf("[P]");
                dicetak = 1;
            } else {
                for (int i = 0; i < JUMLAH_MONSTER; i++) {
                    if (x == posisi_monster_x[i] && y == posisi_monster_y[i]) {
                        printf("[%c]", simbol_monster[i]);
                        dicetak = 1;
                        break;
                    }
                }
            }
            if (!dicetak) {
                printf("[ ]");
            }
        }
        printf("\n");
    }
    fflush(stdout);  // Flush output agar langsung muncul
}

int main() {
    int pemain_x = 0;   // paling kiri
    int pemain_y = 2;   // baris ke-3 (indeks 2)
    int posisi_monster_x[JUMLAH_MONSTER];
    int posisi_monster_y[JUMLAH_MONSTER];
    char simbol_monster[JUMLAH_MONSTER] = {'!', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'};  // ! dan sisanya *
    char masukan;

    // Inisialisasi random
    srand(time(NULL));

    // Set posisi monster lama secara manual
    // Monster 0: ! di paling kanan tengah (x=4, y=2)
    posisi_monster_x[0] = 4;
    posisi_monster_y[0] = 2;
    // Monster 1-5: * dari atas ke bawah di barisan sebelum tanda seru (x=3, y=0 sampai y=4)
    for (int i = 1; i <= 5; i++) {
        posisi_monster_x[i] = 3;  // kolom x=3
        posisi_monster_y[i] = i - 1;  // y=0,1,2,3,4
    }

    // Tambahkan 3 monster random di barisan 2 (x=2), posisi y random
    for (int i = 6; i <= 8; i++) {
        posisi_monster_x[i] = 2;  // barisan x=2
        int valid = 0;
        int percobaan = 0;  // Batasi percobaan agar tidak infinite
        while (!valid && percobaan < 100) {
            posisi_monster_y[i] = rand() % UKURAN_PETA;
            valid = 1;
            // Cek unik dengan semua monster sebelumnya
            for (int j = 0; j < i; j++) {
                if (posisi_monster_x[i] == posisi_monster_x[j] && posisi_monster_y[i] == posisi_monster_y[j]) {
                    valid = 0;
                    break;
                }
            }
            // Cek tidak sama dengan pemain
            if (posisi_monster_x[i] == pemain_x && posisi_monster_y[i] == pemain_y) {
                valid = 0;
            }
            percobaan++;
        }
        if (!valid) {
            printf("Error: Tidak bisa menemukan posisi valid untuk monster %d\n", i);
            return 1;  // Keluar jika gagal
        }
    }

    // Tambahkan 2 monster random di seluruh peta (bukan hanya barisan 3, karena barisan 3 sudah penuh)
    for (int i = 9; i <= 10; i++) {
        int valid = 0;
        int percobaan = 0;
        while (!valid && percobaan < 100) {
            posisi_monster_x[i] = rand() % UKURAN_PETA;
            posisi_monster_y[i] = rand() % UKURAN_PETA;
            valid = 1;
            // Cek unik dengan semua monster sebelumnya
            for (int j = 0; j < i; j++) {
                if (posisi_monster_x[i] == posisi_monster_x[j] && posisi_monster_y[i] == posisi_monster_y[j]) {
                    valid = 0;
                    break;
                }
            }
            // Cek tidak sama dengan pemain
            if (posisi_monster_x[i] == pemain_x && posisi_monster_y[i] == pemain_y) {
                valid = 0;
            }
            percobaan++;
        }
        if (!valid) {
            printf("Error: Tidak bisa menemukan posisi valid untuk monster %d\n", i);
            return 1;
        }
    }

    while (1) {
        cetak_peta(pemain_x, pemain_y, posisi_monster_x, posisi_monster_y, simbol_monster);
        printf("Gerak (w/a/s/d), q untuk keluar: ");
        fflush(stdout);
        if (scanf(" %c", &masukan) != 1) {
            printf("Error input!\n");
            break;
        }

        if (masukan == 'q') break;

        // logika gerakan pemain
        if (masukan == 'w' && pemain_y > 0) pemain_y--;
        else if (masukan == 's' && pemain_y < UKURAN_PETA - 1) pemain_y++;
        else if (masukan == 'a' && pemain_x > 0) pemain_x--;
        else if (masukan == 'd' && pemain_x < UKURAN_PETA - 1) pemain_x++;
        else printf("Tidak bisa!\n");
    }

    return 0;
}
