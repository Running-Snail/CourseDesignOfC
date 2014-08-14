#include "datastruct.h"

Club *updateClubName(Club *aim, char *name)
{
    if (name)
        aim->name = name;
    return aim;
//    return ((name?(aim->name=name):0),aim);
}

Club *updateClubCoach(Club *aim, char *coach)
{
    if (coach)
        aim->coach = coach;
    return aim;
}

Club *updateClubRoundScore(Club *aim, int16_t roundScore)
{
    if (roundScore>0)
        aim->roundScore = roundScore;
    return aim;
}

Club *updateClubGameScore(Club *aim, int16_t gameScore)
{
    if (gameScore>0)
        aim->gameScore = gameScore;
    return aim;
}

Club *getClubById(int32_t clubId)
{
    if (clubId<0 || clubId>=clubs->arrayLen)
        return NULL;

    return (Club *)(dynamicGet(clubs, clubId)->v.pVoid);
}

Club *printClub(Club *c)
{
    if (!c)
        return NULL;

    printf("name:%s coach:%s roundScore:%d gameScore:%d\n", c->name, c->coach, c->roundScore, c->gameScore);

    return c;
}

char *sprintClub(char *str, Club *c)
{
    if (!str || !c)
        return NULL;

    sprintf(str, "name:%s coach:%s roundScore:%d gameScore:%d\n", c->name, c->coach, c->roundScore, c->gameScore);

    return str;
}

Player *updatePlayerName(Player *aim, char *name)
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

Player *updatePlayerGrade(Player *aim, int8_t grade)
{
    if (grade>0)
        aim->grade = grade;
    return aim;
}

Player *updatePlayerRoundNum(Player *aim, int16_t roundNum)
{
    if (roundNum>0)
        aim->roundNum = roundNum;
    return aim;
}

Player *updatePlayerWinNum(Player *aim, int16_t winNum)
{
    if (winNum>0)
        aim->winNum = winNum;
    return aim;
}

Player *getPlayerById(int32_t playerId)
{
    if (playerId<0 || playerId>=players->arrayLen)
        return NULL;

    return (Player *)(dynamicGet(players, playerId)->v.pVoid);
}

Player *printPlayer(Player *p)
{
    if (!p)
        return NULL;

    printf("name:%s clubName:%s roundNum:%d winNum:%d\n", p->name, p->clubName, p->roundNum, p->winNum);

    return p;
}

char *sprintPlayer(char *str, Player *p)
{
    if (!p || !str)
        return NULL;

    sprintf(str, "name:%s clubName:%s roundNum:%d winNum:%d\n", p->name, p->clubName, p->roundNum, p->winNum);

    return str;
}

Game *updateGameNo(Game *aim, int16_t no)
{
    if (no>0)
        aim->no = no;
    return aim;
}

Game *updateGameType(Game *aim, int8_t type)
{
    if (type>=0)
        aim->type = type;
    return aim;
}

Game *updateGameBlackPlayer(Game *aim, char *blackPlayer)
{
    if (blackPlayer)
        aim->blackPlayer = blackPlayer;
    return aim;
}

Game *updateGameWhitePlayer(Game *aim, char *whitePlayer)
{
    if (whitePlayer)
        aim->whitePlayer = whitePlayer;
    return aim;
}

Game *updateGameResult(Game *aim, int8_t result)
{
    if (result>=0)
        aim->result = result;
    return aim;
}

Game *getGameById(int32_t gameId)
{
    if (gameId<0 || gameId>=games->arrayLen)
        return NULL;

    return (Game *)(dynamicGet(games, gameId)->v.pVoid);
}

Game *printGame(Game *g)
{
    if (!g)
        return NULL;

    printf("no:%d type:%d blackPlayer:%s whitePlayer:%s result:%d\n", g->no, g->type, g->blackPlayer, g->whitePlayer, g->result);

    return g;
}

char *sprintGame(char *str, Game *g)
{
    if (!g || !str)
        return NULL;

    printf(str, "no:%d type:%d blackPlayer:%s whitePlayer:%s result:%d\n", g->no, g->type, g->blackPlayer, g->whitePlayer, g->result);

    return str;
}

ClubList *createClubList(void)
{
    ClubList *cl = (ClubList *)malloc(sizeof(ClubList));
    cl->data = NULL;
    cl->next = NULL;
    return cl;
}

ClubList *insertClubList(ClubList *head, ClubListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

ClubList *printClubList(ClubList *head)
{
    return head;
}

char *sprintClubList(char *str, ClubList *head)
{
    return str;
}

PlayerList *createPlayerList(void)
{
    PlayerList *pl = (PlayerList *)malloc(sizeof(PlayerList));
    pl->data = NULL;
    pl->next = NULL;
    return pl;
}

PlayerList *insertPlayerList(PlayerList *head, PlayerListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

PlayerList *printPlayerList(PlayerList *head)
{
    return head;
}

char *sprintPlayerList(char *str, PlayerList *head)
{
    return str;
}

GameList *createGameList(void)
{
    GameList *gl = (GameList *)malloc(sizeof(GameList));
    gl->data = NULL;
    gl->next = NULL;
    return gl;
}

GameList *insertGameList(GameList *head, GameListNode *node)
{
    if (!head || !node)
        return NULL;

    node->next = head->next;
    head->next = node;

    return head;
}

GameList *printGameList(GameList *head)
{
    return head;
}

char *sprintGameList(char *str, GameList *head)
{
    return str;
}

int32_t clubIdByPlayerId(int32_t playerId)
{
    if (playerId<0 || playerId>players->arrayLen)
        return -1;

    Variant *v = dynamicGet(players, playerId);
    Player *p = (Player *)(v->v.pVoid);

    return p->clubId;
}

ClubListNode *searchClubName(ClubList *head, char *clubName)
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

PlayerListNode *searchPlayerName(ClubList *head, char *playerName)
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
