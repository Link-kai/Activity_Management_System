#include "../public.h"

PersonalWin::PersonalWin() {
}

PersonalWin::PersonalWin(int x, int y, int w, int h) {
    this->startX = x;
    this->startY = y;
    this->width = w;
    this->height = h;

    this->toolbar_Label = new CLabel(startX + width - 7, startY - 1, 0, 0, "活动管理系统");
    this->title_Label = new CLabel(startX + width - 5, startY + 1, 0, 0, "个人主页");
    this->system_Label = new CLabel(startX + width - 5, startY + 13, 0, 0, "Activity Management System");

    this->base_Button = new CButton(startX + width - 40, startY + 15, 40, 18, "", 4);

    this->personalData_Label = new CLabel(startX + width - 6, startY + 17, 0, 0, "个 人 信 息");

    string id = "账号：" + management.currentUser.id;
    this->id_Button = new CButton(startX + width - 30, startY + 20, id.length(), 3, id, 2);

    string name = "用户名：" + management.currentUser.name;
    this->name_Button = new CButton(startX + width + 3, startY + 20, id.length(), 3, name, 2);

    string gender = "性别：" + management.currentUser.gender;
    this->gender_Button = new CButton(startX + width - 30, startY + 24, id.length(), 3, gender, 2);

    string age = "年龄：" + to_string(management.currentUser.age);
    this->age_Button = new CButton(startX + width + 3, startY + 24, id.length(), 3, age, 2);

    string preference = "活动偏好：" + management.currentUser.preference;
    this->preference_Button = new CButton(startX + width - 30, startY + 28, id.length(), 3, preference, 2);

    string isAdmin = "用户类型：";
    if (management.currentUser.isAdmin)
        isAdmin += "管理员";
    else isAdmin += "普通用户";
    this->admin_Button = new CButton(startX + width + 3, startY + 28, id.length(), 3, isAdmin, 2);

    this->modify_Button = new CButton(startX + width - 40, startY + 35, 9, 3, "1. 修改信息", 4);
    this->inBox_Button = new CButton(startX + width - 20, startY + 35, 9, 3, "2. 收 件 箱", 4);
    this->bro_Button = new CButton(startX + width, startY + 35, 9, 3, "3. 好友列表", 4);
    this->exit_Button = new CButton(startX + width + 20, startY + 35, 9, 3, "0. 返    回", 4);
}

PersonalWin::~PersonalWin() {
}

void PersonalWin::scau() {
    //37*5 scau
    string scau[10] = {
            "████████╗ ███████╗ ██████╗ ██╗    ██╗\n",
            "██╔═════╝██╔═════╝██╔═══██╗██║    ██║\n",
            "████████╗██║      ████████║██║    ██║\n",
            "╚═════██║██║      ██╔═══██║██║    ██║\n",
            "████████║╚███████╗██║   ██║ ███████╔╝\n",
            "╚═══════╝ ╚══════╝╚═╝   ╚═╝  ╚═════╝\n"
    };
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(5));
    for (int i = 0; i < 6; ++i) {
        CTools::goto_xy(startX + width - 19, startY + 6 + i);
        Sleep(1);
        cout << scau[i];
    }
}

void PersonalWin::showWindow() {
    this->toolbar_Label->show(2);

    CTools::drawWindow(this->startX, this->startY, this->width, this->height, 5);
    this->title_Label->show(2);

    scau();
    this->system_Label->show(5);

    this->base_Button->show(4);

    this->personalData_Label->show(2);

    this->id_Button->show(2);
    this->name_Button->show(2);

    this->gender_Button->show(2);
    this->age_Button->show(2);

    this->preference_Button->show(2);
    this->admin_Button->show(2);

    this->modify_Button->show(4);
    this->inBox_Button->show(4);
    this->bro_Button->show(4);
    this->exit_Button->show(4);
}

void PersonalWin::print(int option) {
    switch (option) {//覆盖，实现退选
        case 1:
            cout << "1. 修改信息" << endl;
            break;
        case 2:
            cout << "2. 收 件 箱" << endl;
            break;
        case 3:
            cout << "3. 好友列表" << endl;
            break;
        case 0:
            cout << "0. 返    回" << endl;
            break;
    }
    return;
}

void PersonalWin::updateOption(int &option, int x) {
    if (x == startX + width - 40 + (9 * 2 - 11) / 2 - 1)
        option = 1;
    else if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)
        option = 2;
    else if (x == startX + width + (9 * 2 - 11) / 2 - 1)
        option = 3;
    else option = 0;
}

int PersonalWin::choose() {
    int option = -1;          //选择功能号 0返回 1修改信息 2收件箱 3好友列表
    char key;
    int x = startX + width - 40 + (9 * 2 - 11) / 2 - 1;
    int y = startY + 35 + 3 / 2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '3') {//数字键选择
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                return option;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//光标移动到 1.修改信息
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//覆盖，实现退选
                if (x == startX + width + 20 + (9 * 2 - 11) / 2 - 1)//如果已经到了0. 返    回，则跳转1. 修改信息，实现滚动高亮
                    x = startX + width - 40 + (9 * 2 - 11) / 2 - 1;
                else
                    x += 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, x);
                print(option);//覆盖，实现选择
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption(option, x);
                print(option);//覆盖，实现退选
                if (x == startX + width - 40 + (9 * 2 - 11) / 2 - 1)//如果已经到了1. 个 人 主 页，则跳转0. 退 出 登 录，实现滚动高亮
                    x = startX + width + 20 + (9 * 2 - 11) / 2 - 1;
                else x -= 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption(option, x);
                print(option);//覆盖，实现选择
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void PersonalWin::modify() {
    CTools::empty(startX + width - 40, startY + 35, 85, 3);

    CButton *modify_name_Button, *modify_pwd_Button, *modify_gender_Button, *modify_age_Button, *modify_preference_Button, *ok_Button;
    modify_name_Button = new CButton(startX + width - 60, startY + 33, 9, 3, "1. 用 户 名", 4);
    modify_pwd_Button = new CButton(startX + width - 40, startY + 33, 9, 3, "2. 密    码", 4);
    modify_gender_Button = new CButton(startX + width - 20, startY + 33, 9, 3, "3. 性    别", 4);
    modify_age_Button = new CButton(startX + width, startY + 33, 9, 3, "4. 年    龄", 4);
    modify_preference_Button = new CButton(startX + width + 20, startY + 33, 9, 3, "5. 活动偏好", 4);
    ok_Button = new CButton(startX + width + 40, startY + 33, 9, 3, "0. 返    回", 4);

    modify_name_Button->show(4);
    modify_pwd_Button->show(4);
    modify_gender_Button->show(4);
    modify_age_Button->show(4);
    modify_preference_Button->show(4);
    ok_Button->show(4);
    int option = 74751;
    do {
        option = choose1();
        //清空提示信息
        CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
        switch (option) {
            case 0:
                CTools::empty(startX + width - 60, startY + 33, 120, 3);
                break;
            case 1: { //用户名
                //显示输入框、标签
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "用户名");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * 请输入新的用户名(≤ 20个字符)");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                //打开光标显示
                CTools::cursorVisible(true);
                //输入新信息
                string name = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                //关闭光标显示
                CTools::cursorVisible(false);
                //清空并更新信息
                CTools::empty(startX + width + 3, startY + 20, 15 * 2, 3);
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //更新信息
                management.currentUser.name = name;
                management.userList.find(management.currentUser.id)->second.name=name;
                //更新面板
                string info = "用户名：" + management.currentUser.name;
                auto name_Button = new CButton(startX + width + 3, startY + 20, 15, 3, info, 2);
                name_Button->show(2);
                //提示更改成功
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 8, windowStartY + 38, 0, 0,
                                                       "修改 用户名 成功！");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "继 续 选 择");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //更新按钮
                modify_name_Button->show(4);
                break;
            }
            case 2: { //密码
                //显示输入框、标签
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "密 码");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     "* 请 输 入 新 密 码");
                CLabel *again_pwd_Label = new CLabel(windowStartX + width - 20, startY + 42, 0, 0, "再次输入");
                CEdit *again_pwd_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 42, 15, 3, "", 8, 2, 0);
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                again_pwd_Label->show(0);
                again_pwd_Edit->show(0);
                //打开光标显示
                CTools::cursorVisible(true);
                //输入新信息
                regex object("(?=.*([a-zA-Z].*))(?=.*[0-9].*)[a-zA-Z0-9-*/+.~!@#$%^&*()]{6,20}$");
                string pwd, again_pwd;
                while (true) {
                    //输入错误时，清空密码
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    CTools::goto_xy(windowStartX + width - 10, startY + 42);
                    cout << "                    ";

                    pwd = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 1);
                    again_pwd = CTools::input(windowStartX + width - 10, windowStartY + 42, 20, 20, 1);
                    //判断密码是否合法
                    if (pwd != again_pwd) {
                        CTools::goto_xy(windowStartX + width + 16, startY + 42);
                        cout << "                                                ";
                        CLabel *tipPwdUnequal_Label = new CLabel(windowStartX + width + 16, startY + 42, 0, 0,
                                                                 "* 两次输入密码不相同！");
                        tipPwdUnequal_Label->show(1);
                        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                        continue;
                    } else {
                        CTools::goto_xy(windowStartX + width + 16, startY + 42);
                        cout << "                              ";
                    }
                    if (!regex_match(pwd, object)) {
                        CLabel *tipPwd_Label = new CLabel(windowStartX + width + 16, startY + 42, 0, 0,
                                                          "* 密码至少6位，至少包含数字、字母，允许特殊字符!");
                        tipPwd_Label->show(1);
                        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    } else {
                        CTools::goto_xy(windowStartX + width + 16, startY + 42);
                        cout << "                                                ";
                        break;
                    }
                }
                //关闭光标显示
                CTools::cursorVisible(false);
                //清空并更新信息
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //更新信息
                management.currentUser.passWord = pwd;
                management.userList.find(management.currentUser.id)->second.passWord=pwd;
                //提示更改成功
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 7, windowStartY + 38, 0, 0,
                                                       "修改 密码 成功！");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "继 续 选 择");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                modify_pwd_Button->show(4);
                break;
            }
            case 3: { //性别
                //显示输入框、标签
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "性 别");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * 请输入您的性别(男 女 其他)");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                //打开光标显示
                CTools::cursorVisible(true);
                //输入新信息
                string gender;
                while (true) {
                    //输入错误时，清空内容
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    gender = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                    if (gender != "男" && gender != "女" && gender != "其他") {
                        CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                        cout << "                              ";
                        CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                             " * 输入错误！ 性别(男 女 其他)");
                        tip_error_Label->show(1);
                        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                    } else {
                        CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                        cout << "                              ";
                        break;
                    }
                }
                //关闭光标显示
                CTools::cursorVisible(false);
                //清空并更新信息
                CTools::empty(startX + width - 30, startY + 24, 15 * 2, 3);
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //更新信息
                management.currentUser.gender = gender;
                management.userList.find(management.currentUser.id)->second.gender=gender;
                //更新面板
                string info = "性别：" + management.currentUser.gender;
                auto gender_Button = new CButton(startX + width - 30, startY + 24, 15, 3, info, 2);
                gender_Button->show(2);
                //提示更改成功
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 7, windowStartY + 38, 0, 0,
                                                       "修改 性别 成功！");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "继 续 选 择");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //更新按钮
                modify_gender_Button->show(4);
                break;
            }
            case 4: { //年龄
                //显示输入框、标签
                CLabel *input_Label = new CLabel(windowStartX + width - 20, windowStartY + 38, 0, 0, "年 龄");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * 请输入您的年龄");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                //打开光标显示
                CTools::cursorVisible(true);
                //输入新信息
                int age;
                while (true) {
                    //输入错误时，清空内容
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    string t = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                    bool flag = true;//判断输入是否为数字
                    for (char c: t) {
                        if (!isdigit(c)) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * 输入错误！请输入数字！");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true) {
                        age = stoi(t);
                        if (age < 0 || age > 100) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * 输入错误！年龄范围0~100！");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                        }
                    }
                    if (!flag)
                        continue;
                    CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                    cout << "                              ";
                    break;
                }
                //关闭光标显示
                CTools::cursorVisible(false);
                //清空并更新信息
                CTools::empty(startX + width + 3, startY + 24, 15 * 2, 3);
                CTools::empty(windowStartX + width - 25, windowStartY + 37, 80, 6);
                //更新信息
                management.currentUser.age = age;
                management.userList.find(management.currentUser.id)->second.age=age;
                //更新面板
                string info = "年龄：" + to_string(management.currentUser.age);
                auto age_Button = new CButton(startX + width + 3, startY + 24, 15, 3, info, 2);
                age_Button->show(2);
                //提示更改成功
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 7, windowStartY + 38, 0, 0,
                                                       "修改 年龄 成功！");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "继 续 选 择");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //更新按钮
                modify_age_Button->show(4);
                break;
            }
            case 5: { //活动偏好
                //显示输入框、标签
                CLabel *input_Label = new CLabel(windowStartX + width - 22, windowStartY + 38, 0, 0, "活动偏好");
                CEdit *input_Edit = new CEdit(windowStartX + width - 20 + 9, startY + 38, 15, 3, "", 8, 2, 0);
                CLabel *tip_input_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                     " * 请输入您的活动偏好");
                CLabel *tip_type_Label = new CLabel(windowStartX + width - 31, windowStartY + 40, 0, 0,
                                                    "输入数字选择活动偏好(0:无 1:综合类 2:知识类 3:体育类 4:艺术类)");
                input_Label->show(0);
                input_Edit->show(0);
                tip_input_Label->show(6);
                tip_type_Label->show(6);
                //打开光标显示
                CTools::cursorVisible(true);
                //输入新信息
                int choice;
                while (true) {
                    //输入错误时，清空内容
                    CTools::goto_xy(windowStartX + width - 10, windowStartY + 38);
                    cout << "                    ";
                    string t = CTools::input(windowStartX + width - 10, windowStartY + 38, 20, 20, 0);
                    bool flag = true;//判断输入是否为数字
                    for (char c: t) {
                        if (!isdigit(c)) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * 输入错误！请输入数字！");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true) {
                        choice = stoi(t);
                        if (choice < 0 || choice > 4) {
                            CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                            cout << "                                ";
                            CLabel *tip_error_Label = new CLabel(windowStartX + width + 16, windowStartY + 38, 0, 0,
                                                                 " * 输入错误！类型范围 0 ~ 4！");
                            tip_error_Label->show(1);
                            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
                            SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                            flag = false;
                        }
                    }
                    if (!flag)
                        continue;
                    CTools::goto_xy(windowStartX + width + 16, windowStartY + 38);
                    cout << "                              ";
                    break;
                }
                switch (choice) {
                    case 0:
                        management.currentUser.preference = "无";
                        break;
                    case 1:
                        management.currentUser.preference = "综合类";
                        break;
                    case 2:
                        management.currentUser.preference = "知识类";
                        break;
                    case 3:
                        management.currentUser.preference = "体育类";
                        break;
                    case 4:
                        management.currentUser.preference = "艺术类";
                        break;
                }
                //关闭光标显示
                CTools::cursorVisible(false);
                //清空并更新信息
                CTools::empty(startX + width - 30, startY + 28, 15 * 2, 3);
                CTools::empty(windowStartX + width - 31, windowStartY + 37, 80, 6);
                //更新信息(currentUser已在switch更新)
                management.userList.find(management.currentUser.id)->second.preference=management.currentUser.preference;
                //更新面板
                string info = "活动偏好：" + management.currentUser.preference;
                auto preference_Button = new CButton(startX + width - 30, startY + 28, 15, 3, info, 2);
                preference_Button->show(2);
                //提示更改成功
                CLabel *tip_success_Label = new CLabel(windowStartX + width - 9, windowStartY + 38, 0, 0,
                                                       "修改 活动偏好 成功！");
                CLabel *tip_jump_Label = new CLabel(windowStartX + width - 5, windowStartY + 40, 0, 0, "继 续 选 择");
                tip_success_Label->show(1);
                tip_jump_Label->show(1);
                //更新按钮
                modify_preference_Button->show(4);
                break;
            }
        }
    } while (option != 0);
}

void PersonalWin::print1(int option) {
    switch (option) {//覆盖，实现退选
        case 1:
            cout << "1. 用 户 名" << endl;
            break;
        case 2:
            cout << "2. 密    码" << endl;
            break;
        case 3:
            cout << "3. 性    别" << endl;
            break;
        case 4:
            cout << "4. 年    龄" << endl;
            break;
        case 5:
            cout << "5. 活动偏好" << endl;
            break;
        case 0:
            cout << "0. 返    回" << endl;
            break;
    }
    return;
}

void PersonalWin::updateOption1(int &option, int x) {
    if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)
        option = 1;
    else if (x == startX + width - 40 + (9 * 2 - 11) / 2 - 1)
        option = 2;
    else if (x == startX + width - 20 + (9 * 2 - 11) / 2 - 1)
        option = 3;
    else if (x == startX + width + (9 * 2 - 11) / 2 - 1)
        option = 4;
    else if (x == startX + width + 20 + (9 * 2 - 11) / 2 - 1)
        option = 5;
    else option = 0;
}

int PersonalWin::choose1() {
    int option = -1;          //选择功能号 0返回 1修改信息 2收件箱 3好友列表
    char key;
    int x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
    int y = startY + 33 + 3 / 2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    while (option == -1) {
        do {
            key = getch();
            if (key >= '0' && key <= '5') {//数字键选择
                option = key - '0';
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                return option;
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//光标移动到 1. 用 户 名
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print1(1);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption1(option, x);
                print1(option);//覆盖，实现退选
                if (x == startX + width + 40 + (9 * 2 - 11) / 2 - 1)//如果已经到了0. 返    回，则跳转1. 用 户 名，实现滚动高亮
                    x = startX + width - 60 + (9 * 2 - 11) / 2 - 1;
                else
                    x += 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption1(option, x);
                print1(option);//覆盖，实现选择
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                //设置原来颜色
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(4));
                updateOption1(option, x);
                print1(option);//覆盖，实现退选
                if (x == startX + width - 60 + (9 * 2 - 11) / 2 - 1)//如果已经到了1. 用 户 名，则跳转0. 返    回，实现滚动高亮
                    x = startX + width + 40 + (9 * 2 - 11) / 2 - 1;
                else x -= 20;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption1(option, x);
                print1(option);//覆盖，实现选择
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void PersonalWin::print2(int option, int mode) {
    if (mode == 1) {
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "√ 接 受" << endl;
                break;
            case 2:
                cout << "× 拒 绝" << endl;
                break;
        }
    } else if (mode == 2) {
        switch (option) {//覆盖，实现退选
            case 1:
                cout << "1. 添 加" << endl;
                break;
            case 0:
                cout << "0. 返 回" << endl;
                break;
        }
    }
    return;
}

void PersonalWin::updateOption2(int &option, int x, int mode) {
    if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)
        option = 1;
    else if (x == startX + width + 2 + (7 * 2 - 8) / 2 - 1) {
        if (mode == 1)
            option = 2;
        else if (mode == 2)
            option = 0;
    }
}

int PersonalWin::choose2(int mode) {
    //选择功能号
    //mode=1时
    //1接受 2拒绝
    //mode=2时
    //1添加 0返回
    int option = -1;
    char key;
    int x = startX + width - 16 + (7 * 2 - 8) / 2 - 1;
    int y = startY + 40 + 3 / 2;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); //获取标准输出句柄
    while (option == -1) {
        do {
            key = getch();
            if (mode == 1) {
                if (key >= '1' && key <= '2') {//数字键选择
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
            } else if (mode == 2) {
                if (key >= '0' && key <= '1') {//数字键选择
                    option = key - '0';
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
                    return option;
                }
            }
            if (option == -1) {
                CTools::goto_xy(x, y);//光标移动到 1 接受 | 1 添加
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                print2(1, mode);
            }
            if (key == KEY_RIGHT || key == KEY_DOWN_) {
                CTools::goto_xy(x, y);
                if (mode == 1) {
                    //设置原来颜色
                    if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(5));
                    else SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                } else if (mode == 2)
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                updateOption2(option, x, mode);
                print2(option, mode);//覆盖，实现退选
                if (x == startX + width + 2 + (7 * 2 - 8) / 2 - 1)//如果已经到了 右按钮 ，则跳转 左按钮 ，实现滚动高亮
                    x = startX + width - 16 + (7 * 2 - 8) / 2 - 1;
                else
                    x += 18;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption2(option, x, mode);
                print2(option, mode);//覆盖，实现选择
            }
            if (key == KEY_LEFT || key == KEY_UP) {
                CTools::goto_xy(x, y);
                if (mode == 1) {
                    //设置原来颜色
                    if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)
                        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(5));
                    else SetConsoleTextAttribute(hOutput, CtrBase::selectColour(1));
                } else if (mode == 2)
                    SetConsoleTextAttribute(hOutput, CtrBase::selectColour(3));
                updateOption2(option, x, mode);
                print2(option, mode);//覆盖，实现退选
                if (x == startX + width - 16 + (7 * 2 - 8) / 2 - 1)//如果已经到了 左按钮 ，则跳转 右按钮 ，实现滚动高亮
                    x = startX + width + 2 + (7 * 2 - 8) / 2 - 1;
                else x -= 18;
                CTools::goto_xy(x, y);
                SetConsoleTextAttribute(hOutput, CtrBase::selectColour(8));
                updateOption2(option, x, mode);
                print2(option, mode);//覆盖，实现选择
            }
        } while (key != '\r');
        SetConsoleTextAttribute(hOutput, CtrBase::selectColour(9));
        return option;
    }
}

void PersonalWin::inBox() {
    CTools::empty(startX + width - 40, startY + 35, 85, 3);
    CButton *inBox_Button = new CButton(startX + width - 30, startY + 33, 30, 11, "", 3);
    CLabel *inBox_Label = new CLabel(startX + width - 5, startY + 34, 0, 0, "收 信 箱");
    inBox_Button->show(3);
    inBox_Label->show(3);
    CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
    if (management.currentUser.inBox.empty()) {//收件箱为空
        CLabel *null_Label = new CLabel(startX + width - 9, startY + 37, 0, 0, "* 收 件 箱 为 空");
        null_Label->show(1);
        exit_Button->show(3);
        char key;
        while (true) {//选择功能号 0返回
            key = getch();
            if (key == '0')
                break;
        }
        CTools::empty(startX + width - 30, startY + 33, 60, 10);
    } else {//收到好友申请
        string name = management.currentUser.inBox;
        CLabel *tip_apply_Label = new CLabel(startX + width - 15, startY + 37, 0, 0, "收到来自          的好友申请");
        CLabel *name_Label = new CLabel(startX + width - 7 + (10 - name.length()) / 2, startY + 37, 0, 0, name);
        CButton *accept_Button = new CButton(startX + width - 16, startY + 40, 7, 3, " √ 接 受", 5);
        CButton *reject_Button = new CButton(startX + width + 2, startY + 40, 7, 3, " × 拒 绝", 1);
        tip_apply_Label->show(1);
        name_Label->show(2);
        accept_Button->show(5);
        reject_Button->show(1);
        int option = 74751;
        do {
            option = choose2(1);
            switch (option) {
                case 1: {
                    bool repeat=false;//标识位，表示是否重复添加
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    for(auto user:management.currentUser.broList){
                        if(user.name==name){
                            CTools::empty(startX + width - 16, startY + 37, 30, 5);
                            CLabel *tip_error_Label = new CLabel(startX + width - 16, startY + 37, 0, 0,
                                                                 "对方已是您的好友，请勿重复添加！");
                            tip_error_Label->show(1);
                            repeat=true;
                            break;
                        }
                    }
                    if(repeat)
                        break;
                    CLabel *tip_accept_Label = new CLabel(startX + width - 15, startY + 37, 0, 0,
                                                          "您已同意          的好友申请");
                    CLabel *tip_friend_Label = new CLabel(startX + width - 8, startY + 39, 0, 0, "你们已成为好友！");
                    tip_accept_Label->show(1);
                    name_Label->show(2);
                    tip_friend_Label->show(1);
                    //接受好友，添加进好友列表
                    for (const auto& pair : management.userList) {
                        if(name==pair.second.name){
                            //更新信息
                            management.currentUser.broList.push_back(pair.second);
                            management.userList.find(management.currentUser.id)->second.broList.push_back(pair.second);
                            break;
                        }
                    }
                    //同时，将自己添加进对方好友列表里
                    for (auto& pair : management.userList) {
                        if(name==pair.second.name){
                            //更新信息
                            pair.second.broList.push_back(management.currentUser);
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    CLabel *tip_reject_Label = new CLabel(startX + width - 15, startY + 37, 0, 0,
                                                          "您已拒绝          的好友申请");
                    tip_reject_Label->show(1);
                    name_Label->show(2);
                    break;
                }
            }
        } while (option != 1 && option != 2);
        exit_Button->show(3);
        char key;
        while (true) {//选择功能号 0返回
            key = getch();
            if (key == '0')
                break;
        }
        //消息已读，清空
        management.currentUser.inBox.clear();
        //更新用户信息
        management.userList.find(management.currentUser.id)->second.inBox.clear();
        //更新面板
        CTools::empty(startX + width - 30, startY + 33, 60, 10);
    }
}

void PersonalWin::broList() {
    CTools::empty(startX + width - 40, startY + 35, 85, 3);
    CButton *broList_Button = new CButton(startX + width - 40, startY + 33, 40, 11, "", 3);
    CLabel *broList_Label = new CLabel(startX + width - 6, startY + 34, 0, 0, "好 友 列 表");
    broList_Button->show(3);
    broList_Label->show(3);
    CButton *add_Button = new CButton(startX + width - 16, startY + 40, 7, 3, "1. 添 加", 3);
    CButton *exit_Button = new CButton(startX + width + 2, startY + 40, 7, 3, "0. 返 回", 3);

    if (management.currentUser.broList.empty()) {
        CLabel *null_Label = new CLabel(startX + width - 11, startY + 37, 0, 0, "* 好 友 列 表 为 空");
        null_Label->show(1);
        add_Button->show(3);
        exit_Button->show(3);
        int option = 74751;
        bool back = false;//标识位，表示是否返回
        bool show=true;//标识位，表示是否显示错误信息
        do {
            option = choose2(2);
            switch (option) {
                case 1: {//1. 添 加
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    //显示输入框、标签
                    CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 37, 0, 0, "账  号");
                    CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 37, 15, 3, "", 8, 2, 0);
                    CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0,
                                                         " * 请输入好友账号");
                    input_Label->show(0);
                    input_Edit->show(0);
                    tip_input_Label->show(6);

                    //搜索好友id
                    string id;
                    while (true) {
                        //输入错误时，清空内容
                        CTools::goto_xy(windowStartX + width - 13, windowStartY + 37);
                        cout << "                    ";
                        //打开光标显示
                        CTools::cursorVisible(true);
                        id = CTools::input(windowStartX + width - 13, windowStartY + 37, 20, 20, 0);
                        //关闭光标显示
                        CTools::cursorVisible(false);
                        //判断用户是否存在
                        User bro;//找到的好友
                        bool flag = false;
                        auto it = management.userList.find(id);
                        if (it != management.userList.end()){//找到
                            if(it->second.id== management.currentUser.id){
                                CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                CLabel *tip_error_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                     "您不能添加自己！");
                                tip_error_Label->show(1);
                                CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                exit_Button->show(3);
                                char key;
                                while (true) {//选择功能号 0 返回
                                    key = getch();
                                    if (key == '0')
                                        break;
                                }
                                CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                flag = false;
                                back=true;
                            }else if(it->first == id){
                                bro = it->second;
                                flag = true;
                            }
                        }
                        if (flag == false) {
                            if (back)
                                break;
                            CTools::goto_xy(windowStartX + width + 13, windowStartY + 37);
                            cout << "                       ";
                            if(show){
                                CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0," * 输入错误！用户不存在");
                                tip_error_Label->show(1);
                            }
                            //选择是否重新添加
                            add_Button->show(3);
                            exit_Button->show(3);
                            int choice = 74751;
                            choice = choose2(2);
                            switch (choice) {
                                case 1://重新 1. 添 加
                                    back = false;
                                    break;
                                case 0:
                                    back = true;
                                    break;
                            }
                            //继续输入
                            if (back)
                                break;
                            else continue;
                        } else {//用户存在
                            //更新信息,发送好友请求
                            management.userList.find(bro.id)->second.inBox=management.currentUser.name;
                            CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                            CLabel *tip_success_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                   "已发送好友申请！");
                            tip_success_Label->show(1);
                            CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                            exit_Button->show(3);
                            char key;
                            while (true) {//选择功能号 0 返回
                                key = getch();
                                if (key == '0')
                                    break;
                            }
                            back = true;
                            break;
                        }
                    }
                    break;
                }
                case 0: {//0. 返 回
                    CTools::empty(startX + width - 16, startY + 37, 30, 5);
                    back = true;
                    break;
                }
            }
            if (back)
                break;
        } while (option != 1 && option != 0);
        CTools::empty(startX + width - 40, startY + 33, 80, 10);
    }
    else {//好友列表非空
        if(management.currentUser.broList.size()==1){
            string user_name = "好友1:" + management.currentUser.broList[0].name;
            auto name_Button = new CButton(startX + width - 10, startY + 36, 10, 3, user_name, 2);
            name_Button->show(2);
            add_Button->show(3);
            exit_Button->show(3);
            int option = 74751;
            bool back = false;//标识位，表示是否返回
            bool show=true;//标识位，表示是否显示错误信息
            do {
                option = choose2(2);
                switch (option) {
                    case 1: {//1. 添 加
                        CTools::empty(startX + width - 16, startY + 37, 30, 5);
                        //显示输入框、标签
                        CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 37, 0, 0, "账  号");
                        CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 37, 15, 3, "", 8, 2, 0);
                        CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0,
                                                             " * 请输入好友账号");
                        input_Label->show(0);
                        input_Edit->show(0);
                        tip_input_Label->show(6);

                        //搜索好友用户名
                        string id;
                        while (true) {
                            //输入错误时，清空内容
                            CTools::goto_xy(windowStartX + width - 13, windowStartY + 37);
                            cout << "                    ";
                            //打开光标显示
                            CTools::cursorVisible(true);
                            id = CTools::input(windowStartX + width - 13, windowStartY + 37, 20, 20, 0);
                            //关闭光标显示
                            CTools::cursorVisible(false);
                            //判断用户是否存在
                            User bro;//找到的好友
                            bool flag = false;
                            bool repeat=false;//标识位，表示是否重复添加
                            auto it = management.userList.find(id);
                            if (it != management.userList.end()){//找到
                                for(auto user:it->second.broList){
                                    if(user.id==management.currentUser.id){
                                        CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                        CLabel *tip_error_Label = new CLabel(startX + width - 16, startY + 37, 0, 0,
                                                                             "对方已是您的好友，请勿重复添加！");
                                        tip_error_Label->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//选择功能号 0 返回
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                        flag = false;
                                        back=true;
                                        repeat=true;
                                        break;
                                    }
                                }
                                if(it->second.id== management.currentUser.id){
                                    CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                    CLabel *tip_error_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                         "您不能添加自己！");
                                    tip_error_Label->show(1);
                                    CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                    exit_Button->show(3);
                                    char key;
                                    while (true) {//选择功能号 0 返回
                                        key = getch();
                                        if (key == '0')
                                            break;
                                    }
                                    CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                    flag = false;
                                    back=true;
                                }else if(it->first == id){
                                    if(!repeat){//不重复才运行
                                        bro = it->second;
                                        flag = true;
                                    }
                                }
                            }
                            if (flag == false) {
                                if (back)
                                    break;
                                CTools::goto_xy(windowStartX + width + 13, windowStartY + 37);
                                cout << "                       ";
                                if(show){
                                    CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0," * 输入错误！用户不存在");
                                    tip_error_Label->show(1);
                                }
                                //选择是否重新添加
                                add_Button->show(3);
                                exit_Button->show(3);
                                int choice = 74751;
                                choice = choose2(2);
                                switch (choice) {
                                    case 1://重新 1. 添 加
                                        back = false;
                                        break;
                                    case 0:
                                        back = true;
                                        break;
                                }
                                //继续输入
                                if (back)
                                    break;
                                else continue;
                            } else {//用户存在
                                //更新信息,发送好友请求
                                management.userList.find(bro.id)->second.inBox=management.currentUser.name;
                                CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                CLabel *tip_success_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                       "已发送好友申请！");
                                tip_success_Label->show(1);
                                CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                exit_Button->show(3);
                                char key;
                                while (true) {//选择功能号 0 返回
                                    key = getch();
                                    if (key == '0')
                                        break;
                                }
                                back = true;
                                break;
                            }
                        }
                        break;
                    }
                    case 0: {//0. 返 回
                        CTools::empty(startX + width - 16, startY + 37, 30, 5);
                        back = true;
                        break;
                    }
                }
                if (back)
                    break;
            } while (option != 1 && option != 0);
            CTools::empty(startX + width - 40, startY + 33, 80, 10);
        }
        else{
            string user1_name = "好友1:" + management.currentUser.broList[0].name;
            string user2_name = "好友2:" + management.currentUser.broList[1].name;
            auto bro1_Button = new CButton(startX + width - 18, startY + 36, 10, 3, user1_name, 2);
            auto bro2_Button = new CButton(startX + width + 1, startY + 36, 10, 3, user2_name, 2);
            bro1_Button->show(2);
            bro2_Button->show(2);
            add_Button->show(3);
            exit_Button->show(3);
            int option = 74751;
            bool back = false;//标识位，表示是否返回
            bool show=true;//标识位，表示是否显示错误信息
            do {
                option = choose2(2);
                switch (option) {
                    case 1: {//1. 添 加
                        CTools::empty(startX + width - 18, startY + 36, 40, 6);
                        //显示输入框、标签
                        CLabel *input_Label = new CLabel(windowStartX + width - 23, windowStartY + 37, 0, 0, "账  号");
                        CEdit *input_Edit = new CEdit(windowStartX + width - 14, startY + 37, 15, 3, "", 8, 2, 0);
                        CLabel *tip_input_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0,
                                                             " * 请输入好友账号");
                        input_Label->show(0);
                        input_Edit->show(0);
                        tip_input_Label->show(6);

                        //搜索好友用户名
                        string id;
                        while (true) {
                            //输入错误时，清空内容
                            CTools::goto_xy(windowStartX + width - 13, windowStartY + 37);
                            cout << "                    ";
                            //打开光标显示
                            CTools::cursorVisible(true);
                            id = CTools::input(windowStartX + width - 13, windowStartY + 37, 20, 20, 0);
                            //关闭光标显示
                            CTools::cursorVisible(false);
                            //判断用户是否存在
                            User bro;//找到的好友
                            bool flag = false;
                            bool repeat=false;//标识位，表示是否重复添加
                            auto it = management.userList.find(id);
                            if (it != management.userList.end()){//找到
                                for(auto user:it->second.broList){
                                    if(user.id==management.currentUser.id){
                                        CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                        CLabel *tip_error_Label = new CLabel(startX + width - 16, startY + 37, 0, 0,
                                                                             "对方已是您的好友，请勿重复添加！");
                                        tip_error_Label->show(1);
                                        CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                        exit_Button->show(3);
                                        char key;
                                        while (true) {//选择功能号 0 返回
                                            key = getch();
                                            if (key == '0')
                                                break;
                                        }
                                        CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                        flag = false;
                                        back=true;
                                        repeat=true;
                                        break;
                                    }
                                }
                                if(it->second.id== management.currentUser.id){
                                    CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                    CLabel *tip_error_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                         "您不能添加自己！");
                                    tip_error_Label->show(1);
                                    CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                    exit_Button->show(3);
                                    char key;
                                    while (true) {//选择功能号 0 返回
                                        key = getch();
                                        if (key == '0')
                                            break;
                                    }
                                    CTools::empty(startX + width - 9, startY + 40, 18, 2);
                                    flag = false;
                                    back=true;
                                }else if(it->first == id){
                                    if(!repeat){//不重复才运行
                                        bro = it->second;
                                        flag = true;
                                    }
                                }
                            }
                            if (flag == false) {
                                if (back)
                                    break;
                                CTools::goto_xy(windowStartX + width + 13, windowStartY + 37);
                                cout << "                       ";
                                if(show){
                                    CLabel *tip_error_Label = new CLabel(windowStartX + width + 13, windowStartY + 37, 0, 0," * 输入错误！用户不存在");
                                    tip_error_Label->show(1);
                                }
                                //选择是否重新添加
                                add_Button->show(3);
                                exit_Button->show(3);
                                int choice = 74751;
                                choice = choose2(2);
                                switch (choice) {
                                    case 1://重新 1. 添 加
                                        back = false;
                                        break;
                                    case 0:
                                        back = true;
                                        break;
                                }
                                //继续输入
                                if (back)
                                    break;
                                else continue;
                            } else {//用户存在
                                //更新信息,发送好友请求
                                management.userList.find(bro.id)->second.inBox=management.currentUser.name;
                                CTools::empty(windowStartX + width - 23, windowStartY + 36, 57, 6);
                                CLabel *tip_success_Label = new CLabel(startX + width - 8, startY + 37, 0, 0,
                                                                       "已发送好友申请！");
                                tip_success_Label->show(1);
                                CButton *exit_Button = new CButton(startX + width - 9, startY + 40, 9, 3, "0. 返    回", 3);
                                exit_Button->show(3);
                                char key;
                                while (true) {//选择功能号 0 返回
                                    key = getch();
                                    if (key == '0')
                                        break;
                                }
                                back = true;
                                break;
                            }
                        }
                        break;
                    }
                    case 0: {//0. 返 回
                        CTools::empty(startX + width - 18, startY + 36, 40, 6);
                        back = true;
                        break;
                    }
                }
                if (back)
                    break;
            } while (option != 1 && option != 0);
            CTools::empty(startX + width - 40, startY + 33, 80, 10);
        }
    }
}