#ifndef ACTIVITY_MANAGEMENT_SYSTEM_PUBLIC_H
#define ACTIVITY_MANAGEMENT_SYSTEM_PUBLIC_H

#include <iostream>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <regex>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "entity/User.h"
#include "entity/Management.h"
#include "entity/Activity.h"

#include "windowTool/CTools.h"
#include "windowTool/CtrBase.h"
#include "windowTool/CLabel.h"
#include "windowTool/CEdit.h"
#include "windowTool/CButton.h"
#include "windowTool/CMouse.h"

#include "window/InitWin.h"
#include "window/RegisterWin.h"
#include "window/LoginWin.h"
#include "window/HomeWin.h"
#include "window/PersonalWin.h"
#include "window/QuitWin.h"

#include "serialize/cereal/archives/json.hpp"
#include "serialize/cereal/types/string.hpp"
#include "serialize/cereal/types/vector.hpp"
#include "serialize/cereal/types/map.hpp"


#define DATA_FILE "../src/dataFile/data.json"


#define windowStartX 10
#define windowStartY 3
#define windowWidth 67
#define windowHeight 45

#define KEY_UP 72
#define KEY_DOWN_ 80
#define KEY_LEFT 75
#define KEY_RIGHT 77



#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)      //检测按键是否被按下
#define mouseMove MOUSE_MOVED			// 鼠标移动时触发
#define mouseClick 0x0					// 鼠标按键按下或松开时触发
extern Management management;
/*佛祖
////////////////////////////////////////////////////////////////////
//                          _ooOoo_                               //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                  |   | \\\  -  /// |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//            佛祖保佑       永不宕机     永无BUG                    //
////////////////////////////////////////////////////////////////////
*/
//50*15 佛祖 '\'需转义
//string fz[20]={
//"                    _ooOoo_                       \n",
//"                   88~ . ~88                      \n",
//"                   (| ^_^ |)                      \n",
//"                   O\\  =  /O                      \n",
//"                ____/`---'\\____                   \n",
//"              .'  \\\\|     |//  `.                 \n",
//"            |   | \\\\\\  -  /// |   |               \n",
//"            \\  .-\\__  `-`  ___/-. /               \n",
//"          ___`. .'  /--.--\\  `. . ___             \n",
//"        .`` '<  `.___\\_<|>_/___.'  >'''.          \n",
//"      | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |         \n",
//"      \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /         \n",
//"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n",
//"      佛祖保佑       永不宕机     永无BUG           \n",
//"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
//};
#endif //ACTIVITY_MANAGEMENT_SYSTEM_PUBLIC_H
