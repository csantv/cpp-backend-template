cmake_minimum_required(VERSION 3.18)
project(uSockets LANGUAGES C CXX)

add_library(usockets STATIC)

set_target_properties(usockets PROPERTIES
    C_STANDARD 11
    CXX_STANDARD 17
    C_EXTENSIONS OFF
    CXX_EXTENSIONS OFF
    INTERPROCEDURAL_OPTIMIZATION ON
)

find_package(OpenSSL REQUIRED)

file(GLOB_RECURSE usockets_SRC "*.c" "*.h" "*.cpp")
target_sources(usockets PRIVATE ${usockets_SRC})
target_include_directories(usockets PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(usockets PRIVATE LIBUS_USE_OPENSSL)
target_link_libraries(usockets PRIVATE OpenSSL::SSL OpenSSL::Crypto)

if (WIN32)
    include(FindPkgConfig)
    pkg_check_modules(LIBUV libuv REQUIRED IMPORTED_TARGET)
    target_link_libraries(usockets PRIVATE PkgConfig::LIBUV)
endif ()
