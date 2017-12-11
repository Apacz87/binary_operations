cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(gtest-demo)

enable_language(C)
enable_language(CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
   set(CMAKE_CXX_FLAGS         "-Wall -Wextra -Wno-unknown-pragmas -Wwrite-strings -Wno-unused -pedantic")
   if(CMAKE_VERSION VERSION_LESS "3.1")
      set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
   else()
      set(CMAKE_CXX_STANDART 11)
   endif()
   set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
   set(CMAKE_CXX_FLAGS_RELEASE "-O3")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

include_directories(
   ${PROJECT_SOURCE_DIR}/source
   )

add_library(
   binary_operations
   source/binary_operations.cpp
   )

set(GOOGLETEST_ROOT googletest/googletest CACHE STRING "Google Test source root")

include_directories(
   ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
   ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
   )

set(GOOGLETEST_SOURCES
   ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
   ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
   )

foreach(_source ${GOOGLETEST_SOURCES})
   set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
   unit_tests
   unit_tests/main.cpp
   unit_tests/setting_bits.cpp
   )

add_dependencies(unit_tests googletest)

target_link_libraries(
   unit_tests
   googletest
   binary_operations
   pthread
   )

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)

