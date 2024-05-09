#ifndef ACTIVITY_MANAGEMENT_SYSTEM_INITWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_INITWIN_H

#include "../public.h"

class InitWin {
public:
    InitWin();

    InitWin(int x, int y, int w, int h);

    ~InitWin();

    void fozu();

    void showWindow();

    void print(int option);

    void updateOption(int& option,int x);

    int choose();

    int startX;
    int startY;
    int width;
    int height;
    CLabel *toolbar_Label, *title_Label;
    CEdit *introduce_Edit;
    CButton *register_Button, *login_Button, *exit_Button;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_INITWIN_H
