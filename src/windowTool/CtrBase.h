#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CTRBASE_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CTRBASE_H

#include "../public.h"

class CtrBase {
public:
    //默认构造
    CtrBase();

    //带参构造
    CtrBase(int x, int y, int w, int h, string content);

    //析构函数
    virtual ~CtrBase();

    //选择颜色 static
    static WORD selectColour(int colour=0);

    void show(int x,int y,int colour=0);

//protected:  //基类成员属性用protected修饰
    int startX;
    int startY;
    int width;
    int height;
    string content;  //内容
    int colour;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CTRBASE_H
