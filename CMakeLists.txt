# Minimum version for cmake compatiblity
cmake_minimum_required(VERSION 3.22)
include(CMakePrintHelpers)
include(FetchContent)

# Set branch names for the sub modules dependencies
set(GITHUB_BRANCH_TOOLCHAIN "HEAD" CACHE STRING "git SHA for CMake Toolchain")
# set the location of all fetched repos
set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/_deps")
# show limited messages while cloning git repos
set(FETCHCONTENT_QUIET ON)

cmake_print_variables(GITHUB_BRANCH_TOOLCHAIN)
FetchContent_Declare(
    cmake-toolchains                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY  git@github.com:kodezine/cmake-toolchains.git
    GIT_TAG         ${GITHUB_BRANCH_TOOLCHAIN}
)

# pre-fetch the toolchain repository as the first job before project configuration
FetchContent_GetProperties(cmake-toolchains)

if(NOT cmake-toolchains_POPULATED)
    FetchContent_Populate(cmake-toolchains)
endif()

project(
    NUCLEO-H7A3ZI-Q
    VERSION     0.0.1
    LANGUAGES   C ASM CXX
    DESCRIPTION "Hardware Abstraction Layer for STM32CubeXX based project"
)
set(STM32_TYPE "h7")
set(STM32_DEVICE "STM32H7A3xxQ")
include(${cmake-toolchains_SOURCE_DIR}/silicon/st/STM32Cube.cmake)

configure_file(${CMAKE_SOURCE_DIR}/cmake/libcore-hal.txt ${CMAKE_SOURCE_DIR}/cubemx/CMakeLists.txt COPYONLY)
add_subdirectory(cubemx)
if(DEMO)
#    add_subdirectory(demo)
endif()
