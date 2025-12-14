cmake_minimum_required(VERSION 3.15)
project(server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where to find Drogon
list(APPEND CMAKE_PREFIX_PATH
    "${CMAKE_SOURCE_DIR}/drogon/build"
)

# Find Drogon
find_package(Drogon CONFIG REQUIRED)

add_executable(server
    src/main.cpp
    src/controllers/HelloController.cpp
)

target_link_libraries(server
    PRIVATE Drogon::Drogon
)
