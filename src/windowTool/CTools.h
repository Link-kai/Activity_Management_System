#ifndef ACTIVITY_MANAGEMENT_SYSTEM_CTOOLS_H
#define ACTIVITY_MANAGEMENT_SYSTEM_CTOOLS_H


class CTools  //������
{
public:
    //���еķ������Ǿ�̬����
    static void drawWindow(int startX, int startY, int width, int height, int colour);//��ӡ����

    //��մ���
    static void empty(int startX, int startY, int width, int height);

    static void goto_xy(int x, int y);

    static void get_xy(int &x, int &y);

    //int x, y                  ��תλ��
    //int maxLen, int maxLine   �ı�����, ÿ�г���
    //int ips                   �Ƿ���ʾ 0:���� 1:����
    //�༭������
    static string input(int x, int y, int maxLen, int maxLine, int ips);

    static int choose();

    static void cursorVisible(bool flag);

    //��ȡ�������ڿ���̨λ��
    static POINT GetMousePos();

    /*
��������int getkey()
�������ܣ���ȡ�û�������������ֵ
������������
�������أ�ascii
*/
    static int getkey();
};


#endif //ACTIVITY_MANAGEMENT_SYSTEM_CTOOLS_H
