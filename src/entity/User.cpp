#include "../public.h"

//�޲ι��캯��
User::User() {}

//���ι��캯��
User::User(const string &name, const string &passWord,Management management) : name(name), passWord(passWord) {
    id = "scau" + string(5 - to_string(management.userNum).length(), '0') + to_string(management.userNum);
    isAdmin=false;
    gender="��";
    age=0;
    preference="��";
}

//��������
User::~User() {

}