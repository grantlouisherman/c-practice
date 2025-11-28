cmake_minimum_required(VERSION 3.10)
project(clox VERSION 1.0)

file(GLOB SOURCE_FILES "*.c")
add_executable(clox ${SOURCE_FILES})
file(GLOB HEADER_FILES "*.h")
source_group("Headers" FILES ${HEADER_FILES})
