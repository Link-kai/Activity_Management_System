#ifndef ACTIVITY_MANAGEMENT_SYSTEM_USER_H
#define ACTIVITY_MANAGEMENT_SYSTEM_USER_H

#include "../public.h"
#include "cereal/cereal.hpp"

class Activity;
class Management;

class User{
public:
    //无参构造函数
    User();

    //带参构造函数（没有myActivity）
    User(const string &name, const string &passWord,Management management);

    //析构函数
    virtual ~User();
    //加入活动
    //活动评论
    //删除活动
    //退出活动
    //修改密码

    //序列化模板函数
    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(cereal::make_nvp("用户id",id));
        ar(cereal::make_nvp("用户名",name));
        ar(cereal::make_nvp("密码",passWord));
        ar(cereal::make_nvp("管理员标志",isAdmin));
        ar(cereal::make_nvp("用户活动",myActivity));
    }

    string id;                      //用户id
    string name;                    //用户名
    string passWord;                //密码
    bool isAdmin;                   //管理员标志     1：是 0：否
    string gender;                  //性别
    int age;                        //年龄
    string preference;              //活动偏好          0:无 1:综合类 2:知识类 3:体育类 4:艺术类
    string inBox;                   //收信箱
    vector<User> broList;           //好友
    vector<Activity> myActivity;    //用户活动
};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_USER_H
