#ifndef ACTIVITY_MANAGEMENT_SYSTEM_LOGINWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_LOGINWIN_H

#include "../public.h"

class LoginWin {
public :
    //�ղι���
    LoginWin();

    //���ι���
    LoginWin(int x, int y, int w, int h);

    //��������
    ~LoginWin();

    //����
    void fozu();

    //��ʾ����
    void showWindow();

    //��¼
    void login(bool flag);

    int startX;
    int startY;
    int width;
    int height;

    //���
    CLabel *toolbar_Label, *title_Label, *userId_Label, *pwd_Label;     //�ı�
    CButton *login_Button, *exit_Button;                                //��ť
    CEdit *userId_Edit, *pwd_Edit;                                      //�����
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_LOGINWIN_H
