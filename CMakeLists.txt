cmake_minimum_required(VERSION 3.8)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/BinaryTreesImplementation/hunter/archive/v0.19.137.7.tar.gz"
    SHA1 "89aaa5f836b0cc2f6223139255eaae066e3bbcb4"
)

project(testProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)
option(BUILD_EXAMPLES "Build Examples" OFF)

if(BUILD_TESTS)
  hunter_add_package(Catch)
  hunter_add_package(SplayTree)
  find_package(SplayTree CONFIG REQUIRED)

  find_package(Catch CONFIG REQUIRED)
  
  enable_testing()

  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(tests ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(tests ${PROJECT_NAME} Catch::Catch )
  target_link_libraries(tests ${PROJECT_NAME} SplayTree::SplayTree )
  add_test(NAME test_name COMMAND tests "-s" "-r" "compact" "--use-colour" "yes") 
endif()

