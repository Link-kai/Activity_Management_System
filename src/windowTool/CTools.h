#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CTOOLS_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CTOOLS_H


class CTools  //工具类
{
public:
    //所有的方法都是静态方法
    static void drawWindow(int startX, int startY, int width, int height, int colour);//打印窗口

    //清空窗口
    static void empty(int startX, int startY, int width, int height);

    static void goto_xy(int x, int y);

    static void get_xy(int &x, int &y);

    //int x, y                  跳转位置
    //int maxLen, int maxLine   文本长度, 每行长度
    //int ips                   是否显示 0:明文 1:密文
    //编辑框输入
    static string input(int x, int y, int maxLen, int maxLine, int ips);

    static int choose();

    static void cursorVisible(bool flag);

    //获取鼠标相对于控制台位置
    static POINT GetMousePos();

    /*
函数名：int getkey()
函数功能：获取用户输入的任意键盘值
函数参数：无
函数返回：ascii
*/
    static int getkey();
};


#endif //ACTIVITY_MANAGEMENT_SYSTEM_CTOOLS_H
