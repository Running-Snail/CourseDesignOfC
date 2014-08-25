#include "controller.h"

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

Club *goReadClubLine(FILE *fin)
{
    Club *c;
    char buffer[READ_BUFFER_LEN] = {0};
    int len;

    if (!fin)
        return NULL;

    if (!(c = goCreateClub()))
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

Player *goReadPlayerLine(FILE *fin)
{
    Player *p;
    char buffer[READ_BUFFER_LEN] = {0};
    int len;
    if (!fin)
        return NULL;

    if (!(p = goCreatePlayer()))
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

ClubList *goViewLoadData(int *error)
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

