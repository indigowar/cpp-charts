cmake_minimum_required(VERSION 3.14)

project(cpp-charts)

include(cmake/build-guard.cmake)
include(cmake/compiler_settings.cmake)

# --- Main Library ---
add_library(charts_lib OBJECT src/charts/application.cpp src/charts/application.hpp src/charts/analysis/tag_storage.hpp src/charts/analysis/elements/element.hpp src/charts/analysis/elements/linked_element.hpp src/charts/analysis/elements/binary_tree_element.hpp src/charts/analysis/elements/graph_element.hpp src/charts/analysis/elements/container_element.hpp)
target_include_directories(charts_lib PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>")
target_compile_features(charts_lib PUBLIC cxx_std_17)

# --- Main Executable ---
add_executable(charts_exe src/main.cpp)
add_executable(charts::exe ALIAS charts_exe)
set_target_properties(
        charts_exe PROPERTIES
        OUTPUT_NAME charts
        EXPORT_NAME exe
)
target_link_libraries(charts_exe PRIVATE charts_lib)

# --- Tests ---
include(cmake/catch2.cmake)
add_executable(tests src/charts/application_test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain charts_lib)

# Clang-format
include(cmake/clang-format.cmake)
