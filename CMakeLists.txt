cmake_minimum_required(VERSION 3.9)
project(TimbreAutomatizado)

#Set cmake
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(RESOURCE resource/)
set(SOURCE_FILES Inicio/inicio.cpp Splash/splash.cpp )
set(INCLUDE_FILES Inicio/inicio.h Splash/splash.cpp )
set(UI_FILES Inicio/inicio.ui)

#Find packages
find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core)

add_executable(TimbreAutomatizado
        main.cpp
        ${SOURCE_FILES}
        ${INCLUDE_FILES}
        ${UI_FILES}
        )

qt5_use_modules(${PROJECT_NAME} Core Gui Widgets )

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )