# Engine
# My Raytrace Engine as a dynamic library

# Learned using
# https://surfertas.github.io/cmake/cpp/projecteuler/2019/05/01/cmake.html
# http://web.archive.org/web/20141116113322/http://preetisblog.com/programming/how-to-write-cmakelists-txt

# Thanks to StackOverflow user vicrucann for linking eigen 
# https://stackoverflow.com/questions/28267104/using-eigen-lib-in-my-cmake-project

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

################################################################################
################### USER DEFINED VARIABLES SET HERE!!! #########################


#set(Eigen3_DIR "C:/Users/dirision/Documents/GitHub/Game/include/Eigen3/Eigen3/cmake")
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

#INCLUDE_DIRECTORIES ( "$C:/Users/dirision/Documents/GitHub/Game/include/Eigen3/Eigen3" )
#target_include_directories(Eigen PRIVATE "$C:/Users/dirision/Documents/GitHub/Game/include/Eigen3/Eigen3" )

################################################################################


# Variable assignment 
# SET(varName varValue)

# Project name for VS
project(Engine DESCRIPTION "My Engine Library")

# Include a library 
#include_directories("C:\Users\dirision\Documents\GitHub\Game\include\Eigen3\Eigen3\Eigen")
# We can include Eigen with the following (since it has a CMakeLists.txt), but because its not installed

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include_directories($(CMAKE_CURRENT_SOURCE_DIR)/src)
include_directories(${EIGEN3_INCLUDE_DIR})


# We had to use the FindEigen3.cmake that was in Eigen3's cmake folder, and copy it to our project's cmake folder. 
# From Within that file, we added a hint to look at an environment variable ( EIGEN3_ROOT )
find_package(Eigen3 3.3 REQUIRED)

file(GLOB ENGINE_SOURCE CONFIGURE_DEPENDS "./src/*.h" "./src/*.cpp")

# Tells cmake that we want to build a library
add_library(Engine SHARED ${ENGINE_SOURCE})
