#ifndef STATISTICS_H
#define STATISTICS_H

#include "datastruct.h"

typedef struct _gameStat {
    int16_t club1Id;
    int16_t club2Id;
    int16_t club1roundScore;
    int16_t club2roundScore;
    int16_t clubIdMasterWin; //主将局胜一方俱乐部的id
} GameStat;

void statRoundNum(ClubList *cl);
void statScore(DynamicArray *games);

#endif
