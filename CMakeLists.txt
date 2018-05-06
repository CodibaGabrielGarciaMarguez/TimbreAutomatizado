cmake_minimum_required(VERSION 3.9)
project(TimbreAutomatizado)

#Set cmake
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTORCC ON)

set(SOURCE_FILES    src/Inicio/inicio.cpp
                    src/Splash/splash.cpp
                    src/Manual/manual.cpp
                    src/Perfiles/perfiles.cpp
                    src/Configuracion/configuracion.cpp
                    src/Creditos/creditos.cpp
                    src/Comunicacion/comunicacion.cpp
                    src/Perfiles/formularioperfiles.cpp
                    src/Perfiles/JsonSerializer.cpp )

set(INCLUDE_FILES   src/Inicio/inicio.h
                    src/Splash/splash.h
                    src/Manual/manual.h
                    src/Perfiles/perfiles.h
                    src/Configuracion/configuracion.h
                    src/Creditos/creditos.h
                    src/Comunicacion/comunicacion.h
                    src/Perfiles/formularioperfiles.h
                    src/Perfiles/JsonSerializer.h
        )

set(UI_FILES        src/Inicio/inicio.ui
                    src/Manual/manual.ui
                    src/Perfiles/perfiles.ui
                    src/Configuracion/configuracion.ui
                    src/Creditos/creditos.ui
                    src/Perfiles/formularioperfiles.ui
        )

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

qt5_use_modules(${PROJECT_NAME} Core Gui Widgets SerialPort)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )