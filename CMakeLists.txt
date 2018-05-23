cmake_minimum_required(VERSION 3.9)
set(PROJECT_NAME ZombieGame)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.cpp headers/Game.h src/Game.cpp headers/GameCharacter.h src/GameCharacter.cpp headers/Player.h src/Player.cpp src/Bullet.cpp headers/Bullet.h headers/Zombie.h src/Zombie.cpp headers/Movement.h src/Movement.cpp headers/PowerUp.h src/PowerUp.cpp headers/Powers.h src/Powers.cpp)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-graphics sfml-window sfml-audio)

add_definitions("-g")