#include "../public.h"

Management::Management(){}

Management::~Management(){}

void Management::run() {
    //��ȡ����
    management.loadData();
    //ѡ����
    int option=74751;
    do{
        InitWin initWin = init();
        option = initWin.choose();
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
    }while(option!=0);
}

bool isInside(COORD pos, CButton *button) {
    return pos.X >= button->startX && pos.X <= button->startX + button->width + 6 &&
           pos.Y >= button->startY && pos.Y <= button->startY + button->height - 1;
}

InitWin Management::init() {
    CTools::cursorVisible(false);
    //��ʼҳ
    Sleep(1);
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
    //ѡ����
    int option=74751;
    do{
        homeWin.showWindow();
        option =homeWin.choose();
        switch (option) {
            case 0:
                CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
                break;
            case 1:
                personalPage();
                break;
            case 2:
                activityPage();
                break;
        }
    }while(option!=0);
}

void Management::personalPage(){
    CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
    PersonalWin personalWin(windowStartX, windowStartY, windowWidth, windowHeight);
    int option=74751;
    personalWin.showWindow();
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

void Management::activityPage(){
    CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
    ActivityWin activityWin(windowStartX, windowStartY, windowWidth, windowHeight);
    activityWin.showWindow();
    int option=74751;
    do{
        activityWin.view_activity_Button->show(4);
        activityWin.creat_activity_Button->show(4);
        activityWin.my_creat_Button->show(4);
        activityWin.my_attend_Button->show(4);
        activityWin.statistics_activity_Button->show(4);
        activityWin.exit_Button->show(4);
        //ѡ����
        option =activityWin.choose();
        //�����ʾ��Ϣ
        CTools::empty(windowStartX + windowWidth - 25, windowStartY + 38, 80, 5);
        switch (option) {
            case 0:
                CTools::empty(windowStartX, windowStartY, windowWidth * 2, windowHeight);
                break;
            case 1:
                activityWin.viewActivity();
                break;
            case 2:
                activityWin.creatActivity();
                break;
            case 3:
                activityWin.myActivity();
                break;
            case 4:
                activityWin.myAttend();
                break;
            case 5:
                activityWin.statisticsActivity();
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
    management.saveData(management);
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

void Management::saveData(Management management){
    ofstream file(DATA_FILE);
    cereal::JSONOutputArchive archive(file);
    //archive(CEREAL_NVP(management.userNum),CEREAL_NVP(management.activityNum),CEREAL_NVP(management.userList),CEREAL_NVP(management.activityList));

    archive(cereal::make_nvp("�û�����",management.userNum));
    archive(cereal::make_nvp("�����",management.activityNum));
    archive(cereal::make_nvp("�û��б�",management.userList));
    archive(cereal::make_nvp("��б�",management.activityList));
}