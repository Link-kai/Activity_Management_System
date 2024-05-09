#ifndef ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITY_H
#define ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITY_H


#include "../public.h"

class User;

class Activity {
public:
    //�޲ι��캯��
    Activity();

    //���ι��캯��
    Activity(string id, const string &name, const string &content, const string &date, const string &location,
             const string &requirement,int max_num_people, int state, const User &creator);

    //��������
    virtual ~Activity();

    //���л�ģ�庯��
    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(cereal::make_nvp("�id",id));
        ar(cereal::make_nvp("���",name));
        ar(cereal::make_nvp("�����",content));
        ar(cereal::make_nvp("�ʱ��", date));
        ar(cereal::make_nvp("��ص�",location));
        ar(cereal::make_nvp("�Ҫ��",requirement));
        ar(cereal::make_nvp("�����",type));
        ar(cereal::make_nvp("��������",max_num_people));
        ar(cereal::make_nvp("�ѱ�������",cur_num_people));
        ar(cereal::make_nvp("״̬",state));
        ar(cereal::make_nvp("�������",creator));
        ar(cereal::make_nvp("�������",participants));
        ar(cereal::make_nvp("�����",comments));
    }

    string id;                         //�id
    string name;                       //���
    string content;                    //�����
    string date;                       //�ʱ��
    string location;                   //��ص�
    string requirement;                //�Ҫ��
    string type;                       //�����
    int max_num_people;                //��������
    int cur_num_people;                //�ѱ�������
    int state;                         //״̬��1��ļ�� 0����
    User creator;                      //�������
    vector<User> participants;         //�������
    vector<string> comments;           //�����
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITY_H