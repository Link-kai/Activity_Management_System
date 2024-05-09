#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CLABEL_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CLABEL_H

#include "../public.h"

class CLabel : public CtrBase {
public:
    //默认构造
    CLabel();

    //带参构造（对于CLabel，w h 无意义）
    CLabel(int x, int y, int w, int h, string content);

    //析构函数
    ~CLabel();

    //选择颜色
    //WORD selectColour(int colour);

    void show(int colour = 0);

private:
    int colour;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CLABEL_H
