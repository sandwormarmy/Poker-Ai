cmake_minimum_required(VERSION 3.30)
project(Poker)

set(CMAKE_CXX_STANDARD 20)

add_executable(Poker main.cpp
        src/header/card.h
        src/enums/CardUtils.cpp
        src/cpp/card.cpp
        src/enums/CardUtils.h
        src/header/Poker.h
        src/cpp/Poker.cpp
        src/header/Player.h
        src/cpp/Player.cpp
        src/header/round.h
        src/cpp/round.cpp
)
