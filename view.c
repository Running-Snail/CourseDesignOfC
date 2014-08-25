#include "view.h"

GtkWidget *goCreateClubNameQueryDialog(void)
{
    GtkWidget *dialog;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label = gtk_label_new("请输入部分或者完整俱乐部名字");
    entry = gtk_entry_new();
    btnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn = gtk_button_new_with_label("查询");
    cancelBtn = gtk_button_new_with_label("取消");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(dialog), "查询");

    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(dialog), box);

    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goPlayerNameQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)dialog);

    return dialog;
}

GtkWidget *goCreatePlayerNameQueryDialog(void)
{
    GtkWidget *dialog;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label = gtk_label_new("请输入部分或者完整选手名字");
    entry = gtk_entry_new();
    btnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn = gtk_button_new_with_label("查询");
    cancelBtn = gtk_button_new_with_label("取消");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(dialog), "查询");

    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(dialog), box);

    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goPlayerNameQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)dialog);

    return dialog;
}

GtkWidget *goCreatePlayerClubQueryDialog(void)
{
    GtkWidget *dialog;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label = gtk_label_new("请输入选手的俱乐部名字");
    entry = gtk_entry_new();
    btnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn = gtk_button_new_with_label("查询");
    cancelBtn = gtk_button_new_with_label("取消");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(dialog), "查询");

    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(dialog), box);

    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goPlayerClubQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)dialog);

    return dialog;
}

GtkWidget *goCreatePlayerWinQueryDialog(void)
{
    PangoFontDescription *hintFont = pango_font_description_from_string ("WenQuanYi Micro Hei 10");
    GtkWidget *dialog;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *hint;
    GtkWidget *lowerEntry;
    GtkWidget *upperEntry;
    GtkWidget *tilde;
    GtkWidget *entriesBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;
    GtkWidget *btnBox;
    EntryChain *entryChain;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    label = gtk_label_new("输入选手胜局数范围");
    hint = gtk_label_new("下限为空默认为0,上限为空默认为最大");
    tilde = gtk_label_new("~");
    lowerEntry = gtk_entry_new();
    upperEntry = gtk_entry_new();
    entriesBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    okBtn = gtk_button_new_with_label("查询");
    cancelBtn = gtk_button_new_with_label("取消");
    btnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    entryChain = (EntryChain *)malloc(sizeof(EntryChain));
    entryChain->next = (EntryChain *)malloc(sizeof(EntryChain));
    entryChain->entry = lowerEntry;
    entryChain->next->entry = upperEntry;
    entryChain->next->next = NULL;

    gtk_container_add(GTK_CONTAINER(dialog), box);

    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);
    gtk_misc_set_alignment(GTK_MISC(hint), 0, 0);

    gtk_widget_modify_font(hint, hintFont);

    gtk_box_pack_start(GTK_BOX(entriesBox), lowerEntry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(entriesBox), tilde, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(entriesBox), upperEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), hint, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entriesBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goPlayerWinQuery), (gpointer *)entryChain);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)dialog);

    return dialog;
}

GtkWidget *goCreateGameNoQueryDialog(void)
{
    GtkWidget *dialog;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label = gtk_label_new("请输入比赛的局数");
    entry = gtk_entry_new();
    btnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn = gtk_button_new_with_label("查询");
    cancelBtn = gtk_button_new_with_label("取消");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(dialog), "查询");

    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(dialog), box);

    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goGameNoQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)dialog);

    return dialog;
}

GtkWidget *goCreateGameBlackQueryDialog(void)
{
    GtkWidget *dialog;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label = gtk_label_new("请输入黑方选手");
    entry = gtk_entry_new();
    btnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn = gtk_button_new_with_label("查询");
    cancelBtn = gtk_button_new_with_label("取消");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(dialog), "查询");

    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(dialog), box);

    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goGameBlackQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)dialog);

    return dialog;
}

GtkWidget *goCreateGameWhiteQueryDialog(void)
{
    GtkWidget *dialog;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label = gtk_label_new("请输白方选手");
    entry = gtk_entry_new();
    btnBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn = gtk_button_new_with_label("查询");
    cancelBtn = gtk_button_new_with_label("取消");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(dialog), "查询");

    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(dialog), box);

    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goGameWhiteQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)dialog);

    return dialog;
}

void goClubNameQuery(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    char *query;
    int i;
    Variant *v;
    Club *c;
    DynamicArray *res;
    GtkWidget *clubItem;
    GtkWidget *heading;
    GtkWidget *contentBox;

    if (!var || !clubs)
        return;

    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //printf(query);
    query = trim(query);

    res = goQueryClubName(clubs, query);

    heading = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_widget_modify_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        c = (Club *)(v->v.pVoid);
        clubItem = goCreateClubListItem(c);

        gtk_widget_set_margin_left(clubItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(clubItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), clubItem, FALSE, FALSE, 0);

        g_signal_connect(G_OBJECT(clubItem), "clicked", G_CALLBACK(goViewShowClubInfo), v);
    }

    gtk_widget_hide(goClubNameQueryDialog);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goPlayerNameQuery(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    char *query;
    int i;
    Variant *v;
    Player *p;
    DynamicArray *res;
    GtkWidget *playerItem;
    GtkWidget *heading;
    GtkWidget *contentBox;

    if (!var)
        return;

    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //printf(query);

    query = trim(query);

    res = goQueryPlayerName(players, query);
    heading = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_widget_modify_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);


    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        p = (Player *)(v->v.pVoid);
        playerItem = goCreatePlayerListItem(p);

        gtk_widget_set_margin_left(playerItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerItem, FALSE, FALSE, 0);

        g_signal_connect(G_OBJECT(playerItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
    }

    gtk_widget_hide(goPlayerNameQueryDialog);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goPlayerClubQuery(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    char *query;
    int i;
    Variant *v;
    Player *p;
    DynamicArray *res;
    GtkWidget *playerItem;
    GtkWidget *heading;
    GtkWidget *contentBox;

    if (!var)
        return;

    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //printf(query);

    query = trim(query);

    res = goQueryPlayerClub(players, query);
    heading = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_widget_modify_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);


    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        p = (Player *)(v->v.pVoid);
        playerItem = goCreatePlayerListItem(p);

        gtk_widget_set_margin_left(playerItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerItem, FALSE, FALSE, 0);

        g_signal_connect(G_OBJECT(playerItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
    }

    gtk_widget_hide(goPlayerClubQueryDialog);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goPlayerWinQuery(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    char *query;
    int lower;
    int upper;
    int i;
    Variant *v;
    Player *p;
    DynamicArray *res;
    GtkWidget *playerItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    EntryChain *entries;

    if (!var)
        return;

    entries = (EntryChain *)var;
    //lower
    query = (char *)gtk_entry_get_text(GTK_ENTRY(entries->entry));
    query = trim(query);

    lower = atoi(query);

    if (!lower) {
        lower = -1;
    }

    entries = entries->next;
    query = (char *)gtk_entry_get_text(GTK_ENTRY(entries->entry));
    query = trim(query);

    upper = atoi(query);

    if (!upper) {
        upper = -1;
    }

    goStatAll(data);

    res = goQueryPlayerWin(players, lower, upper);
    heading = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_widget_modify_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);


    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        p = (Player *)(v->v.pVoid);
        playerItem = goCreatePlayerListItem(p);

        gtk_widget_set_margin_left(playerItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerItem, FALSE, FALSE, 0);

        g_signal_connect(G_OBJECT(playerItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
    }

    gtk_widget_hide(goPlayerWinQueryDialog);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

GtkWidget *goCreateClubListItem(Club *c)
{
    PangoFontDescription *font_desc = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!c)
        return NULL;

    sprintf(label, "   %s\t\t教练:%s", c->name, c->coach);

    li = gtk_button_new_with_label(label);

    gtk_button_set_alignment(GTK_BUTTON(li), 0, 0.5);
    gtk_widget_override_font(li, font_desc);
    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *goCreatePlayerListItem(Player *p)
{
    PangoFontDescription *font_desc = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!p)
        return NULL;

    sprintf(label, "   %s\t\t俱乐部:%s", p->name, p->clubName);

    li = gtk_button_new_with_label(label);

    gtk_button_set_alignment(GTK_BUTTON(li), 0, 0.5);
    gtk_widget_override_font(li, font_desc);
    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *goCreatePlayerListItemClubInfo(Player *p)
{
    PangoFontDescription *font_desc = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!p)
        return NULL;

    sprintf(label, "   %s\t\t段位:%d", p->name, p->grade);

    li = gtk_button_new_with_label(label);

    gtk_button_set_alignment(GTK_BUTTON(li), 0, 0.5);
    gtk_widget_override_font(li, font_desc);
    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *goCreateGameListItem(Game *g)
{
    PangoFontDescription *font = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!g)
        return NULL;

    sprintf(label, "   第%d轮 黑:%s\t白:%s\t%s", g->no, g->blackPlayer, g->whitePlayer, g->result?"白胜":"黑胜");

    li = gtk_button_new_with_label(label);

    gtk_button_set_alignment(GTK_BUTTON(li), 0, 0.5);
    gtk_widget_override_font(li, font);
    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *goCreateGameListItemPlayerInfo(Game *g, Player *p)
{
    PangoFontDescription *font = pango_font_description_from_string ("Serif 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!g || !p)
        return NULL;

    //执黑
    if (g->blackPlayerId == p->id)
        sprintf(label, "   第%d轮\t\t执黑%s %s", g->no, g->result?"负":"胜", g->whitePlayer);
    else
        sprintf(label, "   第%d轮\t\t执白%s %s", g->no, g->result?"胜":"负", g->blackPlayer);

    li = gtk_button_new_with_label(label);

    gtk_button_set_alignment(GTK_BUTTON(li), 0, 0.5);
    gtk_widget_override_font(li, font);
    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

void goViewShowClubInfo(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *clubNameLabelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    PlayerListNode *pl;
    GtkWidget *playerListItem;
    GtkWidget *clubNameLabel;
    GtkWidget *clubCoachLabel;
    GtkWidget *clubRoundScoreLabel;
    GtkWidget *clubGameScoreLabel;
    GtkWidget *clubRankLabel;
    GtkWidget *clubPlayerListLabel;
    GtkWidget *clubWinLabel;
    GtkWidget *clubLoseLabel;
    GtkWidget *contentBox;
    Variant *v;
    Club *c;
    ClubListNode *cl;
    char label[80];

    if (!var)
        return;

    goStatAll(data);

    v = (Variant *)var;
    c = (Club *)(v->v.pVoid);
    cl = goSearchClubName(data, c->name);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    clubNameLabel = gtk_label_new(c->name);
    gtk_misc_set_alignment(GTK_MISC(clubNameLabel), 0, 0);
    gtk_widget_set_margin_left(GTK_MISC(clubNameLabel), UNIFORM_MARGIN_MD);
    gtk_widget_override_font(GTK_MISC(clubNameLabel), clubNameLabelFont);

    sprintf(label, "教练:%s", c->coach);
    clubCoachLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubCoachLabel), 0, 0);
    gtk_widget_set_margin_left(GTK_MISC(clubCoachLabel), UNIFORM_MARGIN_MD);

    sprintf(label, "局分:%d", c->roundScore);
    clubRoundScoreLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubRoundScoreLabel), 0, 0);
    gtk_widget_set_margin_left(GTK_MISC(clubRoundScoreLabel), UNIFORM_MARGIN_MD);

    sprintf(label, "场分:%d", c->gameScore);
    clubGameScoreLabel = gtk_label_new(label);
    gtk_misc_set_alignment(clubGameScoreLabel, 0, 0);
    gtk_widget_set_margin_left(clubGameScoreLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "胜局数:%d", c->blackWinNum + c->whiteWinNum);
    clubWinLabel = gtk_label_new(label);
    gtk_misc_set_alignment(clubWinLabel, 0, 0);
    gtk_widget_set_margin_left(clubWinLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "负局数:%d", c->blackRoundNum + c->whiteRoundNum - c->blackWinNum - c->whiteWinNum);
    clubLoseLabel = gtk_label_new(label);
    gtk_misc_set_alignment(clubLoseLabel, 0, 0);
    gtk_widget_set_margin_left(clubLoseLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "排名:%d", c->ranking);
    clubRankLabel = gtk_label_new(label);
    gtk_misc_set_alignment(clubRankLabel, 0, 0);
    gtk_widget_set_margin_left(clubRankLabel, UNIFORM_MARGIN_MD);

    clubPlayerListLabel = gtk_label_new("选手列表");
    gtk_misc_set_alignment(clubPlayerListLabel, 0, 0);
    gtk_widget_set_margin_left(clubPlayerListLabel, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), clubNameLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubCoachLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubRoundScoreLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubGameScoreLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubWinLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubLoseLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubRankLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubPlayerListLabel, FALSE, FALSE, 0);

    pl = cl->playerListHead->next;

    while (pl) {
        v = createVariant();
        v->v.pVoid = pl->data;
        playerListItem = goCreatePlayerListItemClubInfo(pl->data);

        gtk_widget_set_margin_left(playerListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerListItem, FALSE, FALSE, 0);
        g_signal_connect(G_OBJECT(playerListItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
        pl = pl->next;
    }

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewShowPlayerInfo(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *playerNameLabelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    GtkWidget *playerNameLabel;
    GtkWidget *gradeLabel;
    GtkWidget *clubNameLabel;
    GtkWidget *totalRoundNumLabel;
    GtkWidget *winNumLabel;
    GtkWidget *loseNumLabel;
    GtkWidget *winRateLabel;
    GtkWidget *gameListLabel;
    GtkWidget *gameListItem;
    GtkWidget *contentBox;
    Variant *v;
    Player *p;
    PlayerList *pl;
    GameListNode *gl;
    char label[80];

    if (!var)
        return;

    goStatAll(data);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    v = (Variant *)var;
    p = (Player *)(v->v.pVoid);
    pl = goSearchPlayerName(data, p->name);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    playerNameLabel = gtk_label_new(p->name);
    gtk_misc_set_alignment(playerNameLabel, 0, 0);
    gtk_widget_set_margin_left(playerNameLabel, UNIFORM_MARGIN_MD);
    gtk_widget_override_font(playerNameLabel, playerNameLabelFont);

    sprintf(label, "%d段", p->grade);
    gradeLabel = gtk_label_new(label);
    gtk_misc_set_alignment(gradeLabel, 0, 0);
    gtk_widget_set_margin_left(gradeLabel, UNIFORM_MARGIN_MD);

    clubNameLabel = gtk_label_new(p->clubName);
    gtk_misc_set_alignment(clubNameLabel, 0, 0);
    gtk_widget_set_margin_left(clubNameLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "参赛局数:%d", p->roundNum);
    totalRoundNumLabel = gtk_label_new(label);
    gtk_misc_set_alignment(totalRoundNumLabel, 0, 0);
    gtk_widget_set_margin_left(totalRoundNumLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "胜局数:%d", p->winNum);
    winNumLabel = gtk_label_new(label);
    gtk_misc_set_alignment(winNumLabel, 0, 0);
    gtk_widget_set_margin_left(winNumLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "负局数:%d", p->roundNum - p->winNum);
    loseNumLabel = gtk_label_new(label);
    gtk_misc_set_alignment(loseNumLabel, 0, 0);
    gtk_widget_set_margin_left(loseNumLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "胜率:%.2f%%", p->winRate*100.0);
    winRateLabel = gtk_label_new(label);
    gtk_misc_set_alignment(winRateLabel, 0, 0);
    gtk_widget_set_margin_left(winRateLabel, UNIFORM_MARGIN_MD);

    gameListLabel = gtk_label_new("比赛列表");
    gtk_misc_set_alignment(gameListLabel, 0, 0);
    gtk_widget_set_margin_left(gameListLabel, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), playerNameLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), gradeLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), clubNameLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), totalRoundNumLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), winNumLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), loseNumLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), winRateLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), gameListLabel, FALSE, FALSE, 0);

    gl = pl->gameListHead->next;
    while (gl) {
        v = createVariant();
        v->v.pVoid = gl->data;
        gameListItem = goCreateGameListItemPlayerInfo(gl->data, p->name);

        gtk_widget_set_margin_left(gameListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(gameListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), gameListItem, FALSE, FALSE, 0);
        g_signal_connect(G_OBJECT(gameListItem), "clicked", G_CALLBACK(goViewShowGameInfo), v);
        gl = gl->next;
    }

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewClubRankList(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    GtkWidget *heading;
    GtkWidget *table;
    GtkWidget *rankLabel;
    GtkWidget *nameLabel;
    GtkWidget *gameScoreLabel;
    GtkWidget *roundScoreLabel;
    GtkWidget *winLabel;
    GtkWidget *loseLabel;
    GtkWidget *contentBox;
    GtkWidget *tableBox;
    GtkWidget *detailBtn;
    ClubListNode *cl;
    Club *c;
    Variant *v;
    int lastCol = 1;
    char label[80];

    goStatAll(data);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    table = gtk_grid_new();
    tableBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    heading = gtk_label_new("俱乐部排行榜");
    rankLabel = gtk_label_new("排名");
    nameLabel = gtk_label_new("俱乐部名");
    gameScoreLabel = gtk_label_new("场分");
    roundScoreLabel = gtk_label_new("局分");
    winLabel = gtk_label_new("胜局数");
    loseLabel = gtk_label_new("负局数");

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_widget_override_font(heading, headingFont);

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(heading, UNIFORM_MARGIN_MD);

    gtk_widget_set_margin_left(table, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(table, UNIFORM_MARGIN_MD);
    gtk_grid_attach(GTK_GRID(table), rankLabel, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), nameLabel, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), gameScoreLabel, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), roundScoreLabel, 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), winLabel, 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), loseLabel, 5, 0, 1, 1);

    gtk_widget_set_hexpand(rankLabel, TRUE);
    gtk_widget_set_hexpand(nameLabel, TRUE);
    gtk_widget_set_hexpand(gameScoreLabel, TRUE);
    gtk_widget_set_hexpand(roundScoreLabel, TRUE);
    gtk_widget_set_hexpand(winLabel, TRUE);
    gtk_widget_set_hexpand(loseLabel, TRUE);

    cl = data->next;
    while (cl) {
        c = cl->data;
        v = createVariant();
        v->v.pVoid = c;

        sprintf(label, "%d", c->ranking);
        rankLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), rankLabel, 0, lastCol, 1, 1);

        nameLabel = gtk_label_new(c->name);
        gtk_grid_attach(GTK_GRID(table), nameLabel, 1, lastCol, 1, 1);

        sprintf(label, "%d", c->gameScore);
        gameScoreLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), gameScoreLabel, 2, lastCol, 1, 1);

        sprintf(label, "%d", c->roundScore);
        roundScoreLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), roundScoreLabel, 3, lastCol, 1, 1);

        sprintf(label, "%d", c->whiteWinNum + c->blackWinNum);
        winLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), winLabel, 4, lastCol, 1, 1);

        sprintf(label, "%d", c->blackRoundNum + c->whiteRoundNum - c->whiteWinNum - c->blackWinNum);
        loseLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), loseLabel, 5, lastCol, 1, 1);

        detailBtn = gtk_button_new_with_label("详细");
        gtk_grid_attach(GTK_GRID(table), detailBtn, 6, lastCol, 1, 1);

        g_signal_connect(G_OBJECT(detailBtn), "clicked", G_CALLBACK(goViewShowClubInfo), v);

        cl = cl->next;
        lastCol ++;
    }

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), tableBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(tableBox), table, TRUE, TRUE, 0);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewPlayerRankList(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    GtkWidget *heading;
    GtkWidget *table;
    GtkWidget *rankLabel;
    GtkWidget *nameLabel;
    GtkWidget *clubLabel;
    GtkWidget *rateLabel;
    GtkWidget *roundNumLabel;
    GtkWidget *winLabel;
    GtkWidget *loseLabel;
    GtkWidget *contentBox;
    GtkWidget *tableBox;
    GtkWidget *detailBtn;
    Player *p;
    Variant *v;
    int lastCol = 1;
    int i;
    char label[80];

    goStatAll(data);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    table = gtk_grid_new();
    tableBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    heading = gtk_label_new("选手排行榜");
    rankLabel = gtk_label_new("排名");
    nameLabel = gtk_label_new("选手");
    clubLabel = gtk_label_new("俱乐部");
    rateLabel = gtk_label_new("胜率");
    winLabel = gtk_label_new("胜局数");
    loseLabel = gtk_label_new("负局数");
    roundNumLabel = gtk_label_new("参赛局数");

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_widget_override_font(heading, headingFont);

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(heading, UNIFORM_MARGIN_MD);

    gtk_widget_set_margin_left(table, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(table, UNIFORM_MARGIN_MD);
    gtk_grid_attach(GTK_GRID(table), rankLabel, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), nameLabel, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), clubLabel, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), rateLabel, 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), winLabel, 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), loseLabel, 5, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), roundNumLabel, 6, 0, 1, 1);

    gtk_widget_set_hexpand(rankLabel, TRUE);
    gtk_widget_set_hexpand(nameLabel, TRUE);
    gtk_widget_set_hexpand(clubLabel, TRUE);
    gtk_widget_set_hexpand(rateLabel, TRUE);
    gtk_widget_set_hexpand(winLabel, TRUE);
    gtk_widget_set_hexpand(loseLabel, TRUE);
    gtk_widget_set_hexpand(roundNumLabel, TRUE);

    for (i=0; i<sortedPlayers->arrayLen; i++) {
        v = dynamicGet(sortedPlayers, i);
        p = (Player *)(v->v.pVoid);

        sprintf(label, "%d", i+1);
        rankLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), rankLabel, 0, lastCol, 1, 1);

        nameLabel = gtk_label_new(p->name);
        gtk_grid_attach(GTK_GRID(table), nameLabel, 1, lastCol, 1, 1);

        clubLabel = gtk_label_new(p->clubName);
        gtk_grid_attach(GTK_GRID(table), clubLabel, 2, lastCol, 1, 1);

        sprintf(label, "%.2f", p->winRate * 100.0f);
        rateLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), rateLabel, 3, lastCol, 1, 1);

        sprintf(label, "%d", p->winNum);
        winLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), winLabel, 4, lastCol, 1, 1);

        sprintf(label, "%d", p->roundNum - p->winNum);
        loseLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), loseLabel, 5, lastCol, 1, 1);

        sprintf(label, "%d", p->roundNum);
        roundNumLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), roundNumLabel, 6, lastCol, 1, 1);

        detailBtn = gtk_button_new_with_label("详细");
        gtk_grid_attach(GTK_GRID(table), detailBtn, 7, lastCol, 1, 1);

        g_signal_connect(G_OBJECT(detailBtn), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);

        lastCol ++;
    }

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), tableBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(tableBox), table, TRUE, TRUE, 0);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewGradeStatList(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    GtkWidget *heading;
    GtkWidget *table;
    GtkWidget *gradeLabel;
    GtkWidget *numLabel;
    GtkWidget *contentBox;

    int *grades = (int *)malloc(sizeof(int)*10);
    signed int i;
    char label[80];

    goGradeStatistics(grades, players);

    heading = gtk_label_new("选手段位统计");
    table = gtk_grid_new();
    gradeLabel = gtk_label_new("段位");
    numLabel = gtk_label_new("人数");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_widget_override_font(heading, headingFont);

    gtk_widget_set_margin_left(table, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(table, UNIFORM_MARGIN_MD);
    gtk_grid_attach(GTK_GRID(table), gradeLabel, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), numLabel, 1, 0, 1, 1);

    gtk_widget_set_hexpand(gradeLabel, 1);
    gtk_widget_set_hexpand(numLabel, 1);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), table, FALSE, FALSE, 0);

    for (i=9; i>0; i--) {
        gradeLabel = gtk_label_new(goGradeName(i));
        gtk_grid_attach(GTK_GRID(table), gradeLabel, 0, 10-i, 1, 1);

        sprintf(label, "%d", *(grades+i));
        numLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), numLabel, 1, 10-i, 1, 1);
    }

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewStatClubDetails(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    GtkWidget *heading;
    GtkWidget *table;
    GtkWidget *nameLabel;
    GtkWidget *masterWinLabel;
    GtkWidget *fastWinLabel;
    GtkWidget *blackRoundLabel;
    GtkWidget *blackWinLabel;
    GtkWidget *whiteRoundLabel;
    GtkWidget *whiteWinLabel;
    GtkWidget *contentBox;
    GtkWidget *detailBtn;

    Variant *v;
    Club *c;
    int i;
    char label[80];

    goStatAll(data);

    heading = gtk_label_new("俱乐部详细统计");
    table = gtk_grid_new();
    nameLabel = gtk_label_new("俱乐部");
    masterWinLabel = gtk_label_new("主将局胜局数");
    fastWinLabel = gtk_label_new("快棋局胜局数");
    blackRoundLabel = gtk_label_new("棋手执黑棋数");
    blackWinLabel = gtk_label_new("执黑胜数");
    whiteRoundLabel = gtk_label_new("棋手执白棋数");
    whiteWinLabel = gtk_label_new("执白胜数");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_grid_attach(GTK_GRID(table), nameLabel, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), masterWinLabel, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), fastWinLabel, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), blackRoundLabel, 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), blackWinLabel, 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), whiteRoundLabel, 5, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(table), whiteWinLabel, 6, 0, 1, 1);

    gtk_widget_set_hexpand(nameLabel, 1);
    gtk_widget_set_hexpand(masterWinLabel, 1);
    gtk_widget_set_hexpand(fastWinLabel, 1);
    gtk_widget_set_hexpand(blackRoundLabel, 1);
    gtk_widget_set_hexpand(blackWinLabel, 1);
    gtk_widget_set_hexpand(whiteRoundLabel, 1);
    gtk_widget_set_hexpand(whiteWinLabel, 1);

    gtk_widget_set_margin_left(table, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(table, UNIFORM_MARGIN_MD);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_LG, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        c = (Club *)(v->v.pVoid);

        nameLabel = gtk_label_new(c->name);
        gtk_grid_attach(GTK_GRID(table), nameLabel, 0, i+1, 1, 1);

        sprintf(label, "%d", c->masterWinNum);
        masterWinLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), masterWinLabel, 1, i+1, 1, 1);

        sprintf(label, "%d", c->fastWinNum);
        fastWinLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), fastWinLabel, 2, i+1, 1, 1);

        sprintf(label, "%d", c->blackRoundNum);
        blackRoundLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), blackRoundLabel, 3, i+1, 1, 1);

        sprintf(label, "%d", c->blackWinNum);
        blackWinLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), blackWinLabel, 4, i+1, 1, 1);

        sprintf(label, "%d", c->whiteRoundNum);
        whiteRoundLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), whiteRoundLabel, 5, i+1, 1, 1);

        sprintf(label, "%d", c->whiteWinNum);
        whiteWinLabel = gtk_label_new(label);
        gtk_grid_attach(GTK_GRID(table), whiteWinLabel, 6, i+1, 1, 1);

        detailBtn = gtk_button_new_with_label("详细");
        gtk_grid_attach(GTK_GRID(table), detailBtn, 7, i+1, 1, 1);

        g_signal_connect(G_OBJECT(detailBtn), "clicked", G_CALLBACK(goViewShowClubInfo), NULL);
    }

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), table, FALSE, FALSE, 0);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewShowGameInfo(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *gameNoLabelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    GtkWidget *noLabel;
    GtkWidget *typeLabel;
    GtkWidget *blackPlayerLabel;
    GtkWidget *whitePlayerLabel;
    GtkWidget *resultLabel;
    GtkWidget *contentBox;
    Variant *v;
    Game *g;
    char label[80];

    if (!var)
        return;

    goStatAll(data);

    v = (Variant *)var;
    g = (Game *)(v->v.pVoid);

    sprintf(label, "第%d轮", g->no);
    noLabel = gtk_label_new(label);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_misc_set_alignment(noLabel, 0, 0);
    gtk_widget_set_margin_left(noLabel, UNIFORM_MARGIN_MD);
    gtk_widget_override_font(noLabel, gameNoLabelFont);


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
    gtk_misc_set_alignment(typeLabel, 0, 0);
    gtk_widget_set_margin_left(typeLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "执黑棋手:%s", g->blackPlayer);
    blackPlayerLabel = gtk_label_new(label);
    gtk_misc_set_alignment(blackPlayerLabel, 0, 0);
    gtk_widget_set_margin_left(blackPlayerLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "执白棋手:%s", g->whitePlayer);
    whitePlayerLabel = gtk_label_new(label);
    gtk_misc_set_alignment(whitePlayerLabel, 0, 0);
    gtk_widget_set_margin_left(whitePlayerLabel, UNIFORM_MARGIN_MD);


    switch (g->result) {
    case 0:
        resultLabel = gtk_label_new("黑胜");
        break;
    case 1:
        resultLabel = gtk_label_new("白胜");
        break;
    }
    gtk_misc_set_alignment(resultLabel, 0, 0);
    gtk_widget_set_margin_left(resultLabel, UNIFORM_MARGIN_MD);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_box_pack_start(GTK_BOX(contentBox), noLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), typeLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), blackPlayerLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), whitePlayerLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), resultLabel, FALSE, FALSE, 0);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goStatAll(ClubList *data)
{
    if (!data || goViewStated)
        return;

    goStatRoundNum(data);
    goStatScore(maxGameNo, games, clubs);
    goStatWinRate(players);
    sortPlayerWinRate(data);
    goSortAllPlayers(sortedPlayers);
    ranking(data);

    goViewStated = 1;
}

void goViewStat(GtkWidget *widget, gpointer *var)
{
    if (!data)
        return;

    goStatAll(data);
}

void goViewQuerySelection(void)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    PangoFontDescription *descriptionFont = pango_font_description_from_string ("Serif 12");

    GtkWidget *heading;
    GtkWidget *guide;
    GtkWidget *viewAllClubsBtn;
    GtkWidget *viewAllPlayersBtn;
    GtkWidget *viewAllGamesBtn;
    GtkWidget *contentBox;

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    heading = gtk_label_new("接下来");
    guide = gtk_label_new("数据载入成功,你可以");
    viewAllClubsBtn = gtk_button_new_with_label("查看所有俱乐部");
    viewAllPlayersBtn = gtk_button_new_with_label("查看所有选手");
    viewAllGamesBtn = gtk_button_new_with_label("查看所有棋局");

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_widget_override_font(heading, headingFont);

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(guide, UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(heading, 0, 0);
    gtk_misc_set_alignment(guide, 0, 0);
    gtk_widget_set_margin_left(viewAllClubsBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(viewAllPlayersBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(viewAllGamesBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(viewAllClubsBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(viewAllPlayersBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(viewAllGamesBtn, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), guide, FALSE, FALSE, 0);
    gtk_widget_set_size_request(viewAllClubsBtn, 200, 50);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllClubsBtn, FALSE, FALSE, 2);
    gtk_widget_set_size_request(viewAllPlayersBtn, 200, 50);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllPlayersBtn, FALSE, FALSE, 2);
    gtk_widget_set_size_request(viewAllGamesBtn, 200, 50);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllGamesBtn, FALSE, FALSE, 2);

    g_signal_connect(G_OBJECT(viewAllClubsBtn), "clicked", G_CALLBACK(goViewShowAllClubs), NULL);
    g_signal_connect(G_OBJECT(viewAllPlayersBtn), "clicked", G_CALLBACK(goViewShowAllPlayers), NULL);
    g_signal_connect(G_OBJECT(viewAllGamesBtn), "clicked", G_CALLBACK(goViewShowAllGames), NULL);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewWelcome(void)
{
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    PangoFontDescription *descriptionFont = pango_font_description_from_string ("Serif 12");

    GtkWidget *spacer;
    GtkWidget *heading;
    GtkWidget *description;
    GtkWidget *hgoViewLoadingBox;
    GtkWidget *goViewLoadLabel;
    GtkWidget *goViewLoadButton;
    GtkWidget *align;
    GtkWidget *contentBox;

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    hgoViewLoadingBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    align = gtk_alignment_new(0.5, 0, 0, 0);
    goViewLoadLabel = gtk_label_new("系统已经准备好");
    goViewLoadButton = gtk_button_new_with_label("载入数据");
    spacer = gtk_label_new("");
    heading = gtk_label_new("欢迎");
    description = gtk_label_new("一段描述");

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_widget_set_size_request(spacer, 200, 200);
    gtk_widget_override_font(heading, headingFont);
    gtk_widget_override_font(description, descriptionFont);

    gtk_widget_set_margin_left(goViewLoadButton, UNIFORM_MARGIN_SM);

    gtk_box_pack_start(GTK_BOX(contentBox), spacer, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), description, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hgoViewLoadingBox), goViewLoadLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hgoViewLoadingBox), goViewLoadButton, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(align), hgoViewLoadingBox);
    gtk_box_pack_start(GTK_BOX(contentBox), align, FALSE, FALSE, 0);

    g_signal_connect(G_OBJECT(goViewLoadButton), "clicked", G_CALLBACK(goViewLoad), NULL);

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewShowAllClubs(GtkWidget *widget, gpointer *window)
{
    int i;
    GtkWidget *heading;
    GtkWidget *clubListItem;
    GtkWidget *contentBox;
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    Variant *v;
    Club *c;
    if (!clubs)
        return;

    heading = gtk_label_new("俱乐部");

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(heading, 0, 0);
    gtk_widget_override_font(heading, headingFont);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        c = (Club *)(v->v.pVoid);
        clubListItem = goCreateClubListItem(c);

        gtk_widget_set_margin_left(clubListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(clubListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), clubListItem, FALSE, FALSE, 2);
        g_signal_connect(G_OBJECT(clubListItem), "clicked", G_CALLBACK(goViewShowClubInfo), (gpointer *)v);
    }

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewShowAllPlayers(GtkWidget *widget, gpointer *window)
{
    int i;
    GtkWidget *heading;
    GtkWidget *playerListItem;
    GtkWidget *contentBox;
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    Variant *v;
    Player *p;
    if (!players)
        return;

    heading = gtk_label_new("选手");

    gtk_widget_set_margin_left(GTK_WIDGET(heading), UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(heading, 0, 0);
    gtk_widget_override_font(heading, headingFont);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        playerListItem = goCreatePlayerListItem(p);

        gtk_widget_set_margin_left(playerListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerListItem, FALSE, FALSE, 2);
        g_signal_connect(G_OBJECT(playerListItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
    }

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewShowAllGames(GtkWidget *widget, gpointer *window)
{
    int i;
    GtkWidget *heading;
    GtkWidget *gameListItem;
    GtkWidget *contentBox;
    PangoFontDescription *headingFont = pango_font_description_from_string ("Serif 30");
    Variant *v;
    Game *g;
    if (!games)
        return;

    heading = gtk_label_new("棋局");

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(heading, 0, 0);
    gtk_widget_override_font(heading, headingFont);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_window_resize(goMainWindow, MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        g = (Game *)(v->v.pVoid);
        gameListItem = goCreateGameListItem(g);

        gtk_widget_set_margin_left(gameListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(gameListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), gameListItem, FALSE, FALSE, 2);
        g_signal_connect(G_OBJECT(gameListItem), "clicked", G_CALLBACK(goViewShowGameInfo), v);
    }

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

void goViewShowClubNameQuery(GtkWidget *widget, gpointer *var)
{
    if (!goClubNameQueryDialog)
        goClubNameQueryDialog = goCreateClubNameQueryDialog();

    gtk_widget_show_all(goClubNameQueryDialog);
}

void goViewShowPlayerNameQuery(GtkWidget *widget, gpointer *var)
{
    if (!goPlayerNameQueryDialog)
        goPlayerNameQueryDialog = goCreatePlayerNameQueryDialog();

    gtk_widget_show_all(goPlayerNameQueryDialog);
}

void goViewShowPlayerClubQuery(GtkWidget *widget, gpointer *var)
{
    if (!goPlayerClubQueryDialog)
        goPlayerClubQueryDialog = goCreatePlayerClubQueryDialog();

    gtk_widget_show_all(goPlayerClubQueryDialog);
}

void goViewShowPlayerWinQuery(GtkWidget *widget, gpointer *var)
{
    if (!goPlayerWinQueryDialog)
        goPlayerWinQueryDialog = goCreatePlayerWinQueryDialog();

    gtk_widget_show_all(goPlayerWinQueryDialog);
}

void goViewQuit(GtkWidget *widget, gpointer *window)
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

void goViewLoad(GtkWidget *widget, gpointer *window)
{
    GtkWidget *dialog;
    if (goViewLoadData(NULL)) {
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

    goViewQuerySelection();
}

void goViewHideWindow(GtkWidget *widget, gpointer *var)
{
    if (!var)
        return;

    gtk_widget_hide(GTK_WIDGET(var));
}

void goInitWindows(int *argc, char ***argv)
{
    goViewStated = 0;

    gtk_init(argc, argv);

    //Init main window
    goMainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(goMainWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);
    gtk_window_set_title(GTK_WINDOW(goMainWindow), MAIN_WINDOW_TITLE);

    goClubNameQueryDialog = goCreateClubNameQueryDialog();
    goPlayerNameQueryDialog = goCreatePlayerNameQueryDialog();
    goPlayerClubQueryDialog = goCreatePlayerClubQueryDialog();
    goPlayerWinQueryDialog = goCreatePlayerWinQueryDialog();

    //main box
    goMainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);

    gtk_container_add(GTK_CONTAINER(goMainWindow), goMainBox);

    //Create menu bar instances
    goMenu = gtk_menu_bar_new();

    goMenuSystem = gtk_menu_item_new_with_label("系统");
    goMenuSystemSub = gtk_menu_new();
    goMenuSystemgoViewLoad = gtk_menu_item_new_with_label("载入数据");
    goMenuSystemgoViewQuit = gtk_menu_item_new_with_label("退出");

    goMenuQuery = gtk_menu_item_new_with_label("查询");
    goMenuQuerySub = gtk_menu_new();

    goMenuQueryClub = gtk_menu_item_new_with_label("俱乐部");
    goMenuQueryClubSub = gtk_menu_new();
    goMenuQueryClubAll = gtk_menu_item_new_with_label("显示所有俱乐部");
    goMenuQueryClubName = gtk_menu_item_new_with_label("按名字查找俱乐部");

    goMenuQueryPlayer = gtk_menu_item_new_with_label("选手");
    goMenuQueryPlayerSub = gtk_menu_new();
    goMenuQueryPlayerAll = gtk_menu_item_new_with_label("显示所有选手");
    goMenuQueryPlayerName = gtk_menu_item_new_with_label("按名字查找选手");
    goMenuQueryPlayerClub = gtk_menu_item_new_with_label("按俱乐部查找选手");
    goMenuQueryPlayerWinNum = gtk_menu_item_new_with_label("按胜局数查找选手");

    goMenuQueryGame = gtk_menu_item_new_with_label("棋局");
    goMenuQueryGameSub = gtk_menu_new();
    goMenuQueryGameAll = gtk_menu_item_new_with_label("显示所有棋局");
    goMenuQueryGameNo = gtk_menu_item_new_with_label("按棋局场次查找棋局");
    goMenuQueryGameBlack = gtk_menu_item_new_with_label("按执黑选手查找棋局");
    goMenuQueryGameWhite = gtk_menu_item_new_with_label("按执白选手查找棋局");
    goMenuQueryGameResult = gtk_menu_item_new_with_label("按结果查找棋局");

    goMenuEdit = gtk_menu_item_new_with_label("编辑");
    goMenuEditSub = gtk_menu_new();
    goMenuEditClub = gtk_menu_item_new_with_label("俱乐部");
    goMenuEditPlayer = gtk_menu_item_new_with_label("选手");
    goMenuEditGame = gtk_menu_item_new_with_label("棋局");

    goMenuStat = gtk_menu_item_new_with_label("统计");
    goMenuStatSub = gtk_menu_new();
    goMenuStatClub = gtk_menu_item_new_with_label("俱乐部排行");
    goMenuStatPlayer = gtk_menu_item_new_with_label("选手排行");
    goMenuStatGrade = gtk_menu_item_new_with_label("段位统计");
    goMenuStatClubDetails = gtk_menu_item_new_with_label("俱乐部具体棋局排行");

    //Add to goMenu
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuSystem), goMenuSystemSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuSystemSub), goMenuSystemgoViewLoad);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuSystemSub), goMenuSystemgoViewQuit);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuSystem);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuQuery), goMenuQuerySub);

    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQuerySub), goMenuQueryClub);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuQueryClub), goMenuQueryClubSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryClubSub), goMenuQueryClubAll);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryClubSub), goMenuQueryClubName);

    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQuerySub), goMenuQueryPlayer);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuQueryPlayer), goMenuQueryPlayerSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryPlayerSub), goMenuQueryPlayerAll);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryPlayerSub), goMenuQueryPlayerName);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryPlayerSub), goMenuQueryPlayerClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryPlayerSub), goMenuQueryPlayerWinNum);

    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQuerySub), goMenuQueryGame);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuQueryGame), goMenuQueryGameSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryGameSub), goMenuQueryGameAll);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryGameSub), goMenuQueryGameNo);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryGameSub), goMenuQueryGameBlack);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryGameSub), goMenuQueryGameWhite);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuQueryGameSub), goMenuQueryGameResult);

    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuQuery);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuEdit), goMenuEditSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditPlayer);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditGame);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuEdit);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuStat), goMenuStatSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatPlayer);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatGrade);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatClubDetails);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuStat);

    //Connect signal
    g_signal_connect(G_OBJECT(goMainWindow), "delete_event", G_CALLBACK(goViewQuit), NULL);
    g_signal_connect(G_OBJECT(goMenuSystemgoViewQuit), "activate", G_CALLBACK(goViewQuit), NULL);
    g_signal_connect(G_OBJECT(goMenuSystemgoViewLoad), "activate", G_CALLBACK(goViewLoad), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryClubAll), "activate", G_CALLBACK(goViewShowAllClubs), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerAll), "activate", G_CALLBACK(goViewShowAllPlayers), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryGameAll), "activate", G_CALLBACK(goViewShowAllGames), NULL);
    g_signal_connect(G_OBJECT(goMenuStatClub), "activate", G_CALLBACK(goViewClubRankList), NULL);
    g_signal_connect(G_OBJECT(goMenuStatPlayer), "activate", G_CALLBACK(goViewPlayerRankList), NULL);
    g_signal_connect(G_OBJECT(goMenuStatGrade), "activate", G_CALLBACK(goViewGradeStatList), NULL);
    g_signal_connect(G_OBJECT(goMenuStatClubDetails), "activate", G_CALLBACK(goViewStatClubDetails), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryClubName), "activate", G_CALLBACK(goViewShowClubNameQuery), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerName), "activate", G_CALLBACK(goViewShowPlayerNameQuery), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerClub), "activate", G_CALLBACK(goViewShowPlayerClubQuery), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerWinNum), "activate", G_CALLBACK(goViewShowPlayerWinQuery), NULL);

    gtk_box_pack_start(GTK_BOX(goMainBox), goMenu, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);

    gtk_widget_show_all(goMainWindow);

    goViewWelcome();

    gtk_main();
}
