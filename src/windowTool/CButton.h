#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CBUTTON_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CBUTTON_H

#include "../public.h"

class CButton : public CtrBase {
public:
    //Ĭ�Ϲ���
    CButton();

    //���ι���
    CButton(int x, int y, int w, int h, string content,WORD color);

    //��������
    ~CButton();

    void show(int colour = 0);

    WORD color;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CBUTTON_H
