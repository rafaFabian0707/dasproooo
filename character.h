#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    char role[20];
    int darah;
    int serangan;
    int pertahanan;
    int critChance;
} Player;

void buatKarakter(Player *p) {
    printf("=== PEMBUATAN KARAKTER ===\n");

    // Input nama karakter
    printf("Masukkan nama karakter: ");
    scanf("%s", p->nama);

    int pilihan;
    printf("\nPilih Role: \n");
    printf("1. Fighter (HP tinggi, atk stabil)\n");
    printf("2. Mage    (damage besar)\n");
    printf("3. Marksman  (kritikal tinggi)\n");
    printf("ketik 1 untuk fighter, 2 untuk mage, 3 untuk marksman\n");
    printf("Pilihanmu: ");
    scanf("%d", &pilihan);

    // Set atribut berdasarkan role
    if (pilihan == 1) {
        strcpy(p->role, "Fighter");
        p->darah = 50;
        p->serangan = 10;
        p->pertahanan = 5;
        p->critChance = 5;

    } else if (pilihan == 2) {
        strcpy(p->role, "Mage");
        p->darah = 35;
        p->serangan = 14;
        p->pertahanan = 2;
        p->critChance = 10;

    } else if (pilihan == 3) {
        strcpy(p->role, "Marksman");
        p->darah = 40;
        p->serangan = 9;
        p->pertahanan = 3;
        p->critChance = 20;

    } else {
        printf("Pilihan role tidak valid, default menjadi Fighter.\n");
        strcpy(p->role, "Fighter");
        p->darah = 50;
        p->serangan = 10;
        p->pertahanan = 5;
        p->critChance = 5;
    }

    // Tampilkan karakter
    printf("\n=== KARAKTER BERHASIL DIBUAT ===\n");
    printf("Nama  : %s\n", p->nama);
    printf("Role  : %s\n", p->role);
    printf("HP    : %d\n", p->darah);
    printf("Serangan: %d\n", p->serangan);
    printf("Pertahanan: %d\n", p->pertahanan);
    printf("Crit Chance: %d%%\n\n", p->critChance);
}

