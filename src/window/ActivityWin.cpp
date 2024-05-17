#include "../public.h"

ActivityWin::ActivityWin() {
}

ActivityWin::ActivityWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(startX + width - 7, startY - 1, 0, 0, "活动管理系统");
    this->title_Label = new CLabel(startX + width - 5, startY + 1, 0, 0, "活动主页");
    this->system_Label = new CLabel(startX + width - 5, startY + 13, 0, 0, "Activity Management System");

    view_activity_Button = new CButton(startX + width - 60, startY + 24, 9, 5, "1. 浏览活动", 4);
    creat_activity_Button = new CButton(startX + width - 40, startY + 24, 9, 5, "2. 创建活动", 4);
    my_creat_Button = new CButton(startX + width - 20, startY + 24, 9, 5, "3. 我的创建", 4);
    my_attend_Button = new CButton(startX + width, startY + 24, 9, 5, "4. 我的参加", 4);
    statistics_activity_Button = new CButton(startX + width + 20, startY + 24, 9, 5, "5. 统计功能", 4);
    exit_Button = new CButton(startX + width + 40, startY + 24, 9, 5, "0. 返    回", 4);
}

ActivityWin::~ActivityWin() {
}

void ActivityWin::scau() {
    //37*5 scau
    string scau[10] = {
            "████████╗ ███████╗ ██████╗ ██╗    ██╗\n",
            "██╔═════╝██╔═════╝██╔═══██╗██║    ██║\n",
            "████████╗██║      ████████║██║    ██║\n",
            "╚═════██║██║      ██╔═══██║██║    ██║\n",
            "████████║╚███████╗██║   ██║ ███████╔╝\n",
            "╚═══════╝ ╚══════╝╚═╝   ╚═╝  ╚═════╝\n"
    };
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(5));
    for (int i = 0; i < 6; ++i) {
        CTools::goto_xy(startX + width - 19, startY + 6 + i);
        Sleep(1);
        cout << scau[i];
    }
}

void ActivityWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);
    this->title_Label->show(2);

    scau();
    this->system_Label->show(5);

}

void ActivityWin::print(int option) {
    switch (option) {//覆盖，实现退选
        case 1:
            cout << "1. 浏览活动" << endl;
            break;
        case 2:
            cout << "2. 创建活动" << endl;
            break;
        case 3:
            cout << "3. 我的创建" << endl;
            break;
        case 4:
            cout << "4. 我的参加" << endl;
            break;
        case 5:
            cout << "5. 统计功能" << endl;
            break;
        case 0:
            cout << "0. 返    回" << endl;
            break;
    }
    return;
}

void ActivityWin::updateOption(int &option, int x) {
    if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)
        option = 1;
    else if (x == startX + width - 40 + (9 * 2 - 11) / 2 - 1)
        option = 2;
    else if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)
        option = 3;
    else if (x == startX + width + (9 * 2 - 11) / 2 - 1)
        option = 4;
    else if (x == startX + width + 20 + (9 * 2 - 11) / 2 - 1)
        option = 5;
    else option = 0;
}

int ActivityWin::choose() {
    int option = -1;          //选择功能号 0返回 1浏览活动 2创建活动 3我的活动 4我的参加 5统计功能
    char key;
    int x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
    int y = startY + 24 + 5 / 2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '5') {//数字键选择
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                return option;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//光标移动到 1. 浏览活动
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//覆盖，实现退选
                if (x == startX + width + 40 + (9 * 2 - 11) / 2 - 1)//如果已经到了0. 返    回，则跳转1. 浏览活动，实现滚动高亮
                    x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
                else
                    x += 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, x);
                print(option);//覆盖，实现选择
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//覆盖，实现退选
                if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)//如果已经到了1. 浏览活动，则跳转0. 返    回，实现滚动高亮
                    x = startX + width + 40 + (9 * 2 - 11) / 2 - 1;
                else x -= 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, x);
                print(option);//覆盖，实现选择
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void ActivityWin::print1(int option,int mode) {
    if(mode==1){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 查看活动" << endl;
                break;
            case 2:
                cout << "2. 参加活动" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }
    else if(mode==2){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 查看活动" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }else if(mode==3){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 参加活动" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }else if(mode==4){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 修改活动" << endl;
                break;
            case 2:
                cout << "2. 结束活动" << endl;
                break;
            case 3:
                cout << "3. 删除活动" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }else if(mode==5){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 活动名称" << endl;
                break;
            case 2:
                cout << "2. 活动时间" << endl;
                break;
            case 3:
                cout << "3. 活动地点" << endl;
                break;
            case 4:
                cout << "4. 活动类型" << endl;
                break;
            case 5:
                cout << "5. 活动人数" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }else if(mode==6){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 选择活动" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }else if(mode==7){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 评论活动" << endl;
                break;
            case 2:
                cout << "2. 退出活动" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }else if(mode==8){
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 导出名单" << endl;
                break;
            case 0:
                cout << "0. 返    回" << endl;
                break;
        }
    }
    return;
}

void ActivityWin::updateOption1(int &option, int x,int mode) {
    if(mode==1||mode==7){
        if (x == startX + width - 30 + (9 * 2 - 11) / 2 - 1)
            option = 1;
        else if (x == startX + width - 9 + (9 * 2 - 11) / 2 - 1)
            option = 2;
        else if (x == startX + width + 12 + (9 * 2 - 11) / 2 - 1)
            option = 0;
    }else if(mode==2||mode==3||mode==6||mode==8){
        if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)
            option = 1;
        else if (x == startX + width + 2 + (9 * 2 - 11) / 2 - 1)
            option = 0;
    }else if(mode==4){
        if (x == startX + width - 38 + (9 * 2 - 11) / 2 - 1)
            option = 1;
        else if (x == startX + width - 19 + (9 * 2 - 11) / 2 - 1)
            option = 2;
        else if (x == startX + width + 0 + (9 * 2 - 11) / 2 - 1)
            option = 3;
        else if (x == startX + width + 19 + (9 * 2 - 11) / 2 - 1)
            option = 0;
    }else if(mode==5){
        if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)
            option = 1;
        else if (x == startX + width - 40 + (9 * 2 - 11) / 2 - 1)
            option = 2;
        else if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)
            option = 3;
        else if (x == startX + width + (9 * 2 - 11) / 2 - 1)
            option = 4;
        else if (x == startX + width + 20 + (9 * 2 - 11) / 2 - 1)
            option = 5;
        else option = 0;
    }
}

int ActivityWin::choose1(int mode) {
    //选择功能号
    //mode=1时
    //1查看活动 2参加活动 0返回
    //mode=2时
    //1查看活动 0返回
    //mode=3时
    //1参加活动 0返回
    //mode=4时
    //1修改活动 2结束活动 3删除活动 0返回
    //mode=5时
    //1修改活动 2结束活动 3删除活动 0返回
    //mode=6时
    //1选择活动 0返回
    //mode=7时
    //1评论活动 2退出活动 0返回
    //mode=8时
    //1导出名单 0返回
    int option = -1;
    char key;
    int x,y;
    if(mode==1){
        x = startX + width - 30 + (9 * 2 - 11) / 2 - 1;
        y = startY + 40 + 3 / 2;
    }else if(mode==2||mode==3){
        x = startX + width - 20 + (9 * 2 - 11) / 2 - 1;
        y = startY + 40 + 3 / 2;
    }else if(mode==4){
        x = startX + width - 38 + (9 * 2 - 11) / 2 - 1;
        y = startY + 40 + 3 / 2;
    }else if(mode==5){
        x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
        y = startY + 38 + 3 / 2;
    }else if(mode==6||mode==8){
        x = startX + width - 20 + (9 * 2 - 11) / 2 - 1;
        y = startY + 37 + 3 / 2;
    }else if(mode==7){
        x = startX + width - 30 + (9 * 2 - 11) / 2 - 1;
        y = startY + 40 + 3 / 2;
    }
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    while (option == -1) {
        do {
            if(mode==1||mode==7){
                key = getch();
                if (key >= '0' && key <= '2') {//数字键选择
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//光标移动到 左按钮
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现退选
                    if (x == startX + width + 12 + (9 * 2 - 11) / 2 - 1)//如果已经到了 右按钮 ，则跳转 左按钮 ，实现滚动高亮
                        x = startX + width - 30 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 21;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现选择
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现退选
                    if (x == startX + width - 30 + (9 * 2 - 11) / 2 - 1)//如果已经到了 左按钮 ，则跳转 右按钮 ，实现滚动高亮
                        x = startX + width + 12 + (9 * 2 - 11) / 2 - 1;
                    else x -= 21;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现选择
                }
            }else if(mode==2||mode==3||mode==6||mode==8){
                key = getch();
                if (key >= '0' && key <= '1') {//数字键选择
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//光标移动到 左按钮
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现退选
                    if (x == startX + width + 2 + (9 * 2 - 11) / 2 - 1)//如果已经到了 右按钮 ，则跳转 左按钮 ，实现滚动高亮
                        x = startX + width - 20 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 22;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现选择
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现退选
                    if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)//如果已经到了 左按钮 ，则跳转 右按钮 ，实现滚动高亮
                        x = startX + width + 2 + (9 * 2 - 11) / 2 - 1;
                    else x -= 22;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现选择
                }
            }else if(mode==4){
                key = getch();
                if (key >= '0' && key <= '3') {//数字键选择
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//光标移动到 左按钮
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现退选
                    if (x == startX + width + 19 + (9 * 2 - 11) / 2 - 1)//如果已经到了 右按钮 ，则跳转 左按钮 ，实现滚动高亮
                        x = startX + width - 38 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 19;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现选择
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x, mode);
                    print1(option, mode);//覆盖，实现退选
                    if (x == startX + width - 38 + (9 * 2 - 11) / 2 - 1)//如果已经到了 左按钮 ，则跳转 右按钮 ，实现滚动高亮
                        x = startX + width + 20 + (9 * 2 - 11) / 2 - 1;
                    else x -= 19;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x, mode);
                    print1(option, mode);//覆盖，实现选择
                }
            }else if(mode==5){
                key = getch();
                if (key >= '0' && key <= '5') {//数字键选择
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//光标移动到 左按钮
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现退选
                    if (x == startX + width + 40 + (9 * 2 - 11) / 2 - 1)//如果已经到了 右按钮 ，则跳转 左按钮 ，实现滚动高亮
                        x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 20;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现选择
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现退选
                    if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)//如果已经到了 左按钮 ，则跳转 右按钮 ，实现滚动高亮
                        x = startX + width + 40 + (9 * 2 - 11) / 2 - 1;
                    else x -= 20;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//覆盖，实现选择
                }
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void ActivityWin::viewActivity() {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //绘制表格窗口
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48线
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "名称");//646
    //-31
    //-31线
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "类型");//343
    //-20
    //-19线
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "时间");//343
    //-8
    //-7线
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "地点");//343
    //4
    //5线
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "人数上限");//181
    //16
    //17线
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "参与人数");//181
    //28
    //29线
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "评论");//848
    //46
    //47线
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "状态");//243
    //59
    //60线
    id_Label->show(5);
    name_Label->show(5);
    type_Label->show(5);
    date_Label->show(5);
    location_Label->show(5);
    max_num_Label->show(5);
    cur_num_Label->show(5);
    comment_Label->show(5);
    state_Label->show(5);

    //活动列表为空
    if (management.activityNum == 0) {
        CLabel *empty_Label = new CLabel(startX + width - 14, startY + 25, 0, 0, "活动列表为空，请先创建活动！");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
        exit_Button->show(3);
        char key;
        while (true) {//选择功能号 0返回
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    } else {
        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //绘制竖线
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if(j==2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //打印活动
        int b[10]={-56,-47,-27,-17,-2,10,23,32,50};//表项位置数组
        int cnt=1;//表示第几个活动
        for (const auto& pair : management.activityList) {
            if(cnt>9)
                break;//第一页结束
            Activity activity=pair.second;
            for(int i=0;i<9;++i){
                CTools::goto_xy(startX + width + b[i], startY + 17 + cnt*2);
                switch(i){
                    case 0:
                        cout<<activity.id;
                        break;
                    case 1:{
                        CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + cnt * 2);
                        cout<<activity.name;
                        break;
                    }
                    case 2:
                        cout<<activity.type;
                        break;
                    case 3:{
                        CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.date;
                        break;
                    }
                    case 4:{
                        CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.location;
                        break;
                    }
                    case 5:
                        cout<<activity.max_num_people;
                        break;
                    case 6:
                        cout<<activity.cur_num_people;
                        break;
                    case 7:{
                        CTools::goto_xy(startX + width + 30 + (17 - activity.comments.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.comments;
                        break;
                    }
                    case 8:{
                        if(activity.state=="招募中")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if(activity.state=="结束")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.state;
                        //设置原来颜色
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }
        //打印页数
        CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "第 1 页 | 共   页");
        CLabel *total_num_Label = new CLabel(startX + width + 54, startY + 37, 0, 0, to_string((management.activityList.size()-1)/9+1));
        pages_Label->show(4);
        total_num_Label->show(2);
        if(management.activityList.size()>9){
            CLabel *pages_Label = new CLabel(startX + width - 9, startY + 40, 0, 0, "请按数字键选择页数");
            pages_Label->show(1);
            char key;
            while (true) {//选择页数 1 2
                key = getch();
                if (key == '1')
                    break;
                if(key=='2'){
                    CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "第 2 页 | 共   页");
                    pages_Label->show(4);
                    total_num_Label->show(2);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    int t=0;
                    for (const auto& pair : management.activityList) {
                        t++;
                        if(t!=cnt)
                            continue;
                        Activity activity=pair.second;
                        //判断是否最后一个活动
                        auto it=management.activityList.end();
                        it--;
                        if(pair.first==it->first){
                            for(int i=0;i<9;++i){
                                switch(i){
                                    case 0:
                                        CTools::empty(startX + width -59,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 1:
                                        CTools::empty(startX + width -47,startY + 17 + (cnt%9)*2,15,18-(cnt%9)*2);
                                        break;
                                    case 2:
                                        CTools::empty(startX + width -30,startY + 17 + (cnt%9)*2,11,18-(cnt%9)*2);
                                        break;
                                    case 3:
                                        CTools::empty(startX + width -17,startY + 17 + (cnt%9)*2,9,18-(cnt%9)*2);
                                        break;
                                    case 4:
                                        CTools::empty(startX + width -6,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 5:
                                        CTools::empty(startX + width +6,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 6:
                                        CTools::empty(startX + width +18,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 7:
                                        CTools::empty(startX + width +30,startY + 17 + (cnt%9)*2,17,18-(cnt%9)*2);
                                        break;
                                    case 8:
                                        CTools::empty(startX + width +49,startY + 17 + (cnt%9)*2,7,18-(cnt%9)*2);
                                        break;
                                }
                            }
                        }
                        for(int i=0;i<9;++i){
                            CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                            switch(i){
                                case 0:{
                                    string s(5,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.id;
                                    break;
                                }
                                case 1:{
                                    auto it=management.activityList.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->second.name.length();
                                    CTools::goto_xy(startX + width - 47 + (16 - length) / 2, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.name;
                                    break;
                                }
                                case 2:{
                                    string s(6,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.type;
                                    break;
                                }
                                case 3:{
                                    auto it=management.activityList.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->second.date.length();
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.date;
                                    break;
                                }
                                case 4:{
                                    auto it=management.activityList.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->second.location.length();
                                    CTools::goto_xy(startX + width - 6 + (10 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.location;
                                    break;
                                }
                                case 5:{
                                    string s(4,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.max_num_people;
                                    break;
                                }
                                case 6:{
                                    string s(3,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.cur_num_people;
                                    break;
                                }
                                case 7:{
                                    auto it=management.activityList.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->second.comments.length();
                                    CTools::goto_xy(startX + width + 30 + (17 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + 30 + (17 - activity.comments.length()) / 2+1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.comments;
                                    break;
                                }
                                case 8:{
                                    auto it=management.activityList.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->second.state.length();
                                    CTools::goto_xy(startX + width + 48 + (9 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    if(activity.state=="招募中")
                                        //设置颜色
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    else if(activity.state=="结束")
                                        //设置颜色
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                                    CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.state;
                                    //设置原来颜色
                                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    break;
                                }
                            }
                        }
                        cnt++;
                    }
                    break;
                }
            }
            CTools::empty(startX + width - 9, startY + 40,20,1);
        }
        //选择功能
        CButton *view_Button = new CButton(startX + width - 30, startY + 40, 9, 3, "1. 查看活动", 3);
        CButton *attend_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "2. 参加活动", 3);
        CButton *exit_Button = new CButton(startX + width + 12, startY + 40, 9, 3, "0. 返    回", 3);
        view_Button->show(3);
        attend_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//标识位，表示是否返回
        do {
            option = choose1(1);
            switch (option) {
                case 1:{//1. 查看活动
                    //清除原来按钮
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //刷新按钮
                    CButton *view1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. 查看活动", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. 返    回", 3);
                    view1_Button->show(3);
                    exit1_Button->show(3);
                    //显示输入框、标签
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "活动id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * 请输入活动id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //搜索活动id
                    string id;
                    while (true) {
                        //输入错误时，清空内容
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //打开光标显示
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //关闭光标显示
                        CTools::cursorVisible(false);
                        //判断活动是否存在
                        Activity activity;//找到的活动
                        bool flag = false;
                        auto it = management.activityList.find(id);
                        if (it != management.activityList.end()){//找到
                            activity=it->second;
                            flag = true;
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 38);
                            cout << "                       ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * 输入错误！活动不存在");
                            tip_error_Label->show(1);
                            //选择是否重新查看
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            view1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(2);
                            switch (choice) {
                                case 1://重新 1. 查看活动
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //继续输入
                            if (back)
                                break;
                            else continue;
                        } else {//活动存在
                            CTools::empty(startX + width - 60, startY + 14, 120, 28);
                            CButton *base_Button = new CButton(startX + width - 50, startY + 14, 50, 27, "", 7);

                            CLabel *activity_data_Label = new CLabel(startX + width - 6, startY + 15, 0, 0, "活 动 信 息");

                            string id = "活 动 id：" + activity.id;
                            CButton *id_Button = new CButton(startX + width - 43, startY + 17, 20, 3, id, 5);

                            string name = "活 动 名 称：" + activity.name;
                            CButton *name_Button = new CButton(startX + width + 3, startY + 17, 20, 3, name, 5);

                            string date = "活 动 时 间：" + activity.date;
                            CButton *time_Button = new CButton(startX + width - 43, startY + 21, 20, 3, date, 4);

                            string location = "活 动 地 点：" + activity.location;
                            CButton *location_Button = new CButton(startX + width + 3, startY + 21, 20, 3, location, 4);

                            string max_num_people = "人 数 上 限：" + to_string(activity.max_num_people);
                            CButton *max_num_people_Button = new CButton(startX + width - 43, startY + 25, 20, 3, max_num_people, 2);

                            string cur_num_people = "参 与 人 数：" + to_string(activity.cur_num_people);
                            CButton *cur_num_people_Button = new CButton(startX + width + 3, startY + 25, 20, 3, cur_num_people, 2);

                            string type = "活 动 类 型：" + activity.type;
                            CButton *type_Button = new CButton(startX + width - 43, startY + 29, 20, 3, type, 2);

                            string state = "活 动 状 态：" + activity.state;
                            CButton *state_Button = new CButton(startX + width + 3, startY + 29, 20, 3, state, 2);

                            string content = "活 动 内 容：" + activity.content;
                            CButton *content_Button = new CButton(startX + width - 43, startY + 33, 43, 3, content, 4);

                            string comments = "活 动 评 论：" + activity.comments;
                            CButton *comments_Button = new CButton(startX + width - 43, startY + 37, 43, 3, comments, 4);

                            base_Button->show(7);
                            activity_data_Label->show(2);
                            id_Button->show(5);
                            name_Button->show(5);
                            time_Button->show(4);
                            location_Button->show(4);
                            max_num_people_Button->show(2);
                            cur_num_people_Button->show(2);
                            type_Button->show(2);
                            state_Button->show(2);
                            content_Button->show(4);
                            comments_Button->show(4);

                            CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. 返    回", 3);
                            exit_Button->show(3);
                            char key;
                            while (true) {//选择功能号 0 返回
                                key = getch();
                                if (key == '0')
                                    break;
                            }
                            back = true;
                            break;
                        }
                    }
                    CTools::empty(startX + width - 60, startY + 14, 120, 22);
                    break;
                }
                case 2: {//2. 参加活动
                    //清除原来按钮
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //刷新按钮
                    CButton *attend1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. 参加活动", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. 返    回", 3);
                    attend1_Button->show(3);
                    exit1_Button->show(3);
                    //显示输入框、标签
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "活动id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * 请输入活动id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //搜索活动id
                    string id;
                    bool repeat=false;//标识位，表示是否重复添加
                    while (true) {
                        //输入错误时，清空内容
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //打开光标显示
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //关闭光标显示
                        CTools::cursorVisible(false);
                        //判断活动是否存在
                        Activity activity;//找到的活动
                        bool flag = false;
                        auto it = management.activityList.find(id);
                        if (it != management.activityList.end()){//找到
                            for(auto activity:management.currentUser.myActivity){//检查是否重复添加
                                if(it->first==activity.id){
                                    CTools::empty(windowStartX + width - 23, windowStartY + 40, 57, 3);
                                    CLabel *tip_error_Label = new CLabel(startX + width + 13, startY + 38, 0, 0,
                                                                         " * 已参加该活动，请勿重复添加！");
                                    tip_error_Label->show(1);
                                    repeat=true;
                                    CButton *error_exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                    error_exit_Button->show(3);
                                    char key;
                                    while (true) {//选择功能号 0返回
                                        key = getch();
                                        if (key == '0')
                                            break;
                                    }
                                    CTools::empty(windowStartX + width - 23, windowStartY + 37, 63, 3);
                                    CTools::empty(windowStartX + width + 42, windowStartY + 38, 1, 1);
                                    CTools::empty(startX + width - 9, startY + 40, 18, 3);

                                    view_Button->show(3);
                                    attend_Button->show(3);
                                    exit_Button->show(3);
                                    break;
                                }
                            }
                            if(repeat)
                                break;
                            activity=it->second;
                            flag = true;
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 38);
                            cout << "                       ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * 输入错误！活动不存在");
                            tip_error_Label->show(1);
                            //选择是否重新添加
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            attend1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(3);
                            switch (choice) {
                                case 1://重新 1. 参加活动
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //继续输入
                            if (back)
                                break;
                            else continue;
                        } else {//活动存在
                            //更新信息,添加用户活动
                            activity.cur_num_people++;
                            activity.participants.push_back(management.currentUser);
                            management.currentUser.myActivity.push_back(activity);
                            management.userList.find(management.currentUser.id)->second.myActivity.push_back(activity);
                            management.activityList.find(activity.id)->second.cur_num_people++;
                            management.activityList.find(activity.id)->second.participants.push_back(management.currentUser);
                            CTools::empty(windowStartX + width - 30, windowStartY + 37, 70, 5);
                            CLabel *tip_success_Label = new CLabel(startX + width - 7, startY + 38, 0, 0,
                                                                   "参 加 成 功 ！");
                            tip_success_Label->show(1);
                            CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                            exit_Button->show(3);
                            char key;
                            while (true) {//选择功能号 0 返回
                                key = getch();
                                if (key == '0')
                                    break;
                            }
                            back = true;
                            break;
                        }
                    }
                    break;
                }
                case 0: {//0. 返 回
                    CTools::empty(windowStartX + width - 23, windowStartY + 37, 57, 5);
                    back = true;
                    break;
                }
            }
            if (back)
                break;
        } while (option != 1 && option != 0);
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    }
}

void ActivityWin::creatActivity(){
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    CLabel *tip_creat_Label = new CLabel(startX + width - 5, startY + 16, 0, 0, "创 建 活 动");
    tip_creat_Label->show(2);

    CLabel *name_Label = new CLabel(windowStartX + width - 22, startY + 19, 0, 0, "活动名称");
    CEdit *name_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 19, 15, 3, "", 8, 2, 1);

    CLabel *content_Label = new CLabel(windowStartX + width - 22, startY + 23, 0, 0, "活动内容");
    CEdit *content_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 23, 15, 3, "", 8, 2, 1);

    CLabel *date_Label = new CLabel(windowStartX + width - 22, startY + 27, 0, 0, "活动时间");
    CEdit *date_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 27, 15, 3, "", 8, 2, 1);

    CLabel *location_Label = new CLabel(windowStartX + width - 22, startY + 31, 0, 0, "活动地点");
    CEdit *location_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 31, 15, 3, "", 8, 2, 1);

    CLabel *type_Label = new CLabel(windowStartX + width - 22, startY + 35, 0, 0, "活动类型");
    CEdit *type_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 35, 15, 3, "", 8, 2, 1);
    CLabel *tip_type_Label = new CLabel(windowStartX + width + 16, windowStartY + 35, 0, 0,
                                        "1:综合类 2:知识类 3:体育类 4:艺术类");

    CLabel *max_num_people_Label = new CLabel(windowStartX + width - 22, startY + 39, 0, 0, "活动人数");
    CEdit *max_num_people_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 39, 15, 3, "", 8, 2, 1);

    name_Label->show(4);
    name_Edit->show(4);
    content_Label->show(4);
    content_Edit->show(4);
    date_Label->show(4);
    date_Edit->show(4);
    location_Label->show(4);
    location_Edit->show(4);
    type_Label->show(4);
    type_Edit->show(4);
    tip_type_Label->show(6);
    max_num_people_Label->show(4);
    max_num_people_Edit->show(4);

    //输入内容
    string name,content,date,location,type,state;
    //设置原来颜色
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(10));
    //打开光标
    CTools::cursorVisible(true);
    name = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 19, 20, 20, 0);
    content = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 23, 20, 20, 0);
    date = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 27, 11, 11, 0);
    location = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 31, 10, 10, 0);
    //关闭光标
    CTools::cursorVisible(false);
    int type_input;
    while (true) {
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(10));
        //开启光标显示
        CTools::cursorVisible(true);
        string t = CTools::input(windowStartX + width - 11, windowStartY + 35, 2, 2, 0);
        //关闭光标显示
        CTools::cursorVisible(false);
        bool flag = true;//判断输入是否为数字
        for (char c: t) {
            if (!isdigit(c)) {
                CTools::goto_xy(windowStartX + width -11, windowStartY + 35);
                cout << "          ";
                CTools::goto_xy(windowStartX + width + 16, windowStartY + 35);
                cout << "                                   ";
                CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 35, 0, 0,
                                                     " * 输入错误！请输入数字！");
                tip_error_Label->show(1);
                flag = false;
                break;
            }
        }
        if (flag) {
            type_input = stoi(t);
            if (type_input < 1 || type_input > 4) {
                CTools::goto_xy(windowStartX + width -11, windowStartY + 35);
                cout << "          ";
                CTools::goto_xy(windowStartX + width + 16, windowStartY + 35);
                cout << "                                   ";
                CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 35, 0, 0,
                                                     " * 输入错误！类型范围 1 ~ 4！");
                tip_error_Label->show(1);
                flag = false;
            }
        }
        if (!flag)
            continue;
        CTools::goto_xy(windowStartX + width + 16, windowStartY + 35);
        cout << "                                   ";
        break;
    }
    switch (type_input) {
        case 1:
            type = "综合类";
            break;
        case 2:
            type = "知识类";
            break;
        case 3:
            type = "体育类";
            break;
        case 4:
            type = "艺术类";
            break;
    }
    int max_num_people;
    while (true) {
        //关闭光标显示
        CTools::cursorVisible(true);
        string t = CTools::input(windowStartX + width - 11, windowStartY + 39, 5, 5, 0);
        //关闭光标显示
        CTools::cursorVisible(false);
        bool flag = true;//判断输入是否为数字
        for (char c: t) {
            if (!isdigit(c)) {
                CTools::goto_xy(windowStartX + width -11, windowStartY + 39);
                cout << "          ";
                CTools::goto_xy(windowStartX + width + 16, windowStartY + 39);
                cout << "                                   ";
                CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 39, 0, 0,
                                                     " * 输入错误！请输入数字！");
                tip_error_Label->show(1);
                HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                flag = false;
                break;
            }
        }
        if (flag == true) {
            max_num_people = stoi(t);
            if (max_num_people <= 0 || max_num_people > 1000) {
                CTools::goto_xy(windowStartX + width -11, windowStartY + 39);
                cout << "          ";
                CTools::goto_xy(windowStartX + width + 16, windowStartY + 39);
                cout << "                                   ";
                CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 39, 0, 0,
                                                     " * 输入错误！人数范围1~1000！");
                tip_error_Label->show(1);
                HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                flag = false;
            }
        }
        if (!flag)
            continue;
        CTools::goto_xy(windowStartX + width + 16, windowStartY + 39);
        cout << "                                   ";
        break;
    }
    //新建活动
    management.activityNum++;
    Activity activity(name,content,date,location,type,max_num_people,management.currentUser);
    management.currentUser.myActivity.push_back(activity);
    management.activityList.insert(make_pair(activity.id,activity));
    management.userList.insert(make_pair(management.currentUser.id,management.currentUser));
    CTools::empty(startX + width - 22, startY + 15, 50, 25);
}

void ActivityWin::myActivity(){
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //绘制表格窗口
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48线
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "名称");//646
    //-31
    //-31线
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "类型");//343
    //-20
    //-19线
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "时间");//343
    //-8
    //-7线
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "地点");//343
    //4
    //5线
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "人数上限");//181
    //16
    //17线
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "参与人数");//181
    //28
    //29线
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "评论");//848
    //46
    //47线
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "状态");//243
    //59
    //60线
    id_Label->show(5);
    name_Label->show(5);
    type_Label->show(5);
    date_Label->show(5);
    location_Label->show(5);
    max_num_Label->show(5);
    cur_num_Label->show(5);
    comment_Label->show(5);
    state_Label->show(5);

    vector<Activity> my_creat_activity;
    for (const auto& pair : management.activityList) {
        if (pair.second.creator.id == management.currentUser.id)
            my_creat_activity.push_back(pair.second);
    }

    //我的创建活动列表为空
    if (my_creat_activity.empty()) {
        CLabel *empty_Label = new CLabel(startX + width - 9, startY + 25, 0, 0, "您暂未 创建活动 ！");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
        exit_Button->show(3);
        char key;
        while (true) {//选择功能号 0返回
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    } else {
        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //绘制竖线
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if(j==2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //打印活动
        int b[10]={-56,-47,-27,-17,-2,10,23,32,50};//表项位置数组
        int cnt=1;//表示第几个活动
        for (const auto& activity : my_creat_activity) {
            if(cnt>9)
                break;//第一页结束
            for(int i=0;i<9;++i){
                CTools::goto_xy(startX + width + b[i], startY + 17 + cnt*2);
                switch(i){
                    case 0:
                        cout<<activity.id;
                        break;
                    case 1:{
                        CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + cnt * 2);
                        cout<<activity.name;
                        break;
                    }
                    case 2:
                        cout<<activity.type;
                        break;
                    case 3:{
                        CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.date;
                        break;
                    }
                    case 4:{
                        CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.location;
                        break;
                    }
                    case 5:
                        cout<<activity.max_num_people;
                        break;
                    case 6:
                        cout<<activity.cur_num_people;
                        break;
                    case 7:{
                        CTools::goto_xy(startX + width + 30 + (17 - activity.comments.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.comments;
                        break;
                    }
                    case 8:{
                        if(activity.state=="招募中")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if(activity.state=="结束")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.state;
                        //设置原来颜色
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }

        //打印页数
        CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "第 1 页 | 共   页");
        CLabel *total_num_Label = new CLabel(startX + width + 54, startY + 37, 0, 0, to_string((my_creat_activity.size()-1)/9+1));
        pages_Label->show(4);
        total_num_Label->show(2);
        if(my_creat_activity.size()>9){
            CLabel *pages_Label = new CLabel(startX + width - 9, startY + 40, 0, 0, "请按数字键选择页数");
            pages_Label->show(1);
            char key;
            while (true) {//选择页数 1 2
                key = getch();
                if (key == '1')
                    break;
                if(key=='2'){
                    CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "第 2 页 | 共   页");
                    pages_Label->show(4);
                    total_num_Label->show(2);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    int t=0;
                    for (const auto& activity : my_creat_activity) {
                        t++;
                        if(t!=cnt)
                            continue;
                        //判断是否最后一个活动
                        auto it=my_creat_activity.end();
                        it--;
                        if(activity.id==it->id){
                            for(int i=0;i<9;++i){
                                switch(i){
                                    case 0:
                                        CTools::empty(startX + width -59,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 1:
                                        CTools::empty(startX + width -47,startY + 17 + (cnt%9)*2,15,18-(cnt%9)*2);
                                        break;
                                    case 2:
                                        CTools::empty(startX + width -30,startY + 17 + (cnt%9)*2,11,18-(cnt%9)*2);
                                        break;
                                    case 3:
                                        CTools::empty(startX + width -17,startY + 17 + (cnt%9)*2,9,18-(cnt%9)*2);
                                        break;
                                    case 4:
                                        CTools::empty(startX + width -6,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 5:
                                        CTools::empty(startX + width +6,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 6:
                                        CTools::empty(startX + width +18,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 7:
                                        CTools::empty(startX + width +30,startY + 17 + (cnt%9)*2,17,18-(cnt%9)*2);
                                        break;
                                    case 8:
                                        CTools::empty(startX + width +49,startY + 17 + (cnt%9)*2,7,18-(cnt%9)*2);
                                        break;
                                }
                            }
                        }
                        for(int i=0;i<9;++i){
                            CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                            switch(i){
                                case 0:{
                                    string s(5,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.id;
                                    break;
                                }
                                case 1:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->name.length();
                                    CTools::goto_xy(startX + width - 47 + (16 - length) / 2, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.name;
                                    break;
                                }
                                case 2:{
                                    string s(6,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.type;
                                    break;
                                }
                                case 3:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->date.length();
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.date;
                                    break;
                                }
                                case 4:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->location.length();
                                    CTools::goto_xy(startX + width - 6 + (10 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.location;
                                    break;
                                }
                                case 5:{
                                    string s(4,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.max_num_people;
                                    break;
                                }
                                case 6:{
                                    string s(3,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.cur_num_people;
                                    break;
                                }
                                case 7:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->comments.length();
                                    CTools::goto_xy(startX + width + 30 + (17 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + 30 + (17 - activity.comments.length()) / 2+1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.comments;
                                    break;
                                }
                                case 8:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->state.length();
                                    CTools::goto_xy(startX + width + 48 + (9 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    if(activity.state=="招募中")
                                        //设置颜色
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    else if(activity.state=="结束")
                                        //设置颜色
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                                    CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.state;
                                    //设置原来颜色
                                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    break;
                                }
                            }
                        }
                        cnt++;
                    }
                    break;
                }
            }
            CTools::empty(startX + width - 9, startY + 40,20,1);
        }

        //选择功能
        CButton *select_Button = new CButton(startX + width - 20, startY + 37, 9, 3, "1. 选择活动", 3);
        CButton *exit_Button = new CButton(startX + width + 2, startY + 37, 9, 3, "0. 返    回", 3);

        select_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//标识位，表示是否返回
        do {
            option = choose1(6);
            switch (option) {
                case 0:
                    CTools::empty(startX + width - 60, startY + 15, 120, 28);
                    break;
                case 1: {//1. 选择活动
                    //显示输入框、标签
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 42, 0, 0, "活动id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 42, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0,
                                                         " * 请输入活动id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //搜索活动id
                    string id;
                    Activity activity;//找到的活动
                    while (true) {
                        //输入错误时，清空内容
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 42);
                        cout << "                    ";
                        //打开光标显示
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 42, 5, 20, 0);
                        //关闭光标显示
                        CTools::cursorVisible(false);
                        //判断活动是否存在
                        bool flag = false;
                        for(auto act:my_creat_activity){
                            if(act.id==id){//找到
                                activity=act;
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 42);
                            cout << "                   ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0," * 输入错误！您非活动创建者！");
                            tip_error_Label->show(1);
                            //选择是否重新1. 选择活动
                            CTools::empty(startX + width - 20, startY + 37,60,3);
                            select_Button->show(3);
                            exit_Button->show(3);
                            int choice = 74751;
                            choice = choose1(6);
                            switch (choice) {
                                case 1://重新 1. 选择活动
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //继续输入
                            if (back)
                                break;
                            else continue;
                        } else {//活动存在
                            CTools::empty(windowStartX + width - 23, startY + 37, 70, 6);
                            //选择功能
                            CButton *modify_Button = new CButton(startX + width - 38, startY + 40, 9, 3, "1. 修改活动", 3);
                            CButton *end_Button = new CButton(startX + width - 19, startY + 40, 9, 3, "2. 结束活动", 3);
                            CButton *delete_Button = new CButton(startX + width + 0, startY + 40, 9, 3, "3. 删除活动", 3);
                            CButton *ok_Button = new CButton(startX + width + 19, startY + 40, 9, 3, "0. 返    回", 3);
                            modify_Button->show(3);
                            end_Button->show(3);
                            delete_Button->show(3);
                            ok_Button->show(3);
                            int option = 74751;
                            bool bback = false;//标识位，表示是否返回
                            do {
                                option = choose1(4);
                                switch (option) {
                                    case 1: {//1. 修改活动
                                        //清除原来按钮
                                        CTools::empty(startX + width - 38, startY + 40, 75, 3);

                                        CButton *modify_name_Button, *modify_pwd_Button, *modify_gender_Button, *modify_age_Button, *modify_preference_Button, *ok_Button;
                                        modify_name_Button = new CButton(startX + width - 60, startY + 38, 9, 3, "1. 活动名称", 4);
                                        modify_pwd_Button = new CButton(startX + width - 40, startY + 38, 9, 3, "2. 活动时间", 4);
                                        modify_gender_Button = new CButton(startX + width - 20, startY + 38, 9, 3, "3. 活动地点", 4);
                                        modify_age_Button = new CButton(startX + width, startY + 38, 9, 3, "4. 活动类型", 4);
                                        modify_preference_Button = new CButton(startX + width + 20, startY + 38, 9, 3, "5. 活动人数", 4);
                                        ok_Button = new CButton(startX + width + 40, startY + 38, 9, 3, "0. 返    回", 4);

                                        modify_name_Button->show(4);
                                        modify_pwd_Button->show(4);
                                        modify_gender_Button->show(4);
                                        modify_age_Button->show(4);
                                        modify_preference_Button->show(4);
                                        ok_Button->show(4);
                                        int option = 74751;
                                        do {
                                            option = choose1(5);
                                            //清空提示信息
                                            CTools::empty(windowStartX + width - 20, windowStartY + 41, 50, 2);
                                            switch (option) {
                                                case 0:
                                                    CTools::empty(startX + width - 60, startY + 37, 120, 5);
                                                    break;
                                                case 1:{//活动名称
                                                    //显示输入框、标签
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "活动名称");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 8, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //打开光标显示
                                                    CTools::cursorVisible(true);
                                                    //输入新信息
                                                    string name = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //关闭光标显示
                                                    CTools::cursorVisible(false);
                                                    //清空并更新信息
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //更新信息
                                                    activity.name=name;
                                                    management.activityList.find(activity.id)->second.name=name;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.name=name;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//表示第几个活动
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 47, startY + 17 + (cnt%9) * 2);
                                                            cout<<"                ";
                                                            CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + (cnt%9) * 2);
                                                            //设置颜色
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.name;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "更 新 成 功 ！");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 2:{//活动时间
                                                    //显示输入框、标签
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "活动时间");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //打开光标显示
                                                    CTools::cursorVisible(true);
                                                    //输入新信息
                                                    string date = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //关闭光标显示
                                                    CTools::cursorVisible(false);
                                                    //清空并更新信息
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //更新信息
                                                    activity.date=date;
                                                    management.activityList.find(activity.id)->second.date=date;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=date;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//表示第几个活动
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 17, startY + 17 + (cnt%9) * 2);
                                                            cout<<"          ";
                                                            CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //设置颜色
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.date;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "更 新 成 功 ！");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 3:{//活动地点
                                                    //显示输入框、标签
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "活动地点");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //打开光标显示
                                                    CTools::cursorVisible(true);
                                                    //输入新信息
                                                    string location = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //关闭光标显示
                                                    CTools::cursorVisible(false);
                                                    //清空并更新信息
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //更新信息
                                                    activity.location=location;
                                                    management.activityList.find(activity.id)->second.date=location;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=location;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//表示第几个活动
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 6, startY + 17 + (cnt%9) * 2);
                                                            cout<<"           ";
                                                            CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //设置颜色
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.location;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "更 新 成 功 ！");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 4:{//活动类型
                                                    //显示输入框、标签
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "活动类型");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //打开光标显示
                                                    CTools::cursorVisible(true);
                                                    //输入新信息
                                                    string type = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //关闭光标显示
                                                    CTools::cursorVisible(false);
                                                    //清空并更新信息
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //更新信息
                                                    activity.type=type;
                                                    management.activityList.find(activity.id)->second.date=type;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=type;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//表示第几个活动
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 30, startY + 17 + (cnt%9) * 2);
                                                            cout<<"            ";
                                                            CTools::goto_xy(startX + width - 30 + (10 - activity.type.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //设置颜色
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.type;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "更 新 成 功 ！");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 5:{//活动人数
                                                    //显示输入框、标签
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "活动人数");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //打开光标显示
                                                    CTools::cursorVisible(true);
                                                    //输入新信息
                                                    string max_num_people = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //关闭光标显示
                                                    CTools::cursorVisible(false);
                                                    //清空并更新信息
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //更新信息
                                                    activity.max_num_people=stoi(max_num_people);
                                                    management.activityList.find(activity.id)->second.date=max_num_people;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=max_num_people;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//表示第几个活动
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width + 6, startY + 17 + (cnt%9) * 2);
                                                            cout<<"           ";
                                                            CTools::goto_xy(startX + width + 6 + (10 - max_num_people.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //设置颜色
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.max_num_people;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "更 新 成 功 ！");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                            }
                                        }while (option != 0);
                                        break;
                                    }
                                    case 2:{
                                        //清除原来按钮
                                        CTools::empty(startX + width - 38, startY + 40, 75, 3);
                                        //更新信息
                                        activity.state="结束";
                                        management.activityList.find(activity.id)->second.state="结束";
                                        for(auto& a:management.currentUser.myActivity){
                                            if(a.id==activity.id){
                                                a.state="结束";
                                                break;
                                            }
                                        }
                                        management.userList.find(management.currentUser.id)->second=management.currentUser;

                                        int cnt=1;//表示第几个活动
                                        for (const auto& aaa : my_creat_activity) {
                                            if(activity.id==aaa.id){
                                                CTools::goto_xy(startX + width + 48, startY + 17 + cnt * 2);
                                                cout<<"        ";
                                                CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2+1, startY + 17 + cnt * 2);
                                                //设置颜色
                                                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                cout<<activity.state;
                                            }
                                            cnt++;
                                        }
                                        CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 39, 0, 0, "结 束 成 功 ！");
                                        tip_success->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. 返    回", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//选择功能号 0 返回
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        break;
                                    }
                                    case 3:{//3. 删除活动
                                        //清除原来按钮
                                        CTools::empty(startX + width - 38, startY + 40, 75, 3);
                                        //更新信息
                                        management.activityList.erase(activity.id);
                                        for(auto it=management.currentUser.myActivity.begin();it!=management.currentUser.myActivity.end();++it){
                                            if(it->id==activity.id){
                                                management.currentUser.myActivity.erase(it);
                                                break;
                                            }
                                        }
                                        management.userList.find(management.currentUser.id)->second=management.currentUser;
                                        CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 39, 0, 0, "删 除 成 功 ！");
                                        tip_success->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. 返    回", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//选择功能号 0 返回
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        break;
                                    }
                                    case 0:{
                                        bback=true;
                                        back = true;
                                        break;
                                    }
                                }
                            }while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 0);
                            if(bback){
                                break;
                            }
                            bback = true;
                            break;
                        }
                    }
                    break;
                }
            }
        }while (option != 1 && option != 0);
    }
    CTools::empty(startX + width - 60, startY + 15, 120, 28);
}

void ActivityWin::myAttend(){
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //绘制表格窗口
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48线
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "名称");//646
    //-31
    //-31线
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "类型");//343
    //-20
    //-19线
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "时间");//343
    //-8
    //-7线
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "地点");//343
    //4
    //5线
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "人数上限");//181
    //16
    //17线
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "参与人数");//181
    //28
    //29线
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "评论");//848
    //46
    //47线
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "状态");//243
    //59
    //60线
    id_Label->show(5);
    name_Label->show(5);
    type_Label->show(5);
    date_Label->show(5);
    location_Label->show(5);
    max_num_Label->show(5);
    cur_num_Label->show(5);
    comment_Label->show(5);
    state_Label->show(5);

    vector<Activity> my_attend_activity;
    for (const auto& pair : management.currentUser.myActivity) {
        if (pair.creator.id != management.currentUser.id)
            my_attend_activity.push_back(pair);
    }
    //我的参加活动列表为空
    if(my_attend_activity.empty()){
        CLabel *empty_Label = new CLabel(startX + width - 9, startY + 25, 0, 0, "您暂未 参加活动 ！");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
        exit_Button->show(3);
        char key;
        while (true) {//选择功能号 0返回
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    }else{
        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //绘制竖线
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if(j==2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //打印活动
        int b[10]={-56,-47,-27,-17,-2,10,23,32,50};//表项位置数组
        int cnt=1;//表示第几个活动
        for (const auto& activity : management.currentUser.myActivity) {
            for(int i=0;i<9;++i){
                CTools::goto_xy(startX + width + b[i], startY + 17 + cnt*2);
                switch(i){
                    case 0:
                        cout<<activity.id;
                        break;
                    case 1:{
                        CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + cnt * 2);
                        cout<<activity.name;
                        break;
                    }
                    case 2:
                        cout<<activity.type;
                        break;
                    case 3:{
                        CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.date;
                        break;
                    }
                    case 4:{
                        CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.location;
                        break;
                    }
                    case 5:
                        cout<<activity.max_num_people;
                        break;
                    case 6:
                        cout<<activity.cur_num_people;
                        break;
                    case 7:{
                        CTools::goto_xy(startX + width + 30 + (17 - activity.comments.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.comments;
                        break;
                    }
                    case 8:{
                        if(activity.state=="招募中")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if(activity.state=="结束")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.state;
                        //设置原来颜色
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }
        //选择功能
        CButton *comment_Button = new CButton(startX + width - 30, startY + 40, 9, 3, "1. 评论活动", 3);
        CButton *quit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "2. 退出活动", 3);
        CButton *exit_Button = new CButton(startX + width + 12, startY + 40, 9, 3, "0. 返    回", 3);
        comment_Button->show(3);
        quit_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//标识位，表示是否返回
        do {
            option = choose1(7);
            switch (option) {
                case 1:{//1. 评论活动
                    //清除原来按钮
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //刷新按钮
                    CButton *comment1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. 评论活动", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. 返    回", 3);
                    comment1_Button->show(3);
                    exit1_Button->show(3);
                    //显示输入框、标签
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "活动id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * 请输入活动id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //搜索活动id
                    string id;
                    while (true) {
                        //输入错误时，清空内容
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //打开光标显示
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //关闭光标显示
                        CTools::cursorVisible(false);
                        //判断活动是否存在
                        Activity activity;//找到的活动
                        bool flag = false;
                        for(auto& a:my_attend_activity){
                            if(a.id==id){//找到
                                activity=a;
                                flag=true;
                            }
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 38);
                            cout << "                       ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * 输入错误！活动不存在或未参加");
                            tip_error_Label->show(1);
                            //选择是否重新查看
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            comment1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(2);
                            switch (choice) {
                                case 1://重新 1. 评论活动
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //继续输入
                            if (back)
                                break;
                            else continue;
                        } else {//活动存在
                            CTools::empty(startX + width - 60, startY + 14, 120, 28);
                            CButton *base_Button = new CButton(startX + width - 50, startY + 14, 50, 27, "", 7);

                            CLabel *activity_data_Label = new CLabel(startX + width - 6, startY + 15, 0, 0, "活 动 信 息");

                            string id = "活 动 id：" + activity.id;
                            CButton *id_Button = new CButton(startX + width - 43, startY + 17, 20, 3, id, 5);

                            string name = "活 动 名 称：" + activity.name;
                            CButton *name_Button = new CButton(startX + width + 3, startY + 17, 20, 3, name, 5);

                            string date = "活 动 时 间：" + activity.date;
                            CButton *time_Button = new CButton(startX + width - 43, startY + 21, 20, 3, date, 4);

                            string location = "活 动 地 点：" + activity.location;
                            CButton *location_Button = new CButton(startX + width + 3, startY + 21, 20, 3, location, 4);

                            string max_num_people = "人 数 上 限：" + to_string(activity.max_num_people);
                            CButton *max_num_people_Button = new CButton(startX + width - 43, startY + 25, 20, 3, max_num_people, 2);

                            string cur_num_people = "参 与 人 数：" + to_string(activity.cur_num_people);
                            CButton *cur_num_people_Button = new CButton(startX + width + 3, startY + 25, 20, 3, cur_num_people, 2);

                            string type = "活 动 类 型：" + activity.type;
                            CButton *type_Button = new CButton(startX + width - 43, startY + 29, 20, 3, type, 2);

                            string state = "活 动 状 态：" + activity.state;
                            CButton *state_Button = new CButton(startX + width + 3, startY + 29, 20, 3, state, 2);

                            string content = "活 动 内 容：" + activity.content;
                            CButton *content_Button = new CButton(startX + width - 43, startY + 33, 43, 3, content, 4);

                            string comments = "活 动 评 论：" + activity.comments;
                            CButton *comments_Button = new CButton(startX + width - 43, startY + 37, 43, 3, comments, 4);

                            base_Button->show(7);
                            activity_data_Label->show(2);
                            id_Button->show(5);
                            name_Button->show(5);
                            time_Button->show(4);
                            location_Button->show(4);
                            max_num_people_Button->show(2);
                            cur_num_people_Button->show(2);
                            type_Button->show(2);
                            state_Button->show(2);
                            content_Button->show(4);
                            comments_Button->show(4);

                            //显示输入框、标签
                            CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 42, 0, 0, "评  论");
                            CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 42, 15, 3, "", 8, 2, 0);
                            CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0,
                                                                 " * 评论不超过10字");
                            input_Label->show(0);
                            input_Edit->show(0);
                            tip_input_Label->show(6);

                            string comment;
                            //打开光标显示
                            CTools::cursorVisible(true);
                            comment = CTools::input(windowStartX + width - 13, windowStartY + 42, 20, 20, 0);
                            //关闭光标显示
                            CTools::cursorVisible(false);

                            //清空并更新信息
                            //更新信息
                            activity.comments=comment;
                            management.activityList.find(activity.id)->second.comments=comment;
                            for(auto& a:management.currentUser.myActivity){
                                if(a.id==activity.id){
                                    a.comments=comment;
                                    break;
                                }
                            }
                            management.userList.find(management.currentUser.id)->second=management.currentUser;
                            //刷新信息
                            CTools::empty(startX + width - 23, startY + 41,55,2);
                            CTools::empty(startX + width - 43, startY + 36,86,3);
                            string new_comments = "活 动 评 论：" + comment;
                            CButton *new_comments_Button = new CButton(startX + width - 43, startY + 37, 43, 3, new_comments, 4);
                            new_comments_Button->show(4);
                            CLabel *success_tip_Label = new CLabel(windowStartX + width - 7, windowStartY + 36, 0, 0, "评 论 成 功！");
                            success_tip_Label->show(1);
                            CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. 返    回", 3);
                            exit_Button->show(3);
                            char key;
                            while (true) {//选择功能号 0 返回
                                key = getch();
                                if (key == '0')
                                    break;
                            }
                            back = true;
                            break;
                        }
                    }
                    CTools::empty(startX + width - 60, startY + 14, 120, 22);
                    break;
                }
                case 2: {//2. 退出活动
                    //清除原来按钮
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //刷新按钮
                    CButton *quit1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. 退出活动", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. 返    回", 3);
                    quit1_Button->show(3);
                    exit1_Button->show(3);
                    //显示输入框、标签
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "活动id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * 请输入活动id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //搜索活动id
                    string id;
                    while (true) {
                        //输入错误时，清空内容
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //打开光标显示
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //关闭光标显示
                        CTools::cursorVisible(false);
                        //判断活动是否存在
                        Activity activity;//找到的活动
                        bool flag = false;
                        for(auto& a:my_attend_activity){
                            if(a.id==id){
                                activity=a;
                                flag=true;
                            }
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 38);
                            cout << "                       ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * 输入错误！活动不存在或未参加");
                            tip_error_Label->show(1);
                            //选择是否重新查看
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            quit1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(2);
                            switch (choice) {
                                case 1://重新 1. 评论活动
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //继续输入
                            if (back)
                                break;
                            else continue;
                        } else {//活动存在
                            CTools::empty(startX + width - 60, startY + 14, 120, 28);
                            CButton *base_Button = new CButton(startX + width - 50, startY + 14, 50, 27, "", 7);

                            CLabel *activity_data_Label = new CLabel(startX + width - 6, startY + 15, 0, 0, "活 动 信 息");

                            string id = "活 动 id：" + activity.id;
                            CButton *id_Button = new CButton(startX + width - 43, startY + 17, 20, 3, id, 5);

                            string name = "活 动 名 称：" + activity.name;
                            CButton *name_Button = new CButton(startX + width + 3, startY + 17, 20, 3, name, 5);

                            string date = "活 动 时 间：" + activity.date;
                            CButton *time_Button = new CButton(startX + width - 43, startY + 21, 20, 3, date, 4);

                            string location = "活 动 地 点：" + activity.location;
                            CButton *location_Button = new CButton(startX + width + 3, startY + 21, 20, 3, location, 4);

                            string max_num_people = "人 数 上 限：" + to_string(activity.max_num_people);
                            CButton *max_num_people_Button = new CButton(startX + width - 43, startY + 25, 20, 3, max_num_people, 2);

                            string cur_num_people = "参 与 人 数：" + to_string(activity.cur_num_people);
                            CButton *cur_num_people_Button = new CButton(startX + width + 3, startY + 25, 20, 3, cur_num_people, 2);

                            string type = "活 动 类 型：" + activity.type;
                            CButton *type_Button = new CButton(startX + width - 43, startY + 29, 20, 3, type, 2);

                            string state = "活 动 状 态：" + activity.state;
                            CButton *state_Button = new CButton(startX + width + 3, startY + 29, 20, 3, state, 2);

                            string content = "活 动 内 容：" + activity.content;
                            CButton *content_Button = new CButton(startX + width - 43, startY + 33, 43, 3, content, 4);

                            string comments = "活 动 评 论：" + activity.comments;
                            CButton *comments_Button = new CButton(startX + width - 43, startY + 37, 43, 3, comments, 4);

                            base_Button->show(7);
                            activity_data_Label->show(2);
                            id_Button->show(7);
                            name_Button->show(7);
                            time_Button->show(7);
                            location_Button->show(7);
                            max_num_people_Button->show(7);
                            cur_num_people_Button->show(7);
                            type_Button->show(7);
                            state_Button->show(7);
                            content_Button->show(7);
                            comments_Button->show(7);

                            //更新信息
                            management.activityList.find(activity.id)->second.cur_num_people--;
                            for(auto it=management.currentUser.myActivity.begin();it!=management.currentUser.myActivity.end();++it){
                                if(it->id==activity.id){
                                    management.currentUser.myActivity.erase(it);
                                    break;
                                }
                            }
                            for(auto it=activity.participants.begin();it!=activity.participants.end();++it){
                                if(it->id==management.currentUser.id){
                                    activity.participants.erase(it);
                                    activity.cur_num_people--;
                                    break;
                                }
                            }
                            management.userList.find(management.currentUser.id)->second=management.currentUser;
                            management.activityList.find(activity.id)->second=activity;
                            //提示退出成功
                            CLabel *quit_success_Label1 = new CLabel(windowStartX + width-2, windowStartY + 20, 0, 0, "退");
                            CLabel *quit_success_Label2 = new CLabel(windowStartX + width-2, windowStartY + 24, 0, 0, "出");
                            CLabel *quit_success_Label3 = new CLabel(windowStartX + width-2, windowStartY + 28, 0, 0, "成");
                            CLabel *quit_success_Label4 = new CLabel(windowStartX + width-2, windowStartY + 32, 0, 0, "功");
                            CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. 返    回", 3);
                            quit_success_Label1->show(1);
                            quit_success_Label2->show(1);
                            quit_success_Label3->show(1);
                            quit_success_Label4->show(1);
                            exit_Button->show(3);
                            char key;
                            while (true) {//选择功能号 0 返回
                                key = getch();
                                if (key == '0')
                                    break;
                            }
                            back = true;
                            break;
                        }
                    }
                    CTools::empty(startX + width - 60, startY + 14, 120, 22);
                    break;
                }
                case 0: {//0. 返 回
                    CTools::empty(windowStartX + width - 23, windowStartY + 37, 57, 5);
                    back = true;
                    break;
                }
            }
            if (back)
                break;
        } while (option != 1 && option != 0);
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    }
}

void ActivityWin::statisticsActivity(){
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //绘制表格窗口
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48线
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "名称");//646
    //-31
    //-31线
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "类型");//343
    //-20
    //-19线
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "时间");//343
    //-8
    //-7线
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "地点");//343
    //4
    //5线
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "人数上限");//181
    //16
    //17线
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "参与人数");//181
    //28
    //29线
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "评论");//848
    //46
    //47线
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "状态");//243
    //59
    //60线
    id_Label->show(5);
    name_Label->show(5);
    type_Label->show(5);
    date_Label->show(5);
    location_Label->show(5);
    max_num_Label->show(5);
    cur_num_Label->show(5);
    comment_Label->show(5);
    state_Label->show(5);
    vector<Activity> my_creat_activity;
    for (const auto& pair : management.activityList) {
        if (pair.second.creator.id == management.currentUser.id)
            my_creat_activity.push_back(pair.second);
    }
    //我的创建活动列表为空
    if(my_creat_activity.empty()){
        CLabel *empty_Label = new CLabel(startX + width - 9, startY + 25, 0, 0, "您暂未 创建活动 ！");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
        exit_Button->show(3);
        char key;
        while (true) {//选择功能号 0返回
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    }else {
        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //绘制竖线
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if (j == 2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //设置颜色
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //打印活动
        int b[10] = {-56, -47, -27, -17, -2, 10, 23, 32, 50};//表项位置数组
        int cnt = 1;//表示第几个活动
        for (const auto &activity: my_creat_activity) {
            if(cnt>9)
                break;//第一页结束
            for (int i = 0; i < 9; ++i) {
                CTools::goto_xy(startX + width + b[i], startY + 17 + cnt * 2);
                switch (i) {
                    case 0:
                        cout << activity.id;
                        break;
                    case 1: {
                        CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + cnt * 2);
                        cout << activity.name;
                        break;
                    }
                    case 2:
                        cout << activity.type;
                        break;
                    case 3:{
                        CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.date;
                        break;
                    }
                    case 4: {
                        CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1,
                                        startY + 17 + cnt * 2);
                        cout << activity.location;
                        break;
                    }
                    case 5:
                        cout << activity.max_num_people;
                        break;
                    case 6:
                        cout << activity.cur_num_people;
                        break;
                    case 7: {
                        CTools::goto_xy(startX + width + 30 + (17 - activity.comments.length()) / 2 + 1,
                                        startY + 17 + cnt * 2);
                        cout << activity.comments;
                        break;
                    }
                    case 8: {
                        if (activity.state == "招募中")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if (activity.state == "结束")
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1,
                                        startY + 17 + cnt * 2);
                        cout << activity.state;
                        //设置原来颜色
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }

        //打印页数
        CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "第 1 页 | 共   页");
        CLabel *total_num_Label = new CLabel(startX + width + 54, startY + 37, 0, 0, to_string((my_creat_activity.size()-1)/9+1));
        pages_Label->show(4);
        total_num_Label->show(2);
        if(my_creat_activity.size()>9){
            CLabel *pages_Label = new CLabel(startX + width - 9, startY + 40, 0, 0, "请按数字键选择页数");
            pages_Label->show(1);
            char key;
            while (true) {//选择页数 1 2
                key = getch();
                if (key == '1')
                    break;
                if(key=='2'){
                    CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "第 2 页 | 共   页");
                    pages_Label->show(4);
                    total_num_Label->show(2);
                    //设置原来颜色
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    int t=0;
                    for (const auto& activity : my_creat_activity) {
                        t++;
                        if(t!=cnt)
                            continue;
                        //判断是否最后一个活动
                        auto it=my_creat_activity.end();
                        it--;
                        if(activity.id==it->id){
                            for(int i=0;i<9;++i){
                                switch(i){
                                    case 0:
                                        CTools::empty(startX + width -59,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 1:
                                        CTools::empty(startX + width -47,startY + 17 + (cnt%9)*2,15,18-(cnt%9)*2);
                                        break;
                                    case 2:
                                        CTools::empty(startX + width -30,startY + 17 + (cnt%9)*2,11,18-(cnt%9)*2);
                                        break;
                                    case 3:
                                        CTools::empty(startX + width -17,startY + 17 + (cnt%9)*2,9,18-(cnt%9)*2);
                                        break;
                                    case 4:
                                        CTools::empty(startX + width -6,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 5:
                                        CTools::empty(startX + width +6,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 6:
                                        CTools::empty(startX + width +18,startY + 17 + (cnt%9)*2,10,18-(cnt%9)*2);
                                        break;
                                    case 7:
                                        CTools::empty(startX + width +30,startY + 17 + (cnt%9)*2,17,18-(cnt%9)*2);
                                        break;
                                    case 8:
                                        CTools::empty(startX + width +49,startY + 17 + (cnt%9)*2,7,18-(cnt%9)*2);
                                        break;
                                }
                            }
                        }
                        for(int i=0;i<9;++i){
                            CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                            switch(i){
                                case 0:{
                                    string s(5,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.id;
                                    break;
                                }
                                case 1:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->name.length();
                                    CTools::goto_xy(startX + width - 47 + (16 - length) / 2, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.name;
                                    break;
                                }
                                case 2:{
                                    string s(6,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.type;
                                    break;
                                }
                                case 3:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->date.length();
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.date;
                                    break;
                                }
                                case 4:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->location.length();
                                    CTools::goto_xy(startX + width - 6 + (10 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.location;
                                    break;
                                }
                                case 5:{
                                    string s(4,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.max_num_people;
                                    break;
                                }
                                case 6:{
                                    string s(3,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + b[i], startY + 17 + (cnt%9)*2);
                                    cout<<activity.cur_num_people;
                                    break;
                                }
                                case 7:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->comments.length();
                                    CTools::goto_xy(startX + width + 30 + (17 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    CTools::goto_xy(startX + width + 30 + (17 - activity.comments.length()) / 2+1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.comments;
                                    break;
                                }
                                case 8:{
                                    auto it=my_creat_activity.begin();
                                    for(int i=0;i<(cnt%9)-1;++i)
                                        it++;
                                    int length=it->state.length();
                                    CTools::goto_xy(startX + width + 48 + (9 - length) / 2+1, startY + 17 + (cnt%9) * 2);
                                    string s(length,' ');
                                    cout<<s;
                                    if(activity.state=="招募中")
                                        //设置颜色
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    else if(activity.state=="结束")
                                        //设置颜色
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                                    CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.state;
                                    //设置原来颜色
                                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    break;
                                }
                            }
                        }
                        cnt++;
                    }
                    break;
                }
            }
            CTools::empty(startX + width - 9, startY + 40,20,1);
        }

        //选择功能
        CButton *select_Button = new CButton(startX + width - 20, startY + 37, 9, 3, "1. 选择活动", 3);
        CButton *exit_Button = new CButton(startX + width + 2, startY + 37, 9, 3, "0. 返    回", 3);

        select_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//标识位，表示是否返回
        do {
            option = choose1(6);
            switch (option) {
                case 0:
                    CTools::empty(startX + width - 60, startY + 15, 120, 28);
                    break;
                case 1: {//1. 选择活动
                    //显示输入框、标签
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 42, 0, 0, "活动id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 42, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0,
                                                         " * 请输入活动id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //搜索活动id
                    string id;
                    Activity activity;//找到的活动
                    while (true) {
                        //输入错误时，清空内容
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 42);
                        cout << "                    ";
                        //打开光标显示
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 42, 5, 20, 0);
                        //关闭光标显示
                        CTools::cursorVisible(false);
                        //判断活动是否存在
                        bool flag = false;
                        for(auto act:my_creat_activity){
                            if(act.id==id){//找到
                                activity=act;
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 42);
                            cout << "                   ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0," * 输入错误！您非活动创建者！");
                            tip_error_Label->show(1);
                            //选择是否重新1. 选择活动
                            CTools::empty(startX + width - 20, startY + 37,60,3);
                            select_Button->show(3);
                            exit_Button->show(3);
                            int choice = 74751;
                            choice = choose1(6);
                            switch (choice) {
                                case 1://重新 1. 选择活动
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //继续输入
                            if (back)
                                break;
                            else continue;
                        } else {//活动存在
                            CTools::empty(startX + width - 60, startY + 15, 120, 28);
                            //打印活动参与者
                            //绘制表格窗口
                            CTools::drawWindow(startX + width - 30, startY + 18, 30, 19, 7);
                            CLabel *list_Label = new CLabel(startX + width - 6, startY + 17, 0, 0, "参与者名单");
                            string id="活动id："+activity.id;
                            CLabel *activity_id_Label = new CLabel(startX + width - 30+(27-id.length())/2+1, startY + 16, 0, 0, id);
                            string name="活动名称："+activity.name;
                            CLabel *activity_name_Label = new CLabel(startX + width - 2+(28-name.length())/2+1, startY + 16, 0, 0, name);
                            CLabel *user_id_Label = new CLabel(startX + width - 30+(27-8)/2+1, startY + 19, 0, 0, "用 户 id");
                            CLabel *user_name_Label = new CLabel(startX + width - 2+(28-8)/2+1, startY + 19, 0, 0, "用 户 名");
                            list_Label->show(2);
                            activity_id_Label->show(2);
                            activity_name_Label->show(2);
                            user_id_Label->show(5);
                            user_name_Label->show(5);

                            //绘制竖线
                            //设置颜色
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            for(int i=1;i<=17;++i){
                                if(i==2)
                                    continue;
                                CTools::goto_xy(startX + width - 2, startY + 18 + i);
                                printf("|");
                            }
                            //打印参与者
                            int cnt = 1;//表示第几个用户
                            for(const auto &user:activity.participants){
                                for(int i=1;i<=2;++i){
                                    if(i==1){
                                        CTools::goto_xy(startX + width - 30 + (27 - user.id.length()) / 2 + 1, startY + 19 + cnt * 2);
                                        cout<<user.id;
                                    }else if(i==2){
                                        CTools::goto_xy(startX + width - 2 + (28 - user.name.length()) / 2 + 1, startY + 19 + cnt * 2);
                                        cout<<user.name;
                                    }
                                }
                                cnt++;
                            }

                            //选择功能
                            CButton *export_list_Button = new CButton(startX + width - 20, startY + 37, 9, 3, "1. 导出名单", 3);
                            CButton *exit_Button = new CButton(startX + width + 2, startY + 37, 9, 3, "0. 返    回", 3);

                            export_list_Button->show(3);
                            exit_Button->show(3);
                            int option = 74751;
                            bool back = false;//标识位，表示是否返回
                            do {
                                option = choose1(8);
                                switch (option) {
                                    case 0:
                                        CTools::empty(startX + width - 60, startY + 15, 120, 28);
                                        break;
                                    case 1:{
                                        CTools::empty(startX + width - 21, startY + 37, 40, 3);
                                        activity.exportList(activity);
                                        CLabel *tip_success_Label = new CLabel(startX + width - 7, startY + 37, 0, 0, "导 出 成 功 ！");
                                        CLabel *tip_check_Label = new CLabel(startX + width - 18, startY + 39, 0, 0, "请在 dataFile/participant.json 中查看");
                                        tip_success_Label->show(1);
                                        tip_check_Label->show(3);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. 返    回", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//选择功能号 0 返回
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        back = true;
                                        break;
                                    }
                                }
                            }while (option != 1 && option != 0);
                            break;
                        }
                    }
                    break;
                }
            }
        }while (option != 1 && option != 0);
    }
    CTools::empty(startX + width - 60, startY + 15, 120, 28);
}
