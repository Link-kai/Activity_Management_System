#ifndef ACTIVITY_MANAGEMENT_SYSTEM_LOGINWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_LOGINWIN_H

#include "../public.h"

class LoginWin {
public :
    //空参构造
    LoginWin();

    //带参构造
    LoginWin(int x, int y, int w, int h);

    //析构函数
    ~LoginWin();

    //佛祖
    void fozu();

    //显示窗口
    void showWindow();

    //登录
    void login(bool flag);

    int startX;
    int startY;
    int width;
    int height;

    //组件
    CLabel *toolbar_Label, *title_Label, *userId_Label, *pwd_Label;     //文本
    CButton *login_Button, *exit_Button;                                //按钮
    CEdit *userId_Edit, *pwd_Edit;                                      //输入框
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_LOGINWIN_H
