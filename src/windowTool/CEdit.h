#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CEDIT_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CEDIT_H

#include "../public.h"

class CEdit : public CtrBase {
public :
    //默认构造
    CEdit();

    //带参构造
    CEdit(int x, int y, int w, int h, string content, int maxLen, int inputType, int ips);

    //析构函数
    ~CEdit();

    void show(int colour);

private:
    int inputType;  //输入的类型
    int maxLen;  //最大长度
    int ips;  //1 明文 0 密文
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_CEDIT_H
