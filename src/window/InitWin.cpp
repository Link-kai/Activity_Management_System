#include "../public.h"


InitWin::InitWin() {
}

InitWin::InitWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(windowStartX + width - 7, windowStartY - 1, 0, 0, "活动管理系统");
    this->title_Label = new CLabel(windowStartX + width - 5, windowStartY + 1, 0, 0, "初始页");

    string introduce = "功能选择方式：方向键 OR 数字键";
    this->introduce_Edit = new CEdit(windowStartX + width - 17, windowStartY + 13 + 9, 17, 3, introduce, 50, 2, 1);

    this->register_Button = new CButton(windowStartX + width - 28, windowStartY + 13 + 18, 9, 3, "1. 注  册", 4);
    this->login_Button = new CButton(windowStartX + width - 9, windowStartY + 13 + 18, 9, 3, "2. 登  录", 4);
    this->exit_Button = new CButton(windowStartX + width + 10, windowStartY + 13 + 18, 9, 3, "0. 退  出", 4);
}

InitWin::~InitWin() {
}

void InitWin::fozu() {
    //50*10 佛祖 '\'需转义
    string fz[20] = {
            "                    _ooOoo_                       \n",
            "                   88~ . ~88                      \n",
            "                   (| ^_^ |)                      \n",
            "                   O\\  =  /O                      \n",
            "                ____/`---'\\____                   \n",
            "              .'  \\\\|     |//  `.                 \n",
            "            |   | \\\\\\  -  /// |   |               \n",
            "            \\  .-\\__  `-`  ___/-. /               \n",
            "        .`` '<  `.___\\_<|>_/___.'  >'''.          \n",
            "      | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |         \n",
            "      永不宕机       佛祖保佑     永无BUG           \n"
    };
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(2));
    for (int i = 0; i < 11; ++i) {
        CTools::goto_xy(startX + width - 25, startY + 3 + i);
        Sleep(1);
        cout << fz[i];
    }
}

void InitWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);

    this->title_Label->show(2);
    fozu();

    this->introduce_Edit->show(0);

    this->register_Button->show(4);
    this->login_Button->show(4);
    this->exit_Button->show(4);
}

void InitWin::print(int option) {
    switch (option) {//覆盖，实现退选
        case 1:
            cout << "1. 注  册" << endl;
            break;
        case 2:
            cout << "2. 登  录" << endl;
            break;
        case 0:
            cout << "0. 退  出" << endl;
            break;
    }
    return;
}

void InitWin::updateOption(int &option, int x) {
    if (x == windowStartX + width - 28 + (9 * 2 - 9) / 2 - 1)
        option = 1;
    else if (x == windowStartX + width - 9 + (9 * 2 - 9) / 2 - 1)
        option = 2;
    else option = 0;
}


int InitWin::choose() {
    int option = -1;          //选择功能号 0退出 1注册 2登录
    char key;
    int x = windowStartX + width - 28 + (9 * 2 - 9) / 2 - 1;
    int y = windowStartY + 13 + 18 + 1;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '2') {//数字键选择
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                return option;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//光标移动到 1.注册
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//覆盖，实现退选
                if (x == windowStartX + width + 10 + (9 * 2 - 9) / 2 - 1)//如果已经到了0. 退  出，则跳转1. 注  册，实现滚动高亮
                    x = windowStartX + width - 28 + (9 * 2 - 9) / 2 - 1;
                else
                    x += 19;
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
                if (x == windowStartX + width - 28 + (9 * 2 - 9) / 2 - 1)//如果已经到了1. 注  册，则跳转0. 退  出，实现滚动高亮
                    x = windowStartX + width + 10 + (9 * 2 - 9) / 2 - 1;
                else x -= 19;
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