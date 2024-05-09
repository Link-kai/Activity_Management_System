#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CTRBASE_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CTRBASE_H

#include "../public.h"

class CtrBase {
public:
    //Ĭ�Ϲ���
    CtrBase();

    //���ι���
    CtrBase(int x, int y, int w, int h, string content);

    //��������
    virtual ~CtrBase();

    //ѡ����ɫ static
    static WORD selectColour(int colour=0);

    void show(int x,int y,int colour=0);

//protected:  //�����Ա������protected����
    int startX;
    int startY;
    int width;
    int height;
    string content;  //����
    int colour;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CTRBASE_H
