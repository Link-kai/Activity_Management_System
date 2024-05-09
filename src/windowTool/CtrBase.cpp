#include "../public.h"

CtrBase::CtrBase() {
    this->startX = 0;
    this->startY = 0;
    this->width = 0;
    this->height = 0;
    this->content = "";
}

CtrBase::~CtrBase() {
}

CtrBase::CtrBase(int x, int y, int w, int h, string content) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;
    this->content.assign(content);
}

WORD CtrBase::selectColour(int colour) {
    //1����
    //2����
    //3����
    //4��������
    //5������
    //6����
    //7����
    //8����ťѡ�к�
    //9������Ĭ��ɫ
    switch (colour) {
        case 1:
            return FOREGROUND_INTENSITY | FOREGROUND_RED;
        case 2:
            return FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN;
        case 3:
            return FOREGROUND_INTENSITY | FOREGROUND_GREEN;
        case 4:
            return FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;
        case 5:
            return FOREGROUND_INTENSITY | FOREGROUND_BLUE;
        case 6:
            return FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED;
        case 7:
            return FOREGROUND_INTENSITY;

            //��ťѡ����
        case 8:
            return BACKGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;
        case 9:
            return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        default:
            return 7;
    }
}

void CtrBase::show(int x, int y, int colour) {
    CTools::goto_xy(this->startX, this->startY);
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(colour));//������ɫ
    cout << this->content << endl;
}