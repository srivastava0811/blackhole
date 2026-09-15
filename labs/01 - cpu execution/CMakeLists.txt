cmake_minimum_required(VERSION 3.16)

# CMake is optional for this lab. The primary student workflow is direct
# terminal compilation with `cc`; see setup.md.

project(cpu_execution_lab C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(ENABLE_THREADS "Enable optional threaded benchmark experiments" OFF)

add_executable(cpu_lab
    src/main.c
    src/timer.c
    src/machine_info.c
    src/stride_access.c
    src/row_col_access.c
    src/bandwidth_copy.c
    src/matmul_naive.c
    src/matmul_transposed.c
    src/threaded_sum.c
)

target_include_directories(cpu_lab PRIVATE include)

if(MSVC)
    target_compile_options(cpu_lab PRIVATE /W4)
else()
    target_compile_options(cpu_lab PRIVATE -Wall -Wextra -pedantic)
endif()

if(ENABLE_THREADS)
    find_package(Threads REQUIRED)
    target_compile_definitions(cpu_lab PRIVATE ENABLE_THREADS)
    target_link_libraries(cpu_lab PRIVATE Threads::Threads)
endif()
