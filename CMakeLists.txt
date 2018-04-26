cmake_minimum_required(VERSION 3.9)
project(TimbreAutomatizado)

#Set cmake
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTORCC ON)

set(RESOURCE images/)

set(SOURCE_FILES    Inicio/inicio.cpp
                    Splash/splash.cpp
                    Manual/manual.cpp)

set(INCLUDE_FILES   Inicio/inicio.h
                    Splash/splash.h
                    Manual/manual.h)

set(UI_FILES        Inicio/inicio.ui
                    Manual/manual.ui)

#Find packages
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core)

qt5_add_resources(RESOURCES resources.qrc)

add_executable(TimbreAutomatizado
        main.cpp
        ${SOURCE_FILES}
        ${INCLUDE_FILES}
        ${UI_FILES}
        ${RESOURCES}
        )

qt5_use_modules(${PROJECT_NAME} Core Gui Widgets )

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )