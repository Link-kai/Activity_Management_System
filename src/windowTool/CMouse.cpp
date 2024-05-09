//#include "../public.h"
//
//bool isInside(COORD hangPosition, CButton *button) {
//    return hangPosition.X >= button->startX && hangPosition.X < button->startX + button->width &&
//           hangPosition.Y >= button->startY && hangPosition.Y < button->startY + button->height;
//}
//
////void refresh(COORD hangPosition,vector<CButton*>& buttons) {
////
////    for (auto &button : buttons) {
////        if(isInside(hangPosition,*button))
////            button->setHighLight();
////        else
////            button->setDefault();
////    }
////}
//
//int CMouse::check(vector<CButton *> &buttons) {
//    while (true) {
//        int id;     //按钮id
//        int t=0;    //临时变量
//        POINT p;
//        GetCursorPos(&p);
//        HWND h = GetForegroundWindow();
//        ScreenToClient(h, &p);               //获取鼠标在窗口上的位置
//        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
//        CONSOLE_FONT_INFO consoleCurrentFont;
//        GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont); //获取字体信息
//        int x = p.x /= consoleCurrentFont.dwFontSize.X;
//        int y = p.y /= consoleCurrentFont.dwFontSize.Y;
//        COORD pos = {(short) x, (short) y};
//        for (CButton *button: buttons) {
//            if (isInside(pos, button))
//                button->setHighLight();
//            else button->setDefault();
//        }
//        if(KEY_DOWN(VK_LBUTTON)) {            //鼠标左键按下
//            for (CButton *button: buttons) {
//                if (isInside(pos, button))
//                    return id;
//                id++;
//            }
//        }
////        if(KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
////
////            if(isInside)
////        }
//            Sleep(100);                            //等待100毫秒，减少CPU占用
//    }
//}