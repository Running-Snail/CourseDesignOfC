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

Club *goReadClubLine(FILE *fin);
Player *goReadPlayerLine(FILE *fin);
Game *goReadGameLine(FILE *fin);

ClubList *goCreateLists(DynamicArray *clubs, DynamicArray *players, DynamicArray *games);
ClubList *goViewLoadData(int *error);

char *goGradeName(int grade);
char *trim(char *str);

#endif
