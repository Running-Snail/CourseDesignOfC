#include "statistics.h"

void statRoundNum(ClubList *cl)
{
    Variant *v;
    Club *c;
    Player *p;
    Game *g;
    PlayerListNode *pl;
    GameListNode *gl;
    int i;

    if (!cl)
        return;

    while (cl) {
        c = cl->data;
        pl = cl->playerListHead->next;
        c->roundNum = 0;
        c->winNum = 0;
        c->roundScore = 0;
        c->gameScore = 0;

        while (pl) {
            p = pl->data;
            gl = pl->gameListHead->next;
            p->roundNum = 0;
            p->winNum = 0;

            while (gl) {
                p->roundNum ++;
                g = gl->data;
                gl = gl->next;

                //执黑且黑胜 执白且白胜
                if ( (p->id == g->blackPlayerId && g->result == 0) ||
                     (p->id == g->whitePlayerId && g->result == 1) ) {
                    p->winNum ++;
                    c->roundScore += 2;
                }
            }

            pl = pl->next;
        }

        cl = cl->next;
    }

}

void statScore(int32_t maxGameNo, DynamicArray *games, DynamicArray *clubs)
{
    int i;
    int gameNo;
    Club *c;
    Player *p;
    Game *g;

    GameStat *gameStatistics;
    GameStat *gs;

    if (!games || !clubs)
        return;

    gameStatistics = (GameStat *)malloc(sizeof(GameStat)*(maxGameNo)*(clubs->arrayLen));

    for (i=0; i<maxGameNo*clubs->arrayLen; i++) {
        gs = gameStatistics+i;
        gs->roundScore = 0;
        gs->doesMasterWin = 0;
    }

    //遍历每一场比赛
    for (i=0; i<games->arrayLen; i++) {
        g = getGameById(i);

        //获取胜利的player
        //黑胜
        if (g->result == 0) {
            p = getPlayerById(g->blackPlayerId);
        } else if (g->result == 1) {
            p = getPlayerById(g->whitePlayerId);
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
            c = getClubById(i);
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
