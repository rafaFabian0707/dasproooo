#ifndef ATTACK_SYSTEM_H
#define ATTACK_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nama[50];
    int darah;
    int serangan;
    int pertahanan;
    float critChance;
    float critMultiplier;
} Entity;

static int calculateDamage(Entity *attacker, Entity *defender) {
    int baseDamage = attacker->serangan - (defender->pertahanan / 2);
    if (baseDamage < 1) baseDamage = 1;

    float roll = (float)rand() / RAND_MAX;
    int finalDamage = baseDamage;

    if (roll < attacker->critChance) {
        finalDamage = (int)(baseDamage * attacker->critMultiplier);
        printf(" CRITICAL HIT dari %s! (%d dmg)\n", attacker->nama, finalDamage);
    } else {
        printf("%s menyerang! (%d dmg)\n", attacker->nama, finalDamage);
    }

    return finalDamage;
}

static void startBattle(Entity *player, Entity *enemy) {
    printf("\n===== BATTLE MELAWAN %s =====\n", enemy->nama);

    while (player->darah > 0 && enemy->darah > 0) {

        printf("\n--- STATUS ---\n");
        printf("%s HP: %d\n", player->nama, player->darah);
        printf("%s HP: %d\n", enemy->nama, enemy->darah);

        printf("\n1. Serang\n2. Heal (+10 HP)\n3. Defense (+5 def 1 turn)\n4. Save\n5. Load\n");
        printf("Pilihan: ");

        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            int dmg = calculateDamage(player, enemy);
            enemy->darah -= dmg;
        } 
        else if (pilihan == 2) {
            player->darah += 20;
            printf(" Kamu heal +10 HP!\n");
        } 
        else if (pilihan == 3) {
            player->pertahanan += 5;
            printf(" Defense naik +5 untuk 1 turn!\n");
        } 
        else if (pilihan == 4) {
            saveGame(0, 0, player->darah);
            continue;
        }
        else if (pilihan == 5) {
            int dummyX, dummyY, loadedHP;
            loadGame(&dummyX, &dummyY, &loadedHP);

            player->darah = loadedHP;

            printf(" HP kamu di-load menjadi: %d\n", player->darah);
            continue;
        }
        else{
            printf("Pilihan tidak valid.\n");
            continue;
        }

        if (enemy->darah <= 0) {
            printf("\n %s dikalahkan!\n", enemy->nama);
            break;
        }

        printf("\n%s menyerang balik!\n", enemy->nama);
        int enemyDmg = calculateDamage(enemy, player);
        player->darah -= enemyDmg;

        if (pilihan == 3) player->pertahanan -= 5;

        if (player->darah <= 0) {
            printf("\n Kamu kalah...\n");
            break;
        }
    }
}

#endif
