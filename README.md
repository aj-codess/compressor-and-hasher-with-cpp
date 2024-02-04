configure cmake by touch CMakeLists.txt and add the below snippet
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_TOOLCHAIN_FILE ##directory to your project vcpkg/hash_fun/vcpkg/scripts/buildsystems/vcpkg.cmake)

Project(hasher VERSION 1.0)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


find_package(ZLIB REQUIRED)
target_include_directories(main PUBLIC ${ZLIB_INCLUDE_DIR})
target_link_libraries(main PUBLIC ${ZLIB_LIBRARIES} ${ZLIB_DEPENDENCIES})



in the project directory, install vcpkg by cloning the below repository into the project dir
git clone https://github.com/Microsoft/vcpkg.git


Run the bootstrap script accordingto your system to build vcpkg 
./vcpkg/bootstrap-vcpkg.sh - for mac

