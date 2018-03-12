set(target "main")

include_directories(${LOG4CPP_INCLUDE_DIR}
    ${WRAPPER_LOG_INCLUDE_DIR}
    ${SOME_INCLUDE_DIR})

add_executable(${target} main.cpp)
add_dependencies(${target} ${LOG4CPP_LIBRARY} ${WRAPPER_LOG_LIBRARY} ${SOME_LIBRARY})

if (UNIX AND NOT APPLE)
    target_link_libraries(${target} ${LOG4CPP_LIBRARY}
        ${WRAPPER_LOG_LIBRARY} ${SOME_LIBRARY} pthread)
elseif (WIN32)
    target_link_libraries(${target} ${LOG4CPP_LIBRARY}
        ${WRAPPER_LOG_LIBRARY} ${SOME_LIBRARY})
endif()

add_custom_command(
    TARGET ${target}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_BINARY_DIR}/\$\(Configuration\)"
        "${CMAKE_CURRENT_BINARY_DIR}/../bin")