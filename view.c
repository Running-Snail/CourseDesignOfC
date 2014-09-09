#include "view.h"

/**
 * 创建输入链表(用于多输入框)
 * @return  创建的输入链表
 */
InputChain *goCreateInputChain(void)
{
    InputChain *res = NULL;

    res = (InputChain *)malloc(sizeof(InputChain));
    res->input = NULL;
    res->next = NULL;

    return res;
}

/**
 * 显示根据名字查询俱乐部的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框指针
 */
GtkWidget *goViewShowClubNameQueryDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    //实例化
    goClubNameQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                   = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label                 = gtk_label_new("请输入部分或者完整俱乐部名字");
    entry                 = gtk_entry_new();
    btnBox                = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn                 = gtk_button_new_with_label("查询");
    cancelBtn             = gtk_button_new_with_label("取消");

    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(goClubNameQueryDialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(goClubNameQueryDialog), "查询");

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goClubNameQueryDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goClubNameQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goClubNameQueryDialog);

    //显示
    gtk_widget_show_all(goClubNameQueryDialog);

    return goClubNameQueryDialog;
}

/**
 * 显示根据名字查询选手的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowPlayerNameQueryDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    //实例化
    goPlayerNameQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                     = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    label                   = gtk_label_new("请输入部分或者完整选手名字");
    entry                   = gtk_entry_new();
    btnBox                  = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    okBtn                   = gtk_button_new_with_label("查询");
    cancelBtn               = gtk_button_new_with_label("取消");

    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(goPlayerNameQueryDialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(goPlayerNameQueryDialog), "查询");

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goPlayerNameQueryDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goPlayerNameQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goPlayerNameQueryDialog);

    //显示
    gtk_widget_show_all(goPlayerNameQueryDialog);

    return goPlayerNameQueryDialog;
}

/**
 * 显示根据俱乐部查询选手的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowPlayerClubQueryDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    //实例化
    goPlayerClubQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                     = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    label                   = gtk_label_new("请输入选手的俱乐部名字");
    entry                   = gtk_entry_new();
    btnBox                  = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn                   = gtk_button_new_with_label("查询");
    cancelBtn               = gtk_button_new_with_label("取消");

    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(goPlayerClubQueryDialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(goPlayerClubQueryDialog), "查询");

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goPlayerClubQueryDialog), box);

    //添加信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goPlayerClubQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goPlayerClubQueryDialog);

    //显示
    gtk_widget_show_all(goPlayerClubQueryDialog);

    return goPlayerClubQueryDialog;
}

/**
 * 显示根据选手胜局数查询的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowPlayerWinQueryDialog(GtkWidget *widget, gpointer *var)
{
    PangoFontDescription *hintFont = pango_font_description_from_string ("WenQuanYi Micro Hei 10");
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
    InputChain *inputs;

    //实例化
    goPlayerWinQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                    = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    label                  = gtk_label_new("输入选手胜局数范围");
    hint                   = gtk_label_new("下限为空默认为0,上限为空默认为最大");
    tilde                  = gtk_label_new("~");
    lowerEntry             = gtk_entry_new();
    upperEntry             = gtk_entry_new();
    entriesBox             = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn                  = gtk_button_new_with_label("查询");
    cancelBtn              = gtk_button_new_with_label("取消");
    btnBox                 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);

    //添加进输入序列链表
    inputs              = goCreateInputChain();
    inputs->next        = goCreateInputChain();
    inputs->input       = lowerEntry;
    inputs->next->input = upperEntry;

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);
    gtk_misc_set_alignment(GTK_MISC(hint), 0, 0);

    //修改字体
    gtk_widget_override_font(hint, hintFont);

    //添加控件
    gtk_box_pack_start(GTK_BOX(entriesBox), lowerEntry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(entriesBox), tilde, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(entriesBox), upperEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), hint, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entriesBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goPlayerWinQueryDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goPlayerWinQuery), (gpointer *)inputs);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goPlayerWinQueryDialog);

    //显示
    gtk_widget_show_all(goPlayerWinQueryDialog);

    return goPlayerWinQueryDialog;
}

/**
 * 显示根据比赛场次查询比赛的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowGameNoQueryDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    //实例化
    goGameNoQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                 = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    label               = gtk_label_new("请输入比赛的局数");
    entry               = gtk_entry_new();
    btnBox              = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn               = gtk_button_new_with_label("查询");
    cancelBtn           = gtk_button_new_with_label("取消");

    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(goGameNoQueryDialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(goGameNoQueryDialog), "查询");

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goGameNoQueryDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goGameNoQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goGameNoQueryDialog);

    //显示
    gtk_widget_show_all(goGameNoQueryDialog);

    return goGameNoQueryDialog;
}

/**
 * 显示根据比赛黑方查询比赛的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowGameBlackQueryDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    //实例化
    goGameBlackQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                    = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    label                  = gtk_label_new("请输入黑方选手");
    entry                  = gtk_entry_new();
    btnBox                 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn                  = gtk_button_new_with_label("查询");
    cancelBtn              = gtk_button_new_with_label("取消");

    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(goGameBlackQueryDialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(goGameBlackQueryDialog), "查询");

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goGameBlackQueryDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goGameBlackQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goGameBlackQueryDialog);

    //显示
    gtk_widget_show_all(goGameBlackQueryDialog);

    return goGameBlackQueryDialog;
}

/**
 * 显示根据比赛白方查询比赛的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowGameWhiteQueryDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    //实例化
    goGameWhiteQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                    = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    label                  = gtk_label_new("请输白方选手");
    entry                  = gtk_entry_new();
    btnBox                 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn                  = gtk_button_new_with_label("查询");
    cancelBtn              = gtk_button_new_with_label("取消");

    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(goGameWhiteQueryDialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(goGameWhiteQueryDialog), "查询");

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goGameWhiteQueryDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goGameWhiteQuery), entry);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goGameWhiteQueryDialog);

    //显示
    gtk_widget_show_all(goGameWhiteQueryDialog);

    return goGameWhiteQueryDialog;
}

/**
 * 显示根据比赛结果查询比赛的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowGameResultQueryDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *combo;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;

    //实例化
    goGameResultQueryDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box                     = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    label                   = gtk_label_new("请选择胜负结果");
    combo                   = gtk_combo_box_text_new();
    btnBox                  = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn                   = gtk_button_new_with_label("查询");
    cancelBtn               = gtk_button_new_with_label("取消");

    //添加查询下拉框的数据
    //白胜还是黑胜
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "0", "黑胜");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "1", "白胜");
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(combo), "0");

    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(goGameResultQueryDialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(goGameResultQueryDialog), "查询");

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), combo, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goGameResultQueryDialog), box);

    //添加信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goGameResultQuery), combo);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goViewHideWindow), (gpointer *)goGameResultQueryDialog);

    //显示
    gtk_widget_show_all(goGameResultQueryDialog);

    return goGameResultQueryDialog;
}

/**
 * 显示添加俱乐部的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowAddClubDialog(GtkWidget *widget, gpointer *var)
{
    GtkWidget *label;
    GtkWidget *nameLabel;
    GtkWidget *nameEntry;
    GtkWidget *nameBox;
    GtkWidget *coachLabel;
    GtkWidget *coachEntry;
    GtkWidget *coachBox;
    GtkWidget *box;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;
    InputChain *inputs;
    PangoFontDescription *labelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 16");

    //实例化
    goAddClubDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label           = gtk_label_new("请填写要插入俱乐部的信息");
    nameLabel       = gtk_label_new("俱乐部名");
    nameEntry       = gtk_entry_new();
    nameBox         = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    coachLabel      = gtk_label_new("教练");
    coachEntry      = gtk_entry_new();
    coachBox        = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    box             = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    btnBox          = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn           = gtk_button_new_with_label("插入");
    cancelBtn       = gtk_button_new_with_label("取消");
    inputs          = goCreateInputChain();

    //创建输入链表
    inputs              = goCreateInputChain();
    inputs->input       = nameEntry;
    inputs->next        = goCreateInputChain();
    inputs->next->input = coachEntry;

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //修改字体
    gtk_widget_override_font(label, labelFont);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(nameBox), nameLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(nameBox), nameEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(coachBox), coachLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(coachBox), coachEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), nameBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), coachBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goAddClubDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn), "clicked", G_CALLBACK(goAddClub), (gpointer *)inputs);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goDeleteWindow), (gpointer *)goAddClubDialog);

    //显示
    gtk_widget_show_all(goAddClubDialog);

    return goAddClubDialog;
}

/**
 * 显示添加选手的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowAddPlayerDialog(GtkWidget *widget, gpointer *var)
{
    int i;
    char text[80]; //用于生成拼接字符串
    Club *c;
    Variant *v;
    GtkWidget *label;
    GtkWidget *nameLabel;
    GtkWidget *nameEntry;
    GtkWidget *nameBox;
    GtkWidget *clubLabel;
    GtkWidget *clubComboBoxText;
    GtkWidget *clubBox;
    GtkWidget *gradeLabel;
    GtkWidget *gradeComboBoxText;
    GtkWidget *gradeBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;
    GtkWidget *btnBox;
    GtkWidget *box;
    InputChain *inputs;

    //实例化
    goAddPlayerDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label             = gtk_label_new("请输入要插入选手的信息");
    nameLabel         = gtk_label_new("姓名");
    nameEntry         = gtk_entry_new();
    nameBox           = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    clubLabel         = gtk_label_new("俱乐部");
    clubComboBoxText  = gtk_combo_box_text_new();
    clubBox           = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    gradeLabel        = gtk_label_new("段位");
    gradeComboBoxText = gtk_combo_box_text_new();
    gradeBox          = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn             = gtk_button_new_with_label("插入");
    cancelBtn         = gtk_button_new_with_label("取消");
    btnBox            = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    box               = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    inputs            = goCreateInputChain();

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //设置边距
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);

    //向俱乐部的下拉框中添加数据
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        //跳过已被删除的俱乐部
        if (!v->v.pVoid)
            continue;
        c = (Club *)(v->v.pVoid);

        //俱乐部id转换为字符串
        sprintf(text, "%d", c->id);
        //添加进下拉框
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(clubComboBoxText), text, c->name);
    }

    //初始选择第一个
    gtk_combo_box_set_active(GTK_COMBO_BOX(clubComboBoxText), 0);

    //添加段位下拉框
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "1", goGradeName(1));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "2", goGradeName(2));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "3", goGradeName(3));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "4", goGradeName(4));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "5", goGradeName(5));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "6", goGradeName(6));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "7", goGradeName(7));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "8", goGradeName(8));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "9", goGradeName(9));

    //初始选择初段
    gtk_combo_box_set_active(GTK_COMBO_BOX(gradeComboBoxText), 0);

    //设置输入链表
    inputs->input             = nameEntry;
    inputs->next              = goCreateInputChain();
    inputs->next->input       = clubComboBoxText;
    inputs->next->next        = goCreateInputChain();
    inputs->next->next->input = gradeComboBoxText;

    //添加控件
    gtk_box_pack_start(GTK_BOX(nameBox), nameLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(nameBox), nameEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(gradeBox), gradeLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(gradeBox), gradeComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(clubBox), clubLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(clubBox), clubComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), nameBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), gradeBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), clubBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加控件
    gtk_container_add(GTK_CONTAINER(goAddPlayerDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goAddPlayer), (gpointer *)inputs);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goDeleteWindow), (gpointer *)goAddPlayerDialog);

    //显示
    gtk_widget_show_all(goAddPlayerDialog);

    return goAddPlayerDialog;
}

/**
 * 显示添加比赛的对话框
 * @param  widget 父控件
 * @param  var    数据指针
 * @return        创建的对话框
 */
GtkWidget *goViewShowAddGameDialog(GtkWidget *widget, gpointer *var)
{
    int i;
    char text[80]; //用于拼接字符串
    Player *p;
    Variant *v;
    GtkWidget *label;
    GtkWidget *noLabel;
    GtkWidget *noComboBoxText;
    GtkWidget *noBox;
    GtkWidget *typeLabel;
    GtkWidget *typeComboBoxText;
    GtkWidget *typeBox;
    GtkWidget *blackPlayerLabel;
    GtkWidget *blackPlayerComboBoxText;
    GtkWidget *blackPlayerBox;
    GtkWidget *whitePlayerLabel;
    GtkWidget *whitePlayerComboBoxText;
    GtkWidget *whitePlayerBox;
    GtkWidget *resultLabel;
    GtkWidget *resultComboBoxText;
    GtkWidget *resultBox;
    GtkWidget *box;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;
    InputChain *inputs, *ic;
    PangoFontDescription *labelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 16");

    //实例化
    goAddGameDialog         = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label                   = gtk_label_new("请输入修改后的比赛信息");
    noLabel                 = gtk_label_new("场次");
    noComboBoxText          = gtk_combo_box_text_new();
    noBox                   = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    typeLabel               = gtk_label_new("类别");
    typeComboBoxText        = gtk_combo_box_text_new();
    typeBox                 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    blackPlayerLabel        = gtk_label_new("黑方");
    blackPlayerComboBoxText = gtk_combo_box_text_new();
    blackPlayerBox          = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    whitePlayerLabel        = gtk_label_new("白方");
    whitePlayerComboBoxText = gtk_combo_box_text_new();
    whitePlayerBox          = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    resultLabel             = gtk_label_new("结果");
    resultComboBoxText      = gtk_combo_box_text_new();
    resultBox               = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    box                     = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    btnBox                  = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn                   = gtk_button_new_with_label("修改");
    cancelBtn               = gtk_button_new_with_label("取消");
    inputs                  = goCreateInputChain();

    //设置左对齐
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);

    //修改字体
    gtk_widget_override_font(label, labelFont);

    //向比赛列表中填充场次
    for (i=1; i<=maxGameNo; i++) {
        //数字转换为字符串
        sprintf(text, "%d", i);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(noComboBoxText), text, text);
    }

    //默认选择一个
    gtk_combo_box_set_active(GTK_COMBO_BOX(noComboBoxText), 0);

    //填充棋局类型下拉框
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(typeComboBoxText), "0", "主将局");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(typeComboBoxText), "1", "快棋局");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(typeComboBoxText), "2", "普通局");

    //默认选择一个
    gtk_combo_box_set_active(GTK_COMBO_BOX(typeComboBoxText), 0);

    //填充黑方比赛选手
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);

        sprintf(text, "%d", p->id);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(blackPlayerComboBoxText), text, p->name);
    }

    //默认选择一个
    gtk_combo_box_set_active(GTK_COMBO_BOX(blackPlayerComboBoxText), 0);

    //填充白方比赛选手
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);

        sprintf(text, "%d", p->id);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(whitePlayerComboBoxText), text, p->name);
    }

    //默认选择一个
    gtk_combo_box_set_active(GTK_COMBO_BOX(whitePlayerComboBoxText), 0);

    //填充比赛结果
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(resultComboBoxText), "0", "黑胜");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(resultComboBoxText), "1", "白胜");

    //默认选择一个
    gtk_combo_box_set_active(GTK_COMBO_BOX(resultComboBoxText), 0);

    //设置边距
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);

    //创建输入链表
    ic = inputs;
    ic->input = noComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = typeComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = blackPlayerComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = whitePlayerComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = resultComboBoxText;

    //添加控件
    gtk_box_pack_start(GTK_BOX(noBox), noLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(noBox), noComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(typeBox), typeLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(typeBox), typeComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(blackPlayerBox), blackPlayerLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(blackPlayerBox), blackPlayerComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(whitePlayerBox), whitePlayerLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(whitePlayerBox), whitePlayerComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(resultBox), resultLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(resultBox), resultComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), noBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), typeBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), blackPlayerBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), whitePlayerBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), resultBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goAddGameDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goAddGame), (gpointer *)inputs);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goDeleteWindow), (gpointer *)goAddGameDialog);

    //显示
    gtk_widget_show_all(goAddGameDialog);

    return goAddGameDialog;
}

/**
 * 根据俱乐部名字进行查询,并显示结果
 * @param widget [description]
 * @param var    [description]
 */
void goClubNameQuery(GtkWidget *widget, gpointer *var)
{
    int i;
    Club *c;
    Variant *v;
    char *query;
    GtkWidget *clubItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    DynamicArray *res;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var || !clubs)
        return;

    //获取查询的俱乐部名
    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //去除两边空白
    query = trim(query);
    //查询
    res = goQueryClubName(clubs, query);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //修改控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相应的俱乐部");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        c = (Club *)(v->v.pVoid);
        clubItem = goCreateClubListItem(c);

        //设置边距
        gtk_widget_set_margin_left(clubItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(clubItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), clubItem, FALSE, FALSE, 0);

        //连接信号, 点击查询的俱乐部结果进入详情页
        g_signal_connect(G_OBJECT(clubItem), "clicked", G_CALLBACK(goViewShowClubInfo), v);
    }

    //隐藏查询对话框
    gtk_widget_hide(goClubNameQueryDialog);

    //刷新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 根据选手名字进行查询,并显示查询结果
 * @param widget 父控件
 * @param var    数据指针
 */
void goPlayerNameQuery(GtkWidget *widget, gpointer *var)
{
    int i;
    Player *p;
    Variant *v;
    char *query;
    DynamicArray *res;
    GtkWidget *playerItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var)
        return;

    //获取输入的选手名
    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //去除两边空白
    query = trim(query);
    //查询
    res = goQueryPlayerName(players, query);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //修改控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相对应的选手");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        p = (Player *)(v->v.pVoid);
        playerItem = goCreatePlayerListItem(p);

        //设置边距
        gtk_widget_set_margin_left(playerItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerItem, FALSE, FALSE, 0);

        //连接信号,点击搜索结果进入详情页
        g_signal_connect(G_OBJECT(playerItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
    }

    //隐藏查询对话框
    gtk_widget_hide(goPlayerNameQueryDialog);

    //刷新页面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 根据选手俱乐部查询
 * @param widget 父控件
 * @param var    数据指针
 */
void goPlayerClubQuery(GtkWidget *widget, gpointer *var)
{
    int i;
    Player *p;
    Variant *v;
    char *query;
    DynamicArray *res;
    GtkWidget *playerItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var)
        return;

    //获取俱乐部名
    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //删除两边空格
    query = trim(query);
    //查询
    res = goQueryPlayerClub(players, query);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //设置控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相对应的选手");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        p = (Player *)(v->v.pVoid);
        playerItem = goCreatePlayerListItem(p);

        //设置边距
        gtk_widget_set_margin_left(playerItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerItem, FALSE, FALSE, 0);

        //连接信号
        g_signal_connect(G_OBJECT(playerItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
    }

    //隐藏查询对话框
    gtk_widget_hide(goPlayerClubQueryDialog);

    //更新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 根据选手胜局数查询选手
 * @param widget 父控件
 * @param var    数据指针
 */
void goPlayerWinQuery(GtkWidget *widget, gpointer *var)
{
    int i;
    int lower;
    int upper;
    Player *p;
    Variant *v;
    char *query;
    DynamicArray *res;
    GtkWidget *playerItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    InputChain *inputs;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var)
        return;

    //获取输入链表
    inputs = (InputChain *)var;

    //获取最小值
    query = (char *)gtk_entry_get_text(GTK_ENTRY(inputs->input));
    query = trim(query);

    //字符换转换数组
    lower = atoi(query);

    //调整lower的值
    if (!lower) {
        lower = -1;
    }

    //获取输入链表下一项(upper)
    inputs = inputs->next;
    query = (char *)gtk_entry_get_text(GTK_ENTRY(inputs->input));
    query = trim(query);
    upper = atoi(query);

    //调整upper的值
    if (!upper) {
        upper = -1;
    }

    //统计数据(为了获取选手的胜局数)
    goStatAll(data);

    //查询
    res = goQueryPlayerWin(players, lower, upper);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //调整控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相对应的选手");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        p = (Player *)(v->v.pVoid);
        playerItem = goCreatePlayerListItem(p);

        //调整控件属性
        gtk_widget_set_margin_left(playerItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerItem, FALSE, FALSE, 0);

        //连接信号
        g_signal_connect(G_OBJECT(playerItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
    }

    //隐藏查询对话框
    gtk_widget_hide(goPlayerWinQueryDialog);

    //更新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 根据俱乐部场次查询
 * @param widget 父控件
 * @param var    数据指针
 */
void goGameNoQuery(GtkWidget *widget, gpointer *var)
{
    int no;
    int i;
    Game *g;
    Variant *v;
    char *query;
    DynamicArray *res;
    GtkWidget *gameItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var)
        return;

    //获取场次值
    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //去除两边空格
    query = trim(query);
    //字符串转数字
    no = atoi(query);
    //查询
    res = goQueryGameNo(games, no);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //调整控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相对应的比赛");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        g = (Game *)(v->v.pVoid);
        gameItem = goCreateGameListItem(g);

        //调整控件属性
        gtk_widget_set_margin_left(gameItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(gameItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), gameItem, FALSE, FALSE, 0);

        //连接信号
        g_signal_connect(G_OBJECT(gameItem), "clicked", G_CALLBACK(goViewShowGameInfo), v);
    }

    //隐藏查询框
    gtk_widget_hide(goGameNoQueryDialog);

    //更新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 根据比赛黑方选手查询
 * @param widget 父控件
 * @param var    数据指针
 */
void goGameBlackQuery(GtkWidget *widget, gpointer *var)
{
    int i;
    Game *g;
    Variant *v;
    char *query;
    DynamicArray *res;
    GtkWidget *heading;
    GtkWidget *noResult;
    GtkWidget *gameItem;
    GtkWidget *contentBox;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var)
        return;

    //获取黑方选手
    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //去掉两边空格
    query = trim(query);
    //查询
    res = goQueryGameBlack(games, query);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //调整控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相对应的比赛");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        g = (Game *)(v->v.pVoid);
        gameItem = goCreateGameListItem(g);

        //调整控件属性
        gtk_widget_set_margin_left(gameItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(gameItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), gameItem, FALSE, FALSE, 0);

        //连接信号
        g_signal_connect(G_OBJECT(gameItem), "clicked", G_CALLBACK(goViewShowGameInfo), v);
    }

    //隐藏查询框
    gtk_widget_hide(goGameBlackQueryDialog);

    //更新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 根据比赛白方查询比赛
 * @param widget 父控件
 * @param var    数据指针
 */
void goGameWhiteQuery(GtkWidget *widget, gpointer *var)
{
    int i;
    Game *g;
    Variant *v;
    char *query;
    DynamicArray *res;
    GtkWidget *gameItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var)
        return;

    //获取白方选手名字
    query = (char *)gtk_entry_get_text(GTK_ENTRY(var));
    //去除两边空格
    query = trim(query);
    //查询
    res = goQueryGameWhite(games, query);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //调整控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相对应的比赛");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        g = (Game *)(v->v.pVoid);
        gameItem = goCreateGameListItem(g);

        //调整控件属性
        gtk_widget_set_margin_left(gameItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(gameItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), gameItem, FALSE, FALSE, 0);

        //连接信号
        g_signal_connect(G_OBJECT(gameItem), "clicked", G_CALLBACK(goViewShowGameInfo), v);
    }

    //隐藏查询框
    gtk_widget_hide(goGameWhiteQueryDialog);

    //更新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 根据比赛结果查询
 * @param widget 父控件
 * @param var    数据指针
 */
void goGameResultQuery(GtkWidget *widget, gpointer *var)
{
    int i;
    Game *g;
    Variant *v;
    int result;
    const char *query;
    DynamicArray *res;
    GtkWidget *gameItem;
    GtkWidget *heading;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    //检查指针
    if (!var)
        return;

    //获取比赛结果
    query = gtk_combo_box_get_active_id(GTK_COMBO_BOX(var));
    //获取数字(字符串转数字)
    sscanf(query, "%d", &result);
    //查询
    res = goQueryGameResult(games, result);

    heading    = gtk_label_new("搜索结果");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //调整控件属性
    gtk_widget_override_font(heading, headingFont);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    //没有搜索结果
    if (!res->arrayLen) {
        noResult = gtk_label_new("没有相对应的比赛");
        gtk_misc_set_alignment(GTK_MISC(noResult), 0, 0);
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    //把搜索到的结果添加进列表
    for (i=0; i<res->arrayLen; i++) {
        v = dynamicGet(res, i);
        g = (Game *)(v->v.pVoid);
        gameItem = goCreateGameListItem(g);

        //调整控件属性
        gtk_widget_set_margin_left(gameItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(gameItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), gameItem, FALSE, FALSE, 0);

        //连接信号
        g_signal_connect(G_OBJECT(gameItem), "clicked", G_CALLBACK(goViewShowGameInfo), v);
    }

    //隐藏查询框
    gtk_widget_hide(goGameResultQueryDialog);

    //更新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 显示编辑俱乐部对话框
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewShowClubEditDialog(GtkWidget *widget, gpointer *var)
{
    Club *c;
    Variant *v;
    GtkWidget *label;
    GtkWidget *nameLabel;
    GtkWidget *nameEntry;
    GtkWidget *nameBox;
    GtkWidget *coachLabel;
    GtkWidget *coachEntry;
    GtkWidget *coachBox;
    GtkWidget *box;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;
    GtkWidget *deleteBtn;
    InputChain *inputs;
    PangoFontDescription *labelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 16");

    //检查指针
    if (!var)
        return;

    //获取要更改的俱乐部
    v = (Variant *)var;
    c = (Club *)(v->v.pVoid);
    changingVariant = v;

    //实例化
    goClubEditDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label            = gtk_label_new("请填写修改后的俱乐部信息");
    nameLabel        = gtk_label_new("俱乐部名");
    nameEntry        = gtk_entry_new();
    nameBox          = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    coachLabel       = gtk_label_new("教练");
    coachEntry       = gtk_entry_new();
    coachBox         = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    box              = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    btnBox           = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn            = gtk_button_new_with_label("修改");
    cancelBtn        = gtk_button_new_with_label("取消");
    deleteBtn        = gtk_button_new_with_label("删除此俱乐部");

    //创建输入链表
    inputs              = goCreateInputChain();
    inputs->input       = nameEntry;
    inputs->next        = goCreateInputChain();
    inputs->next->input = coachEntry;

    //调整属性
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);
    gtk_widget_override_font(label, labelFont);

    //设置输入框内容
    gtk_entry_set_text(GTK_ENTRY(nameEntry), c->name);
    gtk_entry_set_text(GTK_ENTRY(coachEntry), c->coach);

    //设置边距
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(nameBox), nameLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(nameBox), nameEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(coachBox), coachLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(coachBox), coachEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), nameBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), coachBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), deleteBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goClubEditDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goUpdateClub), (gpointer *)inputs);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goDeleteWindow), (gpointer *)goClubEditDialog);
    g_signal_connect(G_OBJECT(deleteBtn), "clicked", G_CALLBACK(goViewDeleteClub), (gpointer *)changingVariant);

    //显示
    gtk_widget_show_all(goClubEditDialog);
}

/**
 * 显示编辑选手信息对话框
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewShowPlayerEditDialog(GtkWidget *widget, gpointer *var)
{
    int i;
    Club *c;
    Player *p;
    Variant *v;
    char text[80]; //用于拼接字符串
    GtkWidget *label;
    GtkWidget *nameLabel;
    GtkWidget *nameEntry;
    GtkWidget *nameBox;
    GtkWidget *clubLabel;
    GtkWidget *clubComboBoxText;
    GtkWidget *clubBox;
    GtkWidget *gradeLabel;
    GtkWidget *gradeComboBoxText;
    GtkWidget *gradeBox;
    GtkWidget *box;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;
    GtkWidget *deleteBtn;
    InputChain *inputs;
    PangoFontDescription *labelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 16");

    //检查指针
    if (!var)
        return;

    //获取要编辑的选手信息
    v = (Variant *)var;
    p = (Player *)(v->v.pVoid);
    changingVariant = v;

    //实例化
    goPlayerEditDialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label              = gtk_label_new("请输入修改后的选手信息");
    nameLabel          = gtk_label_new("姓名");
    nameEntry          = gtk_entry_new();
    nameBox            = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    clubLabel          = gtk_label_new("俱乐部");
    clubComboBoxText   = gtk_combo_box_text_new();
    clubBox            = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    gradeLabel         = gtk_label_new("段位");
    gradeComboBoxText  = gtk_combo_box_text_new();
    gradeBox           = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    box                = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    btnBox             = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_ROW_MARGIN);
    okBtn              = gtk_button_new_with_label("修改");
    cancelBtn          = gtk_button_new_with_label("取消");
    deleteBtn          = gtk_button_new_with_label("删除此选手");
    inputs             = goCreateInputChain();

    //调整控件属性
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);
    gtk_widget_override_font(label, labelFont);

    //设置选手姓名输入框
    gtk_entry_set_text(GTK_ENTRY(nameEntry), p->name);

    //填充俱乐部下拉框
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        //跳过删除的俱乐部
        if (!v->v.pVoid)
            continue;

        c = (Club *)(v->v.pVoid);

        sprintf(text, "%d", c->id);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(clubComboBoxText), text, c->name);
    }

    //默认选择当前在的俱乐部
    sprintf(text, "%d", p->clubId);
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(clubComboBoxText), text);

    //填充段位下拉框
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "1", goGradeName(1));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "2", goGradeName(2));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "3", goGradeName(3));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "4", goGradeName(4));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "5", goGradeName(5));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "6", goGradeName(6));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "7", goGradeName(7));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "8", goGradeName(8));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(gradeComboBoxText), "9", goGradeName(9));

    //默认选择当前段位
    sprintf(text, "%d", p->grade);
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(gradeComboBoxText), text);

    //设置边距
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);

    //创建输入链表
    inputs->input             = nameEntry;
    inputs->next              = goCreateInputChain();
    inputs->next->input       = clubComboBoxText;
    inputs->next->next        = goCreateInputChain();
    inputs->next->next->input = gradeComboBoxText;

    //添加控件
    gtk_box_pack_start(GTK_BOX(nameBox), nameLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(nameBox), nameEntry, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(clubBox), clubLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(clubBox), clubComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(gradeBox), gradeLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(gradeBox), gradeComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), nameBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), clubBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), gradeBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), deleteBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goPlayerEditDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goUpdatePlayer), (gpointer *)inputs);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goDeleteWindow), (gpointer *)goPlayerEditDialog);
    g_signal_connect(G_OBJECT(deleteBtn), "clicked", G_CALLBACK(goViewDeletePlayer), (gpointer *)changingVariant);

    //显示
    gtk_widget_show_all(goPlayerEditDialog);
}

/**
 * 显示比赛编辑对话框
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewShowGameEditDialog(GtkWidget *widget, gpointer *var)
{
    int i;
    Game *g;
    Player *p;
    Variant *v;
    char text[80];
    GtkWidget *label;
    GtkWidget *noLabel;
    GtkWidget *noComboBoxText;
    GtkWidget *noBox;
    GtkWidget *typeLabel;
    GtkWidget *typeComboBoxText;
    GtkWidget *typeBox;
    GtkWidget *blackPlayerLabel;
    GtkWidget *blackPlayerComboBoxText;
    GtkWidget *blackPlayerBox;
    GtkWidget *whitePlayerLabel;
    GtkWidget *whitePlayerComboBoxText;
    GtkWidget *whitePlayerBox;
    GtkWidget *resultLabel;
    GtkWidget *resultComboBoxText;
    GtkWidget *resultBox;
    GtkWidget *box;
    GtkWidget *btnBox;
    GtkWidget *okBtn;
    GtkWidget *cancelBtn;
    GtkWidget *deleteBtn;
    InputChain *inputs, *ic;
    PangoFontDescription *labelFont = pango_font_description_from_string ("WenQuanYi Micro Hei 16");

    //检查指针
    if (!var)
        return;

    //获取要编辑的比赛
    v = (Variant *)var;
    g = (Game *)(v->v.pVoid);
    changingVariant = v;

    //实例化
    goGameEditDialog        = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    label                   = gtk_label_new("请输入修改后的比赛信息");
    noLabel                 = gtk_label_new("场次");
    noComboBoxText          = gtk_combo_box_text_new();
    noBox                   = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    typeLabel               = gtk_label_new("类别");
    typeComboBoxText        = gtk_combo_box_text_new();
    typeBox                 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    blackPlayerLabel        = gtk_label_new("黑方");
    blackPlayerComboBoxText = gtk_combo_box_text_new();
    blackPlayerBox          = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    whitePlayerLabel        = gtk_label_new("白方");
    whitePlayerComboBoxText = gtk_combo_box_text_new();
    whitePlayerBox          = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    resultLabel             = gtk_label_new("结果");
    resultComboBoxText      = gtk_combo_box_text_new();
    resultBox               = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    box                     = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    btnBox                  = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    okBtn                   = gtk_button_new_with_label("修改");
    cancelBtn               = gtk_button_new_with_label("取消");
    deleteBtn               = gtk_button_new_with_label("删除此比赛");
    inputs                  = goCreateInputChain();

    //设置控件属性
    gtk_misc_set_alignment(GTK_MISC(label), 0, 0);
    gtk_widget_override_font(label, labelFont);

    //填充比赛场次下拉框
    for (i=1; i<=maxGameNo; i++) {
        sprintf(text, "%d", i);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(noComboBoxText), text, text);
    }

    //默认选择当前场次
    sprintf(text, "%d", g->no);
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(noComboBoxText), text);

    //填充比赛类别
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(typeComboBoxText), "0", "主将局");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(typeComboBoxText), "1", "快棋局");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(typeComboBoxText), "2", "普通局");

    //默认选择当前类别
    sprintf(text, "%d", g->type);
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(typeComboBoxText), text);

    //填充黑方选手下拉框
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        //跳过删除的选手
        if (!v->v.pVoid)
            continue;

        sprintf(text, "%d", p->id);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(blackPlayerComboBoxText), text, p->name);
    }

    //默认选择当前黑方选手
    sprintf(text, "%d", g->blackPlayerId);
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(blackPlayerComboBoxText), text);

    //填充白方选手下拉框
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        p = (Player *)(v->v.pVoid);
        //跳过删除的选手
        if (!v->v.pVoid)
            continue;

        sprintf(text, "%d", p->id);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(whitePlayerComboBoxText), text, p->name);
    }

    //默认选择当前白方选手
    sprintf(text, "%d", g->whitePlayerId);
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(whitePlayerComboBoxText), text);

    //填充比赛结果下拉框
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(resultComboBoxText), "0", "黑胜");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(resultComboBoxText), "1", "白胜");

    //默认选择当前比赛结果
    sprintf(text, "%d", g->result);
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(resultComboBoxText), text);

    //设置边距
    gtk_widget_set_margin_top(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_bottom(box, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(box, UNIFORM_MARGIN_LG);
    gtk_widget_set_margin_right(box, UNIFORM_MARGIN_LG);

    //创建输入链表
    ic = inputs;
    ic->input = noComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = typeComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = blackPlayerComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = whitePlayerComboBoxText;
    ic->next = goCreateInputChain();

    ic = ic->next;
    ic->input = resultComboBoxText;

    //添加控件
    gtk_box_pack_start(GTK_BOX(noBox), noLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(noBox), noComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(typeBox), typeLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(typeBox), typeComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(blackPlayerBox), blackPlayerLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(blackPlayerBox), blackPlayerComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(whitePlayerBox), whitePlayerLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(whitePlayerBox), whitePlayerComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(resultBox), resultLabel, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(resultBox), resultComboBoxText, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(btnBox), okBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(btnBox), cancelBtn, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), noBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), typeBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), blackPlayerBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), whitePlayerBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), resultBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), deleteBtn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), btnBox, FALSE, FALSE, 0);

    //添加布局
    gtk_container_add(GTK_CONTAINER(goGameEditDialog), box);

    //连接信号
    g_signal_connect(G_OBJECT(okBtn),     "clicked", G_CALLBACK(goUpdateGame), (gpointer *)inputs);
    g_signal_connect(G_OBJECT(cancelBtn), "clicked", G_CALLBACK(goDeleteWindow), (gpointer *)goGameEditDialog);
    g_signal_connect(G_OBJECT(deleteBtn), "clicked", G_CALLBACK(goViewDeleteGame), (gpointer *)changingVariant);

    //显示
    gtk_widget_show_all(goGameEditDialog);
}

/**
 * 更新俱乐部信息
 * @param widget 父控件
 * @param var    数据指针
 */
void goUpdateClub(GtkWidget *widget, gpointer *var)
{
    Club *c;
    const char *name;
    const char *coach;
    InputChain *inputs;

    //检查指针
    if (!changingVariant || !var)
        return;

    //获取要修改的俱乐部
    c = (Club *)(changingVariant->v.pVoid);
    inputs = (InputChain *)var;

    //获取俱乐部名字和教练名
    name  = gtk_entry_get_text(GTK_ENTRY(inputs->input));
    coach = gtk_entry_get_text(GTK_ENTRY(inputs->next->input));

    //printf("name %s\n", name);
    //printf("coach %s\n", coach);

    //替换数据
    free(c->name);
    c->name = (char *)malloc(sizeof(char)*strlen(name));
    strcpy(c->name, name);

    free(c->coach);
    c->coach = (char *)malloc(sizeof(char)*strlen(coach));
    strcpy(c->coach, coach);

    //标识俱乐部信息已被修改
    c->changed = 1;

    //刷新数据和菜单
    goRefreshData(data);
    goRefreshEditClubMenu();
    //显示修改后的俱乐部信息
    goViewShowClubInfo(goMainWindow, (gpointer *)changingVariant);

    gtk_widget_destroy(goClubEditDialog);
    goClubEditDialog = NULL;
}

/**
 * 更新选手信息
 * @param widget 父控件
 * @param var    数据指针
 */
void goUpdatePlayer(GtkWidget *widget, gpointer *var)
{
    Club *c;
    Player *p;
    const char *name;
    const char *club;
    const char *gradeStr;
    int grade;
    int clubId;
    Variant *v;
    InputChain *inputs;

    //检查指针
    if (!changingVariant || !var)
        return;

    //获取要修改的选手
    p = (Player *)(changingVariant->v.pVoid);
    inputs = (InputChain *)var;

    //获取数据
    name     = gtk_entry_get_text(GTK_ENTRY(inputs->input));
    club     = gtk_combo_box_get_active_id(GTK_COMBO_BOX(inputs->next->input));
    gradeStr = gtk_combo_box_get_active_id(GTK_COMBO_BOX(inputs->next->next->input));

    // printf("name %s\n", name);
    // printf("club %s\n", club);
    // printf("grade %s\n", gradeStr);

    //字符串转数字
    sscanf(club, "%d", &clubId);
    sscanf(gradeStr, "%d", &grade);

    //更新选手名
    free(p->name);
    p->name = (char *)malloc(sizeof(char)*strlen(name));
    strcpy(p->name, name);

    //更新俱乐部关系
    p->clubId = clubId;
    v = dynamicGet(clubs, clubId);
    c = (Club *)(v->v.pVoid);

    //替换数据
    free(p->clubName);
    p->clubName = (char *)malloc(sizeof(char)*strlen(c->name));
    strcpy(p->clubName, c->name);

    //更新段位信息
    p->grade = grade;

    //标识选手已被修改
    p->changed = 1;

    //刷新数据
    goRefreshData(data);
    goRefreshEditPlayerMenu();

    //显示修改后的选手信息
    goViewShowPlayerInfo(goMainWindow, (gpointer *)changingVariant);

    gtk_widget_destroy(goPlayerEditDialog);
    goPlayerEditDialog = NULL;
}

/**
 * 更新比赛信息
 * @param widget 父控件
 * @param var    数据指针
 */
void goUpdateGame(GtkWidget *widget, gpointer *var)
{
    Game *g;
    Player *p;
    Variant *v;
    int no;
    int type;
    int blackId;
    int whiteId;
    int result;
    const char *text;
    InputChain *inputs, *ic;

    //检查指针
    if (!changingVariant || !var)
        return;

    //获取要修改的比赛信息
    g = (Game *)(changingVariant->v.pVoid);
    inputs = (InputChain *)var;

    //更新场次
    ic = inputs;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &no);
    g->no = no;

    //更新类别
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &type);
    g->type = type;

    //更新黑方
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &blackId);
    g->blackPlayerId = blackId;

    v = dynamicGet(players, blackId);
    p = (Player *)(v->v.pVoid);
    free(g->blackPlayer);
    g->blackPlayer = (char *)malloc(sizeof(char)*strlen(p->name));
    strcpy(g->blackPlayer, p->name);

    //更新白方
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &whiteId);
    g->whitePlayerId = whiteId;

    v = dynamicGet(players, whiteId);
    p = (Player *)(v->v.pVoid);
    free(g->whitePlayer);
    g->whitePlayer = (char *)malloc(sizeof(char)*strlen(p->name));
    strcpy(g->whitePlayer, p->name);

    //更新比赛结果
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &result);
    g->result = result;

    //刷新数据和更新菜单
    goRefreshData(data);
    goRefreshEditGameMenu();

    //显示修改后的比赛信息
    goViewShowGameInfo(goMainWindow, (gpointer *)changingVariant);
    gtk_widget_destroy(goGameEditDialog);
    goGameEditDialog = NULL;
}

/**
 * 添加俱乐部
 * @param widget 父控件
 * @param var    数据指针
 */
void goAddClub(GtkWidget *widget, gpointer *var)
{
    Club *c;
    ClubListNode *cl;
    Variant *v;
    InputChain *inputs;
    const char *name;
    const char *coach;

    //检查指针
    if (!var)
        return;

    //获取输入链表
    inputs = (InputChain *)var;

    //获取数据
    name  = gtk_entry_get_text(GTK_ENTRY(inputs->input));
    coach = gtk_entry_get_text(GTK_ENTRY(inputs->next->input));

    //printf("name %s\n", name);
    //printf("coach %s\n", coach);

    //创建俱乐部
    c = goCreateClub();

    c->name = (char *)malloc(sizeof(char)*strlen(name));
    strcpy(c->name, name);

    c->coach = (char *)malloc(sizeof(char)*strlen(coach));
    strcpy(c->coach, coach);

    //标识俱乐部已被修改
    c->changed = 1;

    //在动态数组中添加
    v = createVariant();
    v->v.pVoid = (void *)c;
    dynamicAppend(&clubs, v);
    c->id = clubs->arrayLen - 1;

    //在链表中添加
    cl = goCreateClubList();
    cl->data = c;
    goInsertClubList(data, cl);

    //刷新数据和更新菜单
    goRefreshData(data);
    goRefreshEditClubMenu();

    //显示添加后的俱乐部信息
    goViewShowClubInfo(goMainWindow, (gpointer *)v);

    gtk_widget_destroy(goAddClubDialog);
    goAddClubDialog = NULL;
}

/**
 * 添加选手
 * @param widget 父控件
 * @param var    数据指针
 */
void goAddPlayer(GtkWidget *widget, gpointer *var)
{
    PlayerListNode *pl;
    ClubListNode *cl;
    Player *p;
    InputChain *inputs;
    const char *name;
    const char *club;
    const char *gradeStr;
    int grade;
    int clubId;
    Variant *v;
    Club *c;

    //检查指针
    if (!var)
        return;

    //获取输入链表
    inputs = (InputChain *)var;

    //获取数据
    name     = gtk_entry_get_text(GTK_ENTRY(inputs->input));
    club     = gtk_combo_box_get_active_id(GTK_COMBO_BOX(inputs->next->input));
    gradeStr = gtk_combo_box_get_active_id(GTK_COMBO_BOX(inputs->next->next->input));

    // printf("name %s\n", name);
    // printf("club %s\n", club);
    // printf("grade %s\n", gradeStr);

    //字符串转数字
    sscanf(club, "%d", &clubId);
    sscanf(gradeStr, "%d", &grade);

    p = goCreatePlayer();

    //更新选手名
    p->name = (char *)malloc(sizeof(char)*strlen(name));
    strcpy(p->name, name);

    //更新俱乐部关系
    p->clubId = clubId;
    v = dynamicGet(clubs, clubId);
    c = (Club *)(v->v.pVoid);

    p->clubName = (char *)malloc(sizeof(char)*strlen(c->name));
    strcpy(p->clubName, c->name);

    //更新段位信息
    p->grade = grade;

    //标识选手已被更新
    p->changed = 1;

    //在动态数组中添加
    v = createVariant();
    v->v.pVoid = (void *)p;
    dynamicAppend(&players, v);
    dynamicAppend(&sortedPlayers, v);
    p->id = players->arrayLen-1;

    //在链表中添加
    cl = goSearchClubName(data, c->name);
    pl = goCreatePlayerList();
    pl->data = p;
    goInsertPlayerList(cl->playerListHead, pl);

    //更新数据和更新菜单
    goRefreshData(data);
    goRefreshEditPlayerMenu();

    //显示添加后的选手信息
    goViewShowPlayerInfo(goMainWindow, (gpointer *)v);

    gtk_widget_destroy(goAddPlayerDialog);
    goAddPlayerDialog = NULL;
}

/**
 * 添加比赛
 * @param widget 父控件
 * @param var    数据指针
 */
void goAddGame(GtkWidget *widget, gpointer *var)
{
    Game *g;
    Player *p;
    Variant *v;
    PlayerListNode *pl;
    GameListNode *gl;
    InputChain *inputs, *ic;
    int no;
    int type;
    int blackId;
    int whiteId;
    int result;
    const char *text;

    //检查指针
    if (!var)
        return;

    //获取输入链表
    inputs = (InputChain *)var;

    g = goCreateGame();

    //更新场次
    ic = inputs;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &no);
    g->no = no;

    //更新类别
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &type);
    g->type = type;

    //更新黑方
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &blackId);
    g->blackPlayerId = blackId;

    v = dynamicGet(players, blackId);
    p = (Player *)(v->v.pVoid);
    g->blackPlayer = (char *)malloc(sizeof(char)*strlen(p->name));
    strcpy(g->blackPlayer, p->name);

    //更新白方
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &whiteId);
    g->whitePlayerId = whiteId;

    v = dynamicGet(players, whiteId);
    p = (Player *)(v->v.pVoid);
    g->whitePlayer = (char *)malloc(sizeof(char)*strlen(p->name));
    strcpy(g->whitePlayer, p->name);

    //更新比赛结果
    ic = ic->next;
    text = gtk_combo_box_get_active_id(GTK_COMBO_BOX(ic->input));
    sscanf(text, "%d", &result);
    g->result = result;

    //在动态数组中添加
    v = createVariant();
    v->v.pVoid = (void *)g;
    dynamicAppend(&clubs, v);
    g->id = clubs->arrayLen - 1;

    //在链表中添加
    gl = goCreateGameList();
    gl->data = g;
    pl = goSearchPlayerName(data, g->blackPlayer);
    goInsertGameList(pl->gameListHead, gl);
    pl = goSearchPlayerName(data, g->whitePlayer);
    goInsertGameList(pl->gameListHead, gl);

    goRefreshData(data);
    goRefreshEditGameMenu();

    goViewShowGameInfo(goMainWindow, (gpointer *)v);
    gtk_widget_destroy(goAddGameDialog);
    goAddGameDialog = NULL;
}

/**
 * 删除俱乐部
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewDeleteClub(GtkWidget *widget, gpointer *var)
{
    Variant *v;
    Club *c;
    GtkWidget *dialog;
    gint result = 0;

    //获取要删除的俱乐部
    v = (Variant *)var;
    c = (Club *)(v->v.pVoid);

    //显示确认对话框
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_OK_CANCEL,
                                    "确定要删除%s么?", c->name);
    gtk_window_set_title(GTK_WINDOW(dialog), "确认删除俱乐部");
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (GTK_RESPONSE_OK == result) {
        //删除俱乐部
        goDeleteClub(data, c->id);
        //刷新菜单
        goRefreshEditClubMenu();
    }

    gtk_widget_hide(goClubEditDialog);
}

/**
 * 删除选手
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewDeletePlayer(GtkWidget *widget, gpointer *var)
{
    Variant *v;
    Player *p;
    GtkWidget *dialog;
    gint result = 0;

    //获取要删除的选手
    v = (Variant *)var;
    p = (Player *)(v->v.pVoid);
    //显示确认对话框
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_OK_CANCEL,
                                    "确定要删除%s么?", p->name);
    gtk_window_set_title(GTK_WINDOW(dialog), "确认删除选手");
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (GTK_RESPONSE_OK == result) {
        //删除选手
        goDeletePlayer(data, p->id);
        //更新菜单
        goRefreshEditPlayerMenu();
    }

    gtk_widget_hide(goPlayerEditDialog);
}

/**
 * 删除比赛
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewDeleteGame(GtkWidget *widget, gpointer *var)
{
    Variant *v;
    Game *g;
    GtkWidget *dialog;
    gint result = 0;

    //获取要删除的比赛
    v = (Variant *)var;
    g = (Game *)(v->v.pVoid);
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_OK_CANCEL,
                                    "确定要删除%s对阵%s的比赛么?", g->blackPlayer, g->whitePlayer);
    gtk_window_set_title(GTK_WINDOW(dialog), "确认删除比赛");
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (GTK_RESPONSE_OK == result) {
        goDeleteGame(data, g->id);
        goRefreshEditGameMenu();
    }

    gtk_widget_hide(goGameEditDialog);
}

void goViewShowWindow(GtkWidget *widget, gpointer *var)
{
    if (!var)
        return;

    gtk_widget_show_all(GTK_WIDGET(var));
}

GtkWidget *goCreateClubListItem(Club *c)
{
    PangoFontDescription *font_desc = pango_font_description_from_string ("WenQuanYi Micro Hei 15");
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
    PangoFontDescription *font_desc = pango_font_description_from_string ("WenQuanYi Micro Hei 15");
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
    PangoFontDescription *font_desc = pango_font_description_from_string ("WenQuanYi Micro Hei 15");
    char label[80] = {0};
    GtkWidget *li;

    if (!p)
        return NULL;

    sprintf(label, "   %s\t\t%s", p->name, goGradeName(p->grade));

    li = gtk_button_new_with_label(label);

    gtk_button_set_alignment(GTK_BUTTON(li), 0, 0.5);
    gtk_widget_override_font(li, font_desc);
    gtk_widget_set_size_request(li, 200, 80);

    return li;
}

GtkWidget *goCreateGameListItem(Game *g)
{
    PangoFontDescription *font = pango_font_description_from_string ("WenQuanYi Micro Hei 15");
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
    PangoFontDescription *font = pango_font_description_from_string ("WenQuanYi Micro Hei 15");
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

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    clubNameLabel = gtk_label_new(c->name);
    gtk_misc_set_alignment(GTK_MISC(clubNameLabel), 0, 0);
    gtk_widget_set_margin_left(clubNameLabel, UNIFORM_MARGIN_MD);
    gtk_widget_override_font(clubNameLabel, clubNameLabelFont);

    sprintf(label, "教练:%s", c->coach);
    clubCoachLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubCoachLabel), 0, 0);
    gtk_widget_set_margin_left(clubCoachLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "局分:%d", c->roundScore);
    clubRoundScoreLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubRoundScoreLabel), 0, 0);
    gtk_widget_set_margin_left(clubRoundScoreLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "场分:%d", c->gameScore);
    clubGameScoreLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubGameScoreLabel), 0, 0);
    gtk_widget_set_margin_left(clubGameScoreLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "胜局数:%d", c->blackWinNum + c->whiteWinNum);
    clubWinLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubWinLabel), 0, 0);
    gtk_widget_set_margin_left(clubWinLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "负局数:%d", c->blackRoundNum + c->whiteRoundNum - c->blackWinNum - c->whiteWinNum);
    clubLoseLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubLoseLabel), 0, 0);
    gtk_widget_set_margin_left(clubLoseLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "排名:%d", c->ranking);
    clubRankLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(clubRankLabel), 0, 0);
    gtk_widget_set_margin_left(clubRankLabel, UNIFORM_MARGIN_MD);

    clubPlayerListLabel = gtk_label_new("选手列表");
    gtk_misc_set_alignment(GTK_MISC(clubPlayerListLabel), 0, 0);
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

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    v = (Variant *)var;
    p = (Player *)(v->v.pVoid);
    pl = goSearchPlayerName(data, p->name);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    playerNameLabel = gtk_label_new(p->name);
    gtk_misc_set_alignment(GTK_MISC(playerNameLabel), 0, 0);
    gtk_widget_set_margin_left(playerNameLabel, UNIFORM_MARGIN_MD);
    gtk_widget_override_font(playerNameLabel, playerNameLabelFont);

    sprintf(label, "%d段", p->grade);
    gradeLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(gradeLabel), 0, 0);
    gtk_widget_set_margin_left(gradeLabel, UNIFORM_MARGIN_MD);

    clubNameLabel = gtk_label_new(p->clubName);
    gtk_misc_set_alignment(GTK_MISC(clubNameLabel), 0, 0);
    gtk_widget_set_margin_left(clubNameLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "参赛局数:%d", p->roundNum);
    totalRoundNumLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(totalRoundNumLabel), 0, 0);
    gtk_widget_set_margin_left(totalRoundNumLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "胜局数:%d", p->winNum);
    winNumLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(winNumLabel), 0, 0);
    gtk_widget_set_margin_left(winNumLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "负局数:%d", p->roundNum - p->winNum);
    loseNumLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(loseNumLabel), 0, 0);
    gtk_widget_set_margin_left(loseNumLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "胜率:%.2f%%", p->winRate*100.0);
    winRateLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(winRateLabel), 0, 0);
    gtk_widget_set_margin_left(winRateLabel, UNIFORM_MARGIN_MD);

    gameListLabel = gtk_label_new("比赛列表");
    gtk_misc_set_alignment(GTK_MISC(gameListLabel), 0, 0);
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
        gameListItem = goCreateGameListItemPlayerInfo(gl->data, p);

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

    contentBox      = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    table           = gtk_grid_new();
    tableBox        = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    heading         = gtk_label_new("俱乐部排行榜");
    rankLabel       = gtk_label_new("排名");
    nameLabel       = gtk_label_new("俱乐部名");
    gameScoreLabel  = gtk_label_new("场分");
    roundScoreLabel = gtk_label_new("局分");
    winLabel        = gtk_label_new("胜局数");
    loseLabel       = gtk_label_new("负局数");

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

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

    gtk_widget_set_hexpand(rankLabel,       TRUE);
    gtk_widget_set_hexpand(nameLabel,       TRUE);
    gtk_widget_set_hexpand(gameScoreLabel,  TRUE);
    gtk_widget_set_hexpand(roundScoreLabel, TRUE);
    gtk_widget_set_hexpand(winLabel,        TRUE);
    gtk_widget_set_hexpand(loseLabel,       TRUE);

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

    contentBox    = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    table         = gtk_grid_new();
    tableBox      = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, UNIFORM_COLUMN_MARGIN);
    heading       = gtk_label_new("选手排行榜");
    rankLabel     = gtk_label_new("排名");
    nameLabel     = gtk_label_new("选手");
    clubLabel     = gtk_label_new("俱乐部");
    rateLabel     = gtk_label_new("胜率");
    winLabel      = gtk_label_new("胜局数");
    loseLabel     = gtk_label_new("负局数");
    roundNumLabel = gtk_label_new("参赛局数");

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

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

    heading    = gtk_label_new("选手段位统计");
    table      = gtk_grid_new();
    gradeLabel = gtk_label_new("段位");
    numLabel   = gtk_label_new("人数");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

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

    heading         = gtk_label_new("俱乐部详细统计");
    table           = gtk_grid_new();
    nameLabel       = gtk_label_new("俱乐部");
    masterWinLabel  = gtk_label_new("主将局胜局数");
    fastWinLabel    = gtk_label_new("快棋局胜局数");
    blackRoundLabel = gtk_label_new("棋手执黑棋数");
    blackWinLabel   = gtk_label_new("执黑胜数");
    whiteRoundLabel = gtk_label_new("棋手执白棋数");
    whiteWinLabel   = gtk_label_new("执白胜数");
    contentBox      = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

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

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_LG, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

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

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_misc_set_alignment(GTK_MISC(noLabel), 0, 0);
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
    gtk_misc_set_alignment(GTK_MISC(typeLabel), 0, 0);
    gtk_widget_set_margin_left(typeLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "执黑棋手:%s", g->blackPlayer);
    blackPlayerLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(blackPlayerLabel), 0, 0);
    gtk_widget_set_margin_left(blackPlayerLabel, UNIFORM_MARGIN_MD);

    sprintf(label, "执白棋手:%s", g->whitePlayer);
    whitePlayerLabel = gtk_label_new(label);
    gtk_misc_set_alignment(GTK_MISC(whitePlayerLabel), 0, 0);
    gtk_widget_set_margin_left(whitePlayerLabel, UNIFORM_MARGIN_MD);


    switch (g->result) {
    case 0:
        resultLabel = gtk_label_new("黑胜");
        break;
    case 1:
        resultLabel = gtk_label_new("白胜");
        break;
    }
    gtk_misc_set_alignment(GTK_MISC(resultLabel), 0, 0);
    gtk_widget_set_margin_left(resultLabel, UNIFORM_MARGIN_MD);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

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
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");

    GtkWidget *heading;
    GtkWidget *guide;
    GtkWidget *viewAllClubsBtn;
    GtkWidget *viewAllPlayersBtn;
    GtkWidget *viewAllGamesBtn;
    GtkWidget *contentBox;

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    heading           = gtk_label_new("接下来");
    guide             = gtk_label_new("数据载入成功,你可以");
    viewAllClubsBtn   = gtk_button_new_with_label("查看所有俱乐部");
    viewAllPlayersBtn = gtk_button_new_with_label("查看所有选手");
    viewAllGamesBtn   = gtk_button_new_with_label("查看所有棋局");

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_widget_override_font(heading, headingFont);

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(guide, UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_misc_set_alignment(GTK_MISC(guide), 0, 0);
    gtk_widget_set_margin_left(viewAllClubsBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(viewAllPlayersBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_left(viewAllGamesBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(viewAllClubsBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(viewAllPlayersBtn, UNIFORM_MARGIN_MD);
    gtk_widget_set_margin_right(viewAllGamesBtn, UNIFORM_MARGIN_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), guide, FALSE, FALSE, 0);
    gtk_widget_set_size_request(viewAllClubsBtn, 200, 50);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllClubsBtn, FALSE, FALSE, 0);
    gtk_widget_set_size_request(viewAllPlayersBtn, 200, 50);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllPlayersBtn, FALSE, FALSE, 0);
    gtk_widget_set_size_request(viewAllGamesBtn, 200, 50);
    gtk_box_pack_start(GTK_BOX(contentBox), viewAllGamesBtn, FALSE, FALSE, 0);

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
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    PangoFontDescription *descriptionFont = pango_font_description_from_string ("WenQuanYi Micro Hei 12");

    GtkWidget *spacer;
    GtkWidget *heading;
    GtkWidget *description;
    GtkWidget *hgoViewLoadingBox;
    GtkWidget *goViewLoadLabel;
    GtkWidget *goViewLoadButton;
    GtkWidget *align;
    GtkWidget *contentBox;

    contentBox        = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);
    hgoViewLoadingBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    align             = gtk_alignment_new(0.5, 0, 0, 0);
    goViewLoadLabel   = gtk_label_new("系统已经准备好");
    goViewLoadButton  = gtk_button_new_with_label("载入数据");
    spacer            = gtk_label_new("");
    heading           = gtk_label_new("欢迎");
    description       = gtk_label_new("纸豪出品,更多关于我的信息,请猛戳帮助");

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

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
    int noClub = 1;
    GtkWidget *heading;
    GtkWidget *clubListItem;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    Variant *v;
    Club *c;
    if (!clubs)
        return;

    heading = gtk_label_new("俱乐部");

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_override_font(heading, headingFont);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        //跳过删除了的俱乐部
        if (!v->v.pVoid)
            continue;
        c = (Club *)(v->v.pVoid);
        clubListItem = goCreateClubListItem(c);

        gtk_widget_set_margin_left(clubListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(clubListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), clubListItem, FALSE, FALSE, 0);
        g_signal_connect(G_OBJECT(clubListItem), "clicked", G_CALLBACK(goViewShowClubInfo), (gpointer *)v);
        noClub = 0;
    }

    //没有俱乐部
    if (noClub) {
        noResult = gtk_label_new("还没有俱乐部");
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
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
    int noPlayer = 1;
    GtkWidget *heading;
    GtkWidget *playerListItem;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    Variant *v;
    Player *p;
    if (!players)
        return;

    heading = gtk_label_new("选手");

    gtk_widget_set_margin_left(GTK_WIDGET(heading), UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_override_font(heading, headingFont);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        //跳过删除了的选手
        if (!v->v.pVoid)
            continue;
        p = (Player *)(v->v.pVoid);
        playerListItem = goCreatePlayerListItem(p);

        gtk_widget_set_margin_left(playerListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(playerListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), playerListItem, FALSE, FALSE, 0);
        g_signal_connect(G_OBJECT(playerListItem), "clicked", G_CALLBACK(goViewShowPlayerInfo), v);
        noPlayer = 0;
    }

    //没有选手
    if (noPlayer) {
        noResult = gtk_label_new("还没有选手");
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
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
    int noGame = 1;
    GtkWidget *heading;
    GtkWidget *gameListItem;
    GtkWidget *contentBox;
    GtkWidget *noResult;
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    Variant *v;
    Game *g;
    if (!games)
        return;

    heading = gtk_label_new("棋局");

    gtk_widget_set_margin_left(heading, UNIFORM_MARGIN_MD);
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_widget_override_font(heading, headingFont);

    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    gtk_window_resize(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);

    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);

    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        //跳过删除了的比赛
        if (!v->v.pVoid)
            continue;
        g = (Game *)(v->v.pVoid);
        gameListItem = goCreateGameListItem(g);

        gtk_widget_set_margin_left(gameListItem, UNIFORM_MARGIN_MD);
        gtk_widget_set_margin_right(gameListItem, UNIFORM_MARGIN_MD);
        gtk_box_pack_start(GTK_BOX(contentBox), gameListItem, FALSE, FALSE, 0);
        g_signal_connect(G_OBJECT(gameListItem), "clicked", G_CALLBACK(goViewShowGameInfo), v);
        noGame = 0;
    }

    //没有比赛
    if (noGame) {
        noResult = gtk_label_new("还没有比赛");
        gtk_box_pack_start(GTK_BOX(contentBox), noResult, FALSE, FALSE, 0);
    }

    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
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

    if (goLoadData(CLUB_FILENAME, PLAYER_FILENAME, GAME_FILENAME)) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "载入数据成功");

        goRefreshEditClubMenu();
        goRefreshEditPlayerMenu();
        goRefreshEditGameMenu();

        //调用显示函数使新加的菜单显示出来
        //gtk_widget_show_all(goMainWindow);

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

/**
 * 隐藏窗口
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewHideWindow(GtkWidget *widget, gpointer *var)
{
    if (!var)
        return;

    gtk_widget_hide(GTK_WIDGET(var));
}

/**
 * 销毁界面
 * @param widget 父控件
 * @param var    数据指针
 */
void goDeleteWindow(GtkWidget *widget, gpointer *var)
{
    if (!var)
        return;

    gtk_widget_destroy(GTK_WIDGET(var));
}

/**
 * 初始化界面
 * @param argc 参数个数
 * @param argv 参数列表指针
 */
void goInitWindows(int *argc, char ***argv)
{
    goViewStated = 0;

    gtk_init(argc, argv);

    //实例化窗口
    goMainWindow            = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //实例化主布局
    goMainBox               = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);

    gtk_container_add(GTK_CONTAINER(goMainWindow), goMainBox);

    //实例化菜单
    goMenu                  = gtk_menu_bar_new();

    goMenuSystem            = gtk_menu_item_new_with_label("系统");
    goMenuSystemSub         = gtk_menu_new();
    goMenuSystemBackup      = gtk_menu_item_new_with_label("备份数据");
    goMenuSystemRecover     = gtk_menu_item_new_with_label("从备份数据恢复");
    goMenuSystemgoViewLoad  = gtk_menu_item_new_with_label("载入数据");
    goMenuSystemgoViewQuit  = gtk_menu_item_new_with_label("退出");

    goMenuQuery             = gtk_menu_item_new_with_label("查询");
    goMenuQuerySub          = gtk_menu_new();

    goMenuQueryClub         = gtk_menu_item_new_with_label("俱乐部");
    goMenuQueryClubSub      = gtk_menu_new();
    goMenuQueryClubAll      = gtk_menu_item_new_with_label("显示所有俱乐部");
    goMenuQueryClubName     = gtk_menu_item_new_with_label("按名字查找俱乐部");

    goMenuQueryPlayer       = gtk_menu_item_new_with_label("选手");
    goMenuQueryPlayerSub    = gtk_menu_new();
    goMenuQueryPlayerAll    = gtk_menu_item_new_with_label("显示所有选手");
    goMenuQueryPlayerName   = gtk_menu_item_new_with_label("按名字查找选手");
    goMenuQueryPlayerClub   = gtk_menu_item_new_with_label("按俱乐部查找选手");
    goMenuQueryPlayerWinNum = gtk_menu_item_new_with_label("按胜局数查找选手");

    goMenuQueryGame         = gtk_menu_item_new_with_label("棋局");
    goMenuQueryGameSub      = gtk_menu_new();
    goMenuQueryGameAll      = gtk_menu_item_new_with_label("显示所有棋局");
    goMenuQueryGameNo       = gtk_menu_item_new_with_label("按棋局场次查找棋局");
    goMenuQueryGameBlack    = gtk_menu_item_new_with_label("按执黑选手查找棋局");
    goMenuQueryGameWhite    = gtk_menu_item_new_with_label("按执白选手查找棋局");
    goMenuQueryGameResult   = gtk_menu_item_new_with_label("按结果查找棋局");

    goMenuEdit              = gtk_menu_item_new_with_label("编辑");
    goMenuEditSub           = gtk_menu_new();
    goMenuEditClub          = gtk_menu_item_new_with_label("俱乐部");
    goMenuEditPlayer        = gtk_menu_item_new_with_label("选手");
    goMenuEditGame          = gtk_menu_item_new_with_label("棋局");
    goMenuEditAddClub       = gtk_menu_item_new_with_label("插入俱乐部");
    goMenuEditAddPlayer     = gtk_menu_item_new_with_label("插入选手");
    goMenuEditAddGame       = gtk_menu_item_new_with_label("插入比赛");

    goMenuStat              = gtk_menu_item_new_with_label("统计");
    goMenuStatSub           = gtk_menu_new();
    goMenuStatClub          = gtk_menu_item_new_with_label("俱乐部排行");
    goMenuStatPlayer        = gtk_menu_item_new_with_label("选手排行");
    goMenuStatGrade         = gtk_menu_item_new_with_label("段位统计");
    goMenuStatClubDetails   = gtk_menu_item_new_with_label("俱乐部具体棋局排行");

    goMenuHelp              = gtk_menu_item_new_with_label("帮助");
    goMenuHelpSub           = gtk_menu_new();
    goMenuHelpAbout         = gtk_menu_item_new_with_label("关于");

    //设置窗口属性
    gtk_window_set_position(GTK_WINDOW(goMainWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(goMainWindow), MAIN_WINDOW_DEFAULT_WIDTH_MD, MAIN_WINDOW_DEFAULT_HEIGHT_MD);
    gtk_window_set_title(GTK_WINDOW(goMainWindow), MAIN_WINDOW_TITLE);
    gtk_window_set_icon(GTK_WINDOW(goMainWindow), createPixBuf("icon.png"));

    //添加系统菜单
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuSystem), goMenuSystemSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuSystemSub), goMenuSystemgoViewLoad);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuSystemSub), goMenuSystemBackup);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuSystemSub), goMenuSystemRecover);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuSystemSub), goMenuSystemgoViewQuit);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuSystem);

    //添加查询菜单
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

    //添加编辑菜单
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuEdit), goMenuEditSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditPlayer);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditGame);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditAddClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditAddPlayer);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuEditSub), goMenuEditAddGame);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuEdit);

    //添加统计菜单
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuStat), goMenuStatSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatClub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatPlayer);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatGrade);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuStatSub), goMenuStatClubDetails);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuStat);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuHelp), goMenuHelpSub);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenuHelpSub), goMenuHelpAbout);
    gtk_menu_shell_append(GTK_MENU_SHELL(goMenu), goMenuHelp);

    //连接信号
    g_signal_connect(G_OBJECT(goMainWindow),            "delete_event", G_CALLBACK(goViewQuit), NULL);
    g_signal_connect(G_OBJECT(goMenuSystemgoViewQuit),  "activate", G_CALLBACK(goViewQuit), NULL);
    g_signal_connect(G_OBJECT(goMenuSystemgoViewLoad),  "activate", G_CALLBACK(goViewLoad), NULL);
    g_signal_connect(G_OBJECT(goMenuSystemBackup),      "activate", G_CALLBACK(goViewBackup), NULL);
    g_signal_connect(G_OBJECT(goMenuSystemRecover),     "activate", G_CALLBACK(goViewRecover), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryClubAll),      "activate", G_CALLBACK(goViewShowAllClubs), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerAll),    "activate", G_CALLBACK(goViewShowAllPlayers), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryGameAll),      "activate", G_CALLBACK(goViewShowAllGames), NULL);
    g_signal_connect(G_OBJECT(goMenuStatClub),          "activate", G_CALLBACK(goViewClubRankList), NULL);
    g_signal_connect(G_OBJECT(goMenuStatPlayer),        "activate", G_CALLBACK(goViewPlayerRankList), NULL);
    g_signal_connect(G_OBJECT(goMenuStatGrade),         "activate", G_CALLBACK(goViewGradeStatList), NULL);
    g_signal_connect(G_OBJECT(goMenuStatClubDetails),   "activate", G_CALLBACK(goViewStatClubDetails), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryClubName),     "activate", G_CALLBACK(goViewShowClubNameQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerName),   "activate", G_CALLBACK(goViewShowPlayerNameQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerClub),   "activate", G_CALLBACK(goViewShowPlayerClubQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryPlayerWinNum), "activate", G_CALLBACK(goViewShowPlayerWinQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryGameNo),       "activate", G_CALLBACK(goViewShowGameNoQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryGameBlack),    "activate", G_CALLBACK(goViewShowGameBlackQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryGameWhite),    "activate", G_CALLBACK(goViewShowGameWhiteQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuQueryGameResult),   "activate", G_CALLBACK(goViewShowGameResultQueryDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuEditAddClub),       "activate", G_CALLBACK(goViewShowAddClubDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuEditAddPlayer),     "activate", G_CALLBACK(goViewShowAddPlayerDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuEditAddGame),       "activate", G_CALLBACK(goViewShowAddGameDialog), NULL);
    g_signal_connect(G_OBJECT(goMenuHelpAbout),         "activate", G_CALLBACK(goViewAbout), NULL);

    gtk_box_pack_start(GTK_BOX(goMainBox), goMenu, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);

    //显示
    gtk_widget_show_all(goMainWindow);

    //显示欢迎界面
    goViewWelcome();

    gtk_main();
}

/**
 * 备份
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewBackup(GtkWidget *widget, gpointer *var)
{
    GtkWidget *dialog;
    int result;

    //确认备份对话框
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_OK_CANCEL,
                                    "将备份到%s %s %s", CLUB_BACKUP_FILENAME, PLAYER_BACKUP_FILENAME, GAME_BACKUP_FILENAME);
    gtk_window_set_title(GTK_WINDOW(dialog), "备份");
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    //选择ok备份
    if (GTK_RESPONSE_OK == result)
        goBackup();
}

/**
 * 从备份文件恢复数据
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewRecover(GtkWidget *widget, gpointer *var)
{
    int result;
    GtkWidget *dialog;

    //显示确认对话框
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_OK_CANCEL,
                                    "将从%s %s %s文件恢复", CLUB_BACKUP_FILENAME, PLAYER_BACKUP_FILENAME, GAME_BACKUP_FILENAME);
    gtk_window_set_title(GTK_WINDOW(dialog), "恢复备份");
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (GTK_RESPONSE_CANCEL == result)
        return;

    //载入数据
    if (goLoadData(CLUB_BACKUP_FILENAME, PLAYER_BACKUP_FILENAME, GAME_BACKUP_FILENAME)) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "载入数据成功");

        goRefreshEditClubMenu();
        goRefreshEditPlayerMenu();
        goRefreshEditGameMenu();

        //调用显示函数使新加的菜单显示出来
        //gtk_widget_show_all(goMainWindow);

    } else {
        //载入数据失败
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

    //显示选择菜单项
    goViewQuerySelection();
}

/**
 * 刷新俱乐部编辑菜单
 */
void goRefreshEditClubMenu(void)
{
    int i;
    Variant *v;
    Club *c;
    GtkWidget *submenu;
    GtkWidget *submenuItem;
    //在修改菜单中添加所有俱乐部
    submenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuEditClub), submenu);
    for (i=0; i<clubs->arrayLen; i++) {
        v = dynamicGet(clubs, i);
        //跳过已被删除的俱乐部
        if (!v->v.pVoid)
            continue;
        c = (Club *)(v->v.pVoid);
        submenuItem = gtk_menu_item_new_with_label(c->name);
        gtk_menu_shell_append(GTK_MENU_SHELL(submenu), submenuItem);
        g_signal_connect(G_OBJECT(submenuItem), "activate", G_CALLBACK(goViewShowClubEditDialog), v);
    }
    gtk_widget_show_all(submenu);
}

/**
 * 刷新选手编辑菜单
 */
void goRefreshEditPlayerMenu(void)
{
    int i;
    Variant *v;
    Player *p;
    GtkWidget *submenu;
    GtkWidget *submenuItem;
    submenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuEditPlayer), submenu);
    for (i=0; i<players->arrayLen; i++) {
        v = dynamicGet(players, i);
        //跳过已被删除的选手
        if (!v->v.pVoid)
            continue;
        p = (Player *)(v->v.pVoid);
        submenuItem = gtk_menu_item_new_with_label(p->name);
        gtk_menu_shell_append(GTK_MENU_SHELL(submenu), submenuItem);
        g_signal_connect(G_OBJECT(submenuItem), "activate", G_CALLBACK(goViewShowPlayerEditDialog), v);
    }
    gtk_widget_show_all(submenu);
}

/**
 * 刷新比赛编辑菜单
 */
void goRefreshEditGameMenu(void)
{
    int i;
    char label[80] = {0};
    Variant *v;
    Game *g;
    GtkWidget *submenu;
    GtkWidget *submenuItem;
    submenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(goMenuEditGame), submenu);
    for (i=0; i<games->arrayLen; i++) {
        v = dynamicGet(games, i);
        //跳过已被删除的比赛
        if (!v->v.pVoid)
            continue;
        g = (Game *)(v->v.pVoid);
        sprintf(label, "第%d轮 黑:%s 白:%s", g->no, g->blackPlayer, g->whitePlayer);
        submenuItem = gtk_menu_item_new_with_label(label);
        gtk_menu_shell_append(GTK_MENU_SHELL(submenu), submenuItem);
        g_signal_connect(G_OBJECT(submenuItem), "activate", G_CALLBACK(goViewShowGameEditDialog), v);
    }
    gtk_widget_show_all(submenu);
}

/**
 * 显示关于
 * @param widget 父控件
 * @param var    数据指针
 */
void goViewAbout(GtkWidget *widget, gpointer *var)
{
    //字体
    PangoFontDescription *headingFont = pango_font_description_from_string ("WenQuanYi Micro Hei 30");
    PangoFontDescription *aboutFont = pango_font_description_from_string ("WenQuanYi Micro Hei 14");
    GtkWidget *heading;
    GtkWidget *about;
    GtkWidget *contentBox;

    //实例化
    heading    = gtk_label_new("关于");
    about      = gtk_label_new("冀子豪\n计科九班\nU201315042\n2014.9.1");
    contentBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, UNIFORM_ROW_MARGIN);

    //设置控件属性
    gtk_misc_set_alignment(GTK_MISC(heading), 0, 0);
    gtk_misc_set_alignment(GTK_MISC(about), 0, 0);
    gtk_widget_override_font(heading, headingFont);
    gtk_widget_override_font(about, aboutFont);
    gtk_widget_set_margin_left(contentBox, UNIFORM_MARGIN_MD);

    //添加控件
    gtk_box_pack_start(GTK_BOX(contentBox), heading, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contentBox), about, FALSE, FALSE, 0);

    //更新界面
    gtk_container_remove(GTK_CONTAINER(goMainBox), goContentScrolledWindow);
    goContentScrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(goContentScrolledWindow), contentBox);
    gtk_box_pack_start(GTK_BOX(goMainBox), goContentScrolledWindow, TRUE, TRUE, 0);
    gtk_widget_show_all(goContentScrolledWindow);
}

/**
 * 创建gtk图像缓冲
 * @param  filename 文件名
 * @return          图像缓冲
 */
GdkPixbuf *createPixBuf(const gchar* filename)
{
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if(!pixbuf) {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}
