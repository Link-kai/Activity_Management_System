#include "../public.h"

//无参构造函数
User::User() {}

//带参构造函数
User::User(const string &name, const string &passWord,Management management) : name(name), passWord(passWord) {
    id = "scau" + string(5 - to_string(management.userNum).length(), '0') + to_string(management.userNum);
    isAdmin=false;
    gender="无";
    age=0;
    preference="无";
}

//析构函数
User::~User() {

}