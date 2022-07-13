if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(
            FATAL
            "You can not build the project in source directory."
    )
endif()