cmake_minimum_required(VERSION 3.17)
project(Vacuum_Cleaner_Agent)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vacuum_Cleaner_Agent main.cpp  "Agent.h" "Agent.cpp"   "Environment.h"   "Environment.cpp"  "Sensor.h" "Effector.h" "Sensor.cpp" "Effector.cpp" "Grid.h" "Grid.cpp" "Problem.h" "Problem.cpp" "States.h" "States.cpp")