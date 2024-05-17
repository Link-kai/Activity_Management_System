#include "../public.h"

PersonalWin::PersonalWin() {
}

PersonalWin::PersonalWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(startX + width - 7, startY - 1, 0, 0, "�����ϵͳ");
    this->title_Label = new CLabel(startX + width - 5, startY + 1, 0, 0, "������ҳ");
    this->system_Label = new CLabel(startX + width - 5, startY + 13, 0, 0, "Activity Management System");

    this->base_Button = new CButton(startX + width - 40, startY + 15, 40, 18, "", 4);

    this->personalData_Label = new CLabel(startX + width - 6, startY + 17, 0, 0, "�� �� �� Ϣ");

    string id = "�˺ţ�" + management.currentUser.id;
    this->id_Button = new CButton(startX + width - 30, startY + 20, id.length(), 3, id, 2);

    string name = "�û�����" + management.currentUser.name;
    this->name_Button = new CButton(startX + width + 3, startY + 20, id.length(), 3, name, 2);

    string gender = "�Ա�" + management.currentUser.gender;
    this->gender_Button = new CButton(startX + width - 30, startY + 24, id.length(), 3, gender, 2);

    string age = "���䣺" + to_string(management.currentUser.age);
    this->age_Button = new CButton(startX + width + 3, startY + 24, id.length(), 3, age, 2);

    string preference = "�ƫ�ã�" + management.currentUser.preference;
    this->preference_Button = new CButton(startX + width - 30, startY + 28, id.length(), 3, preference, 2);

    string isAdmin = "�û����ͣ�";
    if (management.currentUser.isAdmin)
        isAdmin += "����Ա";
    else isAdmin += "��ͨ�û�";
    this->admin_Button = new CButton(startX + width + 3, startY + 28, id.length(), 3, isAdmin, 2);

    this->modify_Button = new CButton(startX + width - 40, startY + 35, 9, 3, "1. �޸���Ϣ", 4);
    this->inBox_Button = new CButton(startX + width - 20, startY + 35, 9, 3, "2. �� �� ��", 4);
    this->bro_Button = new CButton(startX + width, startY + 35, 9, 3, "3. �����б�", 4);
    this->exit_Button = new CButton(startX + width + 20, startY + 35, 9, 3, "0. ��    ��", 4);
}

PersonalWin::~PersonalWin() {
}

void PersonalWin::scau() {
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

void PersonalWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);
    this->title_Label->show(2);

    scau();
    this->system_Label->show(5);

    this->base_Button->show(4);

    this->personalData_Label->show(2);

    this->id_Button->show(2);
    this->name_Button->show(2);

    this->gender_Button->show(2);
    this->age_Button->show(2);

    this->preference_Button->show(2);
    this->admin_Button->show(2);

    this->modify_Button->show(4);
    this->inBox_Button->show(4);
    this->bro_Button->show(4);
    this->exit_Button->show(4);
}

void PersonalWin::print(int option) {
    switch (option) {//���ǣ�ʵ����ѡ
        case 1:
            cout << "1. �޸���Ϣ" << endl;
            break;
        case 2:
            cout << "2. �� �� ��" << endl;
            break;
        case 3:
            cout << "3. �����б�" << endl;
            break;
        case 0:
            cout << "0. ��    ��" << endl;
            break;
    }
    return;
}

void PersonalWin::updateOption(int &option, int x) {
    if (x == startX + width - 40 + (9 * 2 - 11) / 2 - 1)
        option = 1;
    else if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)
        option = 2;
    else if (x == startX + width + (9 * 2 - 11) / 2 - 1)
        option = 3;
    else option = 0;
}

int PersonalWin::choose() {
    int option = -1;          //ѡ���ܺ� 0���� 1�޸���Ϣ 2�ռ��� 3�����б�
    char key;
    int x = startX + width - 40 + (9 * 2 - 11) / 2 - 1;
    int y = startY + 35 + 3 / 2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '3') {//���ּ�ѡ��
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                return option;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//����ƶ��� 1.�޸���Ϣ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//���ǣ�ʵ����ѡ
                if (x == startX + width + 20 + (9 * 2 - 11) / 2 - 1)//����Ѿ�����0. ��    �أ�����ת1. �޸���Ϣ��ʵ�ֹ�������
                    x = startX + width - 40 + (9 * 2 - 11) / 2 - 1;
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
                if (x == startX + width - 40 + (9 * 2 - 11) / 2 - 1)//����Ѿ�����1. �� �� �� ҳ������ת0. �� �� �� ¼��ʵ�ֹ�������
                    x = startX + width + 20 + (9 * 2 - 11) / 2 - 1;
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

void PersonalWin::modify() {
    CTools::empty(startX + width - 40, startY + 35, 85, 3);

    CButton *modify_name_Button, *modify_pwd_Button, *modify_gender_Button, *modify_age_Button, *modify_preference_Button, *ok_Button;
    modify_name_Button = new CButton(startX + width - 60, startY + 33, 9, 3, "1. �� �� ��", 4);
    modify_pwd_Button = new CButton(startX + width - 40, startY + 33, 9, 3, "2. ��    ��", 4);
    modify_gender_Button = new CButton(startX + width - 20, startY + 33, 9, 3, "3. ��    ��", 4);
    modify_age_Button = new CButton(startX + width, startY + 33, 9, 3, "4. ��    ��", 4);
    modify_preference_Button = new CButton(startX + width + 20, startY + 33, 9, 3, "5. �ƫ��", 4);
    ok_Button = new CButton(startX + width + 40, startY + 33, 9, 3, "0. ��    ��", 4);

    modify_name_Button->show(4);
    modify_pwd_Button->show(4);
    modify_gender_Button->show(4);
    modify_age_Button->show(4);
    modify_preference_Button->show(4);
    ok_Button->show(4);
    int option = 74751;
    do {
        option = choose1();
        //�����ʾ��Ϣ
        CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
        switch (option) {
            case 0:
                CTools::empty(startX + width - 60, startY + 33, 120, 3);
                break;
            case 1: { //�û���
                //��ʾ����򡢱�ǩ
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "�û���");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * �������µ��û���(�� 20���ַ�)");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                //�򿪹����ʾ
                CTools::cursorVisible(true);
                //��������Ϣ
                string name = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                //�رչ����ʾ
                CTools::cursorVisible(false);
                //��ղ�������Ϣ
                CTools::empty(startX + width + 3, startY + 20, 15 * 2, 3);
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //������Ϣ
                management.currentUser.name = name;
                management.userList.find(management.currentUser.id)->second.name=name;
                //�������
                string info = "�û�����" + management.currentUser.name;
                auto name_Button = new CButton(startX + width + 3, startY + 20, 15, 3, info, 2);
                name_Button->show(2);
                //��ʾ���ĳɹ�
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 8, windowStartY + 38, 0, 0,
                                                       "�޸� �û��� �ɹ���");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "�� �� ѡ ��");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //���°�ť
                modify_name_Button->show(4);
                break;
            }
            case 2: { //����
                //��ʾ����򡢱�ǩ
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "�� ��");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     "* �� �� �� �� �� ��");
                CLabel *again_pwd_Label = new CLabel(windowStartX + width - 20, startY + 42, 0, 0, "�ٴ�����");
                CEdit *again_pwd_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 42, 15, 3, "", 8, 2, 0);
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                again_pwd_Label->show(0);
                again_pwd_Edit->show(0);
                //�򿪹����ʾ
                CTools::cursorVisible(true);
                //��������Ϣ
                regex object("(?=.*([a-zA-Z].*))(?=.*[0-9].*)[a-zA-Z0-9-*/+.~!@#$%^&*()]{6,20}$");
                string pwd, again_pwd;
                while (true) {
                    //�������ʱ���������
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    CTools::goto_xy(windowStartX + width - 10, startY + 42);
                    cout << "                    ";

                    pwd = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 1);
                    again_pwd = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 1);
                    //�ж������Ƿ�Ϸ�
                    if (pwd != again_pwd) {
                        CTools::goto_xy(windowStartX + width + 16, startY + 42);
                        cout << "                                                ";
                        CLabel *tipPwdUnequal_Label = new CLabel(windowStartX + width + 16, startY + 42, 0, 0,
                                                                 "* �����������벻��ͬ��");
                        tipPwdUnequal_Label->show(1);
                        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        continue;
                    } else {
                        CTools::goto_xy(windowStartX + width + 16, startY + 42);
                        cout << "                              ";
                    }
                    if (!regex_match(pwd, object)) {
                        CLabel *tipPwd_Label = new CLabel(windowStartX + width + 16, startY + 42, 0, 0,
                                                          "* ��������6λ�����ٰ������֡���ĸ�����������ַ�!");
                        tipPwd_Label->show(1);
                        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    } else {
                        CTools::goto_xy(windowStartX + width + 16, startY + 42);
                        cout << "                                                ";
                        break;
                    }
                }
                //�رչ����ʾ
                CTools::cursorVisible(false);
                //��ղ�������Ϣ
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //������Ϣ
                management.currentUser.passWord = pwd;
                management.userList.find(management.currentUser.id)->second.passWord=pwd;
                //��ʾ���ĳɹ�
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 7, windowStartY + 38, 0, 0,
                                                       "�޸� ���� �ɹ���");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "�� �� ѡ ��");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                modify_pwd_Button->show(4);
                break;
            }
            case 3: { //�Ա�
                //��ʾ����򡢱�ǩ
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "�� ��");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * �����������Ա�(�� Ů ����)");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                //�򿪹����ʾ
                CTools::cursorVisible(true);
                //��������Ϣ
                string gender;
                while (true) {
                    //�������ʱ���������
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    gender = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                    if (gender != "��" && gender != "Ů" && gender != "����") {
                        CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                        cout << "                              ";
                        CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                             " * ������� �Ա�(�� Ů ����)");
                        tip_error_Label->show(1);
                        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    } else {
                        CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                        cout << "                              ";
                        break;
                    }
                }
                //�رչ����ʾ
                CTools::cursorVisible(false);
                //��ղ�������Ϣ
                CTools::empty(startX + width - 30, startY + 24, 15 * 2, 3);
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //������Ϣ
                management.currentUser.gender = gender;
                management.userList.find(management.currentUser.id)->second.gender=gender;
                //�������
                string info = "�Ա�" + management.currentUser.gender;
                auto gender_Button = new CButton(startX + width - 30, startY + 24, 15, 3, info, 2);
                gender_Button->show(2);
                //��ʾ���ĳɹ�
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 7, windowStartY + 38, 0, 0,
                                                       "�޸� �Ա� �ɹ���");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "�� �� ѡ ��");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //���°�ť
                modify_gender_Button->show(4);
                break;
            }
            case 4: { //����
                //��ʾ����򡢱�ǩ
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "�� ��");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * ��������������");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                //�򿪹����ʾ
                CTools::cursorVisible(true);
                //��������Ϣ
                int age;
                while (true) {
                    //�������ʱ���������
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    string t = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                    bool flag = true;//�ж������Ƿ�Ϊ����
                    for (char c: t) {
                        if (!isdigit(c)) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * ����������������֣�");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true) {
                        age = stoi(t);
                        if (age < 0 || age > 100) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * ����������䷶Χ0~100��");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                        }
                    }
                    if (!flag)
                        continue;
                    CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                    cout << "                              ";
                    break;
                }
                //�رչ����ʾ
                CTools::cursorVisible(false);
                //��ղ�������Ϣ
                CTools::empty(startX + width + 3, startY + 24, 15 * 2, 3);
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //������Ϣ
                management.currentUser.age = age;
                management.userList.find(management.currentUser.id)->second.age=age;
                //�������
                string info = "���䣺" + to_string(management.currentUser.age);
                auto age_Button = new CButton(startX + width + 3, startY + 24, 15, 3, info, 2);
                age_Button->show(2);
                //��ʾ���ĳɹ�
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 7, windowStartY + 38, 0, 0,
                                                       "�޸� ���� �ɹ���");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "�� �� ѡ ��");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //���°�ť
                modify_age_Button->show(4);
                break;
            }
            case 5: { //�ƫ��
                //��ʾ����򡢱�ǩ
                CLabel *input_Label = new CLabel(windowStartX + width - 22, windowStartY + 38, 0, 0, "�ƫ��");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * ���������Ļƫ��");
                CLabel *tip_type_Label = new CLabel(windowStartX + width - 31, windowStartY + 40, 0, 0,
                                                    "��������ѡ��ƫ��(0:�� 1:�ۺ��� 2:֪ʶ�� 3:������ 4:������)");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                tip_type_Label->show(6);
                //�򿪹����ʾ
                CTools::cursorVisible(true);
                //��������Ϣ
                int choice;
                while (true) {
                    //�������ʱ���������
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    string t = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                    bool flag = true;//�ж������Ƿ�Ϊ����
                    for (char c: t) {
                        if (!isdigit(c)) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * ����������������֣�");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true) {
                        choice = stoi(t);
                        if (choice < 0 || choice > 4) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * ����������ͷ�Χ 0 ~ 4��");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                        }
                    }
                    if (!flag)
                        continue;
                    CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                    cout << "                              ";
                    break;
                }
                switch (choice) {
                    case 0:
                        management.currentUser.preference = "��";
                        break;
                    case 1:
                        management.currentUser.preference = "�ۺ���";
                        break;
                    case 2:
                        management.currentUser.preference = "֪ʶ��";
                        break;
                    case 3:
                        management.currentUser.preference = "������";
                        break;
                    case 4:
                        management.currentUser.preference = "������";
                        break;
                }
                //�رչ����ʾ
                CTools::cursorVisible(false);
                //��ղ�������Ϣ
                CTools::empty(startX + width - 30, startY + 28, 15 * 2, 3);
                CTools::empty(windowStartX + width - 31, windowStartY + 37, 80, 6);
                //������Ϣ(currentUser����switch����)
                management.userList.find(management.currentUser.id)->second.preference=management.currentUser.preference;
                //�������
                string info = "�ƫ�ã�" + management.currentUser.preference;
                auto preference_Button = new CButton(startX + width - 30, startY + 28, 15, 3, info, 2);
                preference_Button->show(2);
                //��ʾ���ĳɹ�
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 9, windowStartY + 38, 0, 0,
                                                       "�޸� �ƫ�� �ɹ���");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "�� �� ѡ ��");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //���°�ť
                modify_preference_Button->show(4);
                break;
            }
        }
    } while (option != 0);
}

void PersonalWin::print1(int option) {
    switch (option) {//���ǣ�ʵ����ѡ
        case 1:
            cout << "1. �� �� ��" << endl;
            break;
        case 2:
            cout << "2. ��    ��" << endl;
            break;
        case 3:
            cout << "3. ��    ��" << endl;
            break;
        case 4:
            cout << "4. ��    ��" << endl;
            break;
        case 5:
            cout << "5. �ƫ��" << endl;
            break;
        case 0:
            cout << "0. ��    ��" << endl;
            break;
    }
    return;
}

void PersonalWin::updateOption1(int &option, int x) {
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

int PersonalWin::choose1() {
    int option = -1;          //ѡ���ܺ� 0���� 1�޸���Ϣ 2�ռ��� 3�����б�
    char key;
    int x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
    int y = startY + 33 + 3 / 2;
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
                CTools::goto_xy(x, y);//����ƶ��� 1. �� �� ��
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print1(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption1(option, x);
                print1(option);//���ǣ�ʵ����ѡ
                if (x == startX + width + 40 + (9 * 2 - 11) / 2 - 1)//����Ѿ�����0. ��    �أ�����ת1. �� �� ����ʵ�ֹ�������
                    x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
                else
                    x += 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption1(option, x);
                print1(option);//���ǣ�ʵ��ѡ��
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                //����ԭ����ɫ
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption1(option, x);
                print1(option);//���ǣ�ʵ����ѡ
                if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)//����Ѿ�����1. �� �� ��������ת0. ��    �أ�ʵ�ֹ�������
                    x = startX + width + 40 + (9 * 2 - 11) / 2 - 1;
                else x -= 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption1(option, x);
                print1(option);//���ǣ�ʵ��ѡ��
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void PersonalWin::print2(int option, int mode) {
    if (mode == 1) {
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "�� �� ��" << endl;
                break;
            case 2:
                cout << "�� �� ��" << endl;
                break;
        }
    } else if (mode == 2) {
        switch (option) {//���ǣ�ʵ����ѡ
            case 1:
                cout << "1. �� ��" << endl;
                break;
            case 0:
                cout << "0. �� ��" << endl;
                break;
        }
    }
    return;
}

void PersonalWin::updateOption2(int &option, int x, int mode) {
    if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)
        option = 1;
    else if (x == startX + width + 2 + (7 * 2 - 8) / 2 - 1) {
        if (mode == 1)
            option = 2;
        else if (mode == 2)
            option = 0;
    }
}

int PersonalWin::choose2(int mode) {
    //ѡ���ܺ�
    //mode=1ʱ
    //1���� 2�ܾ�
    //mode=2ʱ
    //1��� 0����
    int option = -1;
    char key;
    int x = startX + width - 16 + (7 * 2 - 8) / 2 - 1;
    int y = startY + 40 + 3 / 2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    while (option == -1) {
        do {
            key = getch();
            if (mode == 1) {
                if (key >= '1' && key <= '2') {//���ּ�ѡ��
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
            } else if (mode == 2) {
                if (key >= '0' && key <= '1') {//���ּ�ѡ��
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//����ƶ��� 1 ���� | 1 ���
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print2(1, mode);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                if (mode == 1) {
                    //����ԭ����ɫ
                    if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(5));
                    else SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                } else if (mode == 2)
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                updateOption2(option, x, mode);
                print2(option, mode);//���ǣ�ʵ����ѡ
                if (x == startX + width + 2 + (7 * 2 - 8) / 2 - 1)//����Ѿ����� �Ұ�ť ������ת ��ť ��ʵ�ֹ�������
                    x = startX + width - 16 + (7 * 2 - 8) / 2 - 1;
                else
                    x += 18;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption2(option, x, mode);
                print2(option, mode);//���ǣ�ʵ��ѡ��
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                if (mode == 1) {
                    //����ԭ����ɫ
                    if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(5));
                    else SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                } else if (mode == 2)
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                updateOption2(option, x, mode);
                print2(option, mode);//���ǣ�ʵ����ѡ
                if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)//����Ѿ����� ��ť ������ת �Ұ�ť ��ʵ�ֹ�������
                    x = startX + width + 2 + (7 * 2 - 8) / 2 - 1;
                else x -= 18;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption2(option, x, mode);
                print2(option, mode);//���ǣ�ʵ��ѡ��
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void PersonalWin::inBox() {
    CTools::empty(startX + width - 40, startY + 35, 85, 3);
    CButton *inBox_Button = new CButton(startX + width - 30, startY + 33, 30, 11, "", 3);
    CLabel *inBox_Label = new CLabel(startX + width - 5, startY + 34, 0, 0, "�� �� ��");
    inBox_Button->show(3);
    inBox_Label->show(3);
    CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
    if (management.currentUser.inBox.empty()) {//�ռ���Ϊ��
        CLabel *null_Label = new CLabel(startX + width - 9, startY + 37, 0, 0, "* �� �� �� Ϊ ��");
        null_Label->show(1);
        exit_Button->show(3);
        char key;
        while (true) {//ѡ���ܺ� 0����
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 30, startY + 33, 60, 10);
    } else {//�յ���������
        string name = management.currentUser.inBox;
        CLabel *tip_apply_Label = new CLabel(startX + width - 15, startY + 37, 0, 0, "�յ�����          �ĺ�������");
        CLabel *name_Label = new CLabel(startX + width - 7 + (10 - name.length()) / 2, startY + 37, 0, 0, name);
        CButton *accept_Button = new CButton(startX + width - 16, startY + 40, 7, 3, " �� �� ��", 5);
        CButton *reject_Button = new CButton(startX + width + 2, startY + 40, 7, 3, " �� �� ��", 1);
        tip_apply_Label->show(1);
        name_Label->show(2);
        accept_Button->show(5);
        reject_Button->show(1);
        int option = 74751;
        do {
            option = choose2(1);
            switch (option) {
                case 1: {
                    bool repeat=false;//��ʶλ����ʾ�Ƿ��ظ����
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    for(auto user:management.currentUser.broList){
                        if(user.name==name){
                            CTools::empty(startX + width - 16, startY + 37, 30, 5);
                            CLabel *tip_error_Label = new CLabel(startX + width - 16, startY + 37, 0, 0,
                                                                 "�Է��������ĺ��ѣ������ظ���ӣ�");
                            tip_error_Label->show(1);
                            repeat=true;
                            break;
                        }
                    }
                    if(repeat)
                        break;
                    CLabel *tip_accept_Label = new CLabel(startX + width - 15, startY + 37, 0, 0,
                                                          "����ͬ��          �ĺ�������");
                    CLabel *tip_friend_Label = new CLabel(startX + width - 8, startY + 39, 0, 0, "�����ѳ�Ϊ���ѣ�");
                    tip_accept_Label->show(1);
                    name_Label->show(2);
                    tip_friend_Label->show(1);
                    //���ܺ��ѣ���ӽ������б�
                    for (const auto& pair : management.userList) {
                        if(name==pair.second.name){
                            //������Ϣ
                            management.currentUser.broList.push_back(pair.second);
                            management.userList.find(management.currentUser.id)->second.broList.push_back(pair.second);
                            break;
                        }
                    }
                    //ͬʱ�����Լ���ӽ��Է������б���
                    for (auto& pair : management.userList) {
                        if(name==pair.second.name){
                            //������Ϣ
                            pair.second.broList.push_back(management.currentUser);
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    CLabel *tip_reject_Label = new CLabel(startX + width - 15, startY + 37, 0, 0,
                                                          "���Ѿܾ�          �ĺ�������");
                    tip_reject_Label->show(1);
                    name_Label->show(2);
                    break;
                }
            }
        } while (option != 1 && option != 2);
        exit_Button->show(3);
        char key;
        while (true) {//ѡ���ܺ� 0����
            key = getch();
            if (key == '0')
                break;
        }
        //��Ϣ�Ѷ������
        management.currentUser.inBox.clear();
        //�����û���Ϣ
        management.userList.find(management.currentUser.id)->second.inBox.clear();
        //�������
        CTools::empty(startX + width - 30, startY + 33, 60, 10);
    }
}

void PersonalWin::broList() {
    CTools::empty(startX + width - 40, startY + 35, 85, 3);
    CButton *broList_Button = new CButton(startX + width - 40, startY + 33, 40, 11, "", 3);
    CLabel *broList_Label = new CLabel(startX + width - 6, startY + 34, 0, 0, "�� �� �� ��");
    broList_Button->show(3);
    broList_Label->show(3);
    CButton *add_Button = new CButton(startX + width - 16, startY + 40, 7, 3, "1. �� ��", 3);
    CButton *exit_Button = new CButton(startX + width + 2, startY + 40, 7, 3, "0. �� ��", 3);

    if (management.currentUser.broList.empty()) {
        CLabel *null_Label = new CLabel(startX + width - 11, startY + 37, 0, 0, "* �� �� �� �� Ϊ ��");
        null_Label->show(1);
        add_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
        bool show=true;//��ʶλ����ʾ�Ƿ���ʾ������Ϣ
        do {
            option = choose2(2);
            switch (option) {
                case 1: {//1. �� ��
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    //��ʾ����򡢱�ǩ
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 37, 0, 0, "��  ��");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 37, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0,
                                                         " * ����������˺�");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //��������id
                    string id;
                    while (true) {
                        //�������ʱ���������
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 37);
                        cout << "                    ";
                        //�򿪹����ʾ
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 37, 20, 20, 0);
                        //�رչ����ʾ
                        CTools::cursorVisible(false);
                        //�ж��û��Ƿ����
                        User bro;//�ҵ��ĺ���
                        bool flag = false;
                        auto it = management.userList.find(id);
                        if (it != management.userList.end()){//�ҵ�
                            if(it->second.id== management.currentUser.id){
                                CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                CLabel *tip_error_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                     "����������Լ���");
                                tip_error_Label->show(1);
                                CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
                                exit_Button->show(3);
                                char key;
                                while (true) {//ѡ���ܺ� 0 ����
                                    key = getch();
                                    if (key == '0')
                                        break;
                                }
                                CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                flag = false;
                                back=true;
                            }else if(it->first == id){
                                bro = it->second;
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            if (back)
                                break;
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 37);
                            cout << "                       ";
                            if(show){
                                CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0," * ��������û�������");
                                tip_error_Label->show(1);
                            }
                            //ѡ���Ƿ��������
                            add_Button->show(3);
                            exit_Button->show(3);
                            int choice = 74751;
                            choice = choose2(2);
                            switch (choice) {
                                case 1://���� 1. �� ��
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
                        } else {//�û�����
                            //������Ϣ,���ͺ�������
                            management.userList.find(bro.id)->second.inBox=management.currentUser.name;
                            CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                            CLabel *tip_success_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                   "�ѷ��ͺ������룡");
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
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    back = true;
                    break;
                }
            }
            if (back)
                break;
        } while (option != 1 && option != 0);
        CTools::empty(startX + width - 40, startY + 33, 80, 10);
    }
    else {//�����б�ǿ�
        if(management.currentUser.broList.size()==1){
            string user_name = "����1:" + management.currentUser.broList[0].name;
            auto name_Button = new CButton(startX + width - 10, startY + 36, 10, 3, user_name, 2);
            name_Button->show(2);
            add_Button->show(3);
            exit_Button->show(3);
            int option = 74751;
            bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
            bool show=true;//��ʶλ����ʾ�Ƿ���ʾ������Ϣ
            do {
                option = choose2(2);
                switch (option) {
                    case 1: {//1. �� ��
                        CTools::empty(startX + width - 16, startY + 37, 30, 5);
                        //��ʾ����򡢱�ǩ
                        CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 37, 0, 0, "��  ��");
                        CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 37, 15, 3, "", 8, 2, 0);
                        CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0,
                                                             " * ����������˺�");
                        input_Label->show(0);
                        input_Edit->show(0);
                        tip_input_Label->show(6);

                        //���������û���
                        string id;
                        while (true) {
                            //�������ʱ���������
                            CTools::goto_xy(windowStartX + width - 13, windowStartY + 37);
                            cout << "                    ";
                            //�򿪹����ʾ
                            CTools::cursorVisible(true);
                            id = CTools::input(windowStartX + width - 13, windowStartY + 37, 20, 20, 0);
                            //�رչ����ʾ
                            CTools::cursorVisible(false);
                            //�ж��û��Ƿ����
                            User bro;//�ҵ��ĺ���
                            bool flag = false;
                            bool repeat=false;//��ʶλ����ʾ�Ƿ��ظ����
                            auto it = management.userList.find(id);
                            if (it != management.userList.end()){//�ҵ�
                                for(auto user:it->second.broList){
                                    if(user.id==management.currentUser.id){
                                        CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                        CLabel *tip_error_Label = new CLabel(startX + width - 16, startY + 37, 0, 0,
                                                                             "�Է��������ĺ��ѣ������ظ���ӣ�");
                                        tip_error_Label->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//ѡ���ܺ� 0 ����
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                        flag = false;
                                        back=true;
                                        repeat=true;
                                        break;
                                    }
                                }
                                if(it->second.id== management.currentUser.id){
                                    CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                    CLabel *tip_error_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                         "����������Լ���");
                                    tip_error_Label->show(1);
                                    CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
                                    exit_Button->show(3);
                                    char key;
                                    while (true) {//ѡ���ܺ� 0 ����
                                        key = getch();
                                        if (key == '0')
                                            break;
                                    }
                                    CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                    flag = false;
                                    back=true;
                                }else if(it->first == id){
                                    if(!repeat){//���ظ�������
                                        bro = it->second;
                                        flag = true;
                                    }
                                }
                            }
                            if (flag == false) {
                                if (back)
                                    break;
                                CTools::goto_xy(windowStartX + width + 13, windowStartY + 37);
                                cout << "                       ";
                                if(show){
                                    CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0," * ��������û�������");
                                    tip_error_Label->show(1);
                                }
                                //ѡ���Ƿ��������
                                add_Button->show(3);
                                exit_Button->show(3);
                                int choice = 74751;
                                choice = choose2(2);
                                switch (choice) {
                                    case 1://���� 1. �� ��
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
                            } else {//�û�����
                                //������Ϣ,���ͺ�������
                                management.userList.find(bro.id)->second.inBox=management.currentUser.name;
                                CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                CLabel *tip_success_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                       "�ѷ��ͺ������룡");
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
                        CTools::empty(startX + width - 16, startY + 37, 30, 5);
                        back = true;
                        break;
                    }
                }
                if (back)
                    break;
            } while (option != 1 && option != 0);
            CTools::empty(startX + width - 40, startY + 33, 80, 10);
        }
        else{
            string user1_name = "����1:" + management.currentUser.broList[0].name;
            string user2_name = "����2:" + management.currentUser.broList[1].name;
            auto bro1_Button = new CButton(startX + width - 18, startY + 36, 10, 3, user1_name, 2);
            auto bro2_Button = new CButton(startX + width + 1, startY + 36, 10, 3, user2_name, 2);
            bro1_Button->show(2);
            bro2_Button->show(2);
            add_Button->show(3);
            exit_Button->show(3);
            int option = 74751;
            bool back = false;//��ʶλ����ʾ�Ƿ񷵻�
            bool show=true;//��ʶλ����ʾ�Ƿ���ʾ������Ϣ
            do {
                option = choose2(2);
                switch (option) {
                    case 1: {//1. �� ��
                        CTools::empty(startX + width - 18, startY + 36, 40, 6);
                        //��ʾ����򡢱�ǩ
                        CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 37, 0, 0, "��  ��");
                        CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 37, 15, 3, "", 8, 2, 0);
                        CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0,
                                                             " * ����������˺�");
                        input_Label->show(0);
                        input_Edit->show(0);
                        tip_input_Label->show(6);

                        //���������û���
                        string id;
                        while (true) {
                            //�������ʱ���������
                            CTools::goto_xy(windowStartX + width - 13, windowStartY + 37);
                            cout << "                    ";
                            //�򿪹����ʾ
                            CTools::cursorVisible(true);
                            id = CTools::input(windowStartX + width - 13, windowStartY + 37, 20, 20, 0);
                            //�رչ����ʾ
                            CTools::cursorVisible(false);
                            //�ж��û��Ƿ����
                            User bro;//�ҵ��ĺ���
                            bool flag = false;
                            bool repeat=false;//��ʶλ����ʾ�Ƿ��ظ����
                            auto it = management.userList.find(id);
                            if (it != management.userList.end()){//�ҵ�
                                for(auto user:it->second.broList){
                                    if(user.id==management.currentUser.id){
                                        CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                        CLabel *tip_error_Label = new CLabel(startX + width - 16, startY + 37, 0, 0,
                                                                             "�Է��������ĺ��ѣ������ظ���ӣ�");
                                        tip_error_Label->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//ѡ���ܺ� 0 ����
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                        flag = false;
                                        back=true;
                                        repeat=true;
                                        break;
                                    }
                                }
                                if(it->second.id== management.currentUser.id){
                                    CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                    CLabel *tip_error_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                         "����������Լ���");
                                    tip_error_Label->show(1);
                                    CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. ��    ��", 3);
                                    exit_Button->show(3);
                                    char key;
                                    while (true) {//ѡ���ܺ� 0 ����
                                        key = getch();
                                        if (key == '0')
                                            break;
                                    }
                                    CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                    flag = false;
                                    back=true;
                                }else if(it->first == id){
                                    if(!repeat){//���ظ�������
                                        bro = it->second;
                                        flag = true;
                                    }
                                }
                            }
                            if (flag == false) {
                                if (back)
                                    break;
                                CTools::goto_xy(windowStartX + width + 13, windowStartY + 37);
                                cout << "                       ";
                                if(show){
                                    CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0," * ��������û�������");
                                    tip_error_Label->show(1);
                                }
                                //ѡ���Ƿ��������
                                add_Button->show(3);
                                exit_Button->show(3);
                                int choice = 74751;
                                choice = choose2(2);
                                switch (choice) {
                                    case 1://���� 1. �� ��
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
                            } else {//�û�����
                                //������Ϣ,���ͺ�������
                                management.userList.find(bro.id)->second.inBox=management.currentUser.name;
                                CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                CLabel *tip_success_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                       "�ѷ��ͺ������룡");
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
                        CTools::empty(startX + width - 18, startY + 36, 40, 6);
                        back = true;
                        break;
                    }
                }
                if (back)
                    break;
            } while (option != 1 && option != 0);
            CTools::empty(startX + width - 40, startY + 33, 80, 10);
        }
    }
}