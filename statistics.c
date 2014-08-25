#include "statistics.h"

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

void goStatScore(int32_t maxGameNo, DynamicArray *games, DynamicArray *clubs)
{
    int i;
    int gameNo;
    Club *c;
    Player *p;
    Game *g;

    GamegoViewStat *gameStatistics;
    GamegoViewStat *gs;

    if (!games || !clubs)
        return;

    gameStatistics = (GamegoViewStat *)malloc(sizeof(GamegoViewStat)*(maxGameNo)*(clubs->arrayLen));

    for (i=0; i<maxGameNo*clubs->arrayLen; i++) {
        gs = gameStatistics+i;
        gs->roundScore = 0;
        gs->doesMasterWin = 0;
    }

    //遍历每一场比赛
    for (i=0; i<games->arrayLen; i++) {
        g = goGetGameById(i);

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

    for (gameNo=0; gameNo<maxGameNo; gameNo++) {
        for (i=0; i<clubs->arrayLen; i++) {
            gs = gameStatistics + gameNo*(clubs->arrayLen) + i;
            c = goGetClubById(i);
            if (gs->roundScore > 4) {
                c->gameScore += 3;
            } else if (gs->roundScore == 4) {
                if (gs->doesMasterWin) {
                    c->gameScore += 2;
                } else {
                    c->gameScore += 1;
                }
            }
        }
    }
}

void goStatWinRate(DynamicArray *players)
{
    Player *p;
    Variant *v;
    int i;
    if (!players)
        return;

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        p->winRate = 0.0f;
        if (p->roundNum != 0)
            p->winRate = (float)(p->winNum)/(float)(p->roundNum);
    }
}

void sortPlayerWinRateOneClube(PlayerList *head)
{
    PlayerListNode *prev1, *prev2, *maxPrev, *p1, *p2, *max, *p1next;
    if (!head)
        return;

    //selection sort
    prev1 = head;
    p1 = head->next;
    while (p1) {
        maxPrev = prev1;
        max = p1;

        prev2 = p1;
        p2 = p1->next;

        while (p2) {
            if (p2->data->winRate > max->data->winRate) {
                maxPrev = prev2;
                max = p2;
            }

            prev2 = p2;
            p2 = p2->next;
        }

        //swap
        if (max != p1) {
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
}

void goSortAllPlayers(DynamicArray *players)
{
    int i, j;
    int maxI;
    Variant *v, *tmp;
    Player *p, *maxPlayer;

    for (i=0; i<players->arrayLen; i++) {
        maxI = i;
        v = dynamicGet(players, i);
        maxPlayer = (Player *)(v->v.pVoid);
        for (j=i+1; j<players->arrayLen; j++) {
            v = dynamicGet(players, j);
            p = (Player *)(v->v.pVoid);
            if (p->winRate > maxPlayer->winRate) {
                maxI = j;
                v = dynamicGet(players, j);
                maxPlayer = (Player *)(v->v.pVoid);
            }
        }

        //swap
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

void sortPlayerWinRate(ClubList *head)
{
    ClubListNode *cl;
    cl = head->next;
    while (cl) {
        sortPlayerWinRateOneClube(cl->playerListHead);
        cl = cl->next;
    }
}

PlayerListNode *getMaster(ClubListNode *cl)
{
    Player *p;
    PlayerListNode *pl;
    if (!cl)
        return NULL;

    pl = cl->playerListHead->next;

    while (pl) {
        p = pl->data;
        if (p->isMaster)
            return pl;
        pl = pl->next;
    }

    return NULL;
}

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

void ranking(ClubList *head)
{
    ClubListNode *prev1, *prev2, *maxPrev, *max, *p1, *p2, *p1next;
    int i;
    if (!head)
        return;

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
