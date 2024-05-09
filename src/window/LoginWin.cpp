#include "../public.h"


LoginWin::LoginWin() {
}

LoginWin::LoginWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(windowStartX + width - 7, windowStartY - 1, 0, 0, "活动管理系统");
    this->title_Label = new CLabel(windowStartX + width - 5, windowStartY + 1, 0, 0, "登录页");


    this->userId_Label = new CLabel(windowStartX + width - 20, windowStartY + 13 + 6, 0, 0, "账  号");
    this->pwd_Label = new CLabel(windowStartX + width - 20, windowStartY + 13 + 12, 0, 0, "密  码");

    this->userId_Edit = new CEdit(windowStartX + width - 20 + 9, windowStartY + 13 + 6, 15, 3, "", 8, 2, 1);
    this->pwd_Edit = new CEdit(windowStartX + width - 20 + 9, windowStartY + 13 + 12, 15, 3, "", 6, 2, 0);

    this->login_Button = new CButton(windowStartX + width - 15 - 5, windowStartY + 13 + 18, 9, 3, "登    录", 4);
    this->exit_Button = new CButton(windowStartX + width - 15 + 15, windowStartY + 13 + 18, 9, 3, "返    回", 4);
}

LoginWin::~LoginWin() {
}

void LoginWin::fozu() {
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

void LoginWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);

    fozu();
    this->title_Label->show(2);
    this->userId_Label->show();
    this->pwd_Label->show();

    this->userId_Edit->show(0);
    this->pwd_Edit->show(0);

    this->login_Button->show(4);
    this->exit_Button->show(4);

}

void LoginWin::login(bool flag) {
    bool f = true;//标志是否需要输入用户名
    string id, passWord;
    CTools::cursorVisible(true);
    while (true) {
        if (flag) {
            id = management.currentUser.id;
            CTools::goto_xy(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 6);
            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
            cout << id;
            CLabel *tipIdFill_Label = new CLabel(windowStartX + windowWidth + 16, windowStartY + 19, 0, 0,
                                                 "（已自动填充）");
            tipIdFill_Label->show(4);
        } else if (f) {
            id = CTools::input(windowStartX + windowWidth -10, windowStartY + 19, 20, 20, 0);
            auto it=management.userList.find(id);
            if(it!=management.userList.end())//账号存在
                management.currentUser=it->second;
            else{//账号不存在
                CTools::goto_xy(windowStartX + windowWidth -10, windowStartY + 19);
                cout << "                    ";
                CLabel *tipIdError_Label = new CLabel(windowStartX + windowWidth + 16, windowStartY + 19, 0, 0,
                                                       "* 账号不存在，请重新输入!");
                tipIdError_Label->show(1);
                continue;
            }
            CTools::goto_xy(windowStartX + windowWidth + 16, windowStartY + 19);
            cout << "                                                ";
            f = false;
        }
        CTools::goto_xy(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 12);
        cout << "                    ";
        passWord = CTools::input(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 12, 20, 20, 1);
        CTools::goto_xy(windowStartX + windowWidth + 16, windowStartY + 25);
        cout << "                                                ";
        if(passWord!=management.currentUser.passWord){//密码错误
            CLabel *tipPwdError_Label = new CLabel(windowStartX + windowWidth + 16, windowStartY + 25, 0, 0,
                                                   "* 密码错误，请重新输入!");
            tipPwdError_Label->show(1);
        }
        else{
            CTools::cursorVisible(false);
            break;
        }
    }
    CTools::cursorVisible(false);
    /*
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hInput, &mode);
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    mode |= ENABLE_MOUSE_INPUT;
    SetConsoleMode(hInput, mode | ENABLE_MOUSE_INPUT);

    INPUT_RECORD record;
    DWORD n;
    for (COORD pos = {}; ReadConsoleInput(hInput, &record, 1, &n) && n == 1;) {
        COORD pos_new = record.Event.MouseEvent.dwMousePosition;
        if (pos_new.X == pos.X && pos_new.Y == pos.Y)
            continue;
        pos = pos_new;
        if (isInside(pos, loginWin.login_Button)) {
            loginWin.login_Button->setHighLight();
            if (KEY_DOWN(VK_LBUTTON)) {
                //denglu!!!
                cout << "登录成功" << endl;
                system("pause>nul");
                system("cls");
            }
        } else
            loginWin.login_Button->setDefault();
    }
    */
}