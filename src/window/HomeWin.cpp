#include "../public.h"

HomeWin::HomeWin() {
}

HomeWin::HomeWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(startX + width - 7, startY - 1, 0, 0, "�����ϵͳ");
    this->title_Label = new CLabel(startX + width - 5, startY + 1, 0, 0, "ϵͳ��ҳ");
    this->system_Label = new CLabel(startX + width - 5, startY + 13, 0, 0, "Activity Management System");

    this->user_Button = new CButton(startX + width - 15, startY + 18, 15, 5, "1. �� �� �� ҳ", 4);
    this->activity_Button = new CButton(startX + width - 15, startY + 26, 15, 5, "2. �� �� ҳ ��", 4);
    this->exit_Button = new CButton(startX + width - 15, startY + 34, 15, 5, "0. �� �� �� ¼", 4);
}

HomeWin::~HomeWin() {
}

void HomeWin::scau() {
    //37*5 scau
    string scau[10]={
            "�����������������[ ���������������[ �������������[ �����[    �����[\n",
            "�����X�T�T�T�T�T�a�����X�T�T�T�T�T�a�����X�T�T�T�����[�����U    �����U\n",
            "�����������������[�����U      �����������������U�����U    �����U\n",
            "�^�T�T�T�T�T�����U�����U      �����X�T�T�T�����U�����U    �����U\n",
            "�����������������U�^���������������[�����U   �����U ���������������X�a\n",
            "�^�T�T�T�T�T�T�T�a �^�T�T�T�T�T�T�a�^�T�a   �^�T�a  �^�T�T�T�T�T�a\n"
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
    switch (option) {//���ǣ�ʵ����ѡ
        case 1:
            cout << "1. �� �� �� ҳ" << endl;
            break;
        case 2:
            cout << "2. �� �� ҳ ��" << endl;
            break;
        case 0:
            cout << "0. �� �� �� ¼" << endl;
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
    int option = -1;          //ѡ���ܺ� 0�˳���¼ 1������ҳ 2�ҳ��
    char key;
    int x = startX + width - 15 + (15 * 2 - 14) / 2 - 1;
    int y = startY + 18 + 5/2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '2') {//���ּ�ѡ��
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                break;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//����ƶ��� 1.������ҳ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, y);
                print(option);//���ǣ�ʵ����ѡ
                if (y == startY + 34 + 5/2)//����Ѿ�����0. �� �� �� ¼������ת1. �� �� �� ҳ��ʵ�ֹ�������
                    y = startY + 18 + 5/2;
                else
                    y += 8;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, y);
                print(option);//���ǣ�ʵ��ѡ��
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, y);
                print(option);//���ǣ�ʵ����ѡ
                if (y == windowStartY + 18 + 5/2)//����Ѿ�����1. �� �� �� ҳ������ת0. �� �� �� ¼��ʵ�ֹ�������
                    y = windowStartY + 34 + 5/2;
                else y -= 8;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, y);
                print(option);//���ǣ�ʵ��ѡ��
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}