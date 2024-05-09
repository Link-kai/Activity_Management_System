#ifndef ACTIVITY_MANAGEMENT_SYSTEM_HOMEWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_HOMEWIN_H
#include "../public.h"

class HomeWin{
public:
    //空参构造
    HomeWin();

    //带参构造
    HomeWin(int x, int y, int w, int h);

    //析构函数
    ~HomeWin();

    //scau图案
    void scau();

    //显示窗口
    void showWindow();

    void print(int option);

    void updateOption(int& option,int y);

    int choose();

    int startX;
    int startY;
    int width;
    int height;
    CLabel *toolbar_Label, *title_Label,*system_Label;
    CButton *user_Button, *activity_Button, *exit_Button;
};
#endif //ACTIVITY_MANAGEMENT_SYSTEM_HOMEWIN_H
