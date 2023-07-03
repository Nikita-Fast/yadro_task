cmake_minimum_required(VERSION 3.5)

find_package(Python3 COMPONENTS Interpreter Development NumPy)

include_directories(${Python3_INCLUDE_DIRS} libs)

project(yadro_task)

set(CMAKE_CXX_STANDARD 14)

file (GLOB 
            CPPS "src/*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})

target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        libs)
