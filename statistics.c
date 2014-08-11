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

void statScore(DynamicArray *games)
{
    int i;
    Club *c;
    Player *p;
    Game *g;

    GameStat *gameStatistics;
    GameStat *gs;
    gameStatistics = (GameStat *)malloc(sizeof(GameStat)*maxGameNo);

    if (!games)
        return;

    for (i=0; i<maxGameNo; i++) {
        gs = gameStatistics+i;
        gs->club1Id = -1;
        gs->club2Id = -1;
        gs->club1roundScore = 0;
        gs->club2roundScore = 0;
        gs->clubIdMasterWin = -1;
    }

    //遍历每一场比赛
    for (i=0; i<games->arrayLen; i++) {
        g = getGameById(i);
        gs = gameStatistics + g->no;
        if (gs->club1Id == -1) {
            p = getPlayerById(g->blackPlayerId);
            gs->club1Id = p->clubId;

            p = getPlayerById(g->whitePlayerId);
            gs->club2Id = p->clubId;
        }

        //黑胜
        if (g->result == 0) {
            p = getPlayerById(g->blackPlayerId);
        } else {
            p = getPlayerById(g->whitePlayerId);
        }

        //胜的俱乐部id
        if (gs->club1Id == p->clubId) {
            gs->club1roundScore += 2;
            //主将局
            if (g->type == 0) {
                gs->clubIdMasterWin = p->clubId;
            }
        } else if (gs->club2Id == p->clubId) {
            gs->club2roundScore += 2;
            if (g->type == 0) {
                gs->clubIdMasterWin = p->clubId;
            }
        }

        //是主将局 标记主将
        if (g->type == 0) {
            p = getPlayerById(g->blackPlayerId);
            p->isMaster = 1;
            p = getPlayerById(g->whitePlayerId);
            p->isMaster = 1;
        }
    }

    //遍历每场比赛
    for (i=0; i<maxGameNo; i++) {
        gs = gameStatistics+i;
        if (gs->club1roundScore > gs->club2roundScore) {
            c = getClubById(gs->club1Id);
            c->gameScore += 3;
        } else if (gs->club1roundScore < gs->club2roundScore) {
            c = getClubById(gs->club2Id);
            c->gameScore += 3;
        } else if (gs->club1roundScore == gs->club2roundScore) {
            //局分相同 按主将局赢的记两分 负的记1分
            if (gs->clubIdMasterWin!=-1) {
                c = getClubById(gs->clubIdMasterWin);
                c->gameScore += 2;
                if (gs->clubIdMasterWin != gs->club1Id) {
                    c = getClubById(gs->club1Id);
                    c->gameScore += 1;
                } else {
                    c = getClubById(gs->club2Id);
                    c->gameScore += 1;
                }
            }
        }
    }
}
