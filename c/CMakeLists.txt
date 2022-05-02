cmake_minimum_required(VERSION 3.16)
project(LifeConsole)

set(CMAKE_CXX_STANDARD 14)
# 开启 cmake 详细信息
#set(CMAKE_VERBOSE_MAKEFILE ON)


file(GLOB SRC
        src/*
        )

file(GLOB test
        test/*
        )


macro(set_and_echo)
    set(${ARGV0} ${ARGV1})
    message(STATUS "${ARGV0}: ${ARGV1}")
endmacro()

#
#message(STATUS "****************** LIB MODULES *******************")
#
#set_and_echo(LIB_DIR ${CMAKE_BINARY_DIR}/lib)
#set_and_echo(editline_LIB ${LIB_DIR}/editline)

#if (NOT EXISTS ${LIB_DIR})
#    execute_process(COMMAND mkdir ${LIB_DIR})
#endif()
#message("check ${editline_LIB}")
#if (NOT EXISTS ${editline_LIB})
#    execute_process(COMMAND
#            bash -c "git clone https://github.com/troglobit/editline.git -b 1.17.1 ${editline_LIB}")
#set(editline_git_cmd "git clone https://github.com/troglobit/editline.git -b 1.17.1 ${editline_LIB}")
#add_custom_command(
#        OUTPUT COMMAND
#        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/
#        COMMAND
#            echo "${editline_git_cmd}"
#            git clone https://github.com/troglobit/editline.git -b 1.17.1 ${editline_LIB}
#)
#add_custom_target(
#        editline_LIB_target
#        DEPENDS  editline_LIB
#)
#add_dependencies(LifeConsole editline_LIB_target)
#endif()

#message(STATUS "****************** LIB MODULES END *******************")
set(c_utils_include ${CMAKE_SOURCE_DIR}/lib/c_utils/src)
set(c_utils_libs ${CMAKE_SOURCE_DIR}/lib/c_utils/libs)
file(GLOB c_utils_include_files ${c_utils_include}/*.h)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

set(LIB_target ${CMAKE_SOURCE_DIR}/lib/target)
#message(${LIB_target})
#add_library(STATIC editline)
# -I
include_directories(${LIB_target}/include
        ${c_utils_include}
        )

# -L
link_directories(${PROJECT_NAME} ${LIB_target}/lib/)

#link_libraries(${LIB_target}/lib/libeditline.a)

add_executable(${PROJECT_NAME}
        ${SRC}
        ${c_utils_include}
        ${c_utils_libs}/string-lib.o
        #        ${test}
        src/life.h)

# -l
target_link_libraries(${PROJECT_NAME} libeditline.a)
