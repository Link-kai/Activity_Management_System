#ifndef ACTIVITY_MANAGEMENT_SYSTEM_PERSONALWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_PERSONALWIN_H

#include "../public.h"

class PersonalWin {
public:
    //�ղι���
    PersonalWin();

    //���ι���
    PersonalWin(int x, int y, int w, int h);

    //��������
    ~PersonalWin();

    //scauͼ��
    void scau();

    //��ʾ����
    void showWindow();

    //ѡ����
    void print(int option);
    void updateOption(int &option, int y);
    int choose();

    //1. �޸���Ϣ
    void modify();
    //2. �ռ���
    void inBox();
    //3. �����б�
    void broList();

    //ѡ���޸���Ϣ
    void print1(int option);
    void updateOption1(int &option, int y);
    int choose1();

    //��������ѡ�� | ��Ӻ���ѡ��
    void print2(int option,int mode);       //mode 1 2 ��Ӧ��������ģʽ
    void updateOption2(int &option, int x,int mode);
    int choose2(int mode);

    int startX;
    int startY;
    int width;
    int height;
    CLabel *toolbar_Label, *title_Label, *system_Label, *personalData_Label;
    CButton *base_Button, *id_Button, *name_Button, *gender_Button, *age_Button, *preference_Button, *admin_Button;
    CButton *modify_Button,*inBox_Button,*bro_Button,*exit_Button;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_PERSONALWIN_H
