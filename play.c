#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "character.h"
#include "save_load.h"
#include "attack_system.h"
#include "monster.h"
#include "map.h"

Entity convertPlayer(Player *p) {
    Entity e;
    strcpy(e.nama, p->nama);
    e.darah = p->darah;
    e.serangan = p->serangan;
    e.pertahanan = p->pertahanan;
    e.critChance = p->critChance / 100.0f;
    e.critMultiplier = 1.6;
    return e;
}
void buffOrcWin(Player *p, Entity *playerEntity) {
    p->darah = 100;                       // HP langsung penuh
    p->serangan += 5;                  // attack buff +5

    // update entity untuk battle berikutnya
    playerEntity->darah = p->darah;
    playerEntity->serangan = p->serangan;

    printf("\n Kamu mengalahkan Lord!\n");
    printf(" Darah menjadi 100!\n");
    printf(" Attack naik +5!\n");
}


int main() {
    srand(time(NULL));

    Player p;
    buatKarakter(&p);
    Entity player = convertPlayer(&p);

    int px = 0, py = 2;
    char input;

    initAllMonsters();

    while (1) {
        printf("\n====== MAP ======\n");
        cetakMap(px, py);

        printf("\nMove (W A S D), q keluar: ");
        scanf(" %c", &input);

        if (input == 'q') break;

        if (input == 'w' && py > 0) py--;
        else if (input == 's' && py < MAP_SIZE - 1) py++;
        else if (input == 'a' && px > 0) px--;
        else if (input == 'd' && px < MAP_SIZE - 1) px++;
        else continue;

        for (int i = 0; i < TOTAL_MONSTER; i++) {
            if (monsterAlive[i] &&
                monsterX[i] == px &&
                monsterY[i] == py) {

                printf("\n Kamu melawan %s!\n", monsterData[i].nama);

                startBattle(&player, &monsterData[i]);

                if (monsterData[i].darah <= 0) {
    printf(" %s telah dikalahkan!\n", monsterData[i].nama);
    monsterAlive[i] = 0;

    // Jika ORC kalah → buff player
    if (monsterX[i] == 3) {
        buffOrcWin(&p, &player);
    }
}


                if (player.darah <= 0) {
                    printf("\nGAME OVER.\n");
                    return 0;
                }
            }
        }
    }

    return 0;
}
