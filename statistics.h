#ifndef goViewStatISTICS_H
#define goViewStatISTICS_H

#include <math.h>

#include "datastruct.h"

typedef struct _gamegoViewStat {
    int roundScore;    //场分
    int  doesMasterWin; //主将局赢没赢
} GamegoViewStat;

int goViewStated;

void goStatRoundNum(ClubList *head);
void goStatScore(int maxGameNo, DynamicArray *games, DynamicArray *clubs);
void ranking(ClubList *head);
void goStatWinRate(DynamicArray *players);
void goSortAllPlayers(DynamicArray *players);
void goGradeStatistics(int *grades, DynamicArray *players);

#endif
