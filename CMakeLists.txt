cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# project

project(
  CMakeBaseProject
  VERSION 0.1.0
  LANGUAGES CXX
)
  
set(CMAKE_CXX_STANDARD 14)

# app executable
  
add_executable(main main.cpp)

# add dependency manager

set(CPM_DOWNLOAD_VERSION 0.34.0)

if(CPM_SOURCE_CACHE)
set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
file(DOWNLOAD
https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
${CPM_DOWNLOAD_LOCATION}
)
endif()

include(${CPM_DOWNLOAD_LOCATION})

# add dependencies

CPMAddPackage(
  NAME fmt
  GIT_TAG 9.1.0
  GITHUB_REPOSITORY fmtlib/fmt
  OPTIONS "FMT_INSTALL YES" # create an installable target
)

# link dependencies

target_link_libraries(main PRIVATE fmt::fmt)
