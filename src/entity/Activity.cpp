#include "../public.h"

//无参构造函数
Activity::Activity() {}

//带参构造函数
Activity::Activity(const string &name, const string &content, const string &date, const string &location,const string &type,
                   int max_num_people, const User &creator) : name(name),content(content),date(date),
                   location(location),type(type),max_num_people(max_num_people),creator(creator) {
    id = string(5 - to_string(management.activityNum).length(), '0') + to_string(management.activityNum);
    cur_num_people=0;
    state="招募中";
    comments="";
}

//析构函数
Activity::~Activity() {

}

void Activity::exportList(Activity activity){
    ofstream file(PARTICIPANT_FILE);
    cereal::JSONOutputArchive archive(file);
    archive(cereal::make_nvp("活动id",activity.id));
    archive(cereal::make_nvp("活动名称",activity.name));
    archive(cereal::make_nvp("活动参与者",activity.participants));
}