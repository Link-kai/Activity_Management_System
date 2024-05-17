#include "../public.h"

//�޲ι��캯��
Activity::Activity() {}

//���ι��캯��
Activity::Activity(const string &name, const string &content, const string &date, const string &location,const string &type,
                   int max_num_people, const User &creator) : name(name),content(content),date(date),
                   location(location),type(type),max_num_people(max_num_people),creator(creator) {
    id = string(5 - to_string(management.activityNum).length(), '0') + to_string(management.activityNum);
    cur_num_people=0;
    state="��ļ��";
    comments="";
}

//��������
Activity::~Activity() {

}

void Activity::exportList(Activity activity){
    ofstream file(PARTICIPANT_FILE);
    cereal::JSONOutputArchive archive(file);
    archive(cereal::make_nvp("�id",activity.id));
    archive(cereal::make_nvp("�����",activity.name));
    archive(cereal::make_nvp("�������",activity.participants));
}