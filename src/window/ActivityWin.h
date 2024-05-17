#ifndef ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITYWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITYWIN_H

#include "../public.h"

class ActivityWin{
public:
    //空参构造
    ActivityWin();

    //带参构造
    ActivityWin(int x, int y, int w, int h);

    //析构函数
    ~ActivityWin();

    //scau图案
    void scau();

    //显示窗口
    void showWindow();

    //选择功能
    void print(int option);
    void updateOption(int &option, int x);
    int choose();

    //选择功能
    void print1(int option,int mode);
    void updateOption1(int &option, int x,int mode);
    int choose1(int mode);

    //1. 浏览活动
    void viewActivity();
    //2. 创建活动
    void creatActivity();
    //3. 我的活动
    void myActivity();
    //4. 我的参加
    void myAttend();
    //5. 统计功能
    void statisticsActivity();
    int startX;
    int startY;
    int width;
    int height;

    CLabel *toolbar_Label, *title_Label, *system_Label;
    CButton *view_activity_Button,*creat_activity_Button,*my_creat_Button,*my_attend_Button,*statistics_activity_Button,*exit_Button;

};
#endif //ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITYWIN_H
