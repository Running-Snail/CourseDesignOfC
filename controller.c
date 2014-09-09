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
 * 向文件中输出一行俱乐部信息
 * @param fout 要输出的文件
 * @param c    要输出的俱乐部指针
 */
void goWriteClubLine(FILE *fout, Club *c)
{
    if (!c || !fout)
        return;

    fprintf(fout, "\"%s\",\"%s\"\n", c->name, c->coach);
}

/**
 * 向文件中输出一行选手信息
 * @param fout 要输出的文件
 * @param p    要输出的选手指针
 */
void goWritePlayerLine(FILE *fout, Player *p)
{
    if (!p || !fout)
        return;

    fprintf(fout, "\"%s\",\"%s\",%d\n", p->name, p->clubName, p->grade);
}

/**
 * 向文件中输出一行比赛信息
 * @param fout 要输出的文件
 * @param g    要输出的比赛
 */
void goWriteGameLine(FILE *fout, Game *g)
{
    if (!g || !fout)
        return;

    fprintf(fout, "%d,%d,\"%s\",\"%s\",%d\n", g->no, g->type, g->blackPlayer, g->whitePlayer, g->result);
}

/**
 * 载入数据
 * @param  error 错误信息返回
 * @return 读取成功后返回三向链表头指针
 */
ClubList *goLoadData(const char *clubFileName, const char *playerFileName, const char *gameFileName)
{
    int clubNum, playerNum, gameNum;
    int i;
    Club *c;
    Player *p;
    Game *g;
    clubs = createDynamicArray();
    players = createDynamicArray();
    games = createDynamicArray();
    Variant *v;

    //检查文件名
    if (!clubFileName || !playerFileName || !gameFileName
        || strlen(clubFileName)<=0
        || strlen(playerFileName)<=0
        || strlen(gameFileName)<=0)
        return NULL;

    //打开文件
    FILE *clubFile = fopen(clubFileName, "r");
    FILE *playerFile = fopen(playerFileName, "r");
    FILE *gameFile = fopen(gameFileName, "r");
    //读取数量
    fscanf(clubFile, "%d", &clubNum);
    fscanf(playerFile, "%d", &playerNum);
    fscanf(gameFile, "%d", &gameNum);

    //读取俱乐部数据
    for (i=0; i<clubNum; i++) {
        c = goReadClubLine(clubFile);
        c->id = i;
        v = createVariant();
        v->v.pVoid = c;
        dynamicInsert(&clubs, i, v);
    }

    //读取选手数据
    for (i=0; i<playerNum; i++) {
        p = goReadPlayerLine(playerFile);
        p->id = i;
        v = createVariant();
        v->v.pVoid = p;
        dynamicInsert(&players, i, v);
    }

    maxGameNo = 0;

    //读取比赛数据
    for (i=0; i<gameNum; i++) {
        g = goReadGameLine(gameFile);
        g->id = i;
        v = createVariant();
        v->v.pVoid = g;
        dynamicInsert(&games, i, v);
        if (g->no > maxGameNo)
            maxGameNo = g->no;
    }

    //复制一个选手信息
    dynamicDeepCopy(&sortedPlayers, players);

    //创建链表
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

    //创建链表头
    clubListHead = goCreateClubList();

    //插入链表
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        c = (Club *)(v->v.pVoid);
        cl = goCreateClubListNode();
        cl->data = c;
        //cl->playerListHead = goCreatePlayerList();
        goInsertClubList(clubListHead, cl);
    }

    //创建选手信息链
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

    while(*str == ' ') str++;
    //while(isspace(*str)) str++;

    if (*str == 0)
        return str;

    end = str + strlen(str) -1;
    while (end > str && (*end==' '))
    //while (end > str && isspace(*end))
        end--;

    *(end+1) = 0;

    return str;
}

/**
 * 更新数据
 * @param  head 三向链表头
 * @return      更新数据后的三向链表表头指针
 */
ClubList *goRefreshData(ClubList *head)
{
    ClubListNode *cl;
    PlayerListNode *pl;
    GameListNode *gl;
    Club *c;
    Player *p;
    Game *g;
    Variant *v;
    //没有数据时显示未指定
    char noAssigned[] = "未指定";
    int i;

    if (!head)
        return NULL;

    cl = head->next;

    //遍历俱乐部
    while (cl) {
        pl = cl->playerListHead->next;
        c = cl->data;

        //便利俱乐部里的选手
        while (pl) {
            gl = pl->gameListHead->next;
            p = pl->data;

            //如果俱乐部被修改过
            if (c->changed) {
                //更新数据
                free(p->clubName);
                p->clubName = (char *)malloc(sizeof(char)*strlen(c->name));
                strcpy(p->clubName, c->name);
            }

            //遍历选手的每场比赛
            while (gl) {
                g = gl->data;

                //如果选手被修改过
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
            //恢复
            p->changed = 0;
            pl = pl->next;
        }
        //恢复
        c->changed = 0;
        cl = cl->next;
    }

    //更新动态数组内容
    if (clubs && players && games) {
        for (i=0; i<players->arrayLen; i++) {
            v = dynamicGet(players, i);
            //跳过已被删除的选手
            if (!v->v.pVoid)
                continue;
            p = (Player *)(v->v.pVoid);
            //俱乐部不存在了
            if (!dynamicGet(clubs, p->clubId)->v.pVoid) {
                p->clubId = -1;
                free(p->clubName);
                p->clubName = (char *)malloc(sizeof(char)*strlen(noAssigned));
                strcpy(p->clubName, noAssigned);
            }
        }

        for (i=0; i<games->arrayLen; i++) {
            v = dynamicGet(games, i);
            //跳过已被删除的比赛
            if (!v->v.pVoid)
                continue;
            g = (Game *)(v->v.pVoid);
            //黑方选手不存在了
            if (!dynamicGet(players, g->blackPlayerId)->v.pVoid) {
                g->blackPlayerId = -1;
                free(g->blackPlayer);
                g->blackPlayer = (char *)malloc(sizeof(char)*strlen(noAssigned));
                strcpy(g->blackPlayer, noAssigned);
            }
            //白方选手不存在了
            if (!dynamicGet(players, g->whitePlayerId)->v.pVoid) {
                g->whitePlayerId = -1;
                free(g->whitePlayer);
                g->whitePlayer = (char *)malloc(sizeof(char)*strlen(noAssigned));
                strcpy(g->whitePlayer, noAssigned);
            }
        }
    }

    goViewStated = 0;

    return head;
}

/**
 * 删除俱乐部
 * @param head   要删除俱乐部的十字三向链
 * @param clubId 俱乐部ID
 */
void goDeleteClub(ClubList *head, int clubId)
{
    Variant *v;
    Club *c;
    ClubList *cl;
    if (!head || !clubs)
        return;

    v = dynamicGet(clubs, clubId);
    if (!v)
        return;

    //找到clubID对应的链表中的结点
    c = (Club *)(v->v.pVoid);
    cl = head->next;
    while (cl) {
        if (c==cl->data)
            break;
        cl = cl->next;
    }

    //清空动态数组中相应位置
    dynamicInsert(&clubs, clubId, NULL);
    //从链表中删除
    goDeleteNodeClubList(head, cl);
    //更新数据
    goRefreshData(head);
}

/**
 * 删除选手
 * @param head     要删除的三向十字链
 * @param playerId 要删除选手的ID
 */
void goDeletePlayer(ClubList *head, int playerId)
{
    Variant* v;
    ClubList *cl;
    Player *p;
    PlayerList *pl;
    int flag = 1;
    if (!head || !players)
        return;

    v = dynamicGet(players, playerId);
    if (!v)
        return;

    //找到playerID对应的选手链表结点
    p = (Player *)(v->v.pVoid);
    cl = head->next;
    //flag break控制找到就跳出循环
    while (cl && flag) {
        pl = cl->playerListHead->next;
        while (pl && flag) {
            if (p == pl->data) {
                flag = 0;
                break;
            }
            pl = pl->next;
        }
        if (!flag)
            break;
        cl = cl->next;
    }

    //清空动态数组中的相应位置
    dynamicInsert(&players, playerId, NULL);
    //从链表中删除结点
    goDeleteNodePlayerList(cl->playerListHead, pl);
    //更新数据
    goRefreshData(head);
}

/**
 * 删除比赛
 * @param head   要删除的三向链表
 * @param gameId 要删除的比赛的ID
 */
void goDeleteGame(ClubList *head, int gameId)
{
    Variant *v;
    Game *g;
    ClubListNode *cl;
    GameListNode *gl;
    PlayerListNode *pl;
    int flag = 1;
    if (!head || !games)
        return;

    v = dynamicGet(games, gameId);
    if (!v)
        return;

    g = (Game *)(v->v.pVoid);
    cl = head->next;
    //删除对应结点
    while (cl && flag) {
        pl = cl->playerListHead->next;
        while (pl && flag) {
            gl = pl->gameListHead->next;
            while (gl && flag) {
                if (g == gl->data) {
                    goDeleteNodeGameList(pl->gameListHead, gl);
                    //flag = 0;
                    break;
                }
                gl = gl->next;
            }
            if (!flag)
                break;
            pl = pl->next;
        }
        if (!flag)
            break;
        cl = cl->next;
    }

    dynamicInsert(&games, gameId, NULL);

    goRefreshData(head);
}

/**
 * 备份数据
 */
void goBackup(void)
{
    int i, num;
    Variant *v;
    if (!clubs || !players || !games)
        return;

    FILE *clubFile = fopen(CLUB_BACKUP_FILENAME, "w");
    FILE *playerFile = fopen(PLAYER_BACKUP_FILENAME, "w");
    FILE *gameFile = fopen(GAME_BACKUP_FILENAME, "w");

    //检查可用club数量
    num = 0;
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        if (v->v.pVoid)
            num++;
    }
    fprintf(clubFile, "%d\n", num);

    //检查可用的选手数
    num = 0;
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        if (v->v.pVoid)
            num++;
    }
    fprintf(playerFile, "%d\n", num);

    //检查可用的比赛数
    num = 0;
    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        if (v->v.pVoid)
            num++;
    }
    fprintf(gameFile, "%d\n", num);

    //输出俱乐部
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        goWriteClubLine(clubFile, (Club *)(v->v.pVoid));
    }

    //输出选手
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        goWritePlayerLine(playerFile, (Player *)(v->v.pVoid));
    }

    //输出比赛
    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        goWriteGameLine(gameFile, (Game *)(v->v.pVoid));
    }

    fclose(clubFile);
    fclose(playerFile);
    fclose(gameFile);
}
