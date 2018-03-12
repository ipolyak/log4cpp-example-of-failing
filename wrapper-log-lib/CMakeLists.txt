set(target "wrapper-log-lib")

include_directories(${LOG4CPP_INCLUDE_DIR})

FILE(GLOB hdrs "*.h")
FILE(GLOB srcs "*.c*")

ADD_LIBRARY(${target} STATIC ${srcs} ${hdrs})
add_dependencies(${target} ${LOG4CPP_LIBRARY})
target_link_libraries(${target} ${LOG4CPP_LIBRARY})

add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_BINARY_DIR}/\$\(Configuration\)"
    "${CMAKE_CURRENT_BINARY_DIR}/../bin")
