#include "../public.h"

CEdit::~CEdit() {
}

CEdit::CEdit() : CtrBase()  //基类的构造传参
{
    this->maxLen = 0;
    this->inputType = 0;
    this->ips = 0;
}

//为基类的构造进行传参 关注点：派生类形参的名称
CEdit::CEdit(int x, int y, int w, int h, string content,
             int maxLen, int inputType, int ips)
        : CtrBase(x, y, w, h, content) {
    this->maxLen = maxLen;
    this->inputType = inputType;
    this->ips = ips;
}


void CEdit::show(int colour) {
    CTools::drawWindow(startX - 1, startY - 1, width, height,colour);
    CtrBase::show(this->startX,this->startY,colour);
}