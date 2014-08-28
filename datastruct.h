#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"

typedef struct _club {
    int id;        //俱乐部id
    char *  name;       //俱乐部名称(主键)
    char *  coach;      //教练
    int roundScore; //局分
    int gameScore;  //场分
    int ranking;    //排名
    int masterWinNum;
    int fastWinNum;
    int blackRoundNum;
    int whiteRoundNum;
    int blackWinNum;
    int whiteWinNum;
    int changed;
} Club;

typedef struct _player {
    int id;         //选手id
    char *  name;       //棋手名称(主键)
    char *  clubName;   //所属俱乐部名称(外键)
    int clubId;    //俱乐部的key
    int grade;      //段位
    int roundNum;   //参赛局数
    int winNum;     //胜局数
    float winRate;
    int isMaster;   //是否是主将
    int changed;
} Player;

typedef struct _game {
    int id;             //棋局的id
    int no;             //场次
    int  type;           //局别
    char *  blackPlayer;    //黑棋棋手(外键)
    int blackPlayerId; //黑棋棋手key
    char *  whitePlayer;    //白棋棋手(外键)
    int whitePlayerId; //白棋棋手key
    int  result;         //胜负(0黑胜,1白胜)
} Game;

Club *goCreateClub(void);
Club *goGetClubById(int clubId);
Club *goPrintClub(Club *c);
DynamicArray *goQueryClubName(DynamicArray *clubs, char *name);

Player *goCreatePlayer(void);
Player *goGetPlayerById(int playerId);
Player *goPrintPlayer(Player *p);
DynamicArray *goQueryPlayerName(DynamicArray *players, char *name);
DynamicArray *goQueryPlayerClub(DynamicArray *players, char *name);
DynamicArray *goQueryPlayerWin(DynamicArray *players, int lower, int upper);

Game *goCreateGame(void);
Game *goGetGameById(int gameId);
Game *goPrintGame(Game *g);
DynamicArray *goQueryGameNo(DynamicArray *games, int no);
DynamicArray *goQueryGameBlack(DynamicArray *games, char *black);
DynamicArray *goQueryGameWhite(DynamicArray *games, char *white);
DynamicArray *goQueryGameResult(DynamicArray *games, int result);

typedef struct _gameList {
    Game *            data;
    struct _gameList *next;
} GameList, GameListHead, GameListNode;

typedef struct _playerList {
    Player *            data;
    struct _playerList *next;
    GameList *          gameListHead;
} PlayerList, PlayerListHead, PlayerListNode;

typedef struct _clubList {
    Club *            data;
    struct _clubList *next;
    PlayerList *      playerListHead;
} ClubList, ClubListHead, ClubListNode;

DynamicArray *clubs;
DynamicArray *players;
DynamicArray *sortedPlayers;
DynamicArray *games;
ClubList *data;
int maxGameNo;
Variant *changingVariant;

ClubList *goCreateClubList(void);
ClubList *goInsertClubList(ClubList *head, ClubListNode *node);
ClubList *goPrintClubList(ClubList *head);
char *goSprintClubList(char *str, ClubList *head);
PlayerList *goCreatePlayerList(void);
PlayerList *goInsertPlayerList(PlayerList *head, PlayerListNode *node);
PlayerList *goPrintPlayerList(PlayerList *head);
char *goSprintPlayerList(char *str, PlayerList *head);
GameList *goCreateGameList(void);
GameList *goInsertGameList(GameList *head, GameListNode *node);
GameList *goPrintGameList(GameList *head);
char *goSprintGameList(char *str, GameList *head);

ClubListNode *goSearchClubName(ClubList *head, char *clubName);
PlayerListNode *goSearchPlayerName(ClubList *head, char *playerName);

#define goCreateClubListNode   goCreateClubList
#define goCreatePlayerListNode goCreatePlayerList
#define goCreateGameListNode   goCreateGameList

#endif
