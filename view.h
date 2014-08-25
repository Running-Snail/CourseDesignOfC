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

typedef struct _entryChain {
    GtkEntry *entry;
    struct _entryChain *next;
} EntryChain;

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

GtkWidget *goCreateClubListItem(Club *c);
GtkWidget *goCreatePlayerListItem(Player *p);
GtkWidget *goCreatePlayerListItemClubInfo(Player *p);
GtkWidget *goCreateGameListItem(Game *g);
GtkWidget *goCreateGameListItemPlayerInfo(Game *g, Player *p);
GtkWidget *goCreateClubNameQueryDialog();
GtkWidget *goCreatePlayerNameQueryDialog();

GtkWidget *goCreateClubNameQueryDialog(void);
GtkWidget *goCreatePlayerNameQueryDialog(void);
GtkWidget *goCreatePlayerClubQueryDialog(void);
GtkWidget *goCreatePlayerWinQueryDialog(void);
GtkWidget *goCreateGameNoQueryDialog(void);
GtkWidget *goCreateGameBlackQueryDialog(void);
GtkWidget *goCreateGameWhiteQueryDialog(void);

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
void stat(GtkWidget *widget, gpointer *var);
void goViewHideWindow(GtkWidget *widget, gpointer *var);
void goViewQuit(GtkWidget *widget, gpointer *window);
void goViewLoad(GtkWidget *widget, gpointer *window);
void goInitWindows(int *argc, char ***argv);

#endif
