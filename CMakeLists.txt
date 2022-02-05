cmake_minimum_required(VERSION 3.10)
project(test)
set(TARGET_NAME app)

add_executable(${TARGET_NAME}
                                # src/binary_tree.cpp
                                # src/cpp_practice.cpp
                                # src/my_queue.cpp
                                src/unique_ptr.cpp


)

target_include_directories(${TARGET_NAME} PUBLIC include)


