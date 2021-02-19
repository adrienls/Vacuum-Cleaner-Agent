cmake_minimum_required(VERSION 3.17)
project(Vacuum_Cleaner_Agent)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vacuum_Cleaner_Agent main.cpp "Environment/Environment.h" "Environment/Environment.cpp" "Environment/Grid.h" "Environment/Grid.cpp" "Environment/Graph.h" "Environment/Graph.cpp" "Agent/Agent.h" "Agent/Agent.cpp" "Agent/Sensor.h" "Agent/Sensor.cpp" "Agent/Effector.h" "Agent/Effector.cpp" "Agent/Problem.h" "Agent/Problem.cpp" "Agent/States.h" "Agent/States.cpp")