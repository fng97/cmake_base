add_library(greeter)

target_sources(greeter
  PRIVATE
    greeter.cpp
  PUBLIC
    ${CMAKE_HOME_DIRECTORY}/include/greeter/greeter.hpp
)

target_include_directories(greeter PUBLIC $<BUILD_INTERFACE:${CMAKE_HOME_DIRECTORY}/include>)

target_link_libraries(greeter fmt::fmt)
