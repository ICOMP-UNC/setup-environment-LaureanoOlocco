# Request the minimum version of CMake, in case of loew version throws error.

cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

# Define your project

project(

    "FirstProjectInCMake"
    VERSION 1.0.0
    DESCRIPTION "CMake C Project Template for OS II"
    LANGUAGES C
)

include(CTest)

set (CMAKE_C_STANDARD 17)

include_directories(include)

include(FetchContent)

# In this example we are going to use Unity to download the library from the git repository
set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

# Enable debug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    unity
    GIT_REPOSITORY ${UNITY_GIT_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND "" # Disable the update command
)

FetchContent_MakeAvailable(Unity)

file(GLOB_RECURSE SOURCE "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

target_link_libraries(${PROJECT_NAME} DynamiCLib StatiCLib)


# Add subdirectory for the tests
if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()