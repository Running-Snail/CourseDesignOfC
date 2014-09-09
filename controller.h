/**
 * 控制数据等基本函数文件
 * @author 冀子豪
 * @version 1.0.0
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

//引入基本头文件
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//引入自定义头文件
#include "dynamicArray.h"
#include "datastruct.h"
#include "file.h"
#include "statistics.h"

//定义数据文件名
#define CLUB_FILENAME   "club"
#define PLAYER_FILENAME "player"
#define GAME_FILENAME   "game"

//定义备份数据文件名
#define CLUB_BACKUP_FILENAME   "club.backup"
#define PLAYER_BACKUP_FILENAME "player.backup"
#define GAME_BACKUP_FILENAME   "game.backup"

//逐行数据读取函数
Club *goReadClubLine(FILE *fin);
Player *goReadPlayerLine(FILE *fin);
Game *goReadGameLine(FILE *fin);

//逐行输出数据
void goWriteClubLine(FILE *fout, Club *c);
void goWritePlayerLine(FILE *fout, Player *p);
void goWriteGameLine(FILE *fout, Game *g);

//读取数据函数
ClubList *goLoadData(const char *clubFileName, const char *playerFileName, const char *gameFileName);
//创建三向链表函数
ClubList *goCreateLists(DynamicArray *clubs, DynamicArray *players, DynamicArray *games);

//数字转换为中文段位
char *goGradeName(int grade);
//清除字符串两边空格
char *trim(char *str);

//刷新链表数据
ClubList *goRefreshData(ClubList *head);

//删除数据
void goDeleteClub(ClubList *head, int clubId);
void goDeletePlayer(ClubList *head, int playerId);
void goDeleteGame(ClubList *head, int gameId);

//备份和恢复
void goBackup(void);

#endif
