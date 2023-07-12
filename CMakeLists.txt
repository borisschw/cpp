cmake_minimum_required(VERSION 3.12)
project(test)
set(TARGET_NAME app)
SET(CMAKE_CXX_FLAGS "-std=c++17")

add_executable(${TARGET_NAME}
                                # src/ch1/head_first_dp_ch1.cpp
                                # src/ch2_observer/observ_patern_gpt.cpp
                                src/ch2_observer/my_observer.cpp
                                # src/binary_tree.cpp
                                # src/cpp_practice.cpp
                                # src/my_queue.cpp
                                # src/unique_ptr.cpp
                                # src/shared_pointers.cpp
                                # src/uniqwe_pointers_2.cpp
                                # src/deligate_pattern.cpp
                                # src/pass_function.cpp
                                #src/general/lambda_exp.cpp
                                # src/deligate_dp_simple.cpp
                                # src/strategy.cpp
)

target_include_directories(${TARGET_NAME} PUBLIC include)


