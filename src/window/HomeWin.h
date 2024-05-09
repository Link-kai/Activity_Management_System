#ifndef ACTIVITY_MANAGEMENT_SYSTEM_HOMEWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_HOMEWIN_H
#include "../public.h"

class HomeWin{
public:
    //�ղι���
    HomeWin();

    //���ι���
    HomeWin(int x, int y, int w, int h);

    //��������
    ~HomeWin();

    //scauͼ��
    void scau();

    //��ʾ����
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
