/**
 * 控制数据等基本函数文件
 * @author 冀子豪
 * @version 1.0.0
 */
#include "controller.h"

/**
 * 从文件中读取一行,并格式化成俱乐部信息
 * @param  fin 要读取的文件指针
 * @return 俱乐部结构体的指针
 */
Club *goReadClubLine(FILE *fin)
{
    Club *c;
    //初始化一个固定长度的读取缓冲区
    char buffer[READ_BUFFER_LEN] = {0};
    int len;

    //文件指针为空
    if (!fin)
        return NULL;

    //创建俱乐部结构体失败
    if (!(c = goCreateClub()))
        return NULL;

    //读取俱乐部名
    len = readString(fin, buffer);

    //根据读取出来的字符串长度分配字符串空间
    //多一个char来放0
    if (!(c->name = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    //复制俱乐部名字
    strcpy(c->name, buffer);

    //读取教练名字
    len = readString(fin, buffer);
    if (!(c->coach = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    //复制教练名字
    strcpy(c->coach, buffer);

    //忽略回车符
    ignoreChar(fin, '\n');

    return c;
}

/**
 * 从文件中读取一行,并格式化成选手信息
 * @param  fin 要读取的文件指针
 * @return 选手结构体指针
 */
Player *goReadPlayerLine(FILE *fin)
{
    Player *p;
    //初始化一个固定长度的读取缓冲区
    char buffer[READ_BUFFER_LEN] = {0};
    int len;

    //文件指针为空
    if (!fin)
        return NULL;

    //创建选手结构体失败
    if (!(p = goCreatePlayer()))
        return NULL;

    //读取选手名字
    len = readString(fin, buffer);

    //分配
    if (!(p->name = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    //复制选手名字
    strcpy(p->name, buffer);

    len = readString(fin, buffer);
    if (!(p->clubName = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    strcpy(p->clubName, buffer);

    ignoreChar(fin, ',');
    fscanf(fin, "%d", &(p->grade));

    ignoreChar(fin, '\n');

    return p;
}

/**
 * 从文件中读取一行,并格式化成比赛信息
 * @param  fin 要读取的文件指针
 * @return 比赛结构体的指针
 */
Game *goReadGameLine(FILE *fin)
{
    Game *g;
    char buffer[READ_BUFFER_LEN] = {0};
    int len;
    if (!fin)
        return NULL;

    if (!(g = goCreateGame()))
        return NULL;

    fscanf(fin, "%d , %d", &(g->no), &(g->type));
    //Black player
    len = readString(fin, buffer);
    if (!(g->blackPlayer = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    strcpy(g->blackPlayer, buffer);

    //White player
    len = readString(fin, buffer);
    if (!(g->whitePlayer = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    strcpy(g->whitePlayer, buffer);

    ignoreChar(fin, ',');
    fscanf(fin, "%d", &(g->result));

    return g;
}

/**
 * 载入数据
 * @param  error 错误信息返回
 * @return 读取成功后返回三向链表头指针
 */
ClubList *goLoadData(int *error)
{
    int clubNum, playerNum, gagoMenum;
    int i;
    Club *c;
    Player *p;
    Game *g;
    clubs = createDynamicArray();
    players = createDynamicArray();
    games = createDynamicArray();
    Variant *v;

    //Open files
    FILE *clubFile = fopen(CLUB_FILENAME, "r");
    FILE *playerFile = fopen(PLAYER_FILENAME, "r");
    FILE *gameFile = fopen(GAME_FILENAME, "r");
    //Read numbers
    fscanf(clubFile, "%d", &clubNum);
    fscanf(playerFile, "%d", &playerNum);
    fscanf(gameFile, "%d", &gagoMenum);

    //Read data
    for (i=0; i<clubNum; i++) {
        c = goReadClubLine(clubFile);
        c->id = i;
        v = createVariant();
        v->v.pVoid = c;
        dynamicInsert(&clubs, i, v);
    }

    for (i=0; i<playerNum; i++) {
        p = goReadPlayerLine(playerFile);
        p->id = i;
        v = createVariant();
        v->v.pVoid = p;
        dynamicInsert(&players, i, v);
    }

    maxGameNo = 0;

    for (i=0; i<gagoMenum; i++) {
        g = goReadGameLine(gameFile);
        g->id = i;
        v = createVariant();
        v->v.pVoid = g;
        dynamicInsert(&games, i, v);
        if (g->no > maxGameNo)
            maxGameNo = g->no;
    }

    dynamicDeepCopy(&sortedPlayers, players);

    data = goCreateLists(clubs, players, games);
    return data;
}

/**
 * 通过clubs, players, games动态数组创建三向链表
 * @param  clubs   俱乐部动态数组
 * @param  players 选手动态数组
 * @param  games   比赛动态数组
 * @return 创建成功返回三向链表
 */
ClubList *goCreateLists(DynamicArray *clubs, DynamicArray *players, DynamicArray *games)
{
    int i;
    Club *c;
    ClubList *clubListHead;
    ClubListNode *cl;
    Player *p;
    PlayerListNode *pl;
    Game *g;
    GameListNode *gl;
    Variant *v;

    //Create the list of clubs
    clubListHead = goCreateClubList();

    //Insert every club into the list
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        c = (Club *)(v->v.pVoid);
        cl = goCreateClubListNode();
        cl->data = c;
        //Create empty list of players who are in the club
        cl->playerListHead = goCreatePlayerList();
        goInsertClubList(clubListHead, cl);
    }

    //Construct player list
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        //Find the club by club's name
        cl = goSearchClubName(clubListHead, p->clubName);
        if (cl) {
            p->clubId = cl->data->id;
            pl = goCreatePlayerListNode();
            pl->data = p;
            goInsertPlayerList(cl->playerListHead, pl);
            //Create empty list of games which the player played
            pl->gameListHead = goCreateGameList();
        }
    }

    //Construct game list
    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        g = (Game *)(v->v.pVoid);
        //Search for the black player by name
        pl = goSearchPlayerName(clubListHead, g->blackPlayer);
        if (pl) {
            g->blackPlayerId = pl->data->id;
            gl = goCreateGameListNode();
            gl->data = g;
            goInsertGameList(pl->gameListHead, gl);
        }
        //Search for the white player by name
        pl = goSearchPlayerName(clubListHead, g->whitePlayer);
        if (pl) {
            g->whitePlayerId = pl->data->id;
            gl = goCreateGameListNode();
            gl->data = g;
            goInsertGameList(pl->gameListHead, gl);
        }
    }

    return clubListHead;
}

/**
 * 数字转换成中文段位
 * @param  grade 数字表示的段位[1-9]
 * @return 段位的中文表示,grade不在[1-9]之中时返回空字符串
 */
char *goGradeName(int grade)
{
    switch (grade) {
    case 1:
        return "初段";
    case 2:
        return "二段";
    case 3:
        return "三段";
    case 4:
        return "四段";
    case 5:
        return "五段";
    case 6:
        return "六段";
    case 7:
        return "七段";
    case 8:
        return "八段";
    case 9:
        return "九段";
    }

    return "";
}

/**
 * 清除字符串两端的空格,会改变原字符串
 * @param  str 要清除空格的字符串
 * @return 清除完成的字符串首指针
 */
char *trim(char *str)
{
    char *end;

    while(isspace(*str)) str++;

    if (*str == 0)
        return str;

    end = str + strlen(str) -1;
    while (end > str && isspace(*end))
        end--;

    *(end+1) = 0;

    return str;
}

ClubList *goRefreshData(ClubList *head)
{
    ClubListNode *cl;
    PlayerListNode *pl;
    GameListNode *gl;
    Club *c;
    Player *p;
    Game *g;

    if (!head)
        return NULL;

    cl = head->next;

    while (cl) {
        pl = cl->playerListHead->next;
        c = cl->data;

        while (pl) {
            gl = pl->gameListHead->next;
            p = pl->data;

            if (c->changed) {
                free(p->clubName);
                p->clubName = (char *)malloc(sizeof(char)*strlen(c->name));
                strcpy(p->clubName, c->name);
            }

            while (gl) {
                g = gl->data;

                if (p->changed) {
                    if (p->id == g->blackPlayerId) {
                        free(g->blackPlayer);
                        g->blackPlayer = (char *)malloc(sizeof(char)*strlen(p->name));
                        strcpy(g->blackPlayer, p->name);
                    } else if (p->id == g->whitePlayerId) {
                        free(g->whitePlayer);
                        g->whitePlayer = (char *)malloc(sizeof(char)*strlen(p->name));
                        strcpy(g->whitePlayer, p->name);
                    }
                }
                gl = gl->next;
            }
            p->changed = 0;
            pl = pl->next;
        }
        c->changed = 0;
        cl = cl->next;
    }

    goViewStated = 0;

    return head;
}
