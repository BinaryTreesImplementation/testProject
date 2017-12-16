cmake_minimum_required(VERSION 3.8)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/BinaryTreesImplementation/hunter/archive/v0.141.1.tar.gz"
    SHA1 "8238708ef68f34a6cbba00896ca677ee6a00a5ab"
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

