#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CBUTTON_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CBUTTON_H

#include "../public.h"

class CButton : public CtrBase {
public:
    //默认构造
    CButton();

    //带参构造
    CButton(int x, int y, int w, int h, string content,WORD color);

    //析构函数
    ~CButton();

    void show(int colour = 0);

    WORD color;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CBUTTON_H
