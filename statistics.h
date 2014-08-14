#ifndef STATISTICS_H
#define STATISTICS_H

#include "datastruct.h"

typedef struct _gameStat {
    int16_t roundScore;    //场分
    int8_t  doesMasterWin; //主将局赢没赢
} GameStat;

void statRoundNum(ClubList *cl);
void statScore(int32_t maxGameNo, DynamicArray *games, DynamicArray *clubs);

#endif
