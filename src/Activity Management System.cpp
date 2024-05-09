#include "public.h"

Management management;
int main() {
    //退出登录后，current 保存!!!!!!!!!!!!!!!!!!!!!!!
    //新建用户记得management.userNum++;
    SetConsoleTitleA("活动管理系统");
    management.userNum++;
    string name="admin";
    string pwd="kkk2580kkk";
    User user(name,pwd,management);
    user.isAdmin=true;
    user.inBox="科比";
    management.userList.insert(make_pair(user.id,user));
    management.currentUser=user;
    management.userNum++;
    User user1("科比","asd123",management);
    management.userList.insert(make_pair(user1.id,user1));

    management.userNum++;
    User user2("牢大","asd123",management);
    management.userList.insert(make_pair(user2.id,user2));
    management.currentUser.broList.push_back(user2);

    management.personalPage();
//    HomeWin h(windowStartX, windowStartY, windowWidth, windowHeight);
//    h.showWindow();
//    management.run();
/*
    User u1,u2;
    u1.name="林锴";
    u1.id="202121110110";
    u1.passWord="kkk2580kkk";
    u1.isAdmin=true;

    u2.name="方诺雅";
    u2.id="202121110207";
    u2.passWord="fff2580fff";
    u2.isAdmin=false;

    User u3;
    u3.name="陈相机";
    u3.id="50010236";
    u3.passWord="cxj666";
    u3.isAdmin=false;

    Activity a1,a2;
    a1.id="10001";
    a1.name="课设答辩";
    a1.content="讲解程序";
    a1.date="2024-5-20";
    a1.location="教四404";
    a1.requirement="线上";
    a1.type="学习";
    a1.max_num_people=500;
    a1.cur_num_people=250;
    a1.state=1;
    a1.creator=u3;
    a1.participants.push_back(u1);
    a1.participants.push_back(u2);
    //a1.comments.push_back("好的");

    vector<Activity> as1;
    vector<Activity> as2;
    as1.push_back(a1);
    u1.myActivity=as1;
    as2.push_back(a1);
    u2.myActivity=as2;

    map<string, User> mp1;
    mp1.insert(make_pair(u1.id,u1));
    mp1.insert(make_pair(u2.id,u2));
    mp1.insert(make_pair(u3.id,u3));

    map<string, Activity> mp2;
    mp2.insert(make_pair(a1.id,a1));

    Management m;
    m.userNum=3;
    m.activityNum=1;
    m.userList=mp1;
    m.activityList=mp2;

    ofstream file(DATA_FILE);
    cereal::JSONOutputArchive archive(file);
    //archive(CEREAL_NVP(m.userNum),CEREAL_NVP(m.activityNum),CEREAL_NVP(m.userList),CEREAL_NVP(m.activityList));

    archive(cereal::make_nvp("用户数量",m.userNum));
    archive(cereal::make_nvp("活动数量",m.activityNum));
    archive(cereal::make_nvp("用户列表",m.userList));
    archive(cereal::make_nvp("活动列表",m.activityList));
*/
/*
    Management m;
    ifstream file(DATA_FILE);
    cereal::JSONInputArchive archive(file);
    archive(cereal::make_nvp("用户数量",m.userNum));
    archive(cereal::make_nvp("活动数量",m.activityNum));
    archive(cereal::make_nvp("用户列表",m.userList));
    archive(cereal::make_nvp("活动列表",m.activityList));
    cout<<m.userNum<<endl;
    cout<<m.activityNum<<endl;
*/
    system("pause>nul");
    return 0;
}