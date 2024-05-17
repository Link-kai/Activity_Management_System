#include "public.h"

Management management;
int main() {
    SetConsoleTitleA("活动管理系统");
    management.run();
    return 0;
}