cmake_minimum_required(VERSION 3.14)
project(NSBE_Demo VERSION 0.2.0 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    matrixclass
    GIT_REPOSITORY https://github.com/AbstractClassroom-CPP/MatrixClass.git
    GIT_TAG 2.0.0
)
FetchContent_MakeAvailable(matrixclass)

add_executable(matrix_demo main.cpp)
target_link_libraries(matrix_demo PRIVATE MatrixClass::MatrixClass)
