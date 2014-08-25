#include "datastruct.h"

Club *goCreateClub(void)
{
    Club *c;
    c = (Club *)malloc(sizeof(Club));

    c->id = 0;        //俱乐部id
    c->name = NULL;       //俱乐部名称(主键)
    c->coach = NULL;      //教练
    c->roundScore = 0; //局分
    c->gameScore = 0;  //场分
    c->ranking = 0;    //排名
    c->masterWinNum = 0;
    c->fastWinNum = 0;
    c->blackRoundNum = 0;
    c->whiteRoundNum = 0;
    c->blackWinNum = 0;
    c->whiteWinNum = 0;

    return c;
}

Club *goUpdateClubName(Club *aim, char *name)
{
    if (name)
        aim->name = name;
    return aim;
//    return ((name?(aim->name=name):0),aim);
}

Club *goUpdateClubCoach(Club *aim, char *coach)
{
    if (coach)
        aim->coach = coach;
    return aim;
}

Club *goUpdateClubRoundScore(Club *aim, int roundScore)
{
    if (roundScore>0)
        aim->roundScore = roundScore;
    return aim;
}

Club *goUpdateClubGameScore(Club *aim, int gameScore)
{
    if (gameScore>0)
        aim->gameScore = gameScore;
    return aim;
}

Club *goGetClubById(int clubId)
{
    if (clubId<0 || clubId>=clubs->arrayLen)
        return NULL;

    return (Club *)(dynamicGet(clubs, clubId)->v.pVoid);
}

Club *goPrintClub(Club *c)
{
    if (!c)
        return NULL;

    printf("name:%s coach:%s roundScore:%d gameScore:%d\n", c->name, c->coach, c->roundScore, c->gameScore);

    return c;
}

char *goSprintClub(char *str, Club *c)
{
    if (!str || !c)
        return NULL;

    sprintf(str, "name:%s coach:%s roundScore:%d gameScore:%d\n", c->name, c->coach, c->roundScore, c->gameScore);

    return str;
}

Player *goCreatePlayer(void)
{
    Player *p;

    p = (Player *)malloc(sizeof(Player));

    p->id = 0;
    p->name = NULL;
    p->clubId = 0;
    p->clubName = NULL;
    p->grade = 0;      //段位
    p->roundNum = 0;   //参赛局数
    p->winNum = 0;     //胜局数
    p->winRate = 0.0;
    p->isMaster = 0;   //是否是主将

    return p;
}

Player *goUpdatePlayerName(Player *aim, char *name)
{
    if (name)
        aim->name = name;
    return aim;
}

Player *updatePlayerClubName(Player *aim, char *clubName)
{
    if (clubName)
        aim->clubName = clubName;
    return aim;
}

Player *goUpdatePlayerGrade(Player *aim, int grade)
{
    if (grade>0)
        aim->grade = grade;
    return aim;
}

Player *goUpdatePlayerRoundNum(Player *aim, int roundNum)
{
    if (roundNum>0)
        aim->roundNum = roundNum;
    return aim;
}

Player *goUpdatePlayerWinNum(Player *aim, int winNum)
{
    if (winNum>0)
        aim->winNum = winNum;
    return aim;
}

Player *goGetPlayerById(int playerId)
{
    if (playerId<0 || playerId>=players->arrayLen)
        return NULL;

    return (Player *)(dynamicGet(players, playerId)->v.pVoid);
}

Player *goPrintPlayer(Player *p)
{
    if (!p)
        return NULL;

    printf("name:%s clubName:%s roundNum:%d winNum:%d winRate:%.2f\n", p->name, p->clubName, p->roundNum, p->winNum, p->winRate);

    return p;
}

char *goSprintPlayer(char *str, Player *p)
{
    if (!p || !str)
        return NULL;

    sprintf(str, "name:%s clubName:%s roundNum:%d winNum:%d\n", p->name, p->clubName, p->roundNum, p->winNum);

    return str;
}

Game *goCreateGame(void)
{
    Game *g;

    g = (Game *)malloc(sizeof(Game));

    g->id = 0;             //棋局的id
    g->no = 0;             //场次
    g->type = 0;           //局别
    g->blackPlayer = NULL;    //黑棋棋手(外键)
    g->blackPlayerId = 0; //黑棋棋手key
    g->whitePlayer = NULL;    //白棋棋手(外键)
    g->whitePlayerId = 0; //白棋棋手key
    g->result = 0;         //胜负(0黑胜,1白胜)

    return g;
}

Game *goUpdateGameNo(Game *aim, int no)
{
    if (no>0)
        aim->no = no;
    return aim;
}

Game *goUpdateGameType(Game *aim, int type)
{
    if (type>=0)
        aim->type = type;
    return aim;
}

Game *goUpdateGameBlackPlayer(Game *aim, char *blackPlayer)
{
    if (blackPlayer)
        aim->blackPlayer = blackPlayer;
    return aim;
}

Game *goUpdateGameWhitePlayer(Game *aim, char *whitePlayer)
{
    if (whitePlayer)
        aim->whitePlayer = whitePlayer;
    return aim;
}

Game *goUpdateGameResult(Game *aim, int result)
{
    if (result>=0)
        aim->result = result;
    return aim;
}

Game *goGetGameById(int gameId)
{
    if (gameId<0 || gameId>=games->arrayLen)
        return NULL;

    return (Game *)(dynamicGet(games, gameId)->v.pVoid);
}

Game *goPrintGame(Game *g)
{
    if (!g)
        return NULL;

    printf("no:%d type:%d blackPlayer:%s whitePlayer:%s result:%d\n", g->no, g->type, g->blackPlayer, g->whitePlayer, g->result);

    return g;
}

DynamicArray *goQueryGameNo(DynamicArray *games, int no)
{
    int i;
    DynamicArray *res = NULL;
    Variant *v;
    Game *g;

    if (!games)
        return NULL;

    res = createDynamicArray();

    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        g = (Game *)(v->v.pVoid);

        if (g->no == no) {
            dynamicAppend(res, v);
        }
    }

    return res;
}

DynamicArray *goQueryGameBlack(DynamicArray *games, char *black)
{
    int i;
    DynamicArray *res = NULL;
    Variant *v;
    Game *g;

    if (!games)
        return NULL;

    res = createDynamicArray();

    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        g = (Game *)(v->v.pVoid);

        if (strstr(g->blackPlayer, black)!=NULL) {
            dynamicAppend(res, v);
        }
    }

    return res;
}

DynamicArray *goQueryGameWhite(DynamicArray *games, char *white)
{
    int i;
    DynamicArray *res = NULL;
    Variant *v;
    Game *g;

    if (!games)
        return NULL;

    res = createDynamicArray();

    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        g = (Game *)(v->v.pVoid);

        if (strstr(g->whitePlayer, black)!=NULL) {
            dynamicAppend(res, v);
        }
    }

    return res;
}

char *goSprintGame(char *str, Game *g)
{
    if (!g || !str)
        return NULL;

    printf(str, "no:%d type:%d blackPlayer:%s whitePlayer:%s result:%d\n", g->no, g->type, g->blackPlayer, g->whitePlayer, g->result);

    return str;
}

ClubList *goCreateClubList(void)
{
    ClubList *cl = (ClubList *)malloc(sizeof(ClubList));
    cl->data = NULL;
    cl->next = NULL;
    return cl;
}

ClubList *goInsertClubList(ClubList *head, ClubListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

ClubList *goPrintClubList(ClubList *head)
{
    return head;
}

char *goSprintClubList(char *str, ClubList *head)
{
    return str;
}

PlayerList *goCreatePlayerList(void)
{
    PlayerList *pl = (PlayerList *)malloc(sizeof(PlayerList));
    pl->data = NULL;
    pl->next = NULL;
    return pl;
}

PlayerList *goInsertPlayerList(PlayerList *head, PlayerListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

PlayerList *goPrintPlayerList(PlayerList *head)
{
    return head;
}

char *goSprintPlayerList(char *str, PlayerList *head)
{
    return str;
}

GameList *goCreateGameList(void)
{
    GameList *gl = (GameList *)malloc(sizeof(GameList));
    gl->data = NULL;
    gl->next = NULL;
    return gl;
}

GameList *goInsertGameList(GameList *head, GameListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

GameList *goPrintGameList(GameList *head)
{
    return head;
}

char *goSprintGameList(char *str, GameList *head)
{
    return str;
}

int clubIdByPlayerId(int playerId)
{
    if (playerId<0 || playerId>players->arrayLen)
        return -1;

    Variant *v = dynamicGet(players, playerId);
    Player *p = (Player *)(v->v.pVoid);

    return p->clubId;
}

ClubListNode *goSearchClubName(ClubList *head, char *clubName)
{
    ClubListNode *n;
    if (!head || !clubName)
        return NULL;

    n = head->next;
    while (n) {
        if (0 == strcmp(n->data->name, clubName))
            return n;
        n = n->next;
    }

    return n;
}

PlayerListNode *goSearchPlayerName(ClubList *head, char *playerName)
{
    ClubListNode *cl;
    PlayerListNode *pl;
    if (!head || !playerName)
        return NULL;

    cl = head->next;
    while (cl) {
        pl = cl->playerListHead->next;
        while (pl) {
            if (0==strcmp(pl->data->name, playerName))
                return pl;
            pl = pl->next;
        }
        cl = cl->next;
    }

    return NULL;
}

DynamicArray *goQueryClubName(DynamicArray *clubs, char *name)
{
    DynamicArray *res = NULL;
    int i;
    Variant *v;
    Club *c;

    if (!clubs)
        return NULL;

    res = createDynamicArray();

    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        c = (Club *)(v->v.pVoid);

        if (strstr(c->name, name)!=NULL) {
            dynamicAppend(&res, v);
        }
    }

    return res;
}

DynamicArray *goQueryPlayerName(DynamicArray *players, char *name)
{
    DynamicArray *res = NULL;
    int i;
    Variant *v;
    Player *p;

    if (!players)
        return NULL;

    res = createDynamicArray();

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);

        if (strstr(p->name, name)!=NULL) {
            dynamicAppend(&res, v);
        }
    }

    return res;
}

DynamicArray *goQueryPlayerClub(DynamicArray *players, char *name)
{
    DynamicArray *res = NULL;
    int i;
    Variant *v;
    Player *p;

    if (!players)
        return NULL;

    res = createDynamicArray();

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);

        if (strstr(p->clubName, name)!=NULL) {
            dynamicAppend(&res, v);
        }
    }

    return res;
}

DynamicArray *goQueryPlayerWin(DynamicArray *players, int lower, int upper)
{
    DynamicArray *res = NULL;

    int i;
    Variant *v;
    Player *p;

    if (!players)
        return NULL;

    if (lower < 0)
        lower = 0;

    if (upper < 0)
        upper = 99999999;

    res = createDynamicArray();

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);

        if (p->winNum >= lower && p->winNum <= upper) {
            dynamicAppend(&res, v);
        }
    }

    return res;
}
