cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# project

project(
  CMakeBaseProject
  VERSION 0.1.0
  LANGUAGES CXX
)

# disable compiler extensions (-std=c++xx instead of -std=g++xx)

set(CMAKE_CXX_EXTENSIONS OFF)

# include testing

include(CTest)

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
  NAME fmt  # for string formatting
  GIT_TAG 9.1.0
  GITHUB_REPOSITORY fmtlib/fmt
  OPTIONS "FMT_INSTALL YES"  # create an installable target
)

CPMAddPackage(
  NAME spdlog  # for logging
  GITHUB_REPOSITORY gabime/spdlog 
  VERSION 1.8.2
  # don't bother linking our fmtlib
)

CPMAddPackage(
  NAME googletest  # for testing
  GITHUB_REPOSITORY google/googletest
  GIT_TAG release-1.12.1
  VERSION 1.12.1
  OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt"
)

# add libs

add_subdirectory(src/greeter)

if(BUILD_TESTING)  # set by CTest
  enable_testing()
  add_subdirectory(tests/greeter)
endif()

# add executable
  
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# set standard

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_14)  # should this be public or private?

# link dependencies

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE spdlog::spdlog greeter)
