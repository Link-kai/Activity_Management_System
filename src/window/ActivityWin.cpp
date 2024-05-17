#include "../public.h"

ActivityWin::ActivityWin() {
}

ActivityWin::ActivityWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(startX + width - 7, startY - 1, 0, 0, "�����ϵͳ");
    this->title_Label = new CLabel(startX + width - 5, startY + 1, 0, 0, "���ҳ");
    this->system_Label = new CLabel(startX + width - 5, startY + 13, 0, 0, "Activity Management System");

    view_activity_Button = new CButton(startX + width - 60, startY + 24, 9, 5, "1. ����", 4);
    creat_activity_Button = new CButton(startX + width - 40, startY + 24, 9, 5, "2. �����", 4);
    my_creat_Button = new CButton(startX + width - 20, startY + 24, 9, 5, "3. �ҵĴ���", 4);
    my_attend_Button = new CButton(startX + width, startY + 24, 9, 5, "4. �ҵĲμ�", 4);
    statistics_activity_Button = new CButton(startX + width + 20, startY + 24, 9, 5, "5. ͳ�ƹ���", 4);
    exit_Button = new CButton(startX + width + 40, startY + 24, 9, 5, "0. ��    ��", 4);
}

ActivityWin::~ActivityWin() {
}

void ActivityWin::scau() {
    //37*5 scau
    string scau[10] = {
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

void ActivityWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);
    this->title_Label->show(2);

    scau();
    this->system_Label->show(5);

}

void ActivityWin::print(int option) {
    switch (option) {//���ǣ�ʵ����ѡ
        case 1:
            cout << "1. ����" << endl;
            break;
        case 2:
            cout << "2. �����" << endl;
            break;
        case 3:
            cout << "3. �ҵĴ���" << endl;
            break;
        case 4:
            cout << "4. �ҵĲμ�" << endl;
            break;
        case 5:
            cout << "5. ͳ�ƹ���" << endl;
            break;
        case 0:
            cout << "0. ��    ��" << endl;
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
    int option = -1;          //ѡ���ܺ� 0���� 1���� 2����� 3�ҵĻ 4�ҵĲμ� 5ͳ�ƹ���
    char key;
    int x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
    int y = startY + 24 + 5 / 2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '5') {//���ּ�ѡ��
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                return option;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//����ƶ��� 1. ����
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//���ǣ�ʵ����ѡ
                if (x == startX + width + 40 + (9 * 2 - 11) / 2 - 1)//����Ѿ�����0. ��    �أ�����ת1. ������ʵ�ֹ�������
                    x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
                else
                    x += 20;
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
                if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)//����Ѿ�����1. ����������ת0. ��    �أ�ʵ�ֹ�������
                    x = startX + width + 40 + (9 * 2 - 11) / 2 - 1;
                else x -= 20;
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

void ActivityWin::print1(int option,int mode) {
    if(mode==1){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. �鿴�" << endl;
                break;
            case 2:
                cout << "2. �μӻ" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
                break;
        }
    }
    else if(mode==2){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. �鿴�" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
                break;
        }
    }else if(mode==3){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. �μӻ" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
                break;
        }
    }else if(mode==4){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. �޸Ļ" << endl;
                break;
            case 2:
                cout << "2. �����" << endl;
                break;
            case 3:
                cout << "3. ɾ���" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
                break;
        }
    }else if(mode==5){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. �����" << endl;
                break;
            case 2:
                cout << "2. �ʱ��" << endl;
                break;
            case 3:
                cout << "3. ��ص�" << endl;
                break;
            case 4:
                cout << "4. �����" << endl;
                break;
            case 5:
                cout << "5. �����" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
                break;
        }
    }else if(mode==6){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. ѡ��" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
                break;
        }
    }else if(mode==7){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. ���ۻ" << endl;
                break;
            case 2:
                cout << "2. �˳��" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
                break;
        }
    }else if(mode==8){
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. ��������" << endl;
                break;
            case 0:
                cout << "0. ��    ��" << endl;
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
    //ѡ���ܺ�
    //mode=1ʱ
    //1�鿴� 2�μӻ 0����
    //mode=2ʱ
    //1�鿴� 0����
    //mode=3ʱ
    //1�μӻ 0����
    //mode=4ʱ
    //1�޸Ļ 2����� 3ɾ��� 0����
    //mode=5ʱ
    //1�޸Ļ 2����� 3ɾ��� 0����
    //mode=6ʱ
    //1ѡ�� 0����
    //mode=7ʱ
    //1���ۻ 2�˳�� 0����
    //mode=8ʱ
    //1�������� 0����
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
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    while (option == -1) {
        do {
            if(mode==1||mode==7){
                key = getch();
                if (key >= '0' && key <= '2') {//���ּ�ѡ��
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//����ƶ��� ��ť
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width + 12 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� �Ұ�ť ������ת ��ť ��ʵ�ֹ�������
                        x = startX + width - 30 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 21;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ��ѡ��
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width - 30 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� ��ť ������ת �Ұ�ť ��ʵ�ֹ�������
                        x = startX + width + 12 + (9 * 2 - 11) / 2 - 1;
                    else x -= 21;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ��ѡ��
                }
            }else if(mode==2||mode==3||mode==6||mode==8){
                key = getch();
                if (key >= '0' && key <= '1') {//���ּ�ѡ��
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//����ƶ��� ��ť
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width + 2 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� �Ұ�ť ������ת ��ť ��ʵ�ֹ�������
                        x = startX + width - 20 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 22;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ��ѡ��
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� ��ť ������ת �Ұ�ť ��ʵ�ֹ�������
                        x = startX + width + 2 + (9 * 2 - 11) / 2 - 1;
                    else x -= 22;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ��ѡ��
                }
            }else if(mode==4){
                key = getch();
                if (key >= '0' && key <= '3') {//���ּ�ѡ��
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//����ƶ��� ��ť
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width + 19 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� �Ұ�ť ������ת ��ť ��ʵ�ֹ�������
                        x = startX + width - 38 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 19;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ��ѡ��
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                    updateOption1(option, x, mode);
                    print1(option, mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width - 38 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� ��ť ������ת �Ұ�ť ��ʵ�ֹ�������
                        x = startX + width + 20 + (9 * 2 - 11) / 2 - 1;
                    else x -= 19;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x, mode);
                    print1(option, mode);//���ǣ�ʵ��ѡ��
                }
            }else if(mode==5){
                key = getch();
                if (key >= '0' && key <= '5') {//���ּ�ѡ��
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
                if (option == -1) {
                    CTools::goto_xy(x, y);//����ƶ��� ��ť
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    print1(1,mode);
                }
                if (key == KEY_RIGHT || key == KEY_DOWN_) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width + 40 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� �Ұ�ť ������ת ��ť ��ʵ�ֹ�������
                        x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
                    else
                        x += 20;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ��ѡ��
                }
                if (key == KEY_LEFT || key == KEY_UP) {
                    CTools::goto_xy(x, y);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ����ѡ
                    if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)//����Ѿ����� ��ť ������ת �Ұ�ť ��ʵ�ֹ�������
                        x = startX + width + 40 + (9 * 2 - 11) / 2 - 1;
                    else x -= 20;
                    CTools::goto_xy(x, y);
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                    updateOption1(option, x,mode);
                    print1(option,mode);//���ǣ�ʵ��ѡ��
                }
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void ActivityWin::viewActivity() {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //���Ʊ�񴰿�
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48��
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "����");//646
    //-31
    //-31��
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "����");//343
    //-20
    //-19��
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "ʱ��");//343
    //-8
    //-7��
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "�ص�");//343
    //4
    //5��
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "��������");//181
    //16
    //17��
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "��������");//181
    //28
    //29��
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "����");//848
    //46
    //47��
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "״̬");//243
    //59
    //60��
    id_Label->show(5);
    name_Label->show(5);
    type_Label->show(5);
    date_Label->show(5);
    location_Label->show(5);
    max_num_Label->show(5);
    cur_num_Label->show(5);
    comment_Label->show(5);
    state_Label->show(5);

    //��б�Ϊ��
    if (management.activityNum == 0) {
        CLabel *empty_Label = new CLabel(startX + width - 14, startY + 25, 0, 0, "��б�Ϊ�գ����ȴ������");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
        exit_Button->show(3);
        char key;
        while (true) {//ѡ���ܺ� 0����
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    } else {
        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //��������
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if(j==2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //��ӡ�
        int b[10]={-56,-47,-27,-17,-2,10,23,32,50};//����λ������
        int cnt=1;//��ʾ�ڼ����
        for (const auto& pair : management.activityList) {
            if(cnt>9)
                break;//��һҳ����
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
                        if(activity.state=="��ļ��")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if(activity.state=="����")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.state;
                        //����ԭ����ɫ
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }
        //��ӡҳ��
        CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "�� 1 ҳ | ��   ҳ");
        CLabel *total_num_Label = new CLabel(startX + width + 54, startY + 37, 0, 0, to_string((management.activityList.size()-1)/9+1));
        pages_Label->show(4);
        total_num_Label->show(2);
        if(management.activityList.size()>9){
            CLabel *pages_Label = new CLabel(startX + width - 9, startY + 40, 0, 0, "�밴���ּ�ѡ��ҳ��");
            pages_Label->show(1);
            char key;
            while (true) {//ѡ��ҳ�� 1 2
                key = getch();
                if (key == '1')
                    break;
                if(key=='2'){
                    CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "�� 2 ҳ | ��   ҳ");
                    pages_Label->show(4);
                    total_num_Label->show(2);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    int t=0;
                    for (const auto& pair : management.activityList) {
                        t++;
                        if(t!=cnt)
                            continue;
                        Activity activity=pair.second;
                        //�ж��Ƿ����һ���
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
                                    if(activity.state=="��ļ��")
                                        //������ɫ
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    else if(activity.state=="����")
                                        //������ɫ
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                                    CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.state;
                                    //����ԭ����ɫ
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
        //ѡ����
        CButton *view_Button = new CButton(startX + width - 30, startY + 40, 9, 3, "1. �鿴�", 3);
        CButton *attend_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "2. �μӻ", 3);
        CButton *exit_Button = new CButton(startX + width + 12, startY + 40, 9, 3, "0. ��    ��", 3);
        view_Button->show(3);
        attend_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
        do {
            option = choose1(1);
            switch (option) {
                case 1:{//1. �鿴�
                    //���ԭ����ť
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //ˢ�°�ť
                    CButton *view1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. �鿴�", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. ��    ��", 3);
                    view1_Button->show(3);
                    exit1_Button->show(3);
                    //��ʾ����򡢱�ǩ
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "�id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * ������id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //�����id
                    string id;
                    while (true) {
                        //�������ʱ���������
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //�򿪹����ʾ
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //�رչ����ʾ
                        CTools::cursorVisible(false);
                        //�жϻ�Ƿ����
                        Activity activity;//�ҵ��Ļ
                        bool flag = false;
                        auto it = management.activityList.find(id);
                        if (it != management.activityList.end()){//�ҵ�
                            activity=it->second;
                            flag = true;
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 38);
                            cout << "                       ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * ������󣡻������");
                            tip_error_Label->show(1);
                            //ѡ���Ƿ����²鿴
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            view1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(2);
                            switch (choice) {
                                case 1://���� 1. �鿴�
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //��������
                            if (back)
                                break;
                            else continue;
                        } else {//�����
                            CTools::empty(startX + width - 60, startY + 14, 120, 28);
                            CButton *base_Button = new CButton(startX + width - 50, startY + 14, 50, 27, "", 7);

                            CLabel *activity_data_Label = new CLabel(startX + width - 6, startY + 15, 0, 0, "�� �� �� Ϣ");

                            string id = "�� �� id��" + activity.id;
                            CButton *id_Button = new CButton(startX + width - 43, startY + 17, 20, 3, id, 5);

                            string name = "�� �� �� �ƣ�" + activity.name;
                            CButton *name_Button = new CButton(startX + width + 3, startY + 17, 20, 3, name, 5);

                            string date = "�� �� ʱ �䣺" + activity.date;
                            CButton *time_Button = new CButton(startX + width - 43, startY + 21, 20, 3, date, 4);

                            string location = "�� �� �� �㣺" + activity.location;
                            CButton *location_Button = new CButton(startX + width + 3, startY + 21, 20, 3, location, 4);

                            string max_num_people = "�� �� �� �ޣ�" + to_string(activity.max_num_people);
                            CButton *max_num_people_Button = new CButton(startX + width - 43, startY + 25, 20, 3, max_num_people, 2);

                            string cur_num_people = "�� �� �� ����" + to_string(activity.cur_num_people);
                            CButton *cur_num_people_Button = new CButton(startX + width + 3, startY + 25, 20, 3, cur_num_people, 2);

                            string type = "�� �� �� �ͣ�" + activity.type;
                            CButton *type_Button = new CButton(startX + width - 43, startY + 29, 20, 3, type, 2);

                            string state = "�� �� ״ ̬��" + activity.state;
                            CButton *state_Button = new CButton(startX + width + 3, startY + 29, 20, 3, state, 2);

                            string content = "�� �� �� �ݣ�" + activity.content;
                            CButton *content_Button = new CButton(startX + width - 43, startY + 33, 43, 3, content, 4);

                            string comments = "�� �� �� �ۣ�" + activity.comments;
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

                            CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. ��    ��", 3);
                            exit_Button->show(3);
                            char key;
                            while (true) {//ѡ���ܺ� 0 ����
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
                case 2: {//2. �μӻ
                    //���ԭ����ť
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //ˢ�°�ť
                    CButton *attend1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. �μӻ", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. ��    ��", 3);
                    attend1_Button->show(3);
                    exit1_Button->show(3);
                    //��ʾ����򡢱�ǩ
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "�id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * ������id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //�����id
                    string id;
                    bool repeat=false;//��ʶλ����ʾ�Ƿ��ظ����
                    while (true) {
                        //�������ʱ���������
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //�򿪹����ʾ
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //�رչ����ʾ
                        CTools::cursorVisible(false);
                        //�жϻ�Ƿ����
                        Activity activity;//�ҵ��Ļ
                        bool flag = false;
                        auto it = management.activityList.find(id);
                        if (it != management.activityList.end()){//�ҵ�
                            for(auto activity:management.currentUser.myActivity){//����Ƿ��ظ����
                                if(it->first==activity.id){
                                    CTools::empty(windowStartX + width - 23, windowStartY + 40, 57, 3);
                                    CLabel *tip_error_Label = new CLabel(startX + width + 13, startY + 38, 0, 0,
                                                                         " * �ѲμӸû�������ظ���ӣ�");
                                    tip_error_Label->show(1);
                                    repeat=true;
                                    CButton *error_exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
                                    error_exit_Button->show(3);
                                    char key;
                                    while (true) {//ѡ���ܺ� 0����
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
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * ������󣡻������");
                            tip_error_Label->show(1);
                            //ѡ���Ƿ��������
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            attend1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(3);
                            switch (choice) {
                                case 1://���� 1. �μӻ
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //��������
                            if (back)
                                break;
                            else continue;
                        } else {//�����
                            //������Ϣ,����û��
                            activity.cur_num_people++;
                            activity.participants.push_back(management.currentUser);
                            management.currentUser.myActivity.push_back(activity);
                            management.userList.find(management.currentUser.id)->second.myActivity.push_back(activity);
                            management.activityList.find(activity.id)->second.cur_num_people++;
                            management.activityList.find(activity.id)->second.participants.push_back(management.currentUser);
                            CTools::empty(windowStartX + width - 30, windowStartY + 37, 70, 5);
                            CLabel *tip_success_Label = new CLabel(startX + width - 7, startY + 38, 0, 0,
                                                                   "�� �� �� �� ��");
                            tip_success_Label->show(1);
                            CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
                            exit_Button->show(3);
                            char key;
                            while (true) {//ѡ���ܺ� 0 ����
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
                case 0: {//0. �� ��
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
    CLabel *tip_creat_Label = new CLabel(startX + width - 5, startY + 16, 0, 0, "�� �� �� ��");
    tip_creat_Label->show(2);

    CLabel *name_Label = new CLabel(windowStartX + width - 22, startY + 19, 0, 0, "�����");
    CEdit *name_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 19, 15, 3, "", 8, 2, 1);

    CLabel *content_Label = new CLabel(windowStartX + width - 22, startY + 23, 0, 0, "�����");
    CEdit *content_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 23, 15, 3, "", 8, 2, 1);

    CLabel *date_Label = new CLabel(windowStartX + width - 22, startY + 27, 0, 0, "�ʱ��");
    CEdit *date_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 27, 15, 3, "", 8, 2, 1);

    CLabel *location_Label = new CLabel(windowStartX + width - 22, startY + 31, 0, 0, "��ص�");
    CEdit *location_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 31, 15, 3, "", 8, 2, 1);

    CLabel *type_Label = new CLabel(windowStartX + width - 22, startY + 35, 0, 0, "�����");
    CEdit *type_Edit = new CEdit(windowStartX + width - 22 + 10, windowStartY + 35, 15, 3, "", 8, 2, 1);
    CLabel *tip_type_Label = new CLabel(windowStartX + width + 16, windowStartY + 35, 0, 0,
                                        "1:�ۺ��� 2:֪ʶ�� 3:������ 4:������");

    CLabel *max_num_people_Label = new CLabel(windowStartX + width - 22, startY + 39, 0, 0, "�����");
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

    //��������
    string name,content,date,location,type,state;
    //����ԭ����ɫ
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(10));
    //�򿪹��
    CTools::cursorVisible(true);
    name = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 19, 20, 20, 0);
    content = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 23, 20, 20, 0);
    date = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 27, 11, 11, 0);
    location = CTools::input(windowStartX + width - 22 + 10 + 1, startY + 31, 10, 10, 0);
    //�رչ��
    CTools::cursorVisible(false);
    int type_input;
    while (true) {
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(10));
        //���������ʾ
        CTools::cursorVisible(true);
        string t = CTools::input(windowStartX + width - 11, windowStartY + 35, 2, 2, 0);
        //�رչ����ʾ
        CTools::cursorVisible(false);
        bool flag = true;//�ж������Ƿ�Ϊ����
        for (char c: t) {
            if (!isdigit(c)) {
                CTools::goto_xy(windowStartX + width -11, windowStartY + 35);
                cout << "          ";
                CTools::goto_xy(windowStartX + width + 16, windowStartY + 35);
                cout << "                                   ";
                CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 35, 0, 0,
                                                     " * ����������������֣�");
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
                                                     " * ����������ͷ�Χ 1 ~ 4��");
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
            type = "�ۺ���";
            break;
        case 2:
            type = "֪ʶ��";
            break;
        case 3:
            type = "������";
            break;
        case 4:
            type = "������";
            break;
    }
    int max_num_people;
    while (true) {
        //�رչ����ʾ
        CTools::cursorVisible(true);
        string t = CTools::input(windowStartX + width - 11, windowStartY + 39, 5, 5, 0);
        //�رչ����ʾ
        CTools::cursorVisible(false);
        bool flag = true;//�ж������Ƿ�Ϊ����
        for (char c: t) {
            if (!isdigit(c)) {
                CTools::goto_xy(windowStartX + width -11, windowStartY + 39);
                cout << "          ";
                CTools::goto_xy(windowStartX + width + 16, windowStartY + 39);
                cout << "                                   ";
                CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 39, 0, 0,
                                                     " * ����������������֣�");
                tip_error_Label->show(1);
                HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
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
                                                     " * �������������Χ1~1000��");
                tip_error_Label->show(1);
                HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
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
    //�½��
    management.activityNum++;
    Activity activity(name,content,date,location,type,max_num_people,management.currentUser);
    management.currentUser.myActivity.push_back(activity);
    management.activityList.insert(make_pair(activity.id,activity));
    management.userList.insert(make_pair(management.currentUser.id,management.currentUser));
    CTools::empty(startX + width - 22, startY + 15, 50, 25);
}

void ActivityWin::myActivity(){
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //���Ʊ�񴰿�
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48��
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "����");//646
    //-31
    //-31��
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "����");//343
    //-20
    //-19��
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "ʱ��");//343
    //-8
    //-7��
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "�ص�");//343
    //4
    //5��
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "��������");//181
    //16
    //17��
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "��������");//181
    //28
    //29��
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "����");//848
    //46
    //47��
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "״̬");//243
    //59
    //60��
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

    //�ҵĴ�����б�Ϊ��
    if (my_creat_activity.empty()) {
        CLabel *empty_Label = new CLabel(startX + width - 9, startY + 25, 0, 0, "����δ ����� ��");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
        exit_Button->show(3);
        char key;
        while (true) {//ѡ���ܺ� 0����
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    } else {
        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //��������
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if(j==2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //��ӡ�
        int b[10]={-56,-47,-27,-17,-2,10,23,32,50};//����λ������
        int cnt=1;//��ʾ�ڼ����
        for (const auto& activity : my_creat_activity) {
            if(cnt>9)
                break;//��һҳ����
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
                        if(activity.state=="��ļ��")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if(activity.state=="����")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.state;
                        //����ԭ����ɫ
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }

        //��ӡҳ��
        CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "�� 1 ҳ | ��   ҳ");
        CLabel *total_num_Label = new CLabel(startX + width + 54, startY + 37, 0, 0, to_string((my_creat_activity.size()-1)/9+1));
        pages_Label->show(4);
        total_num_Label->show(2);
        if(my_creat_activity.size()>9){
            CLabel *pages_Label = new CLabel(startX + width - 9, startY + 40, 0, 0, "�밴���ּ�ѡ��ҳ��");
            pages_Label->show(1);
            char key;
            while (true) {//ѡ��ҳ�� 1 2
                key = getch();
                if (key == '1')
                    break;
                if(key=='2'){
                    CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "�� 2 ҳ | ��   ҳ");
                    pages_Label->show(4);
                    total_num_Label->show(2);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    int t=0;
                    for (const auto& activity : my_creat_activity) {
                        t++;
                        if(t!=cnt)
                            continue;
                        //�ж��Ƿ����һ���
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
                                    if(activity.state=="��ļ��")
                                        //������ɫ
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    else if(activity.state=="����")
                                        //������ɫ
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                                    CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.state;
                                    //����ԭ����ɫ
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

        //ѡ����
        CButton *select_Button = new CButton(startX + width - 20, startY + 37, 9, 3, "1. ѡ��", 3);
        CButton *exit_Button = new CButton(startX + width + 2, startY + 37, 9, 3, "0. ��    ��", 3);

        select_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
        do {
            option = choose1(6);
            switch (option) {
                case 0:
                    CTools::empty(startX + width - 60, startY + 15, 120, 28);
                    break;
                case 1: {//1. ѡ��
                    //��ʾ����򡢱�ǩ
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 42, 0, 0, "�id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 42, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0,
                                                         " * ������id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //�����id
                    string id;
                    Activity activity;//�ҵ��Ļ
                    while (true) {
                        //�������ʱ���������
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 42);
                        cout << "                    ";
                        //�򿪹����ʾ
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 42, 5, 20, 0);
                        //�رչ����ʾ
                        CTools::cursorVisible(false);
                        //�жϻ�Ƿ����
                        bool flag = false;
                        for(auto act:my_creat_activity){
                            if(act.id==id){//�ҵ�
                                activity=act;
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 42);
                            cout << "                   ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0," * ����������ǻ�����ߣ�");
                            tip_error_Label->show(1);
                            //ѡ���Ƿ�����1. ѡ��
                            CTools::empty(startX + width - 20, startY + 37,60,3);
                            select_Button->show(3);
                            exit_Button->show(3);
                            int choice = 74751;
                            choice = choose1(6);
                            switch (choice) {
                                case 1://���� 1. ѡ��
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //��������
                            if (back)
                                break;
                            else continue;
                        } else {//�����
                            CTools::empty(windowStartX + width - 23, startY + 37, 70, 6);
                            //ѡ����
                            CButton *modify_Button = new CButton(startX + width - 38, startY + 40, 9, 3, "1. �޸Ļ", 3);
                            CButton *end_Button = new CButton(startX + width - 19, startY + 40, 9, 3, "2. �����", 3);
                            CButton *delete_Button = new CButton(startX + width + 0, startY + 40, 9, 3, "3. ɾ���", 3);
                            CButton *ok_Button = new CButton(startX + width + 19, startY + 40, 9, 3, "0. ��    ��", 3);
                            modify_Button->show(3);
                            end_Button->show(3);
                            delete_Button->show(3);
                            ok_Button->show(3);
                            int option = 74751;
                            bool bback = false;//��ʶλ����ʾ�Ƿ񷵻�
                            do {
                                option = choose1(4);
                                switch (option) {
                                    case 1: {//1. �޸Ļ
                                        //���ԭ����ť
                                        CTools::empty(startX + width - 38, startY + 40, 75, 3);

                                        CButton *modify_name_Button, *modify_pwd_Button, *modify_gender_Button, *modify_age_Button, *modify_preference_Button, *ok_Button;
                                        modify_name_Button = new CButton(startX + width - 60, startY + 38, 9, 3, "1. �����", 4);
                                        modify_pwd_Button = new CButton(startX + width - 40, startY + 38, 9, 3, "2. �ʱ��", 4);
                                        modify_gender_Button = new CButton(startX + width - 20, startY + 38, 9, 3, "3. ��ص�", 4);
                                        modify_age_Button = new CButton(startX + width, startY + 38, 9, 3, "4. �����", 4);
                                        modify_preference_Button = new CButton(startX + width + 20, startY + 38, 9, 3, "5. �����", 4);
                                        ok_Button = new CButton(startX + width + 40, startY + 38, 9, 3, "0. ��    ��", 4);

                                        modify_name_Button->show(4);
                                        modify_pwd_Button->show(4);
                                        modify_gender_Button->show(4);
                                        modify_age_Button->show(4);
                                        modify_preference_Button->show(4);
                                        ok_Button->show(4);
                                        int option = 74751;
                                        do {
                                            option = choose1(5);
                                            //�����ʾ��Ϣ
                                            CTools::empty(windowStartX + width - 20, windowStartY + 41, 50, 2);
                                            switch (option) {
                                                case 0:
                                                    CTools::empty(startX + width - 60, startY + 37, 120, 5);
                                                    break;
                                                case 1:{//�����
                                                    //��ʾ����򡢱�ǩ
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "�����");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 8, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //�򿪹����ʾ
                                                    CTools::cursorVisible(true);
                                                    //��������Ϣ
                                                    string name = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //�رչ����ʾ
                                                    CTools::cursorVisible(false);
                                                    //��ղ�������Ϣ
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //������Ϣ
                                                    activity.name=name;
                                                    management.activityList.find(activity.id)->second.name=name;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.name=name;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//��ʾ�ڼ����
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 47, startY + 17 + (cnt%9) * 2);
                                                            cout<<"                ";
                                                            CTools::goto_xy(startX + width - 47 + (16 - activity.name.length()) / 2, startY + 17 + (cnt%9) * 2);
                                                            //������ɫ
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.name;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "�� �� �� �� ��");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 2:{//�ʱ��
                                                    //��ʾ����򡢱�ǩ
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "�ʱ��");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //�򿪹����ʾ
                                                    CTools::cursorVisible(true);
                                                    //��������Ϣ
                                                    string date = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //�رչ����ʾ
                                                    CTools::cursorVisible(false);
                                                    //��ղ�������Ϣ
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //������Ϣ
                                                    activity.date=date;
                                                    management.activityList.find(activity.id)->second.date=date;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=date;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//��ʾ�ڼ����
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 17, startY + 17 + (cnt%9) * 2);
                                                            cout<<"          ";
                                                            CTools::goto_xy(startX + width - 18 + (10 - activity.date.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //������ɫ
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.date;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "�� �� �� �� ��");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 3:{//��ص�
                                                    //��ʾ����򡢱�ǩ
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "��ص�");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //�򿪹����ʾ
                                                    CTools::cursorVisible(true);
                                                    //��������Ϣ
                                                    string location = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //�رչ����ʾ
                                                    CTools::cursorVisible(false);
                                                    //��ղ�������Ϣ
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //������Ϣ
                                                    activity.location=location;
                                                    management.activityList.find(activity.id)->second.date=location;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=location;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//��ʾ�ڼ����
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 6, startY + 17 + (cnt%9) * 2);
                                                            cout<<"           ";
                                                            CTools::goto_xy(startX + width - 6 + (10 - activity.location.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //������ɫ
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.location;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "�� �� �� �� ��");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 4:{//�����
                                                    //��ʾ����򡢱�ǩ
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "�����");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //�򿪹����ʾ
                                                    CTools::cursorVisible(true);
                                                    //��������Ϣ
                                                    string type = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //�رչ����ʾ
                                                    CTools::cursorVisible(false);
                                                    //��ղ�������Ϣ
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //������Ϣ
                                                    activity.type=type;
                                                    management.activityList.find(activity.id)->second.date=type;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=type;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//��ʾ�ڼ����
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width - 30, startY + 17 + (cnt%9) * 2);
                                                            cout<<"            ";
                                                            CTools::goto_xy(startX + width - 30 + (10 - activity.type.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //������ɫ
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.type;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "�� �� �� �� ��");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                                case 5:{//�����
                                                    //��ʾ����򡢱�ǩ
                                                    CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 42, 0, 0, "�����");
                                                    CEdit *input_Edit = new CEdit(windowStartX + width - 11, startY + 42, 15, 3, "", 15, 2, 0);
                                                    input_Label->show(0);
                                                    input_Edit->show(0);
                                                    //�򿪹����ʾ
                                                    CTools::cursorVisible(true);
                                                    //��������Ϣ
                                                    string max_num_people = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 0);
                                                    //�رչ����ʾ
                                                    CTools::cursorVisible(false);
                                                    //��ղ�������Ϣ
                                                    CTools::empty(windowStartX + width - 20, windowStartY + 41, 80, 2);
                                                    //������Ϣ
                                                    activity.max_num_people=stoi(max_num_people);
                                                    management.activityList.find(activity.id)->second.date=max_num_people;
                                                    for(auto& a:management.currentUser.myActivity){
                                                        if(a.id==activity.id){
                                                            a.date=max_num_people;
                                                            break;
                                                        }
                                                    }
                                                    management.userList.find(management.currentUser.id)->second=management.currentUser;

                                                    int cnt=1;//��ʾ�ڼ����
                                                    for (const auto& aaa : my_creat_activity) {
                                                        if(activity.id==aaa.id){
                                                            CTools::goto_xy(startX + width + 6, startY + 17 + (cnt%9) * 2);
                                                            cout<<"           ";
                                                            CTools::goto_xy(startX + width + 6 + (10 - max_num_people.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                                            //������ɫ
                                                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                            cout<<activity.max_num_people;
                                                        }
                                                        cnt++;
                                                    }
                                                    CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 42, 0, 0, "�� �� �� �� ��");
                                                    tip_success->show(1);
                                                    break;
                                                }
                                            }
                                        }while (option != 0);
                                        break;
                                    }
                                    case 2:{
                                        //���ԭ����ť
                                        CTools::empty(startX + width - 38, startY + 40, 75, 3);
                                        //������Ϣ
                                        activity.state="����";
                                        management.activityList.find(activity.id)->second.state="����";
                                        for(auto& a:management.currentUser.myActivity){
                                            if(a.id==activity.id){
                                                a.state="����";
                                                break;
                                            }
                                        }
                                        management.userList.find(management.currentUser.id)->second=management.currentUser;

                                        int cnt=1;//��ʾ�ڼ����
                                        for (const auto& aaa : my_creat_activity) {
                                            if(activity.id==aaa.id){
                                                CTools::goto_xy(startX + width + 48, startY + 17 + cnt * 2);
                                                cout<<"        ";
                                                CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2+1, startY + 17 + cnt * 2);
                                                //������ɫ
                                                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                                cout<<activity.state;
                                            }
                                            cnt++;
                                        }
                                        CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 39, 0, 0, "�� �� �� �� ��");
                                        tip_success->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. ��    ��", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//ѡ���ܺ� 0 ����
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        break;
                                    }
                                    case 3:{//3. ɾ���
                                        //���ԭ����ť
                                        CTools::empty(startX + width - 38, startY + 40, 75, 3);
                                        //������Ϣ
                                        management.activityList.erase(activity.id);
                                        for(auto it=management.currentUser.myActivity.begin();it!=management.currentUser.myActivity.end();++it){
                                            if(it->id==activity.id){
                                                management.currentUser.myActivity.erase(it);
                                                break;
                                            }
                                        }
                                        management.userList.find(management.currentUser.id)->second=management.currentUser;
                                        CLabel *tip_success=new CLabel(windowStartX + width - 7, windowStartY + 39, 0, 0, "ɾ �� �� �� ��");
                                        tip_success->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. ��    ��", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//ѡ���ܺ� 0 ����
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
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //���Ʊ�񴰿�
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48��
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "����");//646
    //-31
    //-31��
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "����");//343
    //-20
    //-19��
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "ʱ��");//343
    //-8
    //-7��
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "�ص�");//343
    //4
    //5��
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "��������");//181
    //16
    //17��
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "��������");//181
    //28
    //29��
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "����");//848
    //46
    //47��
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "״̬");//243
    //59
    //60��
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
    //�ҵĲμӻ�б�Ϊ��
    if(my_attend_activity.empty()){
        CLabel *empty_Label = new CLabel(startX + width - 9, startY + 25, 0, 0, "����δ �μӻ ��");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
        exit_Button->show(3);
        char key;
        while (true) {//ѡ���ܺ� 0����
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    }else{
        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //��������
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if(j==2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //��ӡ�
        int b[10]={-56,-47,-27,-17,-2,10,23,32,50};//����λ������
        int cnt=1;//��ʾ�ڼ����
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
                        if(activity.state=="��ļ��")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if(activity.state=="����")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + cnt * 2);
                        cout<<activity.state;
                        //����ԭ����ɫ
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }
        //ѡ����
        CButton *comment_Button = new CButton(startX + width - 30, startY + 40, 9, 3, "1. ���ۻ", 3);
        CButton *quit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "2. �˳��", 3);
        CButton *exit_Button = new CButton(startX + width + 12, startY + 40, 9, 3, "0. ��    ��", 3);
        comment_Button->show(3);
        quit_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
        do {
            option = choose1(7);
            switch (option) {
                case 1:{//1. ���ۻ
                    //���ԭ����ť
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //ˢ�°�ť
                    CButton *comment1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. ���ۻ", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. ��    ��", 3);
                    comment1_Button->show(3);
                    exit1_Button->show(3);
                    //��ʾ����򡢱�ǩ
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "�id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * ������id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //�����id
                    string id;
                    while (true) {
                        //�������ʱ���������
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //�򿪹����ʾ
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //�رչ����ʾ
                        CTools::cursorVisible(false);
                        //�жϻ�Ƿ����
                        Activity activity;//�ҵ��Ļ
                        bool flag = false;
                        for(auto& a:my_attend_activity){
                            if(a.id==id){//�ҵ�
                                activity=a;
                                flag=true;
                            }
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 38);
                            cout << "                       ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * ������󣡻�����ڻ�δ�μ�");
                            tip_error_Label->show(1);
                            //ѡ���Ƿ����²鿴
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            comment1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(2);
                            switch (choice) {
                                case 1://���� 1. ���ۻ
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //��������
                            if (back)
                                break;
                            else continue;
                        } else {//�����
                            CTools::empty(startX + width - 60, startY + 14, 120, 28);
                            CButton *base_Button = new CButton(startX + width - 50, startY + 14, 50, 27, "", 7);

                            CLabel *activity_data_Label = new CLabel(startX + width - 6, startY + 15, 0, 0, "�� �� �� Ϣ");

                            string id = "�� �� id��" + activity.id;
                            CButton *id_Button = new CButton(startX + width - 43, startY + 17, 20, 3, id, 5);

                            string name = "�� �� �� �ƣ�" + activity.name;
                            CButton *name_Button = new CButton(startX + width + 3, startY + 17, 20, 3, name, 5);

                            string date = "�� �� ʱ �䣺" + activity.date;
                            CButton *time_Button = new CButton(startX + width - 43, startY + 21, 20, 3, date, 4);

                            string location = "�� �� �� �㣺" + activity.location;
                            CButton *location_Button = new CButton(startX + width + 3, startY + 21, 20, 3, location, 4);

                            string max_num_people = "�� �� �� �ޣ�" + to_string(activity.max_num_people);
                            CButton *max_num_people_Button = new CButton(startX + width - 43, startY + 25, 20, 3, max_num_people, 2);

                            string cur_num_people = "�� �� �� ����" + to_string(activity.cur_num_people);
                            CButton *cur_num_people_Button = new CButton(startX + width + 3, startY + 25, 20, 3, cur_num_people, 2);

                            string type = "�� �� �� �ͣ�" + activity.type;
                            CButton *type_Button = new CButton(startX + width - 43, startY + 29, 20, 3, type, 2);

                            string state = "�� �� ״ ̬��" + activity.state;
                            CButton *state_Button = new CButton(startX + width + 3, startY + 29, 20, 3, state, 2);

                            string content = "�� �� �� �ݣ�" + activity.content;
                            CButton *content_Button = new CButton(startX + width - 43, startY + 33, 43, 3, content, 4);

                            string comments = "�� �� �� �ۣ�" + activity.comments;
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

                            //��ʾ����򡢱�ǩ
                            CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 42, 0, 0, "��  ��");
                            CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 42, 15, 3, "", 8, 2, 0);
                            CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0,
                                                                 " * ���۲�����10��");
                            input_Label->show(0);
                            input_Edit->show(0);
                            tip_input_Label->show(6);

                            string comment;
                            //�򿪹����ʾ
                            CTools::cursorVisible(true);
                            comment = CTools::input(windowStartX + width - 13, windowStartY + 42, 20, 20, 0);
                            //�رչ����ʾ
                            CTools::cursorVisible(false);

                            //��ղ�������Ϣ
                            //������Ϣ
                            activity.comments=comment;
                            management.activityList.find(activity.id)->second.comments=comment;
                            for(auto& a:management.currentUser.myActivity){
                                if(a.id==activity.id){
                                    a.comments=comment;
                                    break;
                                }
                            }
                            management.userList.find(management.currentUser.id)->second=management.currentUser;
                            //ˢ����Ϣ
                            CTools::empty(startX + width - 23, startY + 41,55,2);
                            CTools::empty(startX + width - 43, startY + 36,86,3);
                            string new_comments = "�� �� �� �ۣ�" + comment;
                            CButton *new_comments_Button = new CButton(startX + width - 43, startY + 37, 43, 3, new_comments, 4);
                            new_comments_Button->show(4);
                            CLabel *success_tip_Label = new CLabel(windowStartX + width - 7, windowStartY + 36, 0, 0, "�� �� �� ����");
                            success_tip_Label->show(1);
                            CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. ��    ��", 3);
                            exit_Button->show(3);
                            char key;
                            while (true) {//ѡ���ܺ� 0 ����
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
                case 2: {//2. �˳��
                    //���ԭ����ť
                    CTools::empty(startX + width - 30, startY + 40,60,3);
                    //ˢ�°�ť
                    CButton *quit1_Button = new CButton(startX + width - 20, startY + 40, 9, 3, "1. �˳��", 3);
                    CButton *exit1_Button = new CButton(startX + width + 2, startY + 40, 9, 3, "0. ��    ��", 3);
                    quit1_Button->show(3);
                    exit1_Button->show(3);
                    //��ʾ����򡢱�ǩ
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 38, 0, 0, "�id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 38, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0,
                                                         " * ������id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //�����id
                    string id;
                    while (true) {
                        //�������ʱ���������
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 38);
                        cout << "                    ";
                        //�򿪹����ʾ
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 38, 5, 20, 0);
                        //�رչ����ʾ
                        CTools::cursorVisible(false);
                        //�жϻ�Ƿ����
                        Activity activity;//�ҵ��Ļ
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
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 38, 0, 0," * ������󣡻�����ڻ�δ�μ�");
                            tip_error_Label->show(1);
                            //ѡ���Ƿ����²鿴
                            CTools::empty(startX + width - 30, startY + 40,60,3);
                            quit1_Button->show(3);
                            exit1_Button->show(3);
                            int choice = 74751;
                            choice = choose1(2);
                            switch (choice) {
                                case 1://���� 1. ���ۻ
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //��������
                            if (back)
                                break;
                            else continue;
                        } else {//�����
                            CTools::empty(startX + width - 60, startY + 14, 120, 28);
                            CButton *base_Button = new CButton(startX + width - 50, startY + 14, 50, 27, "", 7);

                            CLabel *activity_data_Label = new CLabel(startX + width - 6, startY + 15, 0, 0, "�� �� �� Ϣ");

                            string id = "�� �� id��" + activity.id;
                            CButton *id_Button = new CButton(startX + width - 43, startY + 17, 20, 3, id, 5);

                            string name = "�� �� �� �ƣ�" + activity.name;
                            CButton *name_Button = new CButton(startX + width + 3, startY + 17, 20, 3, name, 5);

                            string date = "�� �� ʱ �䣺" + activity.date;
                            CButton *time_Button = new CButton(startX + width - 43, startY + 21, 20, 3, date, 4);

                            string location = "�� �� �� �㣺" + activity.location;
                            CButton *location_Button = new CButton(startX + width + 3, startY + 21, 20, 3, location, 4);

                            string max_num_people = "�� �� �� �ޣ�" + to_string(activity.max_num_people);
                            CButton *max_num_people_Button = new CButton(startX + width - 43, startY + 25, 20, 3, max_num_people, 2);

                            string cur_num_people = "�� �� �� ����" + to_string(activity.cur_num_people);
                            CButton *cur_num_people_Button = new CButton(startX + width + 3, startY + 25, 20, 3, cur_num_people, 2);

                            string type = "�� �� �� �ͣ�" + activity.type;
                            CButton *type_Button = new CButton(startX + width - 43, startY + 29, 20, 3, type, 2);

                            string state = "�� �� ״ ̬��" + activity.state;
                            CButton *state_Button = new CButton(startX + width + 3, startY + 29, 20, 3, state, 2);

                            string content = "�� �� �� �ݣ�" + activity.content;
                            CButton *content_Button = new CButton(startX + width - 43, startY + 33, 43, 3, content, 4);

                            string comments = "�� �� �� �ۣ�" + activity.comments;
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

                            //������Ϣ
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
                            //��ʾ�˳��ɹ�
                            CLabel *quit_success_Label1 = new CLabel(windowStartX + width-2, windowStartY + 20, 0, 0, "��");
                            CLabel *quit_success_Label2 = new CLabel(windowStartX + width-2, windowStartY + 24, 0, 0, "��");
                            CLabel *quit_success_Label3 = new CLabel(windowStartX + width-2, windowStartY + 28, 0, 0, "��");
                            CLabel *quit_success_Label4 = new CLabel(windowStartX + width-2, windowStartY + 32, 0, 0, "��");
                            CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. ��    ��", 3);
                            quit_success_Label1->show(1);
                            quit_success_Label2->show(1);
                            quit_success_Label3->show(1);
                            quit_success_Label4->show(1);
                            exit_Button->show(3);
                            char key;
                            while (true) {//ѡ���ܺ� 0 ����
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
                case 0: {//0. �� ��
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
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    CTools::empty(startX + width - 60, startY + 24, 120, 5);
    //���Ʊ�񴰿�
    CTools::drawWindow(startX + width - 60, startY + 15, 60, 22, 7);
    //-59
    CLabel *id_Label = new CLabel(startX + width - 55, startY + 16, 0, 0, "id");//424
    //-49
    //-48��
    //-47
    CLabel *name_Label = new CLabel(startX + width - 41, startY + 16, 0, 0, "����");//646
    //-31
    //-31��
    //-30
    CLabel *type_Label = new CLabel(startX + width - 26, startY + 16, 0, 0, "����");//343
    //-20
    //-19��
    //-18
    CLabel *date_Label = new CLabel(startX + width - 14, startY + 16, 0, 0, "ʱ��");//343
    //-8
    //-7��
    //-6
    CLabel *location_Label = new CLabel(startX + width - 2, startY + 16, 0, 0, "�ص�");//343
    //4
    //5��
    //6
    CLabel *max_num_Label = new CLabel(startX + width + 8, startY + 16, 0, 0, "��������");//181
    //16
    //17��
    //18
    CLabel *cur_num_Label = new CLabel(startX + width + 20, startY + 16, 0, 0, "��������");//181
    //28
    //29��
    //30
    CLabel *comment_Label = new CLabel(startX + width + 37, startY + 16, 0, 0, "����");//848
    //46
    //47��
    //48
    CLabel *state_Label = new CLabel(startX + width + 51, startY + 16, 0, 0, "״̬");//243
    //59
    //60��
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
    //�ҵĴ�����б�Ϊ��
    if(my_creat_activity.empty()){
        CLabel *empty_Label = new CLabel(startX + width - 9, startY + 25, 0, 0, "����δ ����� ��");
        empty_Label->show(1);
        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
        exit_Button->show(3);
        char key;
        while (true) {//ѡ���ܺ� 0����
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 60, startY + 15, 120, 28);
    }else {
        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(7));
        int a[10] = {-48, -31, -18, -7, 5, 17, 29, 48};
        //��������
        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 22 - 1; ++j) {
                if (j == 2)
                    continue;
                CTools::goto_xy(startX + width + a[i], startY + 15 + j);
                printf("|");
            }
        }

        //������ɫ
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
        //��ӡ�
        int b[10] = {-56, -47, -27, -17, -2, 10, 23, 32, 50};//����λ������
        int cnt = 1;//��ʾ�ڼ����
        for (const auto &activity: my_creat_activity) {
            if(cnt>9)
                break;//��һҳ����
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
                        if (activity.state == "��ļ��")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        else if (activity.state == "����")
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                        CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1,
                                        startY + 17 + cnt * 2);
                        cout << activity.state;
                        //����ԭ����ɫ
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        break;
                    }
                }
            }
            cnt++;
        }

        //��ӡҳ��
        CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "�� 1 ҳ | ��   ҳ");
        CLabel *total_num_Label = new CLabel(startX + width + 54, startY + 37, 0, 0, to_string((my_creat_activity.size()-1)/9+1));
        pages_Label->show(4);
        total_num_Label->show(2);
        if(my_creat_activity.size()>9){
            CLabel *pages_Label = new CLabel(startX + width - 9, startY + 40, 0, 0, "�밴���ּ�ѡ��ҳ��");
            pages_Label->show(1);
            char key;
            while (true) {//ѡ��ҳ�� 1 2
                key = getch();
                if (key == '1')
                    break;
                if(key=='2'){
                    CLabel *pages_Label = new CLabel(startX + width + 41, startY + 37, 0, 0, "�� 2 ҳ | ��   ҳ");
                    pages_Label->show(4);
                    total_num_Label->show(2);
                    //����ԭ����ɫ
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    int t=0;
                    for (const auto& activity : my_creat_activity) {
                        t++;
                        if(t!=cnt)
                            continue;
                        //�ж��Ƿ����һ���
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
                                    if(activity.state=="��ļ��")
                                        //������ɫ
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                                    else if(activity.state=="����")
                                        //������ɫ
                                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                                    CTools::goto_xy(startX + width + 48 + (9 - activity.state.length()) / 2 + 1, startY + 17 + (cnt%9) * 2);
                                    cout<<activity.state;
                                    //����ԭ����ɫ
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

        //ѡ����
        CButton *select_Button = new CButton(startX + width - 20, startY + 37, 9, 3, "1. ѡ��", 3);
        CButton *exit_Button = new CButton(startX + width + 2, startY + 37, 9, 3, "0. ��    ��", 3);

        select_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
        do {
            option = choose1(6);
            switch (option) {
                case 0:
                    CTools::empty(startX + width - 60, startY + 15, 120, 28);
                    break;
                case 1: {//1. ѡ��
                    //��ʾ����򡢱�ǩ
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 42, 0, 0, "�id");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 42, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0,
                                                         " * ������id");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //�����id
                    string id;
                    Activity activity;//�ҵ��Ļ
                    while (true) {
                        //�������ʱ���������
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 42);
                        cout << "                    ";
                        //�򿪹����ʾ
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 42, 5, 20, 0);
                        //�رչ����ʾ
                        CTools::cursorVisible(false);
                        //�жϻ�Ƿ����
                        bool flag = false;
                        for(auto act:my_creat_activity){
                            if(act.id==id){//�ҵ�
                                activity=act;
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 42);
                            cout << "                   ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 42, 0, 0," * ����������ǻ�����ߣ�");
                            tip_error_Label->show(1);
                            //ѡ���Ƿ�����1. ѡ��
                            CTools::empty(startX + width - 20, startY + 37,60,3);
                            select_Button->show(3);
                            exit_Button->show(3);
                            int choice = 74751;
                            choice = choose1(6);
                            switch (choice) {
                                case 1://���� 1. ѡ��
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //��������
                            if (back)
                                break;
                            else continue;
                        } else {//�����
                            CTools::empty(startX + width - 60, startY + 15, 120, 28);
                            //��ӡ�������
                            //���Ʊ�񴰿�
                            CTools::drawWindow(startX + width - 30, startY + 18, 30, 19, 7);
                            CLabel *list_Label = new CLabel(startX + width - 6, startY + 17, 0, 0, "����������");
                            string id="�id��"+activity.id;
                            CLabel *activity_id_Label = new CLabel(startX + width - 30+(27-id.length())/2+1, startY + 16, 0, 0, id);
                            string name="����ƣ�"+activity.name;
                            CLabel *activity_name_Label = new CLabel(startX + width - 2+(28-name.length())/2+1, startY + 16, 0, 0, name);
                            CLabel *user_id_Label = new CLabel(startX + width - 30+(27-8)/2+1, startY + 19, 0, 0, "�� �� id");
                            CLabel *user_name_Label = new CLabel(startX + width - 2+(28-8)/2+1, startY + 19, 0, 0, "�� �� ��");
                            list_Label->show(2);
                            activity_id_Label->show(2);
                            activity_name_Label->show(2);
                            user_id_Label->show(5);
                            user_name_Label->show(5);

                            //��������
                            //������ɫ
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            for(int i=1;i<=17;++i){
                                if(i==2)
                                    continue;
                                CTools::goto_xy(startX + width - 2, startY + 18 + i);
                                printf("|");
                            }
                            //��ӡ������
                            int cnt = 1;//��ʾ�ڼ����û�
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

                            //ѡ����
                            CButton *export_list_Button = new CButton(startX + width - 20, startY + 37, 9, 3, "1. ��������", 3);
                            CButton *exit_Button = new CButton(startX + width + 2, startY + 37, 9, 3, "0. ��    ��", 3);

                            export_list_Button->show(3);
                            exit_Button->show(3);
                            int option = 74751;
                            bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
                            do {
                                option = choose1(8);
                                switch (option) {
                                    case 0:
                                        CTools::empty(startX + width - 60, startY + 15, 120, 28);
                                        break;
                                    case 1:{
                                        CTools::empty(startX + width - 21, startY + 37, 40, 3);
                                        activity.exportList(activity);
                                        CLabel *tip_success_Label = new CLabel(startX + width - 7, startY + 37, 0, 0, "�� �� �� �� ��");
                                        CLabel *tip_check_Label = new CLabel(startX + width - 18, startY + 39, 0, 0, "���� dataFile/participant.json �в鿴");
                                        tip_success_Label->show(1);
                                        tip_check_Label->show(3);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 41, 9, 3, "0. ��    ��", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//ѡ���ܺ� 0 ����
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
