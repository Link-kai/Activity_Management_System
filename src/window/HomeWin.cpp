#include "../public.h"

HomeWin::HomeWin() {
}

HomeWin::HomeWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(startX + width - 7, startY - 1, 0, 0, "活动管理系统");
    this->title_Label = new CLabel(startX + width - 5, startY + 1, 0, 0, "系统主页");
    this->system_Label = new CLabel(startX + width - 5, startY + 13, 0, 0, "Activity Management System");

    this->user_Button = new CButton(startX + width - 15, startY + 18, 15, 5, "1. 个 人 主 页", 4);
    this->activity_Button = new CButton(startX + width - 15, startY + 26, 15, 5, "2. 活 动 页 面", 4);
    this->exit_Button = new CButton(startX + width - 15, startY + 34, 15, 5, "0. 退 出 登 录", 4);
}

HomeWin::~HomeWin() {
}

void HomeWin::scau() {
    //37*5 scau
    string scau[10]={
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
void HomeWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);
    this->title_Label->show(2);

    scau();
    this->system_Label->show(5);

    this->user_Button->show(4);
    this->activity_Button->show(4);
    this->exit_Button->show(4);
}

void HomeWin::print(int option) {
    switch (option) {//覆盖，实现退选
        case 1:
            cout << "1. 个 人 主 页" << endl;
            break;
        case 2:
            cout << "2. 活 动 页 面" << endl;
            break;
        case 0:
            cout << "0. 退 出 登 录" << endl;
            break;
    }
    return;
}

void HomeWin::updateOption(int &option, int y) {
    if (y == startY + 18 + 5/2)
        option = 1;
    else if (y == startY + 26 + 5/2)
        option = 2;
    else option = 0;
}

int HomeWin::choose() {
    int option = -1;          //选择功能号 0退出登录 1个人主页 2活动页面
    char key;
    int x = startX + width - 15 + (15 * 2 - 14) / 2 - 1;
    int y = startY + 18 + 5/2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '2') {//数字键选择
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                break;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//光标移动到 1.个人主页
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, y);
                print(option);//覆盖，实现退选
                if (y == startY + 34 + 5/2)//如果已经到了0. 退 出 登 录，则跳转1. 个 人 主 页，实现滚动高亮
                    y = startY + 18 + 5/2;
                else
                    y += 8;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, y);
                print(option);//覆盖，实现选择
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, y);
                print(option);//覆盖，实现退选
                if (y == windowStartY + 18 + 5/2)//如果已经到了1. 个 人 主 页，则跳转0. 退 出 登 录，实现滚动高亮
                    y = windowStartY + 34 + 5/2;
                else y -= 8;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, y);
                print(option);//覆盖，实现选择
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}