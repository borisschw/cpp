cmake_minimum_required(VERSION 3.12)
project(test)
set(TARGET_NAME app)
SET(CMAKE_CXX_FLAGS "-std=c++17")

add_executable(${TARGET_NAME}
                                # src/binary_tree.cpp
                                # src/cpp_practice.cpp
                                # src/my_queue.cpp
                                # src/unique_ptr.cpp
                                # src/shared_pointers.cpp
                                # src/uniqwe_pointers_2.cpp
                                # src/deligate_pattern.cpp
                                # src/pass_function.cpp
                                src/lambda_exp.cpp
)

target_include_directories(${TARGET_NAME} PUBLIC include)


