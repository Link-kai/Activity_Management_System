#include "../public.h"


InitWin::InitWin() {
}

InitWin::InitWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(windowStartX + width - 7, windowStartY - 1, 0, 0, "�����ϵͳ");
    this->title_Label = new CLabel(windowStartX + width - 5, windowStartY + 1, 0, 0, "��ʼҳ");

    string introduce = "����ѡ��ʽ������� OR ���ּ�";
    this->introduce_Edit = new CEdit(windowStartX + width - 17, windowStartY + 13 + 9, 17, 3, introduce, 50, 2, 1);

    this->register_Button = new CButton(windowStartX + width - 28, windowStartY + 13 + 18, 9, 3, "1. ע  ��", 4);
    this->login_Button = new CButton(windowStartX + width - 9, windowStartY + 13 + 18, 9, 3, "2. ��  ¼", 4);
    this->exit_Button = new CButton(windowStartX + width + 10, windowStartY + 13 + 18, 9, 3, "0. ��  ��", 4);
}

InitWin::~InitWin() {
}

void InitWin::fozu() {
    //50*10 ���� '\'��ת��
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
    switch (option) {//���ǣ�ʵ����ѡ
        case 1:
            cout << "1. ע  ��" << endl;
            break;
        case 2:
            cout << "2. ��  ¼" << endl;
            break;
        case 0:
            cout << "0. ��  ��" << endl;
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
    int option = -1;          //ѡ���ܺ� 0�˳� 1ע�� 2��¼
    char key;
    int x = windowStartX + width - 28 + (9 * 2 - 9) / 2 - 1;
    int y = windowStartY + 13 + 18 + 1;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '2') {//���ּ�ѡ��
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                return option;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//����ƶ��� 1.ע��
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//���ǣ�ʵ����ѡ
                if (x == windowStartX + width + 10 + (9 * 2 - 9) / 2 - 1)//����Ѿ�����0. ��  ��������ת1. ע  �ᣬʵ�ֹ�������
                    x = windowStartX + width - 28 + (9 * 2 - 9) / 2 - 1;
                else
                    x += 19;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, x);
                print(option);//���ǣ�ʵ��ѡ��
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//���ǣ�ʵ����ѡ
                if (x == windowStartX + width - 28 + (9 * 2 - 9) / 2 - 1)//����Ѿ�����1. ע  �ᣬ����ת0. ��  ����ʵ�ֹ�������
                    x = windowStartX + width + 10 + (9 * 2 - 9) / 2 - 1;
                else x -= 19;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, x);
                print(option);//���ǣ�ʵ��ѡ��
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}