cmake_minimum_required(VERSION 3.16)

project(arthadrishya VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

# === Include all project source files ===
set(PROJECT_SOURCES
    main_moduleA.cpp

    # Source and header files
    visions.cpp
    visions.h
    profile.cpp
    profile.h
    insertt.cpp
    insertt.h
    goaldata.cpp
    goaldata.h

    # UI files (needed for AutoUic to work)
    visions.ui
    profile.ui
    insertt.ui

    # Resource file
    resource.qrc
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# === Executable target ===
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(arthadrishya
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(arthadrishya SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(arthadrishya
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# === Link Qt libraries ===
target_link_libraries(arthadrishya PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# === Bundle info for macOS/iOS (optional) ===
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.arthadrishya)
endif()

set_target_properties(arthadrishya PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# === Install locations (optional) ===
include(GNUInstallDirs)
install(TARGETS arthadrishya
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# === Finalize for Qt 6 ===
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(arthadrishya)
endif()
