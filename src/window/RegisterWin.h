#ifndef ACTIVITY_MANAGEMENT_SYSTEM_REGISTERWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_REGISTERWIN_H

#include "../public.h"

class RegisterWin {
public:
    //空参构造
    RegisterWin();

    //带参构造
    RegisterWin(int x, int y, int w, int h);

    //析构函数
    ~RegisterWin();

    //佛祖
    void fozu();

    //显示窗口
    void showWindow();

    //注册
    void signUp();

    int startX;
    int startY;
    int width;
    int height;

    //组件
    CLabel *toolbar_Label, *title_Label, *userName_Label, *pwd_Label, *again_pwd_Label;     //文本
    CButton *register_Button, *exit_Button;                                                 //按钮
    CEdit *userName_Edit, *pwd_Edit, *again_pwd_Edit;                                       //输入框

};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_REGISTERWIN_H
