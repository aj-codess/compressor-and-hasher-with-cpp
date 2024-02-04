cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_TOOLCHAIN_FILE /Users/macbook/Documents/Projects/cpp_pool/hash_fun/vcpkg/scripts/buildsystems/vcpkg.cmake)

Project(hasher VERSION 1.0)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


find_package(ZLIB REQUIRED)
target_include_directories(main PUBLIC ${ZLIB_INCLUDE_DIR})
target_link_libraries(main PUBLIC ${ZLIB_LIBRARIES} ${ZLIB_DEPENDENCIES})
