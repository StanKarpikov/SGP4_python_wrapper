cmake_minimum_required(VERSION 3.9)

project(SGP4_project VERSION 0.0.1 DESCRIPTION "SGP4 library")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

set(SOURCE_LIB SGP4.cpp)

add_library(SGP4 SHARED ${SOURCE_LIB})
set_target_properties(SGP4 PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(SGP4 PROPERTIES SOVERSION 0)
set_target_properties(SGP4 PROPERTIES PUBLIC_HEADER SGP4/SGP4.h)

include(GNUInstallDirs)

install(TARGETS SGP4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
