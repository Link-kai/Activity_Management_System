#include "../public.h"

CButton::CButton() : CtrBase() {
}

CButton::CButton(int x, int y, int w, int h, string content,WORD color)
        : CtrBase(x, y, w, h, content) {
    this->color=color;
}

CButton::~CButton() {
}

void CButton::show(int colour) {
    CTools::drawWindow(startX, startY, width, height, colour);
    CTools::goto_xy(startX + (width * 2 - content.length()) / 2 - 1, startY + height/2);
    cout << content << endl;
}