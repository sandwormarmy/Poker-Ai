cmake_minimum_required(VERSION 3.30)
project(Poker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_SOURCE_DIR}/src/GUI/ui")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# UI-Dateien verarbeiten
set(UI_FILES src/GUI/ui/MainWindow.ui)
qt6_wrap_ui(UIC_FILES ${UI_FILES})

# Executable definieren
qt_add_executable(Poker
        main.cpp
        ${UIC_FILES}  # Generierte UI-Dateien hinzufügen
        src/utils/CardUtils.cpp
        src/cpp/card.cpp
        src/utils/CardUtils.h
        src/cpp/Poker.cpp
        src/cpp/Player.cpp
        src/GUI/cpp/mainwindow.cpp
        src/GUI/header/MainWindow.h
        src/GUI/cpp/settingswindow.cpp
        src/GUI/header/settingswindow.h
        src/GUI/ui/settingswindow.ui
)

# Qt-Bibliotheken verlinken
target_link_libraries(Poker PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
