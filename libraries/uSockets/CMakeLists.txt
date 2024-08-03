cmake_minimum_required(VERSION 3.18)
project(uSockets LANGUAGES C)

add_library(usockets STATIC)

set_target_properties(usockets PROPERTIES
    C_STANDARD 11
    C_EXTENSIONS OFF
    INTERPROCEDURAL_OPTIMIZATION ON
)

include(FindPkgConfig)

pkg_check_modules(LIBUV REQUIRED libuv IMPORTED_TARGET)

file(GLOB_RECURSE usockets_SRC "*.c" "*.h")
target_sources(usockets PRIVATE ${usockets_SRC})
target_include_directories(usockets PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(usockets PRIVATE LIBUS_NO_SSL LIBUS_USE_LIBUV)
target_link_libraries(usockets PRIVATE PkgConfig::LIBUV)
