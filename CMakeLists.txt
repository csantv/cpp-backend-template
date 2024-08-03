cmake_minimum_required(VERSION 3.28)
project(cpp_backend_template)

add_executable(backend)

set_target_properties(backend PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS OFF
    INTERPROCEDURAL_OPTIMIZATION ON
    EXPORT_COMPILE_COMMANDS ON
)

include(FindPkgConfig)

pkg_check_modules(ZLIB REQUIRED zlib IMPORTED_TARGET)

add_subdirectory(libraries/uSockets)

if (WIN32)
    target_sources(backend PRIVATE src/win32/signal.cpp)
elseif (UNIX)
    target_sources(backend PRIVATE src/unix/signal.cpp)
endif ()

target_sources(backend PRIVATE
    src/main.cpp
    include/application.hpp
    include/signal.hpp
    src/application.cpp
)
target_include_directories(backend PRIVATE include/)
target_include_directories(backend SYSTEM PRIVATE third_party/)
target_link_libraries(backend PRIVATE usockets PkgConfig::ZLIB)
target_compile_definitions(backend PRIVATE SPDLOG_USE_STD_FORMAT)
