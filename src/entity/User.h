#ifndef ACTIVITY_MANAGEMENT_SYSTEM_USER_H
#define ACTIVITY_MANAGEMENT_SYSTEM_USER_H

#include "../public.h"
#include "cereal/cereal.hpp"

class Activity;
class Management;

class User{
public:
    //�޲ι��캯��
    User();

    //���ι��캯����û��myActivity��
    User(const string &name, const string &passWord,Management management);

    //��������
    virtual ~User();
    //����
    //�����
    //ɾ���
    //�˳��
    //�޸�����

    //���л�ģ�庯��
    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(cereal::make_nvp("�û�id",id));
        ar(cereal::make_nvp("�û���",name));
        ar(cereal::make_nvp("����",passWord));
        ar(cereal::make_nvp("����Ա��־",isAdmin));
        ar(cereal::make_nvp("�û��",myActivity));
    }

    string id;                      //�û�id
    string name;                    //�û���
    string passWord;                //����
    bool isAdmin;                   //����Ա��־     1���� 0����
    string gender;                  //�Ա�
    int age;                        //����
    string preference;              //�ƫ��          0:�� 1:�ۺ��� 2:֪ʶ�� 3:������ 4:������
    string inBox;                   //������
    vector<User> broList;           //����
    vector<Activity> myActivity;    //�û��
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_USER_H
