#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CLABEL_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CLABEL_H

#include "../public.h"

class CLabel : public CtrBase {
public:
    //Ĭ�Ϲ���
    CLabel();

    //���ι��죨����CLabel��w h �����壩
    CLabel(int x, int y, int w, int h, string content);

    //��������
    ~CLabel();

    //ѡ����ɫ
    //WORD selectColour(int colour);

    void show(int colour = 0);

private:
    int colour;
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CLABEL_H
