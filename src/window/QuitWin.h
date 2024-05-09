#ifndef ACTIVITY_MANAGEMENT_SYSTEM_QUITWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_QUITWIN_H

#include "../public.h"

class QuitWin {
public:
    //�ղι���
    QuitWin();

    //���ι���
    QuitWin(int x, int y, int w, int h);

    //��������
    ~QuitWin();

    void fozu();

    //��л
    void thank();

    //��ʾ����
    void showWindow();

    int startX;
    int startY;
    int width;
    int height;
    //���
    CLabel *toolbar_Label, *title_Label, *userName_Label, *pwd_Label;   //�ı�
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_QUITWIN_H
