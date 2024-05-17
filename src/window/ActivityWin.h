#ifndef ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITYWIN_H
#define ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITYWIN_H

#include "../public.h"

class ActivityWin{
public:
    //�ղι���
    ActivityWin();

    //���ι���
    ActivityWin(int x, int y, int w, int h);

    //��������
    ~ActivityWin();

    //scauͼ��
    void scau();

    //��ʾ����
    void showWindow();

    //ѡ����
    void print(int option);
    void updateOption(int &option, int x);
    int choose();

    //ѡ����
    void print1(int option,int mode);
    void updateOption1(int &option, int x,int mode);
    int choose1(int mode);

    //1. ����
    void viewActivity();
    //2. �����
    void creatActivity();
    //3. �ҵĻ
    void myActivity();
    //4. �ҵĲμ�
    void myAttend();
    //5. ͳ�ƹ���
    void statisticsActivity();
    int startX;
    int startY;
    int width;
    int height;

    CLabel *toolbar_Label, *title_Label, *system_Label;
    CButton *view_activity_Button,*creat_activity_Button,*my_creat_Button,*my_attend_Button,*statistics_activity_Button,*exit_Button;

};
#endif //ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITYWIN_H
