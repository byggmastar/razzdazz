#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NR_OF_DICE 8
#define GOAL 10

typedef struct {
    float points;
    int results[10];
} score;

/**
 * Initialize score card
 */
void init(float *score_card) {
    score all[] = {
        {0.5, {18, 38, 19, 37, 40, 17, 39, 16}},
        {1.5, {42, 15, 41, 14 }},
        {10, {8, 48}},
        {5, {45, 13, 10, 11, 44, 12, 43}},
        {8, {46, 9, 47}},
        {0}
    };
    for(int i = 0; all[i].points != 0; i ++) {
        for(int j = 0; all[i].results[j] != 0; j ++) {
            score_card[all[i].results[j]] = all[i].points;
        }
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    float score_card[NR_OF_DICE * 6];
    memset(score_card, 0, NR_OF_DICE * 6 * sizeof(float));
    init(score_card);

    float score = 0;
    int cost = 2;
    int cost_total = 0;
    int times = 0;

    while (score < GOAL) {
        times ++;
        cost_total += cost;
        int dice_total = 0;
        for (int i = 0; i < NR_OF_DICE; i ++) {
            dice_total += (rand() % 6) + 1;
        }
        if ( dice_total == 29) {
            cost += 2;
        } else {
            score += score_card[dice_total];
        }
    }
    printf("Cost per turn at end: %i, total money spent: %i, number of times played: %d\n", cost, cost_total, times );
    return 0;
}