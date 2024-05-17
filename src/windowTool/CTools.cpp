#include "../public.h"

//光标跳转
void CTools::goto_xy(int x, int y) {
    //获取句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //光标结构体
    COORD pos = {(short) x, (short) y};
    SetConsoleCursorPosition(hOut, pos);
}

void CTools::drawWindow(int startX, int startY, int width, int height, int colour) {
    //设置颜色
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(colour));//设置颜色
    int i = 0;
    //打印顶部
    //光标定位 找规律 ┗  ┛ ┏ ┓ ┃ ━
    goto_xy(startX, startY);
    printf("╭");
    for (i = 0; i < width - 2; i++)  //控制循环次数width-2次
    {
        //Sleep(1);
        printf("━ ");
    }
    printf("╮");
    if(startX==windowStartX&&startY==windowStartY||startX==windowStartX+windowWidth-60&&startY==windowStartY+15||startX==windowStartX+windowWidth-60&&startY==windowStartY+15){
        //打印表头线
        goto_xy(startX, startY + 2);
        for (i = 0; i < width - 1; i++)  //控制循环次数width-2次
            printf("━ ");
    }

    //左边 x不变 y在变 (y到y+height)
    for (i = 1; i <= height - 1; i++) {
        //Sleep(1);
        goto_xy(startX, startY + i);
        printf("┃");
        goto_xy(startX + width * 2 - 3, startY + i);
        printf("┃");
    }

    //底部 x在变化    y不变 （x到x+width） ━
    goto_xy(startX, startY + height - 1);
    printf("╰");
    for (i = 0; i < width - 2; i++)
        printf("━ ");
    printf("╯");

    goto_xy(startX, startX + height);
}

void CTools::empty(int startX, int startY, int width, int height){
    for(int i=0;i<=width;++i){
        for(int j=0;j<=height;++j){
            CTools::goto_xy(startX+i, startY+j);
            cout<<" ";
        }
        cout<<endl;
    }
}

string CTools::input(int x, int y, int maxLen, int maxLine, int ips) {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
    if(x==windowStartX + windowWidth - 22 + 10 + 1)
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(10));
    CTools::goto_xy(x, y);
    string text;
    char key;
    int len = 0, line = 0;
    while ((key = getch()) != '\r' && len < maxLen) {
        if (key == KEY_LEFT || key == KEY_UP || key == KEY_RIGHT || key == KEY_DOWN_) {
            key = '\0';
            text.pop_back();
            continue;
        }
        if (key == VK_BACK) {
            if (len != 0) {
                CTools::goto_xy(x + len - 1, y);
                putchar(' ');
                CTools::goto_xy(x + len - 1, y);
                text.pop_back();
                len--;
            }
        } else {
            if (line == maxLine - 1)
                CTools::goto_xy(x, y + 1);
            if (ips == 1)
                putchar('*');
            else putchar(key);
            text.push_back(key);
            len++;
        }
    }
    return text;
}

int CTools::choose(){
    char key;
    int option = 0;
    while (true) {
        key = getch();
        if(key=='0'||key=='1'||key=='2'){
            option=key-'0';
            break;
        }
    }
    return option;
}

void CTools::cursorVisible(bool flag){
    //flag true 开启光标显示  flag false 关闭光标显示
    HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cInfo{};
    GetConsoleCursorInfo(hOutput, &cInfo); //获取现有光标信息
    cInfo.bVisible = flag; //false为隐藏窗口,true为显示窗口
    SetConsoleCursorInfo(hOutput, &cInfo);  //重新设置光标信息
}

//获取鼠标相对于控制台位置
POINT CTools::GetMousePos() {
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(GetForegroundWindow(), &p);
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    CONSOLE_FONT_INFO consoleCurrentFont;
    GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont);
    p.x /= consoleCurrentFont.dwFontSize.X;
    p.y = (p.y - consoleCurrentFont.dwFontSize.Y / 2) / consoleCurrentFont.dwFontSize.Y;
    return p;
}

/*
函数名：int getkey()
函数功能：获取用户输入的任意键盘值
函数参数：无
函数返回：ascii
*/
/*int CTools::getkey() {
    char key = 0;
    key = getch();
    if (key == -32)//方向按键 第一个值都是32
    {
        key = getch();
        switch (key) {
            case 72:
                return KEY_UP;
            case 80:
                return KEY_DOWN;
            case 75:
                return KEY_LEFT;
            case 77:
                return KEY_RIGHT;
        }
    } else if (key == 13) {
        return KEY_ENTER;
    } else if (key == 27) {
        return KEY_ESC;
    }
    return key;
}*/