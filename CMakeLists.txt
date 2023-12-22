cmake_minimum_required(VERSION 3.20)

project("NumCppTest" CXX)
# 开启 O3 优化
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
add_executable(${PROJECT_NAME} main.cpp)

find_package(NumCpp 2.12.1 REQUIRED)
target_link_libraries(${PROJECT_NAME}
    NumCpp::NumCpp
)