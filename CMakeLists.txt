cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(GameProject DESCRIPTION "My game engine used in a project")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(ENGINE_LIB_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/Engine")
set(PAM_LIB_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/PAM")

if    ($(CMAKE_BUILD_TYPE) EQUAL "Debug"  )
    set(ENGINE_LIB_BUILD_PATH "${ENGINE_LIB_PATH}/build/Debug")
    set(BUILD_SUFFIX "_dbg")
elseif($(CMAKE_BUILD_TYPE) EQUAL "Release")
    set(ENGINE_LIB_BUILD_PATH "${ENGINE_LIB_PATH}/build/Release")
    set(BUILD_SUFFIX "_rel")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Add this directory for importing the engine 
add_subdirectory(${ENGINE_LIB_PATH})

# For PAM dumping
#add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/lib/PAM" "${CMAKE_CURRENT_LIST_DIR}/lib/PAM/bin")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/lib/PAM")
# find_library(PAM_LIB_DIR PAM)

include_directories($(CMAKE_CURRENT_SOURCE_DIR)/src
                    ${EIGEN3_INCLUDE_DIR}
                    "${PAM_LIB_PATH}/src"
                    "${ENGINE_LIB_PATH}/src")
#include_directories(${EIGEN3_INCLUDE_DIR})
#include_directories("${PAM_LIB_PATH}/src")

# We had to use the FindEigen3.cmake that was in Eigen3's cmake folder, and copy it to our project's cmake folder. 
# From Within that file, we added a hint to look at an environment variable ( EIGEN3_ROOT )
find_package(Eigen3 3.3 REQUIRED)

# Set Cmake to move dlls to executable folder
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}")

####################################
# Executables for debug and release
set(EXE_NAME "Game${BUILD_SUFFIX}")
file(GLOB GAME_SOURCE CONFIGURE_DEPENDS "./src/*.h" "./src/*.cpp")

add_compile_options("$<$<NOT:$<CONFIG:RELEASE>>:-DDEBUG>")

add_executable(${EXE_NAME} ${GAME_SOURCE})
# Add Engine
target_include_directories(${EXE_NAME}  PUBLIC "${ENGINE_LIB_PATH}/src"
                                        PUBLIC "${PAM_LIB_PATH}/src)")
target_link_directories(${EXE_NAME} PUBLIC "${ENGINE_LIB_PATH}/src"
                                    PUBLIC "${PAM_LIB_PATH}/src)")
target_link_libraries(${EXE_NAME} Engine PAM)

# Add PAM
#target_include_directories(${EXE_NAME} PUBLIC "${PAM_LIB_PATH}/src")
#target_link_directories(${EXE_NAME} PUBLIC "${PAM_LIB_PATH}/src")
#target_link_libraries(${EXE_NAME} PAM)