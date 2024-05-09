#ifndef ACTIVITY_MANAGEMENT_SYSTEM_PERSONALWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_PERSONALWIN_H

#include "../public.h"

class PersonalWin {
public:
    //空参构造
    PersonalWin();

    //带参构造
    PersonalWin(int x, int y, int w, int h);

    //析构函数
    ~PersonalWin();

    //scau图案
    void scau();

    //显示窗口
    void showWindow();

    //选择功能
    void print(int option);
    void updateOption(int &option, int y);
    int choose();

    //1. 修改信息
    void modify();
    //2. 收件箱
    void inBox();
    //3. 好友列表
    void broList();

    //选择修改信息
    void print1(int option);
    void updateOption1(int &option, int y);
    int choose1();

    //好友申请选择 | 添加好友选择
    void print2(int option,int mode);       //mode 1 2 对应上面两种模式
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
