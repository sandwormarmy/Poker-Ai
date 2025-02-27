cmake_minimum_required(VERSION 3.16)
project(Poker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Plattformabhängige Konfiguration
if(WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")  # Qt-Pfad für Windows
elseif(UNIX)
    find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
    if (NOT Qt6_FOUND)
        set(CMAKE_PREFIX_PATH "/usr/lib/cmake")  # Standard für Arch Linux
    endif()
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# UI-Dateien verarbeiten
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_SOURCE_DIR}/src/GUI/ui")
set(UI_FILES src/GUI/ui/MainWindow.ui src/GUI/ui/settingswindow.ui src/GUI/ui/PokerWindow.ui)
qt6_wrap_ui(UIC_FILES ${UI_FILES})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)


# Executable definieren
qt_add_executable(Poker
        main.cpp
        ${UIC_FILES}  # Generierte UI-Dateien hinzufügen
        src/utils/CardUtils.cpp
        src/cpp/Card.cpp
        src/utils/CardUtils.h
        src/cpp/Poker.cpp
        src/cpp/Player.cpp
        src/GUI/cpp/MainWindow.cpp
        src/GUI/header/MainWindow.h
        src/GUI/cpp/settingswindow.cpp
        src/GUI/header/settingswindow.h
        src/GUI/ui/settingswindow.ui
        src/GUI/cpp/PokerSettingsPage.cpp
        src/GUI/header/PokerSettingsPage.h
        src/GUI/cpp/PokerWindow.cpp
        src/GUI/header/PokerWindow.h
        src/GUI/ui/PokerWindow.ui
)

# Qt-Bibliotheken verlinken
target_link_libraries(Poker PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

target_include_directories(Poker PRIVATE
        ${CMAKE_BINARY_DIR}/Poker_autogen/include
)

# Falls nötig: Qt DLLs unter Windows kopieren
if(WIN32)
    add_custom_command(TARGET Poker POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Qt6::Core>
            $<TARGET_FILE:Qt6::Gui>
            $<TARGET_FILE:Qt6::Widgets>
            $<TARGET_FILE_DIR:Poker>
    )
endif()
