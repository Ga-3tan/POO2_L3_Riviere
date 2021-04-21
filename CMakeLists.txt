cmake_minimum_required(VERSION 3.16)
project(POO2_L3_Riviere)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -pedantic")

add_executable(POO2_L3_Riviere main.cpp river/River.h river/River.cpp river/Controller.h river/Controller.cpp river/container/Container.h river/container/Container.cpp river/container/Boat.h river/container/Boat.cpp river/container/Bank.h river/container/Bank.cpp river/person/Person.h river/person/Person.cpp river/person/Son.h river/person/Son.cpp river/person/Daughter.h river/person/Daughter.cpp river/person/Mother.h river/person/Mother.cpp river/person/Father.h river/person/Father.cpp river/person/Policeman.h river/person/Policeman.cpp river/person/Robber.h river/person/Robber.cpp)