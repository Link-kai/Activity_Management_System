#include "../public.h"

//�����ת
void CTools::goto_xy(int x, int y) {
    //��ȡ���
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ṹ��
    COORD pos = {(short) x, (short) y};
    SetConsoleCursorPosition(hOut, pos);
}

void CTools::drawWindow(int startX, int startY, int width, int height, int colour) {
    //������ɫ
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(colour));//������ɫ
    int i = 0;
    //��ӡ����
    //��궨λ �ҹ��� ��  �� �� �� �� ��
    goto_xy(startX, startY);
    printf("�q");
    for (i = 0; i < width - 2; i++)  //����ѭ������width-2��
    {
        //Sleep(1);
        printf("�� ");
    }
    printf("�r");
    if(startX==windowStartX&&startY==windowStartY||startX==windowStartX+windowWidth-60&&startY==windowStartY+15||startX==windowStartX+windowWidth-60&&startY==windowStartY+15){
        //��ӡ��ͷ��
        goto_xy(startX, startY + 2);
        for (i = 0; i < width - 1; i++)  //����ѭ������width-2��
            printf("�� ");
    }

    //��� x���� y�ڱ� (y��y+height)
    for (i = 1; i <= height - 1; i++) {
        //Sleep(1);
        goto_xy(startX, startY + i);
        printf("��");
        goto_xy(startX + width * 2 - 3, startY + i);
        printf("��");
    }

    //�ײ� x�ڱ仯    y���� ��x��x+width�� ��
    goto_xy(startX, startY + height - 1);
    printf("�t");
    for (i = 0; i < width - 2; i++)
        printf("�� ");
    printf("�s");

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
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
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
    //flag true ���������ʾ  flag false �رչ����ʾ
    HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cInfo{};
    GetConsoleCursorInfo(hOutput, &cInfo); //��ȡ���й����Ϣ
    cInfo.bVisible = flag; //falseΪ���ش���,trueΪ��ʾ����
    SetConsoleCursorInfo(hOutput, &cInfo);  //�������ù����Ϣ
}

//��ȡ�������ڿ���̨λ��
POINT CTools::GetMousePos() {
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(GetForegroundWindow(), &p);
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��׼������
    CONSOLE_FONT_INFO consoleCurrentFont;
    GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont);
    p.x /= consoleCurrentFont.dwFontSize.X;
    p.y = (p.y - consoleCurrentFont.dwFontSize.Y / 2) / consoleCurrentFont.dwFontSize.Y;
    return p;
}

/*
��������int getkey()
�������ܣ���ȡ�û�������������ֵ
������������
�������أ�ascii
*/
/*int CTools::getkey() {
    char key = 0;
    key = getch();
    if (key == -32)//���򰴼� ��һ��ֵ����32
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