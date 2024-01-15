cmake_minimum_required(VERSION 3.27)

project(KiPlay)

set(CMAKE_CXX_STANDARD 23)

#-----FTXUI------
include(FetchContent)

FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
#----------------
#-----SQLITE3----
find_package(SQLite3 REQUIRED)
#----------------

add_executable(KiPlay main.cpp
        MusicFile.cpp
        MusicFile.h
        Finder.cpp
        Finder.h
        Database.cpp
        Database.h
)

target_link_libraries(KiPlay
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
    PRIVATE SQLite::SQLite3)
