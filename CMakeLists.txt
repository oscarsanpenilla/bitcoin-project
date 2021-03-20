cmake_minimum_required(VERSION 3.0.0)
project(bitcoin)

find_package(CURL REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC curl)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

