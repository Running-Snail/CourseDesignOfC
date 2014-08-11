#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"
#include "datastruct.h"
#include "file.h"
#include "statistics.h"

#define CLUB_FILENAME "club"
#define PLAYER_FILENAME "player"
#define GAME_FILENAME "game"

Club *readClubLine(FILE *fin);
Player *readPlayerLine(FILE *fin);
Game *readGameLine(FILE *fin);

ClubList *createLists(DynamicArray *clubs, DynamicArray *players, DynamicArray *games);
ClubList *loadData(int32_t *error);

#endif
