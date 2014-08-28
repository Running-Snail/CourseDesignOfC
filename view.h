#ifndef VIEW_H
#define VIEW_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "dynamicArray.h"
#include "datastruct.h"
#include "statistics.h"
#include "controller.h"

#define MAIN_WINDOW_TITLE "Go"
#define MAIN_WINDOW_DEFAULT_WIDTH_MD 500
#define MAIN_WINDOW_DEFAULT_HEIGHT_MD 600
#define MAIN_WINDOW_DEFAULT_WIDTH_LG 950
#define MAIN_WINDOW_DEFAULT_HEIGHT_LG 800

#define UNIFORM_MARGIN_SM 10
#define UNIFORM_MARGIN_MD 20
#define UNIFORM_MARGIN_LG 30

#define UNIFORM_ROW_MARGIN 2
#define UNIFORM_COLUMN_MARGIN 2

typedef struct _inputChain {
    GtkEntry *input;
    struct _inputChain *next;
} InputChain;

GtkWidget *goMainWindow;
GtkWidget *goMainBox;
GtkWidget *goContentScrolledWindow;

GtkWidget *goMenu;

GtkWidget *goMenuSystem;
GtkWidget *goMenuSystemSub;
GtkWidget *goMenuSystemgoViewLoad;
GtkWidget *goMenuSystemgoViewQuit;

GtkWidget *goMenuQuery;
GtkWidget *goMenuQuerySub;

GtkWidget *goMenuQueryClub;
GtkWidget *goMenuQueryClubSub;
GtkWidget *goMenuQueryClubAll;
GtkWidget *goMenuQueryClubName;

GtkWidget *goMenuQueryPlayer;
GtkWidget *goMenuQueryPlayerSub;
GtkWidget *goMenuQueryPlayerAll;
GtkWidget *goMenuQueryPlayerName;
GtkWidget *goMenuQueryPlayerClub;
GtkWidget *goMenuQueryPlayerWinNum;

GtkWidget *goMenuQueryGame;
GtkWidget *goMenuQueryGameSub;
GtkWidget *goMenuQueryGameAll;
GtkWidget *goMenuQueryGameNo;
GtkWidget *goMenuQueryGameBlack;
GtkWidget *goMenuQueryGameWhite;
GtkWidget *goMenuQueryGameResult;

GtkWidget *goMenuEdit;
GtkWidget *goMenuEditSub;
GtkWidget *goMenuEditClub;
GtkWidget *goMenuEditPlayer;
GtkWidget *goMenuEditGame;
GtkWidget *goMenuEditAddClub;
GtkWidget *goMenuEditAddPlayer;
GtkWidget *goMenuEditAddGame;

GtkWidget *goMenuStat;
GtkWidget *goMenuStatSub;
GtkWidget *goMenuStatClub;
GtkWidget *goMenuStatPlayer;
GtkWidget *goMenuStatGrade;
GtkWidget *goMenuStatClubDetails;

GtkWidget *goClubNameQueryDialog;
GtkWidget *goPlayerNameQueryDialog;
GtkWidget *goPlayerClubQueryDialog;
GtkWidget *goPlayerWinQueryDialog;
GtkWidget *goGameNoQueryDialog;
GtkWidget *goGameBlackQueryDialog;
GtkWidget *goGameWhiteQueryDialog;
GtkWidget *goGameResultQueryDialog;

GtkWidget *goClubEditDialog;
GtkWidget *goPlayerEditDialog;
GtkWidget *goGameEditDialog;

GtkWidget *goAddClubDialog;
GtkWidget *goAddPlayerDialog;
GtkWidget *goAddGameDialog;

InputChain *goCreateInputChain(void);

GtkWidget *goCreateClubListItem(Club *c);
GtkWidget *goCreatePlayerListItem(Player *p);
GtkWidget *goCreatePlayerListItemClubInfo(Player *p);
GtkWidget *goCreateGameListItem(Game *g);
GtkWidget *goCreateGameListItemPlayerInfo(Game *g, Player *p);
GtkWidget *goCreateClubNameQueryDialog();
GtkWidget *goCreatePlayerNameQueryDialog();

GtkWidget *goViewShowClubNameQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowPlayerNameQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowPlayerClubQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowPlayerWinQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowGameNoQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowGameBlackQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowGameWhiteQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowGameResultQueryDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowAddClubDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowAddPlayerDialog(GtkWidget *widget, gpointer *var);
GtkWidget *goViewShowAddGameDialog(GtkWidget *widget, gpointer *var);

void goViewQuerySelection(void);
void goViewWelcome(void);
void goStatAll(ClubList *data);
void goViewShowAllClubs(GtkWidget *widget, gpointer *window);
void goViewShowAllPlayers(GtkWidget *widget, gpointer *window);
void goViewShowAllGames(GtkWidget *widget, gpointer *window);
void goViewShowClubInfo(GtkWidget *widget, gpointer *var);
void goViewShowPlayerInfo(GtkWidget *widget, gpointer *var);
void goViewClubRankList(GtkWidget *widget, gpointer *var);
void goViewPlayerRankList(GtkWidget *widget, gpointer *var);
void goViewGradeStatList(GtkWidget *widget, gpointer *var);
void goViewStatClubDetails(GtkWidget *widget, gpointer *var);
void goViewShowGameInfo(GtkWidget *widget, gpointer *var);

void goViewShowClubNameQuery(GtkWidget *widget, gpointer *var);
void goViewShowPlayerNameQuery(GtkWidget *widget, gpointer *var);
void goViewShowPlayerWinQuery(GtkWidget *widget, gpointer *var);
void goClubNameQuery(GtkWidget *widget, gpointer *var);
void goPlayerNameQuery(GtkWidget *widget, gpointer *var);
void goPlayerClubQuery(GtkWidget *widget, gpointer *var);
void goPlayerWinQuery(GtkWidget *widget, gpointer *var);
void goGameNoQuery(GtkWidget *widget, gpointer *var);
void goGameBlackQuery(GtkWidget *widget, gpointer *var);
void goGameWhiteQuery(GtkWidget *widget, gpointer *var);
void goGameResultQuery(GtkWidget *widget, gpointer *var);

void goViewShowClubEditDialog(GtkWidget *widget, gpointer *var);
void goViewShowPlayerEditDialog(GtkWidget *widget, gpointer *var);
void goViewShowGameEditDialog(GtkWidget *widget, gpointer *var);

void goUpdateClub(GtkWidget *widget, gpointer *var);
void goUpdatePlayer(GtkWidget *widget, gpointer *var);
void goUpdateGame(GtkWidget *widget, gpointer *var);

void goAddClub(GtkWidget *widget, gpointer *var);
void goAddPlayer(GtkWidget *widget, gpointer *var);
void goAddGame(GtkWidget *widget, gpointer *var);

void goViewShowWindow(GtkWidget *widget, gpointer *var);
void goViewHideWindow(GtkWidget *widget, gpointer *var);
void goDeleteWindow(GtkWidget *widget, gpointer *var);
void goViewQuit(GtkWidget *widget, gpointer *window);
void goViewLoad(GtkWidget *widget, gpointer *window);
void goInitWindows(int *argc, char ***argv);

#endif
