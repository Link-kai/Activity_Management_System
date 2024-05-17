#ifndef ACTIVITY_MANAGEMENT_SYSTEM_MANAGEMENT_H
#define ACTIVITY_MANAGEMENT_SYSTEM_MANAGEMENT_H

#include "../public.h"
class InitWin;
class Management{
public:
    const int MAX_USERS = 500;          //����û���
    const int MAX_ACTIVITIES = 1000;    //�����

    Management();
    ~Management();

    //����
    void run();
    //��ʼ���
    InitWin init();
    //ע�����
    void signUp();
    //��¼���
    void login(bool flag);
    //ϵͳ�����
    void home();
    //������ҳ
    void personalPage();
    //����
    void activityPage();
    //�˳����
    void quit();
    //��������
    void loadData();
    //��ȡ����
    void saveData(Management management);

    //�˵����
    //�����û�
    //���ػ
    //�����û�
    //����
    //�û�ע��
    //�û���¼
    //�����
    //ɾ���
    //�鿴�
    //�޸Ļ
    //���л�ģ�庯��
    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(cereal::make_nvp("�û�����",userNum));
        ar(cereal::make_nvp("�����",activityNum));
        ar(cereal::make_nvp("�û��б�",userList));
        ar(cereal::make_nvp("��б�",activityList));
    }

    int userNum;                             //�û�����
    int activityNum;                         //�����
    map<string, User> userList;              //�û��б�
    map<string, Activity> activityList;      //��б�
    User currentUser;                        //��ǰ�û�

};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_MANAGEMENT_H
