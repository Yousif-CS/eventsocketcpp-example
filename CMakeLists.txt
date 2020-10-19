# An example CMakeLists.txt file to demonstrate usage of eventsocketcpp

cmake_minimum_required(VERSION 3.0.0)
project(eventsocketcpp-example)
set(EXECUTABLE_OUTPUT_PATH ./out)

find_package(EventSocketCpp REQUIRED)
add_executable(${PROJECT_NAME} examples/server.cpp)

target_link_libraries(${PROJECT_NAME} EventSocketCpp::EventSocketCpp)
