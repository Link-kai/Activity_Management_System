#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CEDIT_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CEDIT_H

#include "../public.h"

class CEdit : public CtrBase {
public :
    //Ĭ�Ϲ���
    CEdit();

    //���ι���
    CEdit(int x, int y, int w, int h, string content, int maxLen, int inputType, int ips);

    //��������
    ~CEdit();

    void show(int colour);

private:
    int inputType;  //���������
    int maxLen;  //��󳤶�
    int ips;  //1 ���� 0 ����
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CEDIT_H
