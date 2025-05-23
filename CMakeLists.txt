cmake_minimum_required(VERSION 3.16)

project(SwiftBoost VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SwiftBoost
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        windowstweaks.h windowstweaks.cpp windowstweaks.ui
        cpu_tweaks.h cpu_tweaks.cpp cpu_tweaks.ui
        gpu_tweaks.h gpu_tweaks.cpp gpu_tweaks.ui
        network.h network.cpp network.ui
        power_tweaks.h power_tweaks.cpp power_tweaks.ui
        revert_and_services.h revert_and_services.cpp revert_and_services.ui
        mainmenu.h mainmenu.cpp mainmenu.ui
        resources.qrc
    )
else()
    if(ANDROID)
        add_library(SwiftBoost SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(SwiftBoost
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SwiftBoost PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SwiftBoost)
endif()

set_target_properties(SwiftBoost PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SwiftBoost
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SwiftBoost)
endif()
