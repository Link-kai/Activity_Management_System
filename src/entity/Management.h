#ifndef ACTIVITY_MANAGEMENT_SYSTEM_MANAGEMENT_H
#define ACTIVITY_MANAGEMENT_SYSTEM_MANAGEMENT_H

#include "../public.h"
class InitWin;
class Management{
public:
    const int MAX_USERS = 500;          //最大用户数
    const int MAX_ACTIVITIES = 1000;    //最大活动数

    Management();
    ~Management();

    //启动
    void run();
    //初始面板
    InitWin init();
    //注册面板
    void signUp();
    //登录面板
    void login(bool flag);
    //系统主面板
    void home();
    //个人主页
    void personalPage();
    //活动面板
    void activityPage();
    //退出面板
    void quit();
    //保存数据
    void loadData();
    //读取数据
    void saveData(Management management);

    //菜单面板
    //加载用户
    //加载活动
    //保存用户
    //保存活动
    //用户注册
    //用户登录
    //创建活动
    //删除活动
    //查看活动
    //修改活动
    //序列化模板函数
    template <class Archive>
    void serialize(Archive & ar)
    {
        ar(cereal::make_nvp("用户数量",userNum));
        ar(cereal::make_nvp("活动数量",activityNum));
        ar(cereal::make_nvp("用户列表",userList));
        ar(cereal::make_nvp("活动列表",activityList));
    }

    int userNum;                             //用户数量
    int activityNum;                         //活动数量
    map<string, User> userList;              //用户列表
    map<string, Activity> activityList;      //活动列表
    User currentUser;                        //当前用户

};

#endif //ACTIVITY_MANAGEMENT_SYSTEM_MANAGEMENT_H
