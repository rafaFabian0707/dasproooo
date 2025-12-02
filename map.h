#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "monster.h"

void cetakMap(int px, int py) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < 5; x++) {

            int printed = 0;

            if (x == px && y == py) {
                printf("[P]");
                printed = 1;
            }

            for (int i = 0; i < TOTAL_MONSTER && !printed; i++) {
                if (monsterAlive[i] &&
                    monsterX[i] == x &&
                    monsterY[i] == y) {

                    printf("[M]");
                    printed = 1;
                }
            }

            if (!printed) printf("[ ]");
        }
        printf("\n");
    }
}

#endif
