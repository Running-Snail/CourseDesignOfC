#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"

typedef struct _club {
    int32_t id;        //俱乐部id
    char *  name;       //俱乐部名称(主键)
    char *  coach;      //教练
    int16_t roundScore; //局分
    int16_t gameScore;  //场分
    int16_t ranking;    //排名
    int16_t winNum;
    int16_t roundNum;
} Club;

typedef struct _player {
    int32_t id;         //选手id
    char *  name;       //棋手名称(主键)
    char *  clubName;   //所属俱乐部名称(外键)
    int32_t clubId;    //俱乐部的key
    int8_t  grade;      //段位
    int16_t roundNum;   //参赛局数
    int16_t winNum;     //胜局数
    int8_t  isMaster;   //是否是主将
} Player;

typedef struct _game {
    int32_t id;             //棋局的id
    int16_t no;             //场次
    int8_t  type;           //局别
    char *  blackPlayer;    //黑棋棋手(外键)
    int32_t blackPlayerId; //黑棋棋手key
    char *  whitePlayer;    //白棋棋手(外键)
    int32_t whitePlayerId; //白棋棋手key
    int8_t  result;         //胜负(0黑胜,1白胜)
} Game;

Club *updateClubName(Club *aim, char *name);
Club *updateClubCoach(Club *aim, char *coach);
Club *updateClubRoundScore(Club *aim, int16_t roundScore);
Club *updateClubGameScore(Club *aim, int16_t gameScore);
Club *getClubById(int32_t clubId);
Club *printClub(Club *c);
char *sprintClub(char *str, Club *c);

Player *updatePlayerName(Player *aim, char *name);
Player *updatePlayerGrade(Player *aim, int8_t grade);
Player *updatePlayerRoundNum(Player *aim, int16_t roundNum);
Player *updatePlayerWinNum(Player *aim, int16_t winNum);
Player *getPlayerById(int32_t playerId);
Player *printPlayer(Player *p);
char *sprintPlayer(char *str, Player *p);

Game *updateGameNo(Game *aim, int16_t no);
Game *updateGameType(Game *aim, int8_t type);
Game *updateGameBlackPlayer(Game *aim, char *blackPlayer);
Game *updateGameWhitePlayer(Game *aim, char *whitePlayer);
Game *updateGameResult(Game *aim, int8_t result);
Game *getGameById(int32_t gameId);
Game *printGame(Game *g);
char *sprintGame(char *str, Game *g);

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
DynamicArray *games;
ClubList *data;
int32_t maxGameNo;

ClubList *createClubList(void);
ClubList *insertClubList(ClubList *head, ClubListNode *node);
ClubList *printClubList(ClubList *head);
char *sprintClubList(char *str, ClubList *head);
PlayerList *createPlayerList(void);
PlayerList *insertPlayerList(PlayerList *head, PlayerListNode *node);
PlayerList *printPlayerList(PlayerList *head);
char *sprintPlayerList(char *str, PlayerList *head);
GameList *createGameList(void);
GameList *insertGameList(GameList *head, GameListNode *node);
GameList *printGameList(GameList *head);
char *sprintGameList(char *str, GameList *head);

ClubListNode *searchClubName(ClubList *head, char *clubName);
PlayerListNode *searchPlayerName(ClubList *head, char *playerName);

#define createClubListNode   createClubList
#define createPlayerListNode createPlayerList
#define createGameListNode   createGameList

#endif
