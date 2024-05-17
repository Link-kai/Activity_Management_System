cmake_minimum_required(VERSION 3.28)
project(Activity_Management_System)

set(CMAKE_CXX_STANDARD 17)

include_directories(./src/serialize/)

add_executable(Activity_Management_System "src/Activity Management System.cpp"
        src/windowTool/CTools.h
        src/windowTool/CTools.cpp
        src/windowTool/CtrBase.h
        src/windowTool/CtrBase.cpp
        src/windowTool/CLabel.h
        src/windowTool/CLabel.cpp
        src/windowTool/CEdit.h
        src/windowTool/CEdit.cpp
        src/windowTool/CButton.h
        src/windowTool/CButton.cpp
        src/window/LoginWin.h
        src/window/LoginWin.cpp
        src/public.h
        src/entity/User.h
        src/entity/User.cpp
        src/entity/Activity.h
        src/entity/Activity.cpp
        src/entity/Management.h
        src/entity/Management.cpp
        src/windowTool/CMouse.h
        src/windowTool/CMouse.cpp
        src/window/InitWin.h
        src/window/InitWin.cpp
        src/window/RegisterWin.h
        src/window/RegisterWin.cpp
        src/window/QuitWin.h
        src/window/QuitWin.cpp
        src/window/HomeWin.h
        src/window/HomeWin.cpp
        src/window/PersonalWin.h
        src/window/PersonalWin.cpp
        src/window/ActivityWin.h
        src/window/ActivityWin.cpp
)
