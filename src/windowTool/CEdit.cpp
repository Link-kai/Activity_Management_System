#include "../public.h"

CEdit::~CEdit() {
}

CEdit::CEdit() : CtrBase()  //����Ĺ��촫��
{
    this->maxLen = 0;
    this->inputType = 0;
    this->ips = 0;
}

//Ϊ����Ĺ�����д��� ��ע�㣺�������βε�����
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