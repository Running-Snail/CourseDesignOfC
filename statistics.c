/**
 * 
 */
#include "statistics.h"

/**
 * 统计局数
 * @param head 要统计的三向十字链表表头
 */
void goStatRoundNum(ClubList *head)
{
    Club *c;
    Player *p;
    Game *g;
    ClubListNode *cl;
    PlayerListNode *pl;
    GameListNode *gl;

    if (!head)
        return;

    cl = head->next;

    //遍历每一个俱乐部
    while (cl) {
        c = cl->data;
        pl = cl->playerListHead->next;
        c->blackRoundNum = 0;
        c->whiteRoundNum = 0;
        c->blackWinNum = 0;
        c->whiteWinNum = 0;
        c->roundScore = 0;
        c->gameScore = 0;

        //便利俱乐部下每一个选手
        while (pl) {
            p = pl->data;
            gl = pl->gameListHead->next;
            p->roundNum = 0;
            p->winNum = 0;

            //遍历选手下每一场比赛
            while (gl) {
                p->roundNum ++;
                g = gl->data;
                gl = gl->next;

                //执黑且黑胜 执白且白胜
                if ( (p->id == g->blackPlayerId && g->result == 0) ||
                     (p->id == g->whitePlayerId && g->result == 1) ) {
                    p->winNum ++;
                    c->roundScore += 2;

                    //黑胜
                    if (g->result == 0) {
                        c->blackWinNum ++;
                    } else if (g->result == 1) {
                        c->whiteWinNum ++;
                    }

                    //主将局
                    if (g->type == 0) {
                        c->masterWinNum ++;
                    }

                    //快棋局
                    if (g->type == 1) {
                        c->fastWinNum ++;
                    }
                }

                //统计执黑胜局数和执白胜局数
                if (p->id == g->blackPlayerId) {
                    c->blackRoundNum ++;
                } else if (p->id == g->whitePlayerId) {
                    c->whiteRoundNum ++;
                }
            }

            pl = pl->next;
        }

        cl = cl->next;
    }

}

/**
 * 统计比分
 * @param maxGameNo 最大比赛场次
 * @param games     比赛动态数组
 * @param clubs     俱乐部动态数组
 */
void goStatScore(int32_t maxGameNo, DynamicArray *games, DynamicArray *clubs)
{
    int i;
    int gameNo;
    Club *c;
    Player *p;
    Game *g;

    //比赛统计局数结构体指针
    GameScoreStat *gameStatistics;
    GameScoreStat *gs;

    if (!games || !clubs)
        return;

    //创建统计数据
    gameStatistics = (GameScoreStat *)malloc(sizeof(GameScoreStat)*(maxGameNo)*(clubs->arrayLen));

    //初始化统计数据
    for (i=0; i<maxGameNo*clubs->arrayLen; i++) {
        gs = gameStatistics+i;
        gs->roundScore = 0;
        gs->doesMasterWin = 0;
    }

    //遍历每一场比赛
    for (i=0; i<games->arrayLen; i++) {
        g = goGetGameById(i);
        if (!g)
            continue;
        //获取胜利的player
        //黑胜
        if (g->result == 0) {
            p = goGetPlayerById(g->blackPlayerId);
        } else if (g->result == 1) {
            p = goGetPlayerById(g->whitePlayerId);
        }
        //转换下标
        gs = gameStatistics + (g->no-1)*(clubs->arrayLen) + p->clubId;
        gs->roundScore += 2;

        //是主将局
        if (g->type == 0) {
            gs->doesMasterWin = 1;
        }
    }

    //遍历每一局比赛
    for (gameNo=0; gameNo<maxGameNo; gameNo++) {
        for (i=0; i<clubs->arrayLen; i++) {
            //当前统计的数据
            gs = gameStatistics + gameNo*(clubs->arrayLen) + i;
            c = goGetClubById(i);
            //俱乐部不存在则跳过
            if (!c)
                continue;
            if (gs->roundScore > 4) {
                //局分大于4,直接场分加3
                c->gameScore += 3;
            } else if (gs->roundScore == 4) {
                //局分等于4的看哪方主将赢了
                if (gs->doesMasterWin) {
                    c->gameScore += 2;
                } else {
                    c->gameScore += 1;
                }
            }
        }
    }
}

/**
 * 统计选手胜率
 * @param players 选手动态数组
 */
void goStatWinRate(DynamicArray *players)
{
    Player *p;
    Variant *v;
    int i;
    if (!players)
        return;

    //遍历每一个数组
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        //跳过已被删除的选手
        if (!v->v.pVoid)
            continue;
        p = (Player *)(v->v.pVoid);
        //计算胜率
        p->winRate = 0.0f;
        if (p->roundNum != 0)
            p->winRate = (float)(p->winNum)/(float)(p->roundNum);
    }
}

/**
 * 把同一个俱乐部中的选手按照胜率排序
 * @param head 选手信息链
 */
void sortPlayerWinRateOneClube(PlayerList *head)
{
    PlayerListNode *prev1, *prev2, *maxPrev, *p1, *p2, *max, *p1next;
    if (!head)
        return;

    //选择排序
    prev1 = head;
    p1 = head->next;
    //外层遍历
    while (p1) {
        //假定当前为最大值
        maxPrev = prev1;
        max = p1;

        //内层遍历
        prev2 = p1;
        p2 = p1->next;
        while (p2) {
            //如果找到更大的修改max结点指向
            if (p2->data->winRate > max->data->winRate) {
                maxPrev = prev2;
                max = p2;
            }

            prev2 = p2;
            p2 = p2->next;
        }

        //交换
        if (max != p1) {
            //当p1和maxPrev相等时要修复
            if (p1 == maxPrev)
                p1next = p1;
            else
                p1next = p1->next;

            //交换
            prev1->next = max;
            maxPrev->next = p1;
            p1->next = max->next;
            max->next = p1next;
            //交换后p1到了max后面
            //重新指向前面
            p1 = max;
        }

        //移向下一个结点
        prev1 = p1;
        p1 = p1->next;
    }
}

/**
 * 在整个选手动态数组中根据胜率排序
 * @param players 
 */
void goSortAllPlayers(DynamicArray *players)
{
    int i, j;
    int maxI;
    Variant *v, *tmp;
    Player *p, *maxPlayer;

    //选择排序
    for (i=0; i<players->arrayLen; i++) {
        maxI = i;
        v = dynamicGet(players, i);
        //跳过已删除的选手
        if (!v->v.pVoid)
            continue;
        
        maxPlayer = (Player *)(v->v.pVoid);
        for (j=i+1; j<players->arrayLen; j++) {
            v = dynamicGet(players, j);
            //跳过已删除的选手
            if (!v->v.pVoid)
                continue;

            p = (Player *)(v->v.pVoid);
            //比较胜率
            if (p->winRate > maxPlayer->winRate) {
                maxI = j;
                v = dynamicGet(players, j);
                maxPlayer = (Player *)(v->v.pVoid);
            }
        }

        //交换两者
        if (maxI != i) {
            // tmp = i
            tmp = dynamicGet(players, i);
            // i = maxI
            dynamicInsert(&players, i, dynamicGet(players, maxI));
            // maxI = tmp
            dynamicInsert(&players, maxI, tmp);
        }
    }
}

/**
 * 对所有俱乐部中的选手进行胜率排序
 * @param head 十字三向链表
 */
void sortPlayerWinRate(ClubList *head)
{
    ClubListNode *cl;
    cl = head->next;
    while (cl) {
        //对每个俱乐部的选手进行排序
        sortPlayerWinRateOneClube(cl->playerListHead);
        cl = cl->next;
    }
}

/**
 * 获取主将
 * @param  cl 俱乐部信息链
 * @return    主将信息结点,没有找到或者cl是NULL则返回NULL
 */
PlayerListNode *getMaster(ClubListNode *cl)
{
    Player *p;
    PlayerListNode *pl;
    if (!cl)
        return NULL;

    //遍历寻找主将
    pl = cl->playerListHead->next;
    while (pl) {
        p = pl->data;
        if (p->isMaster)
            return pl;
        pl = pl->next;
    }

    return NULL;
}

/**
 * 比较函数
 * @param  cl1 比较的第一个结点
 * @param  cl2 比较的第二个结点
 * @return     比较的结果(0或1)
 */
int comp(ClubListNode *cl1, ClubListNode *cl2)
{
    Club *c1, *c2;
    PlayerListNode *master1, *master2, *pl1, *pl2;
    Player *p1, *p2;
    if (!cl1 || !cl2)
        return 0;

    c1 = cl1->data;
    c2 = cl2->data;

    //比局分
    if (c1->gameScore > c2->gameScore)
        return 1;

    //局分相同比场分
    if ((c1->gameScore == c2->gameScore) &&
        (c1->roundScore > c2->roundScore))
        return 1;

    //局分，场分都相同，比主将胜率
    if ((c1->gameScore == c2->gameScore) &&
        (c1->roundScore == c2->roundScore)) {
        master1 = getMaster(cl1);
        master2 = getMaster(cl2);

        p1 = master1->data;
        p2 = master2->data;

        if (p1->winRate > p2->winRate) {
            return 1;
        }
    }

    //局分，场分，主将胜率都相同，比选手之间胜率
    if ((c1->gameScore == c2->gameScore) &&
        (c1->roundScore == c2->roundScore) &&
        fabs(p1->winRate - p2->winRate) < 1e-7) {

        pl1 = cl1->playerListHead;
        pl2 = cl2->playerListHead;

        while (fabs(pl1->data->winRate - pl2->data->winRate) < 1e-7 &&
               pl1->data->roundNum > 15 &&
               pl2->data->roundNum > 15) {
            pl1 = pl1->next;
            pl2 = pl2->next;
        }

        if (pl1->data->winRate > pl2->data->winRate)
            return 1;

        //选手比分相同，并且pl2的参赛场数少于15场，pl1应该排在pl2前面
        if (fabs(pl1->data->winRate - pl2->data->winRate) < 1e-7 &&
            pl2->data->roundNum <= 15)
            return 1;

    }

    //最后一种可能性，pl1的参赛场数少于等于15场，pl2的参赛场数多于15场，不交换
    return 0;
}

/**
 * 给俱乐部排名
 * @param head 俱乐部信息链
 */
void ranking(ClubList *head)
{
    ClubListNode *prev1, *prev2, *maxPrev, *max, *p1, *p2, *p1next;
    int i;
    if (!head)
        return;

    //遍历选手
    prev1 = head;
    p1 = head->next;
    while (p1) {
        maxPrev = prev1;
        max = p1;

        prev2 = p1;
        p2 = p1->next;

        while (p2) {
            if (comp(p2, max)) {
                maxPrev = prev2;
                max = p2;
            }
            prev2 = p2;
            p2 = p2->next;
        }

        if (p1 != max) {
            // fix bug
            if (p1 == maxPrev)
                p1next = p1;
            else
                p1next = p1->next;

            prev1->next = max;
            maxPrev->next = p1;
            p1->next = max->next;
            max->next = p1next;

            p1 = max;
        }

        prev1 = p1;
        p1 = p1->next;
    }

    i=1;
    p1 = head->next;
    while (p1) {
        p1->data->ranking = i++;
        p1 = p1->next;
    }
}

/**
 * 
 * @param grades  [description]
 * @param players [description]
 */
void goGradeStatistics(int *grades, DynamicArray *players)
{
    int i;
    Variant *v;
    Player *p;

    if (!players || !grades)
        return;

    for (i=0; i<=9; i++) {
        *(grades+i) = 0;
    }

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        (*(grades + p->grade)) ++;
    }
}
