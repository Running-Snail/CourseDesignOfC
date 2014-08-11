#include "controller.h"

Club *readClubLine(FILE *fin)
{
    Club *c;
    char buffer[READ_BUFFER_LEN] = {0};
    int32_t len;

    if (!fin)
        return NULL;

    if (!(c = (Club *)malloc(sizeof(Club))))
        return NULL;

    len = readString(fin, buffer);
    if (!(c->name = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    strcpy(c->name, buffer);

    len = readString(fin, buffer);
    if (!(c->coach = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

    strcpy(c->coach, buffer);

    ignoreChar(fin, '\n');

    return c;
}

Player *readPlayerLine(FILE *fin)
{
    Player *p;
    char buffer[READ_BUFFER_LEN] = {0};
    int32_t len;
    if (!fin)
        return NULL;

    if (!(p = (Player *)malloc(sizeof(Player))))
        return NULL;

    len = readString(fin, buffer);
    if (!(p->name = (char *)malloc(sizeof(char)*len + sizeof(char))))
        return NULL;

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

Game *readGameLine(FILE *fin)
{
    Game *g;
    char buffer[READ_BUFFER_LEN] = {0};
    int32_t len;
    if (!fin)
        return NULL;

    if (!(g = (Game *)malloc(sizeof(Game))))
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

ClubList *loadData(int32_t *error)
{
    int32_t clubNum, playerNum, gameNum;
    int32_t i, j;
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
    fscanf(gameFile, "%d", &gameNum);

    //Read data
    for (i=0; i<clubNum; i++) {
        c = readClubLine(clubFile);
        c->id = i;
        v = createVariant();
        v->v.pVoid = c;
        dynamicInsert(&clubs, i, v);
    }

    for (i=0; i<playerNum; i++) {
        p = readPlayerLine(playerFile);
        p->id = i;
        v = createVariant();
        v->v.pVoid = p;
        dynamicInsert(&players, i, v);
    }

    maxGameNo = 0;

    for (i=0; i<gameNum; i++) {
        g = readGameLine(gameFile);
        g->id = i;
        v = createVariant();
        v->v.pVoid = g;
        dynamicInsert(&games, i, v);
        if (g->no > maxGameNo)
            maxGameNo = g->no;
    }

    data = createLists(clubs, players, games);
    return data;
}

ClubList *createLists(DynamicArray *clubs, DynamicArray *players, DynamicArray *games)
{
    int32_t i, j;
    Club *c;
    ClubList *clubListHead;
    ClubListNode *clubListCurrent, *cl;
    Player *p;
    PlayerList *playerListHead;
    PlayerListNode *playerListCurrent, *pl;
    Game *g;
    GameList *gameListHead;
    GameListNode *gameListCurrent, *gl;
    Variant *v;

    //Create the list of clubs
    clubListHead = createClubList();

    //Insert every club into the list
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        c = (Club *)(v->v.pVoid);
        cl = createClubListNode();
        cl->data = c;
        //Create empty list of players who are in the club
        cl->playerListHead = createPlayerList();
        insertClubList(clubListHead, cl);
    }

    //Construct player list
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        //Find the club by club's name
        if (cl = searchClubName(clubListHead, p->clubName)) {
            p->clubId = cl->data->id;
            pl = createPlayerListNode();
            pl->data = p;
            insertPlayerList(cl->playerListHead, pl);
            //Create empty list of games which the player played
            pl->gameListHead = createGameList();
        }
    }

    //Construct game list
    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        g = (Game *)(v->v.pVoid);
        //Search for the black player by name
        if (pl = searchPlayerName(clubListHead, g->blackPlayer)) {
            g->blackPlayerId = pl->data->id;
            gl = createGameListNode();
            gl->data = g;
            insertGameList(pl->gameListHead, gl);
        }
        //Search for the white player by name
        if (pl = searchPlayerName(clubListHead, g->whitePlayer)) {
            g->whitePlayerId = pl->data->id;
            gl = createGameListNode();
            gl->data = g;
            insertGameList(pl->gameListHead, gl);
        }
    }

    return clubListHead;
}

