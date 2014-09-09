#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"

//俱乐部结构体
typedef struct _club {
    int   id;            //俱乐部id
    char *name;          //俱乐部名称(主键)
    char *coach;         //教练
    int   roundScore;    //局分
    int   gameScore;     //场分
    int   ranking;       //排名
    int   masterWinNum;  //主将胜局数
    int   fastWinNum;    //快棋胜局数
    int   blackRoundNum; //执黑局数
    int   whiteRoundNum; //执白局数
    int   blackWinNum;   //执黑胜局数
    int   whiteWinNum;   //执白胜局数
    int   changed;       //数据是否有更新(主要是俱乐部名)
} Club;

//选手结构体
typedef struct _player {
    int   id;        //选手id
    char  *name;     //棋手名称(主键)
    char  *clubName; //所属俱乐部名称(外键)
    int   clubId;    //俱乐部的key
    int   grade;     //段位
    int   roundNum;  //参赛局数
    int   winNum;    //胜局数
    float winRate;   //胜率
    int   isMaster;  //是否是主将
    int   changed;   //数据是否被修改(主要是选手名)
} Player;

//比赛结构体
typedef struct _game {
    int   id;            //棋局的id
    int   no;            //场次
    int   type;          //局别
    char *blackPlayer;   //黑棋棋手(外键)
    int   blackPlayerId; //黑棋棋手key
    char *whitePlayer;   //白棋棋手(外键)
    int   whitePlayerId; //白棋棋手key
    int   result;        //胜负(0黑胜,1白胜)
} Game;

//与俱乐部有关
Club *goCreateClub(void);
Club *goGetClubById(int clubId);
Club *goPrintClub(Club *c);
//根据名字查找俱乐部
DynamicArray *goQueryClubName(DynamicArray *clubs, char *name);

//与选手有关
Player *goCreatePlayer(void);
Player *goGetPlayerById(int playerId);
Player *goPrintPlayer(Player *p);
//根据选手名查找
DynamicArray *goQueryPlayerName(DynamicArray *players, char *name);
//根据选手俱乐部查找
DynamicArray *goQueryPlayerClub(DynamicArray *players, char *name);
//根据选手胜局数查找
DynamicArray *goQueryPlayerWin(DynamicArray *players, int lower, int upper);

//与比赛有关
Game *goCreateGame(void);
Game *goGetGameById(int gameId);
Game *goPrintGame(Game *g);
//根据比赛场次查找
DynamicArray *goQueryGameNo(DynamicArray *games, int no);
//根据比赛执黑选手查找
DynamicArray *goQueryGameBlack(DynamicArray *games, char *black);
//根据比赛执白选手查找
DynamicArray *goQueryGameWhite(DynamicArray *games, char *white);
//根据比赛结果查找
DynamicArray *goQueryGameResult(DynamicArray *games, int result);

//比赛信息链
typedef struct _gameList {
    Game *            data;
    struct _gameList *next;
} GameList, GameListHead, GameListNode;

//选手信息链
typedef struct _playerList {
    Player *            data;
    struct _playerList *next;
    GameList *          gameListHead;
} PlayerList, PlayerListHead, PlayerListNode;

//俱乐部信息链
typedef struct _clubList {
    Club *            data;
    struct _clubList *next;
    PlayerList *      playerListHead;
} ClubList, ClubListHead, ClubListNode;

//动态数组
DynamicArray *clubs;
DynamicArray *players;
DynamicArray *sortedPlayers;
DynamicArray *games;
//三向链表表头
ClubList *data;
//比赛最大场次数
int maxGameNo;
Variant *changingVariant;

//与俱乐部信息链有关
ClubList *goCreateClubList(void);
ClubList *goInsertClubList(ClubList *head, ClubListNode *node);
ClubList *goDeleteNodeClubList(ClubList *head, ClubListNode *node);
ClubList *goPrintClubList(ClubList *head);

//与选手信息链有关
PlayerList *goCreatePlayerList(void);
PlayerList *goInsertPlayerList(PlayerList *head, PlayerListNode *node);
PlayerList *goDeleteNodePlayerList(PlayerList *head, PlayerListNode *node);
PlayerList *goPrintPlayerList(PlayerList *head);

//与比赛信息链有关
GameList *goCreateGameList(void);
GameList *goInsertGameList(GameList *head, GameListNode *node);
GameList *goDeleteNodeGameList(GameList *head, GameListNode *node);
GameList *goPrintGameList(GameList *head);

//根据名字查找结点
ClubListNode *goSearchClubName(ClubList *head, char *clubName);
PlayerListNode *goSearchPlayerName(ClubList *head, char *playerName);

//别名
#define goCreateClubListNode   goCreateClubList
#define goCreatePlayerListNode goCreatePlayerList
#define goCreateGameListNode   goCreateGameList

#endif
