cmake_minimum_required(VERSION 3.8)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/BinaryTreesImplementation/hunter/archive/v0.19.137.7.tar.gz"
    SHA1 "89aaa5f836b0cc2f6223139255eaae066e3bbcb4"
)

project(testProject)

### Download dependencies ###
hunter_add_package(SplayTree)

### Find dependencies ###
find_package(SplayTree CONFIG REQUIRED) # GTest::main

### Targets ###
file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
add_executable(tests ${${PROJECT_NAME}_TEST_SOURCES})
target_link_libraries(tests ${PROJECT_NAME} SplayTree::SplayTree )


### Testing ###
enable_testing()

if(IOS)
  # Extra cmake modules needed for iOS testing:
  # * https://github.com/ruslo/sugar/tree/master/cmake/core#sugar_add_ios_gtest
  add_test(
      NAME SimpleTest COMMAND "${CMAKE_COMMAND}" -E echo "iOS testing ignored"
  )
elseif(ANDROID)
  # Building .apk, testing: https://github.com/forexample/android-cmake
  add_test(
      NAME SimpleTest
      COMMAND "${CMAKE_COMMAND}" -E echo "Android testing ignored"
  )
else()
  add_test(NAME SimpleTest COMMAND testProject)
endif()
