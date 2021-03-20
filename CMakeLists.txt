cmake_minimum_required(VERSION 3.14)
project(bitcoin)

find_package(CURL REQUIRED)


add_executable(${PROJECT_NAME}
    src/main.cpp
    src/bitcoin.cpp
    src/curlhandle.cpp
    )
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC curl)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)


