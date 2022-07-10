cmake_minimum_required(VERSION 3.22)
project(CG_1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CG_1 main.cpp shape.h shape.cpp matrix.h matrix.cpp area.h area.cpp window.h window.cpp)
target_link_libraries(CG_1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

