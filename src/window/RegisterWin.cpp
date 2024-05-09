#include "../public.h"

RegisterWin::RegisterWin() {
}

RegisterWin::RegisterWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(windowStartX + width - 7, windowStartY - 1, 0, 0, "�����ϵͳ");
    this->title_Label = new CLabel(windowStartX + width - 5, windowStartY + 1, 0, 0, "ע��ҳ");

    this->userName_Label = new CLabel(windowStartX + width - 20, windowStartY + 13 + 6, 0, 0, "�û���");
    this->pwd_Label = new CLabel(windowStartX + width - 20, windowStartY + 13 + 12, 0, 0, "��  ��");
    this->again_pwd_Label = new CLabel(windowStartX + width - 21, windowStartY + 13 + 18, 0, 0, "�ٴ�����");

    this->userName_Edit = new CEdit(windowStartX + width - 20 + 9, windowStartY + 13 + 6, 15, 3, "", 8, 2, 1);
    this->pwd_Edit = new CEdit(windowStartX + width - 20 + 9, windowStartY + 13 + 12, 15, 3, "", 6, 2, 0);
    this->again_pwd_Edit = new CEdit(windowStartX + width - 20 + 9, windowStartY + 13 + 18, 15, 3, "", 6, 2, 0);

    this->register_Button = new CButton(windowStartX + width - 15 - 5, windowStartY + 13 + 24, 9, 3, "ע    ��", 4);
    this->exit_Button = new CButton(windowStartX + width - 15 + 15, windowStartY + 13 + 24, 9, 3, "��    ��", 4);
}

RegisterWin::~RegisterWin() {
}

void RegisterWin::fozu() {
    //50*15 ���� '\'��ת��
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
            "      ����崻�       ���汣��     ����BUG           \n"
    };
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(2));
    for (int i = 0; i < 11; ++i) {
        CTools::goto_xy(startX + width - 25, startY + 3 + i);
        Sleep(1);
        cout << fz[i];
    }
}

void RegisterWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);

    fozu();
    this->title_Label->show(2);
    this->userName_Label->show();
    this->pwd_Label->show();
    this->again_pwd_Label->show();

    this->userName_Edit->show(0);
    this->pwd_Edit->show(0);
    this->again_pwd_Edit->show(0);

    this->register_Button->show(4);
    this->exit_Button->show(4);

}

void RegisterWin::signUp() {
    regex object("(?=.*([a-zA-Z].*))(?=.*[0-9].*)[a-zA-Z0-9-*/+.~!@#$%^&*()]{6,20}$");
    string userName, passWord, again_passWord;
    bool f = true;//��־�Ƿ������û���
    CTools::cursorVisible(true);
    while (true) {
        if (f) {
            userName = CTools::input(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 6, 20, 20, 0);
            f = false;
        }
        CTools::goto_xy(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 12);
        cout << "                    ";
        CTools::goto_xy(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 18);
        cout << "                    ";
        passWord = CTools::input(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 12, 20, 20, 1);
        again_passWord = CTools::input(windowStartX + windowWidth - 20 + 9 + 1, windowStartY + 13 + 18, 20, 20,
                                       1);
        if (passWord != again_passWord) {
            CTools::goto_xy(windowStartX + windowWidth + 16, windowStartY + 25);
            cout << "                                                ";
            CLabel *tipPwdUnequal_Label = new CLabel(windowStartX + windowWidth + 16, windowStartY + 31, 0, 0,
                                                     "* �����������벻��ͬ��");
            tipPwdUnequal_Label->show(1);
            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
            continue;
        } else {
            CTools::goto_xy(windowStartX + windowWidth + 16, windowStartY + 31);
            cout << "                              ";
        }
        if (!regex_match(passWord, object)) {
            CLabel *tipPwd_Label = new CLabel(windowStartX + windowWidth + 16, windowStartY + 25, 0, 0,
                                              "* ��������6λ�����ٰ������֡���ĸ�����������ַ�!");
            tipPwd_Label->show(1);
            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        } else {
            CTools::goto_xy(windowStartX + windowWidth + 16, windowStartY + 25);
            cout << "                                                ";
            break;
        }
    }
    CTools::cursorVisible(false);
    //����User
    management.userNum++;
    User user(userName, passWord, management);
    management.userList.insert(make_pair(user.id, user));
    management.currentUser = user;
    //�رչ��
    CTools::cursorVisible(false);
    //��ʾ�˺ţ���ת
    CTools::empty(windowStartX + width - 20, windowStartY + 13 + 5, windowWidth, windowHeight / 2);
    CLabel *tipSuccess_Label = new CLabel(windowStartX + width - 20, windowStartY + 13 + 11, 0, 0,
                                          "* ע��ɹ��������˺��ǣ�");
    tipSuccess_Label->show(4);
    CLabel *tipId_Label = new CLabel(windowStartX + width + 4, windowStartY + 13 + 11, 0, 0,
                                     management.currentUser.id);
    tipId_Label->show(1);
    CLabel *toContinue_Label = new CLabel(windowStartX + width - 12, windowStartY + 13 + 13, 0, 0,
                                          "�������������¼...");
    toContinue_Label->show(4);
    system("pause>nul");
}
