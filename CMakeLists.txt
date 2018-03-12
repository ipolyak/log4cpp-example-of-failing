cmake_minimum_required(VERSION 3.0.2)

set(PROJECT_NAME log4cpp-example-of-failing)
project(${PROJECT_NAME})

# Choose Debug/Release mode
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

# Set compiler flags
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

set(CXX_STANDARD 98)
set(CXX_STANDARD_REQUIRED ON)

# - pthread library for unix-based platforms
if (UNIX AND NOT APPLE)
    find_package(Threads)
    if (NOT THREADS_FOUND)
        message(FATAL_ERROR "Pthread library not found.")
    endif()
    include_directories(SYSTEM ${THREADS_INCLUDE_DIR})
endif()

# Build
# - log4cp library
set(LOG4CPP_LIBRARY "log4cpp")
set(LOG4CPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/log4cpp/include")
# generating config.h header for log4pp library
if (UNIX AND NOT APPLE)
    message(STATUS "Configure of log4cpp library started.")
    execute_process(COMMAND /bin/sh chmod +x "${CMAKE_CURRENT_SOURCE_DIR}/log4cpp/configure"
        COMMAND /bin/sh "${CMAKE_CURRENT_SOURCE_DIR}/log4cpp/configure"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/log4cpp/")
endif()

# - wrapper for the log4cpp library
set(WRAPPER_LOG_LIBRARY "wrapper-log-lib")
set(WRAPPER_LOG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/wrapper-log-lib")

# - some library
set(SOME_LIBRARY "some-lib")
set(SOME_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/some-lib")

add_subdirectory("log4cpp")
add_subdirectory("wrapper-log-lib")
add_subdirectory("some-lib")
add_subdirectory("main")

# Report
message(STATUS "")
message(STATUS "==============================================================")
message(STATUS "Configuration for ${PROJECT_NAME}")
message(STATUS "==============================================================")
message(STATUS "")
message(STATUS "Configuration: ${CMAKE_BUILD_TYPE}")
message(STATUS "Include directories:")
message(STATUS "   - ${WRAPPER_LOG_LIBRARY}: ${WRAPPER_LOG_INCLUDE_DIR}")
message(STATUS "   - ${LOG4CPP_LIBRARY}: ${LOG4CPP_INCLUDE_DIR}")
message(STATUS "   - ${SOME_LIBRARY}: ${SOME_INCLUDE_DIR}")
message(STATUS "Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}")
message(STATUS "")
message(STATUS "==============================================================")
message(STATUS "")