#ifndef VIEW_H
#define VIEW_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "datastruct.h"
#include "dynamicArray.h"
#include "controller.h"

#define MAIN_WINDOW_TITLE "Go"
#define MAIN_WINDOW_WIDTH 500
#define MAIN_WINDOW_HEIGHT 600

GtkWidget *mainWindow;
GtkWidget *mainBox;
GtkWidget *contentScrolledWindow;

GtkWidget *menu;

GtkWidget *menuSystem;
GtkWidget *menuSystemSub;
GtkWidget *menuSystemLoad;
GtkWidget *menuSystemQuit;

GtkWidget *menuQuery;
GtkWidget *menuQuerySub;

GtkWidget *menuQueryClub;
GtkWidget *menuQueryClubSub;
GtkWidget *menuQueryClubAll;
GtkWidget *menuQueryClubName;

GtkWidget *menuQueryPlayer;
GtkWidget *menuQueryPlayerSub;
GtkWidget *menuQueryPlayerAll;
GtkWidget *menuQueryPlayerName;
GtkWidget *menuQueryPlayerClub;
GtkWidget *menuQueryPlayerWinNum;

GtkWidget *menuQueryGame;
GtkWidget *menuQueryGameSub;
GtkWidget *menuQueryGameAll;
GtkWidget *menuQueryGameNo;
GtkWidget *menuQueryGameBlack;
GtkWidget *menuQueryGameWhite;
GtkWidget *menuQueryGameResult;

GtkWidget *menuEdit;
GtkWidget *menuEditSub;
GtkWidget *menuEditClub;
GtkWidget *menuEditPlayer;
GtkWidget *menuEditGame;

GtkWidget *menuStat;
GtkWidget *menuStatSub;
GtkWidget *menuStatClub;
GtkWidget *menuStatPlayer;
GtkWidget *menuStatGrade;
GtkWidget *menuStatClubGame;

GtkWidget *createClubListItem(char *clubName, char *coach);
GtkWidget *createPlayerListItem(char *name, char *clubName);
GtkWidget *createPlayerListItemClubInfo(char *name, int8_t grade);
GtkWidget *createGameListItem(int32_t no, char *blackPlayer, char *whitePlayer, int8_t result);
GtkWidget *createGameListItemPlayerInfo(Game *g, char *playerName);

void removeBoxAllChild(GtkWidget *box);

void querySelection(void);
void welcome(void);
void showAllClubs(GtkWidget *widget, gpointer *window);
void showAllPlayers(GtkWidget *widget, gpointer *window);
void showAllGames(GtkWidget *widget, gpointer *window);
void showClubInfo(GtkWidget *widget, gpointer *var);
void showPlayerInfo(GtkWidget *widget, gpointer *var);
void showGameInfo(GtkWidget *widget, gpointer *var);
void stat(GtkWidget *widget, gpointer *var);
void quit(GtkWidget *widget, gpointer *window);
void load(GtkWidget *widget, gpointer *window);
void initWindows(int *argc, char ***argv);

#endif
