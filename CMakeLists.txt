cmake_minimum_required(VERSION 3.9)

project(SGP4_cpp_wrapper_project VERSION 0.0.1 DESCRIPTION "SGP4 library wrapper for Python")

option(TEST_E "Test as executable" OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 --no-undefined")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 --no-undefined")

set(SOURCE 
	SGP4_cpp_wrapper.cpp
	wrap.cpp
)
set(INCLUDE_DIR 
	${CMAKE_CURRENT_SOURCE_DIR}
)
if(TEST_E)
  message("Make as executable")
  add_executable(SGP4_cpp_wrapper ${SOURCE})
else()
  message("Make as shared library")
  add_library(SGP4_cpp_wrapper SHARED ${SOURCE})
  set_target_properties(SGP4_cpp_wrapper PROPERTIES VERSION ${PROJECT_VERSION})
  set_target_properties(SGP4_cpp_wrapper PROPERTIES SOVERSION 0)
  set_target_properties(SGP4_cpp_wrapper PROPERTIES PUBLIC_HEADER SGP4_cpp_wrapper.h)
endif()

target_include_directories(SGP4_cpp_wrapper PRIVATE ${INCLUDE_DIR})

add_library(SGP4 SHARED IMPORTED)
set_property(TARGET SGP4 PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/SGP4/libSGP4.so)
target_link_libraries(SGP4_cpp_wrapper SGP4)

find_package(Python 3.7 EXACT COMPONENTS Development)
find_package(PythonInterp 3.7 EXACT)
find_package(PythonLibs 3.7 EXACT)
find_package(Boost REQUIRED COMPONENTS system python3)

message("Boost package directories: ${Boost_INCLUDE_DIRS}")
message("Boost package libraries: ${Boost_LIBRARIES}")
target_include_directories(SGP4_cpp_wrapper PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries (SGP4_cpp_wrapper ${Boost_LIBRARIES})

message("Python3 package directories: ${Python_INCLUDE_DIRS}")
message("Python3 package libraries: ${Python_LIBRARIES}")
target_include_directories(SGP4_cpp_wrapper PRIVATE ${Python_INCLUDE_DIRS} ${PythonLibs_LIBRARIES})
target_link_libraries (SGP4_cpp_wrapper ${Python_LIBRARIES} ${PythonLibs_LIBRARIES})



