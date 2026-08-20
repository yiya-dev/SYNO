cmake_minimum_required(VERSION 3.22)

project(SYNO
    VERSION 0.1.0
    DESCRIPTION "SYNO Digital Audio Workstation"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(SYNO_BUILD_TESTS "Build SYNO tests" ON)

# JUCE
add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/external/JUCE
    ${CMAKE_CURRENT_BINARY_DIR}/JUCE
)

# SYNO application
juce_add_gui_app(SYNO
    PRODUCT_NAME "SYNO"
    COMPANY_NAME "YIYA"
    BUNDLE_ID "com.yiya.syno"
    VERSION "0.1.0"
)

juce_generate_juce_header(SYNO)

target_sources(SYNO
    PRIVATE
        src/syno/app/main.cpp
)

target_compile_definitions(SYNO
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:SYNO,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:SYNO,JUCE_VERSION>"
)

target_link_libraries(SYNO
    PRIVATE
        juce::juce_gui_extra
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

if(SYNO_BUILD_TESTS)
    enable_testing()
endif()