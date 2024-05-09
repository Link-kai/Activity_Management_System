#ifndef ACTIVITY_MANAGEMENT_SYSTEM_QUITWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_QUITWIN_H

#include "../public.h"

class QuitWin {
public:
    //空参构造
    QuitWin();

    //带参构造
    QuitWin(int x, int y, int w, int h);

    //析构函数
    ~QuitWin();

    void fozu();

    //致谢
    void thank();

    //显示窗口
    void showWindow();

    int startX;
    int startY;
    int width;
    int height;
    //组件
    CLabel *toolbar_Label, *title_Label, *userName_Label, *pwd_Label;   //文本
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_QUITWIN_H
