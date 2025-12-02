#include <stdio.h>

void saveGame(int x, int y, int hp) {
    FILE *file = fopen("save.txt", "w");
    if (!file) {
        printf("Gagal membuka save file\n");
        
        return;
    } else {
         printf("Game berhasil disimpan!\n");
    }
    fprintf(file, "%d %d %d\n", x, y, hp);
    fclose(file);
   
}

void loadGame(int *x, int *y, int *hp) {
    FILE *file = fopen("save.txt", "r");
    if (!file) {
        printf("Tidak ada save file!\n");
        return;
    }
    fscanf(file, "%d %d %d", x, y, hp);
    fclose(file);
    printf("Game berhasil di-load!\n");
}

