#ifndef MONSTER_SYSTEM_H
#define MONSTER_SYSTEM_H

#include <string.h>
#include "attack_system.h"

#define MAP_SIZE 5
#define TOTAL_MONSTER (MAP_SIZE * 4)

int monsterX[TOTAL_MONSTER];
int monsterY[TOTAL_MONSTER];
int monsterAlive[TOTAL_MONSTER];
Entity monsterData[TOTAL_MONSTER];

Entity buatMonster(int col) {
    Entity m;

    if (col == 1) {
        strcpy(m.nama, "Minion");
        m.darah = 20; m.serangan = 4; m.pertahanan = 1;
        m.critChance = 0.05; m.critMultiplier = 1.3;
    }
    else if (col == 2) {
        strcpy(m.nama, "Turtle");
        m.darah = 35; m.serangan = 7; m.pertahanan = 2;
        m.critChance = 0.08; m.critMultiplier = 1.4;
    }
    else if (col == 3) {
        strcpy(m.nama, "Lord");
        m.darah = 55; m.serangan = 10; m.pertahanan = 4;
        m.critChance = 0.10; m.critMultiplier = 1.5;
    }
    else {
        strcpy(m.nama, "King Balmond");
        m.darah = 100; m.serangan = 18; m.pertahanan = 6;
        m.critChance = 0.10; m.critMultiplier = 2.0;
    }

    return m;
}

void semuaMonsters() {
    int idx = 0;
    for (int col = 1; col <= 4; col++) {
        for (int row = 0; row < MAP_SIZE; row++) {
            monsterX[idx] = col;
            monsterY[idx] = row;
            monsterAlive[idx] = 1;
            monsterData[idx] = buatMonster(col);
            idx++;
        }
    }
}

#endif
