file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)

add_custom_target(
        clang-format
        COMMAND /usr/bin/clang-format
        --config=${CMAKE_SOURCE_DIR}/.clang-format
        -i
        ${ALL_SOURCE_FILES}
)