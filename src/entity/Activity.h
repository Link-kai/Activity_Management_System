#ifndef ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITY_H
#define ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITY_H

#include "../public.h"

class User;

class Activity {
public:
    //无参构造函数
    Activity();

    //带参构造函数
    Activity(const string &name, const string &content, const string &date, const string &location,
             const string &type,int max_num_people, const User &creator);

    //析构函数
    virtual ~Activity();

    //导出参与者名单
    void exportList(Activity activity);

    //序列化模板函数
    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(cereal::make_nvp("活动id",id));
        ar(cereal::make_nvp("活动名",name));
        ar(cereal::make_nvp("活动内容",content));
        ar(cereal::make_nvp("活动时间", date));
        ar(cereal::make_nvp("活动地点",location));
        ar(cereal::make_nvp("活动类型",type));
        ar(cereal::make_nvp("人数上限",max_num_people));
        ar(cereal::make_nvp("已报名人数",cur_num_people));
        ar(cereal::make_nvp("状态",state));
        ar(cereal::make_nvp("活动创建者",creator));
        ar(cereal::make_nvp("活动参与者",participants));
        ar(cereal::make_nvp("活动评论",comments));
    }

    string id;                         //活动id
    string name;                       //活动名
    string content;                    //活动内容
    string date;                       //活动时间
    string location;                   //活动地点
    string type;                       //活动类型，0:无 1:综合类 2:知识类 3:体育类 4:艺术类
    int max_num_people;                //人数上限
    int cur_num_people;                //已报名人数
    string state;                      //状态，招募中 结束
    User creator;                      //活动创建者
    vector<User> participants;         //活动参与者
    string comments;                   //活动评论
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_ACTIVITY_H
