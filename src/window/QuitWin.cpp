#include "../public.h"

QuitWin::QuitWin() {
}

QuitWin::QuitWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(windowStartX + width - 7, windowStartY - 1, 0, 0, "�����ϵͳ");
    this->title_Label = new CLabel(windowStartX + width - 5, windowStartY + 1, 0, 0, "�˳�ҳ");

}

QuitWin::~QuitWin() {
}

void QuitWin::fozu() {
    //50*15 ���� '\'��ת��
    string fz[20] = {
            "                    _ooOoo_                       \n",
            "                   88~ . ~88                      \n",
            "                   (| ^_^ |)                      \n",
            "                   O\\  =  /O                      \n",
            "                ____/`---'\\____                   \n",
            "              .'  \\\\|     |//  `.                 \n",
            "            |   | \\\\\\  -  /// |   |               \n",
            "            \\  .-\\__  `-`  ___/-. /               \n",
            "        .`` '<  `.___\\_<|>_/___.'  >'''.          \n",
            "      | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |         \n",
            //"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n",
            "      ����崻�       ���汣��     ����BUG           \n"
    };
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(2));
    for (int i = 0; i < 11; ++i) {
        CTools::goto_xy(startX + width - 25, startY + 3 + i);
        Sleep(1);
        cout << fz[i];
    }
}

void QuitWin::thank() {
    //93*7 ��л
    string tk[10] = {
            "::::::::::: :::    :::     :::     ::::    ::: :::    :::     :::   :::  ::::::::  :::    :::\n",
            "    :+:     :+:    :+:   :+: :+:   :+:+:   :+: :+:   :+:      :+:   :+: :+:    :+: :+:    :+:\n",
            "    +:+     +:+    +:+  +:+   +:+  :+:+:+  +:+ +:+  +:+        +:+ +:+  +:+    +:+ +:+    +:+\n",
            "    +#+     +#++:++#++ +#++:++#++: +#+ +:+ +#+ +#++:++          +#++:   +#+    +:+ +#+    +:+\n",
            "    +#+     +#+    +#+ +#+     +#+ +#+  +#+#+# +#+  +#+          +#+    +#+    +#+ +#+    +#+\n",
            "    #+#     #+#    #+# #+#     #+# #+#   #+#+# #+#   #+#         #+#    #+#    #+# #+#    #+#\n",
            "    ###     ###    ### ###     ### ###    #### ###    ###        ###     ########   ########\n"
    };
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(2));
    for (int i = 0; i < 7; ++i) {
        CTools::goto_xy(startX + width - 46, startY + 20 + i);
        Sleep(1);
        cout << tk[i];
    }
}

void QuitWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);

    this->title_Label->show(2);

    fozu();
    thank();
}