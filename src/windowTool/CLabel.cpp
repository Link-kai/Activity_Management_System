#include "../public.h"

CLabel::CLabel() : CtrBase() {
}

CLabel::CLabel(int x, int y, int w, int h, string content)
        : CtrBase(x, y, w, h, content) {
    this->colour=colour;
}


CLabel::~CLabel() {
}

//WORD CLabel::selectColour(int colour){
//    //1£ººì
//    //2£º»Æ
//    //3£ºÂÌ
//    //4£º±¡ºÉÀ¶
//    //5£º×ÏÀ¶
//    //6£º×Ï
//    //7£º»Ò
//    switch(colour){
//        case 1: return FOREGROUND_INTENSITY|FOREGROUND_RED;
//        case 2: return FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN;
//        case 3: return FOREGROUND_INTENSITY|FOREGROUND_GREEN;
//        case 4: return FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE;
//        case 5: return FOREGROUND_INTENSITY|FOREGROUND_BLUE;
//        case 6: return FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED;
//        case 7: return FOREGROUND_INTENSITY;
//        default: return 7;
//    }
//}

void CLabel::show(int colour) {
    CtrBase::show(this->startX,this->startY,colour);
}