/**
 * @version 1.0.0
 * @author  冀子豪
 */
#include "datastruct.h"

/**
 * 创建俱乐部结构体
 * @return 创建的俱乐部信息
 */
Club *goCreateClub(void)
{
    Club *c;
    c = (Club *)malloc(sizeof(Club));

    c->id            = 0;    //俱乐部id
    c->name          = NULL; //俱乐部名称(主键)
    c->coach         = NULL; //教练
    c->roundScore    = 0;    //局分
    c->gameScore     = 0;    //场分
    c->ranking       = 0;    //排名
    c->masterWinNum  = 0;    //主将局胜利数
    c->fastWinNum    = 0;    //快棋局胜利数
    c->blackRoundNum = 0;    //执黑局数
    c->whiteRoundNum = 0;    //执白局数
    c->blackWinNum   = 0;    //执黑胜利数
    c->whiteWinNum   = 0;    //执白胜利数

    return c;
}

/**
 * 根据club的id获取俱乐部信息
 * @param  clubId 俱乐部id
 * @return        获取的俱乐部结构体指针
 */
Club *goGetClubById(int clubId)
{
    if (clubId<0 || clubId>=clubs->arrayLen)
        return NULL;

    return (Club *)(dynamicGet(clubs, clubId)->v.pVoid);
}

/**
 * 输出俱乐部信息
 * @param  c 要打印的俱乐部
 * @return   输入的俱乐部
 */
Club *goPrintClub(Club *c)
{
    if (!c)
        return NULL;

    printf("name:%s coach:%s roundScore:%d gameScore:%d\n", c->name, c->coach, c->roundScore, c->gameScore);

    return c;
}

/**
 * 输出俱乐部信息
 * @param  str 要打印到的字符串指针
 * @param  c   要打印的俱乐部
 * @return     打印到的字符串指针
 */
char *goSprintClub(char *str, Club *c)
{
    if (!str || !c)
        return NULL;

    sprintf(str, "name:%s coach:%s roundScore:%d gameScore:%d\n", c->name, c->coach, c->roundScore, c->gameScore);

    return str;
}

/**
 * 创建选手结构体
 * @return 创建的选手结构体指针
 */
Player *goCreatePlayer(void)
{
    Player *p;

    p = (Player *)malloc(sizeof(Player));

    p->id       = 0;    //选手id
    p->name     = NULL; //选手名字
    p->clubId   = 0;    //选手俱乐部id
    p->clubName = NULL; //选手俱乐部名字
    p->grade    = 0;    //段位
    p->roundNum = 0;    //参赛局数
    p->winNum   = 0;    //胜局数
    p->winRate  = 0.0;  //胜率
    p->isMaster = 0;    //是否是主将

    return p;
}

/**
 * 根据选手id获取选手
 * @param  playerId 选手id
 * @return          获取的选手结构体指针
 */
Player *goGetPlayerById(int playerId)
{
    if (playerId<0 || playerId>=players->arrayLen)
        return NULL;

    return (Player *)(dynamicGet(players, playerId)->v.pVoid);
}

/**
 * 输出选手信息
 * @param  p 要打印的选手
 * @return   传入的选手
 */
Player *goPrintPlayer(Player *p)
{
    if (!p)
        return NULL;

    printf("name:%s clubName:%s roundNum:%d winNum:%d winRate:%.2f\n", p->name, p->clubName, p->roundNum, p->winNum, p->winRate);

    return p;
}

/**
 * 输出选手信息
 * @param  str 要输出的目标字符串
 * @param  p   选手
 * @return     输出的字符串指针
 */
char *goSprintPlayer(char *str, Player *p)
{
    if (!p || !str)
        return NULL;

    sprintf(str, "name:%s clubName:%s roundNum:%d winNum:%d\n", p->name, p->clubName, p->roundNum, p->winNum);

    return str;
}

/**
 * 创建比赛结构体
 * @return 创建的比赛结构体指针
 */
Game *goCreateGame(void)
{
    Game *g;

    g = (Game *)malloc(sizeof(Game));

    g->id            = 0;    //棋局的id
    g->no            = 0;    //场次
    g->type          = 0;    //局别
    g->blackPlayer   = NULL; //黑棋棋手(外键)
    g->blackPlayerId = 0;    //黑棋棋手key
    g->whitePlayer   = NULL; //白棋棋手(外键)
    g->whitePlayerId = 0;    //白棋棋手key
    g->result        = 0;    //胜负(0黑胜,1白胜)

    return g;
}

/**
 * 根据比赛Id获取比赛结构体指针
 * @param  gameId 比赛Id
 * @return        获取的比赛结构体指针
 */
Game *goGetGameById(int gameId)
{
    if (gameId<0 || gameId>=games->arrayLen)
        return NULL;

    return (Game *)(dynamicGet(games, gameId)->v.pVoid);
}

/**
 * 输出比赛信息
 * @param  g 要输出的比赛信息
 * @return   输入的比赛结构体指针
 */
Game *goPrintGame(Game *g)
{
    if (!g)
        return NULL;

    printf("no:%d type:%d blackPlayer:%s whitePlayer:%s result:%d\n", g->no, g->type, g->blackPlayer, g->whitePlayer, g->result);

    return g;
}

/**
 * 查询场次为no的比赛
 * @param  games 保存比赛的动态数组
 * @param  no    比赛的场次
 * @return       保存所有比赛场次为no的动态数组
 */
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
            dynamicAppend(&res, v);
        }
    }

    return res;
}

/**
 * 查询执黑选手为black的比赛
 * @param  games 保存比赛的动态数组
 * @param  black 执黑选手的姓名
 * @return       查询结果的动态数组
 */
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
            dynamicAppend(&res, v);
        }
    }

    return res;
}

/**
 * 查询执白选手为white的比赛
 * @param  games 保存比赛信息的动态数组
 * @param  white 执白选手的姓名
 * @return       查询的结果
 */
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

        if (strstr(g->whitePlayer, white)!=NULL) {
            dynamicAppend(&res, v);
        }
    }

    return res;
}

/**
 * 输出比赛信息
 * @param  str 要输出到的字符串
 * @param  g   要输出的比赛
 * @return     输出的字符串
 */
char *goSprintGame(char *str, Game *g)
{
    if (!g || !str)
        return NULL;

    printf(str, "no:%d type:%d blackPlayer:%s whitePlayer:%s result:%d\n", g->no, g->type, g->blackPlayer, g->whitePlayer, g->result);

    return str;
}

/**
 * 创建俱乐部链表结构体
 * @return 创建的俱乐部链表结构体指针
 */
ClubList *goCreateClubList(void)
{
    ClubList *cl = (ClubList *)malloc(sizeof(ClubList));
    cl->data = NULL;
    cl->next = NULL;
    //创建空的选手信息链
    cl->playerListHead = goCreatePlayerList();
    return cl;
}

/**
 * 插入俱乐部链表
 * @param  head 要插入到的俱乐部链表
 * @param  node 要插入的俱乐部链表结点
 * @return      俱乐部链表
 */
ClubList *goInsertClubList(ClubList *head, ClubListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

/**
 * 创建选手信息链
 * @return 创建的选手信息链
 */
PlayerList *goCreatePlayerList(void)
{
    PlayerList *pl = (PlayerList *)malloc(sizeof(PlayerList));
    pl->data = NULL;
    pl->next = NULL;
    pl->gameListHead = goCreateGameList();
    return pl;
}

/**
 * 插入选手信息链
 * @param  head 要插入的选手信息链
 * @param  node 要插入的选手信息
 * @return      选手信息链
 */
PlayerList *goInsertPlayerList(PlayerList *head, PlayerListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

/**
 * 闯将比赛信息链
 * @return 创建的比赛信息链
 */
GameList *goCreateGameList(void)
{
    GameList *gl = (GameList *)malloc(sizeof(GameList));
    gl->data = NULL;
    gl->next = NULL;
    return gl;
}

/**
 * 插入到比赛信息链
 * @param  head 要插入的比赛信息链表
 * @param  node 要插入的比赛
 * @return      比赛信息链
 */
GameList *goInsertGameList(GameList *head, GameListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

/**
 * 根据选手id获取俱乐部id
 * @param  playerId 选手id
 * @return          俱乐部id
 */
int clubIdByPlayerId(int playerId)
{
    if (playerId<0 || playerId>players->arrayLen)
        return -1;

    Variant *v = dynamicGet(players, playerId);
    Player *p = (Player *)(v->v.pVoid);

    return p->clubId;
}

/**
 *
 * @param  head
 * @param  clubName
 * @return
 */
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

/**
 *
 * @param  head
 * @param  playerName
 * @return
 */
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

/**
 *
 * @param  clubs
 * @param  name
 * @return
 */
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

/**
 *
 * @param  players
 * @param  name
 * @return
 */
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

/**
 *
 * @param  players
 * @param  name
 * @return
 */
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

/**
 *
 * @param  players
 * @param  lower
 * @param  upper
 * @return
 */
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

/**
 *
 * @param  games
 * @param  result
 * @return
 */
DynamicArray *goQueryGameResult(DynamicArray *games, int result)
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

        if (g->result == result) {
            dynamicAppend(&res, v);
        }
    }

    return res;
}
