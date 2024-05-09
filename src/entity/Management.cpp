#include "../public.h"

Management::Management(){}

Management::~Management(){}

void Management::run() {

    while (true) {
        InitWin initWin = init();
//        int x = windowStartX + initWin.width - 28;
//        int y = windowStartY + 13 + 18 + 1;
//        CTools::goto_xy(x + (9 * 2 - 9) / 2 - 1, y);//����ƶ��� 1.ע��
        //ѡ����
        int option = initWin.choose();
        switch (option) {
            case 0:
                quit();
                break;
            case 1:
                signUp();
                break;
            case 2:
                login(false);
                break;
        }
    }

}

bool isInside(COORD pos, CButton *button) {
    return pos.X >= button->startX && pos.X <= button->startX + button->width + 6 &&
           pos.Y >= button->startY && pos.Y <= button->startY + button->height - 1;
}

InitWin Management::init() {
    CTools::cursorVisible(false);
    //��ʼҳ
    InitWin initWin(windowStartX, windowStartY, windowWidth, windowHeight);
    initWin.showWindow();
    return initWin;
}

void Management::signUp() {
    CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
    RegisterWin registerWin(windowStartX, windowStartY, windowWidth, windowHeight);
    registerWin.showWindow();
    registerWin.signUp();
    login(true);
}

void Management::login(bool flag) {
    CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
    LoginWin loginWin(windowStartX, windowStartY, windowWidth, windowHeight);
    loginWin.showWindow();
    loginWin.login(flag);
    home();
}

void Management::home(){
    CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
    HomeWin homeWin(windowStartX, windowStartY, windowWidth, windowHeight);
    homeWin.showWindow();
    //ѡ����
    int option =homeWin.choose();
    switch (option) {
        case 0:
            CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
            cout<<"�˳�ϵͳ";
            break;
        case 1:
            personalPage();
            break;
        case 2:
            CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
            cout<<"�����";
            break;
    }
}

void Management::personalPage(){
    CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
    PersonalWin personalWin(windowStartX, windowStartY, windowWidth, windowHeight);
    personalWin.showWindow();
    int option=74751;
    do{
        //��ʾ��ť
        CButton *modify_Button,*inBox_Button,*bro_Button,*exit_Button;
        modify_Button = new CButton(windowStartX + windowWidth - 40, windowStartY + 35, 9, 3, "1. �޸���Ϣ", 4);
        inBox_Button = new CButton(windowStartX + windowWidth - 20, windowStartY + 35, 9, 3, "2. �� �� ��", 4);
        bro_Button = new CButton(windowStartX + windowWidth, windowStartY + 35, 9, 3, "3. �����б�", 4);
        exit_Button = new CButton(windowStartX + windowWidth + 20, windowStartY + 35, 9, 3, "0. ��    ��", 4);
        modify_Button->show(4);
        inBox_Button->show(4);
        bro_Button->show(4);
        exit_Button->show(4);
        //ѡ����
        option =personalWin.choose();
        //�����ʾ��Ϣ
        CTools::empty(windowStartX + windowWidth - 25, windowStartY + 38, 80, 5);
        switch (option) {
            case 0:
                CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
                cout<<"0. ��    ��";
                break;
            case 1:
                personalWin.modify();
                break;
            case 2:
                personalWin.inBox();
                break;
            case 3:
                personalWin.broList();
                break;
        }
    }while(option!=0);
}

void Management::quit() {
    CTools::cursorVisible(false);
    CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
    //�˳�ҳ
    QuitWin quitWin(windowStartX, windowStartY, windowWidth, windowHeight);
    quitWin.showWindow();
    CTools::goto_xy(windowStartX + windowWidth - 9, windowStartY + 13 + 18);
    system("pause");
    exit(0);
}

void Management::loadData() {
    ifstream file(DATA_FILE);
    cereal::JSONInputArchive archive(file);
    archive(cereal::make_nvp("�û�����",management.userNum));
    archive(cereal::make_nvp("�����",management.activityNum));
    archive(cereal::make_nvp("�û��б�",management.userList));
    archive(cereal::make_nvp("��б�",management.activityList));
}