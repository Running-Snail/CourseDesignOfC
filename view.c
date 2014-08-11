#include "view.h"

GtkWidget *createClubListItem(char *clubName, char *coach)
{
    PangoFontDescription *font_desc = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!clubName || !coach)
        return NULL;

    sprintf(label, "%s\t\t教练:%s", clubName, coach);

    li = gtk_button_new_with_label(label);
    gtk_widget_modify_font(li, font_desc);

    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *createPlayerListItem(char *name, char *clubName)
{
    PangoFontDescription *font_desc = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!name || !clubName)
        return NULL;

    sprintf(label, "%s\t\t俱乐部:%s", name, clubName);

    li = gtk_button_new_with_label(label);
    gtk_widget_modify_font(li, font_desc);

    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *createPlayerListItemClubInfo(char *name, int8_t grade)
{
    PangoFontDescription *font_desc = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!name)
        return NULL;

    sprintf(label, "%s\t\t段位:%d", name, grade);

    li = gtk_button_new_with_label(label);
    gtk_widget_modify_font(li, font_desc);

    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *createGameListItem(int32_t no, char *blackPlayer, char *whitePlayer, int8_t result)
{
    PangoFontDescription *font = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!blackPlayer || !whitePlayer)
        return NULL;

    sprintf(label, "no.%d\t黑:%s\t白:%s\t%s", no, blackPlayer, whitePlayer, result?"白胜":"黑胜");

    li = gtk_button_new_with_label(label);
    gtk_widget_modify_font(li, font);

    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *createGameListItemPlayerInfo(Game *g, char *playerName)
{
    PangoFontDescription *font = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!g)
        return NULL;

    //执黑
    if (0 == strcmp(playerName, g->blackPlayer))
        sprintf(label, "no.%d\t对手:%s 执白\t%s", g->no, g->whitePlayer, g->result?"负":"胜");
    else
        sprintf(label, "no.%d\t对手:%s 执黑\t%s", g->no, g->blackPlayer, g->result?"胜":"负");

    li = gtk_button_new_with_label(label);
    gtk_widget_modify_font(li, font);

    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

void showClubInfo(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *clubNameLabelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    PlayerListNode *pl;
    GtkWidget *playerListItem;
    GtkWidget *playerListItemAlign;
    GtkWidget *clubNameLabel;
    GtkWidget *clubNameLabelAlign;
    GtkWidget *clubCoachLabel;
    GtkWidget *clubCoachLabelAlign;
    GtkWidget *clubRoundScoreLabel;
    GtkWidget *clubRoundScoreLabelAlign;
    GtkWidget *clubGameScoreLabel;
    GtkWidget *clubGameScoreLabelAlign;
    GtkWidget *clubRankLabel;
    GtkWidget *clubRankLabelAlign;
    GtkWidget *clubPlayerListLabel;
    GtkWidget *clubPlayerListLabelAlign;
    GtkWidget *clubWinLabel;
    GtkWidget *clubWinLabelAlign;
    GtkWidget *clubLoseLabel;
    GtkWidget *clubLoseLabelAlign;
    Variant *v;
    Club *c;
    ClubListNode *cl;
    char label[80];

    if (!var)
        return;

    v = (Variant *)var;
    c = (Club *)(v->v.pVoid);
    cl = searchClubName(data, c->name);

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    clubNameLabel = gtk_label_new(c->name);
    clubNameLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    sprintf(label, "教练:%s", c->coach);
    clubCoachLabel = gtk_label_new(label);
    clubCoachLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    sprintf(label, "局分:%d", c->roundScore);
    clubRoundScoreLabel = gtk_label_new(label);
    clubRoundScoreLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    sprintf(label, "场分:%d", c->gameScore);
    clubGameScoreLabel = gtk_label_new(label);
    clubGameScoreLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    sprintf(label, "胜局数:%d", c->winNum);
    clubWinLabel = gtk_label_new(label);
    clubWinLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    sprintf(label, "负局数:%d", c->roundNum - c->winNum);
    clubLoseLabel = gtk_label_new(label);
    clubLoseLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    sprintf(label, "排名:%d", c->ranking);
    clubRankLabel = gtk_label_new(label);
    clubRankLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    clubPlayerListLabel = gtk_label_new("选手列表");
    clubPlayerListLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    gtk_widget_modify_font(clubNameLabel, clubNameLabelFont);

    gtk_container_add(GTK_CONTAINER(clubNameLabelAlign), clubNameLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubNameLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubCoachLabelAlign), clubCoachLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubCoachLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubRoundScoreLabelAlign), clubRoundScoreLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubRoundScoreLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubGameScoreLabelAlign), clubGameScoreLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubGameScoreLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubWinLabelAlign), clubWinLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubWinLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubLoseLabelAlign), clubLoseLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubLoseLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubRankLabelAlign), clubRankLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubRankLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubPlayerListLabelAlign), clubPlayerListLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubPlayerListLabelAlign, FALSE, FALSE, 0);

    pl = cl->playerListHead->next;

    while (pl) {
        v = createVariant();
        v->v.pVoid = pl->data;
        playerListItem = createPlayerListItemClubInfo(pl->data->name, pl->data->grade);
        playerListItemAlign = gtk_alignment_new(0.5, 0, 0.8, 0);
        gtk_container_add(GTK_CONTAINER(playerListItemAlign), playerListItem);
        gtk_box_pack_start(GTK_BOX(contentBox), playerListItemAlign, FALSE, FALSE, 0);
        g_signal_connect(G_OBJECT(playerListItem), "clicked", G_CALLBACK(showPlayerInfo), v);
        pl = pl->next;
    }

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void showPlayerInfo(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *playerNameLabelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    GtkWidget *playerNameLabel;
    GtkWidget *playerNameLabelAlign;
    GtkWidget *gradeLabel;
    GtkWidget *gradeLabelAlign;
    GtkWidget *clubNameLabel;
    GtkWidget *clubNameLabelAlign;
    GtkWidget *totalRoundNumLabel;
    GtkWidget *totalRoundNumLabelAlign;
    GtkWidget *winNumLabel;
    GtkWidget *winNumLabelAlign;
    GtkWidget *loseNumLabel;
    GtkWidget *loseNumLabelAlign;
    GtkWidget *winRateLabel;
    GtkWidget *winRateLabelAlign;
    GtkWidget *gameListLabel;
    GtkWidget *gameListLabelAlign;
    GtkWidget *gameListItem;
    GtkWidget *gameListItemAlign;
    Variant *v;
    Player *p;
    PlayerList *pl;
    GameListNode *gl;
    char label[80];

    if (!var)
        return;

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    v = (Variant *)var;
    p = (Player *)(v->v.pVoid);
    pl = searchPlayerName(data, p->name);

    playerNameLabel = gtk_label_new(p->name);
    playerNameLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    gtk_widget_modify_font(playerNameLabel, playerNameLabelFont);

    sprintf(label, "%d段", p->grade);
    gradeLabel = gtk_label_new(label);
    gradeLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    clubNameLabel = gtk_label_new(p->clubName);
    clubNameLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    sprintf(label, "参赛局数:%d", p->roundNum);
    totalRoundNumLabel = gtk_label_new(label);
    totalRoundNumLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    sprintf(label, "胜局数:%d", p->winNum);
    winNumLabel = gtk_label_new(label);
    winNumLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    sprintf(label, "负局数:%d", p->roundNum - p->winNum);
    loseNumLabel = gtk_label_new(label);
    loseNumLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    sprintf(label, "胜率:%.2f", (float)(p->winNum)/(float)(p->roundNum));
    winRateLabel = gtk_label_new(label);
    winRateLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    gameListLabel = gtk_label_new("比赛列表");
    gameListLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    gtk_container_add(GTK_CONTAINER(playerNameLabelAlign), playerNameLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), playerNameLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(gradeLabelAlign), gradeLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), gradeLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(clubNameLabelAlign), clubNameLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), clubNameLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(totalRoundNumLabelAlign), totalRoundNumLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), totalRoundNumLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(winNumLabelAlign), winNumLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), winNumLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(loseNumLabelAlign), loseNumLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), loseNumLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(winRateLabelAlign), winRateLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), winRateLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(gameListLabelAlign), gameListLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), gameListLabelAlign, FALSE, FALSE, 0);

    gl = pl->gameListHead->next;
    while (gl) {
        gameListItem = createGameListItemPlayerInfo(gl->data, p->name);
        gameListItemAlign = gtk_alignment_new(0.5, 0, 0.8, 0);
        gtk_container_add(GTK_CONTAINER(gameListItemAlign), gameListItem);
        gtk_box_pack_start(GTK_BOX(contentBox), gameListItemAlign, FALSE, FALSE, 0);
        v = createVariant();
        v->v.pVoid = gl->data;
        g_signal_connect(G_OBJECT(gameListItem), "clicked", G_CALLBACK(showGameInfo), v);
        gl = gl->next;
    }

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void showGameInfo(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *gameNoLabelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    GtkWidget *noLabel;
    GtkWidget *noLabelAlign;
    GtkWidget *typeLabel;
    GtkWidget *typeLabelAlign;
    GtkWidget *blackPlayerLabel;
    GtkWidget *blackPlayerLabelAlign;
    GtkWidget *whitePlayerLabel;
    GtkWidget *whitePlayerLabelAlign;
    GtkWidget *resultLabel;
    GtkWidget *resultLabelAlign;
    Variant *v;
    Game *g;
    char label[80];

    if (!var)
        return;

    v = (Variant *)var;
    g = (Game *)(v->v.pVoid);

    sprintf(label, "No.%d", g->no);
    noLabel = gtk_label_new(label);
    noLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);
    gtk_widget_modify_font(noLabel, gameNoLabelFont);

    switch (g->type) {
    case 0:
        typeLabel = gtk_label_new("主将局");
        break;
    case 1:
        typeLabel = gtk_label_new("快棋局");
        break;
    case 2:
        typeLabel = gtk_label_new("普通局");
        break;
    }
    typeLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    sprintf(label, "执黑棋手:%s", g->blackPlayer);
    blackPlayerLabel = gtk_label_new(label);
    blackPlayerLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    sprintf(label, "执白棋手:%s", g->whitePlayer);
    whitePlayerLabel = gtk_label_new(label);
    whitePlayerLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    switch (g->result) {
    case 0:
        resultLabel = gtk_label_new("黑胜");
        break;
    case 1:
        resultLabel = gtk_label_new("白胜");
        break;
    }
    resultLabelAlign = gtk_alignment_new(0.1, 0, 0, 0);

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(noLabelAlign), noLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), noLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(typeLabelAlign), typeLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), typeLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(blackPlayerLabelAlign), blackPlayerLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), blackPlayerLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(whitePlayerLabelAlign), whitePlayerLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), whitePlayerLabelAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(resultLabelAlign), resultLabel);
    gtk_box_pack_start(GTK_BOX(contentBox), resultLabelAlign, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void stat(GtkWidget *widget, gpointer *var)
{
    if (!data)
        return;

    statRoundNum(data->next);
    statScore(games);
}

void querySelection(void)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    PangoFontDescription *descriptionFont = pango_font_description_from_string ("Serif 12");

    GtkWidget *headingSpacer;
    GtkWidget *heading;
    GtkWidget *headingAlign;
    GtkWidget *guide;
    GtkWidget *guideAlign;
    GtkWidget *viewAllClubsBtn;
    GtkWidget *viewAllClubsBtnAlign;
    GtkWidget *viewAllPlayersBtn;
    GtkWidget *viewAllPlayersBtnAlign;
    GtkWidget *viewAllGamesBtn;
    GtkWidget *viewAllGamesBtnAlign;

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    headingSpacer = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    heading = gtk_label_new("接下来");
    headingAlign = gtk_alignment_new(0.1, 0, 0, 0);
    guide = gtk_label_new("数据载入成功,你可以");
    guideAlign = gtk_alignment_new(0.1, 0, 0, 0);
    viewAllClubsBtn = gtk_button_new_with_label("查看所有俱乐部");
    viewAllClubsBtnAlign = gtk_alignment_new(0.5, 0, 0.8, 0);
    viewAllPlayersBtn = gtk_button_new_with_label("查看所有选手");
    viewAllPlayersBtnAlign = gtk_alignment_new(0.5, 0, 0.8, 0);
    viewAllGamesBtn = gtk_button_new_with_label("查看所有棋局");
    viewAllGamesBtnAlign = gtk_alignment_new(0.5, 0, 0.8, 0);

    gtk_widget_set_size_request(headingSpacer, 200, 20);
    gtk_widget_modify_font(heading, headingFont);

    gtk_box_pack_start(GTK_BOX(contentBox), headingSpacer, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(headingAlign), heading);
    gtk_box_pack_start(GTK_BOX(contentBox), headingAlign, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(guideAlign), guide);
    gtk_box_pack_start(GTK_BOX(contentBox), guideAlign, FALSE, FALSE, 0);
    gtk_widget_set_size_request(viewAllClubsBtn, 200, 50);
    gtk_container_add(GTK_CONTAINER(viewAllClubsBtnAlign), viewAllClubsBtn);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllClubsBtnAlign, FALSE, FALSE, 2);
    gtk_widget_set_size_request(viewAllPlayersBtn, 200, 50);
    gtk_container_add(GTK_CONTAINER(viewAllPlayersBtnAlign), viewAllPlayersBtn);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllPlayersBtnAlign, FALSE, FALSE, 2);
    gtk_widget_set_size_request(viewAllGamesBtn, 200, 50);
    gtk_container_add(GTK_CONTAINER(viewAllGamesBtnAlign), viewAllGamesBtn);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllGamesBtnAlign, FALSE, FALSE, 2);

    g_signal_connect(G_OBJECT(viewAllClubsBtn), "clicked", G_CALLBACK(showAllClubs), NULL);
    g_signal_connect(G_OBJECT(viewAllPlayersBtn), "clicked", G_CALLBACK(showAllPlayers), NULL);
    g_signal_connect(G_OBJECT(viewAllGamesBtn), "clicked", G_CALLBACK(showAllGames), NULL);

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void welcome(void)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    PangoFontDescription *descriptionFont = pango_font_description_from_string ("Serif 12");

    GtkWidget *spacer;
    GtkWidget *heading;
    GtkWidget *description;
    GtkWidget *hLoadingBox;
    GtkWidget *loadLabel;
    GtkWidget *loadButton;
    GtkWidget *align;

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    hLoadingBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    align = gtk_alignment_new(0.5,0,0,0);
    loadLabel = gtk_label_new("系统已经准备好");
    loadButton = gtk_button_new_with_label("载入数据");
    spacer = gtk_label_new("");
    heading = gtk_label_new("欢迎");
    description = gtk_label_new("一段描述");

    gtk_widget_set_size_request(spacer, 200, 200);
    gtk_widget_modify_font(heading, headingFont);
    gtk_widget_modify_font(description, descriptionFont);

    gtk_box_pack_start(GTK_BOX(contentBox), spacer, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), description, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hLoadingBox), loadLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hLoadingBox), loadButton, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(align), hLoadingBox);
    gtk_box_pack_start(GTK_BOX(contentBox), align, FALSE, FALSE, 0);

    g_signal_connect(G_OBJECT(loadButton), "clicked", G_CALLBACK(load), NULL);

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void showAllClubs(GtkWidget *widget, gpointer *window)
{
    int32_t i;
    GtkWidget *heading;
    GtkWidget *headingAlign;
    GtkWidget *clubListItem;
    GtkWidget *clubListItemAlign;
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    Variant *v;
    Club *c;
    if (!clubs)
        return;

    heading = gtk_label_new("俱乐部");
    headingAlign = gtk_alignment_new(0.1, 0, 0, 0);
    gtk_widget_modify_font(heading, headingFont);

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(headingAlign), heading);
    gtk_box_pack_start(GTK_BOX(contentBox), headingAlign, FALSE, FALSE, 0);

    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        c = (Club *)(v->v.pVoid);
        clubListItem = createClubListItem(c->name, c->coach);
        clubListItemAlign = gtk_alignment_new(0.5, 0, 0.8, 0);
        gtk_container_add(GTK_CONTAINER(clubListItemAlign), clubListItem);
        gtk_box_pack_start(GTK_BOX(contentBox), clubListItemAlign, FALSE, FALSE, 2);
        g_signal_connect(G_OBJECT(clubListItem), "clicked", G_CALLBACK(showClubInfo), (gpointer *)v);
    }

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void showAllPlayers(GtkWidget *widget, gpointer *window)
{
    int32_t i;
    GtkWidget *heading;
    GtkWidget *headingAlign;
    GtkWidget *playerListItem;
    GtkWidget *playerListItemAlign;
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    Variant *v;
    Player *p;
    if (!players)
        return;

    heading = gtk_label_new("选手");
    headingAlign = gtk_alignment_new(0.1, 0, 0, 0);
    gtk_widget_modify_font(heading, headingFont);

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(headingAlign), heading);
    gtk_box_pack_start(GTK_BOX(contentBox), headingAlign, FALSE, FALSE, 0);

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        playerListItem = createPlayerListItem(p->name, p->clubName);
        playerListItemAlign = gtk_alignment_new(0.5, 0, 0.8, 0);
        gtk_container_add(GTK_CONTAINER(playerListItemAlign), playerListItem);
        gtk_box_pack_start(GTK_BOX(contentBox), playerListItemAlign, FALSE, FALSE, 2);
        g_signal_connect(G_OBJECT(playerListItem), "clicked", G_CALLBACK(showPlayerInfo), v);
    }

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void showAllGames(GtkWidget *widget, gpointer *window)
{
    int32_t i;
    GtkWidget *heading;
    GtkWidget *headingAlign;
    GtkWidget *gameListItem;
    GtkWidget *gameListItemAlign;
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    Variant *v;
    Game *g;
    if (!games)
        return;

    heading = gtk_label_new("棋局");
    headingAlign = gtk_alignment_new(0.1, 0, 0, 0);
    gtk_widget_modify_font(heading, headingFont);

    gtk_container_remove(GTK_CONTAINER(mainBox), contentBox);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(headingAlign), heading);
    gtk_box_pack_start(GTK_BOX(contentBox), headingAlign, FALSE, FALSE, 0);

    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        g = (Game *)(v->v.pVoid);
        gameListItem = createGameListItem(g->no, g->blackPlayer, g->whitePlayer, g->result);
        gameListItemAlign = gtk_alignment_new(0.5, 0, 0.8, 0);
        gtk_container_add(GTK_CONTAINER(gameListItemAlign), gameListItem);
        gtk_box_pack_start(GTK_BOX(contentBox), gameListItemAlign, FALSE, FALSE, 2);
        g_signal_connect(G_OBJECT(gameListItem), "clicked", G_CALLBACK(showGameInfo), v);
    }

    gtk_container_add(GTK_CONTAINER(mainBox), contentBox);
    gtk_widget_show_all(contentBox);
}

void quit(GtkWidget *widget, gpointer *window)
{
    GtkWidget *dialog;
    gint result = 0;

    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_OK_CANCEL,
                                    "要退出么?");
    gtk_window_set_title(GTK_WINDOW(dialog), "退出");
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (GTK_RESPONSE_OK == result)
        gtk_main_quit();
}

void load(GtkWidget *widget, gpointer *window)
{
    GtkWidget *dialog;
    if (loadData(NULL)) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "载入数据成功");

    } else {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "载入数据失败");
    }
    gtk_window_set_title(GTK_WINDOW(dialog), "载入数据");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (!data)
        return;

    querySelection();
}

void initWindows(int *argc, char ***argv)
{
    mainBox;

    gtk_init(argc, argv);

    //Init main window
    mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(mainWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(mainWindow), MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
    gtk_window_set_title(GTK_WINDOW(mainWindow), MAIN_WINDOW_TITLE);

    //main box
    mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(mainWindow), mainBox);

    //Create menu bar instances
    menu = gtk_menu_bar_new();

    menuSystem = gtk_menu_item_new_with_label("系统");
    menuSystemSub = gtk_menu_new();
    menuSystemLoad = gtk_menu_item_new_with_label("载入数据");
    menuSystemQuit = gtk_menu_item_new_with_label("退出");

    menuQuery = gtk_menu_item_new_with_label("查询");
    menuQuerySub = gtk_menu_new();

    menuQueryClub = gtk_menu_item_new_with_label("俱乐部");
    menuQueryClubSub = gtk_menu_new();
    menuQueryClubAll = gtk_menu_item_new_with_label("显示所有俱乐部");
    menuQueryClubName = gtk_menu_item_new_with_label("按名字查找俱乐部");

    menuQueryPlayer = gtk_menu_item_new_with_label("选手");
    menuQueryPlayerSub = gtk_menu_new();
    menuQueryPlayerAll = gtk_menu_item_new_with_label("显示所有选手");
    menuQueryPlayerName = gtk_menu_item_new_with_label("按名字查找选手");
    menuQueryPlayerClub = gtk_menu_item_new_with_label("按俱乐部查找选手");
    menuQueryPlayerWinNum = gtk_menu_item_new_with_label("按胜局数查找选手");

    menuQueryGame = gtk_menu_item_new_with_label("棋局");
    menuQueryGameSub = gtk_menu_new();
    menuQueryGameAll = gtk_menu_item_new_with_label("显示所有棋局");
    menuQueryGameNo = gtk_menu_item_new_with_label("按棋局场次查找棋局");
    menuQueryGameBlack = gtk_menu_item_new_with_label("按执黑选手查找棋局");
    menuQueryGameWhite = gtk_menu_item_new_with_label("按执白选手查找棋局");
    menuQueryGameResult = gtk_menu_item_new_with_label("按结果查找棋局");

    menuEdit = gtk_menu_item_new_with_label("编辑");
    menuEditSub = gtk_menu_new();
    menuEditClub = gtk_menu_item_new_with_label("俱乐部");
    menuEditPlayer = gtk_menu_item_new_with_label("选手");
    menuEditGame = gtk_menu_item_new_with_label("棋局");

    menuStat = gtk_menu_item_new_with_label("统计");
    menuStatSub = gtk_menu_new();
    menuStatClub = gtk_menu_item_new_with_label("俱乐部排行");
    menuStatPlayer = gtk_menu_item_new_with_label("选手排行");
    menuStatGrade = gtk_menu_item_new_with_label("棋局排行");
    menuStatClubGame = gtk_menu_item_new_with_label("俱乐部具体棋局排行");

    //Add to menu
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuSystem), menuSystemSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuSystemSub), menuSystemLoad);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuSystemSub), menuSystemQuit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuSystem);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuQuery), menuQuerySub);

    gtk_menu_shell_append(GTK_MENU_SHELL(menuQuerySub), menuQueryClub);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuQueryClub), menuQueryClubSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryClubSub), menuQueryClubAll);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryClubSub), menuQueryClubName);

    gtk_menu_shell_append(GTK_MENU_SHELL(menuQuerySub), menuQueryPlayer);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuQueryPlayer), menuQueryPlayerSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryPlayerSub), menuQueryPlayerAll);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryPlayerSub), menuQueryPlayerName);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryPlayerSub), menuQueryPlayerClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryPlayerSub), menuQueryPlayerWinNum);

    gtk_menu_shell_append(GTK_MENU_SHELL(menuQuerySub), menuQueryGame);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuQueryGame), menuQueryGameSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryGameSub), menuQueryGameAll);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryGameSub), menuQueryGameNo);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryGameSub), menuQueryGameBlack);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryGameSub), menuQueryGameWhite);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuQueryGameSub), menuQueryGameResult);

    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuQuery);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuEdit), menuEditSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuEditSub), menuEditClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuEditSub), menuEditPlayer);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuEditSub), menuEditGame);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuEdit);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuStat), menuStatSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuStatSub), menuStatClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuStatSub), menuStatPlayer);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuStatSub), menuStatGrade);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuStatSub), menuStatClubGame);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuStat);

    //Connect signal
    g_signal_connect(G_OBJECT(mainWindow), "delete_event", G_CALLBACK(quit), NULL);

    g_signal_connect(G_OBJECT(menuSystemQuit), "activate", G_CALLBACK(quit), NULL);

    g_signal_connect(G_OBJECT(menuSystemLoad), "activate", G_CALLBACK(load), NULL);

    g_signal_connect(G_OBJECT(menuQueryClubAll), "activate", G_CALLBACK(showAllClubs), NULL);

    g_signal_connect(G_OBJECT(menuQueryPlayerAll), "activate", G_CALLBACK(showAllPlayers), NULL);

    g_signal_connect(G_OBJECT(menuQueryGameAll), "activate", G_CALLBACK(showAllGames), NULL);

    g_signal_connect(G_OBJECT(menuStatClub), "activate", G_CALLBACK(stat), NULL);

    gtk_box_pack_start(GTK_BOX(mainBox), menu, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(mainBox), contentBox, FALSE, TRUE, 0);

    gtk_widget_show_all(mainWindow);

    welcome();

    gtk_main();
}
