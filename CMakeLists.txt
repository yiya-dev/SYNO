cmake_minimum_required(VERSION 3.22)
project(SYNO VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(SYNO_BUILD_TESTS "Build SYNO tests" ON)
option(SYNO_BUILD_SERVER_TOOLS "Build native auxiliary tools" OFF)

# JUCE integration will be pinned here once the first native prototype is established.
# Preferred workflow: add JUCE as a git submodule or FetchContent with a pinned commit/tag.
# Do not use an unpinned dependency for release builds.

add_executable(syno-bootstrap
    src/syno/app/main.cpp
)

target_compile_features(syno-bootstrap PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(syno-bootstrap PRIVATE /W4 /permissive-)
else()
    target_compile_options(syno-bootstrap PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(SYNO_BUILD_TESTS)
    enable_testing()
endif()
