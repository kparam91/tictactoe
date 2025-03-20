cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#find all cpp files in directories and add to SRC_FILES variable
file(GLOB_RECURSE SRC_FILES src/*.cpp)

project(tictactoe VERSION 1.0)
add_executable(tictactoe ${SRC_FILES})
#THIS LINE HAS TO BE AFTER THE ADD_EXECUTABLE SO THAT TARGET CAN BE FOUND AND LINKED
target_include_directories(tictactoe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)