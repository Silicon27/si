cmake_minimum_required(VERSION 3.10)

project(si LANGUAGES CXX ASM)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()


set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/local-testing/*.cpp")

add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${TEST_FILES}
        include/si/memory.hpp
        include/si/type_traits.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
