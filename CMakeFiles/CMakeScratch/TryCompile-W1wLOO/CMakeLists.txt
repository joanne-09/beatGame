cmake_minimum_required(VERSION 3.29.3.0)
project(CMAKE_TRY_COMPILE C)
set_property(DIRECTORY PROPERTY INCLUDE_DIRECTORIES "")
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILE_DEFINITIONS}")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${EXE_LINKER_FLAGS}")
include_directories(${INCLUDE_DIRECTORIES})
set(CMAKE_SUPPRESS_REGENERATION 1)
link_directories(${LINK_DIRECTORIES})
add_definitions([==[-v -Wl,-v]==])
cmake_policy(SET CMP0065 NEW)
cmake_policy(SET CMP0083 NEW)
cmake_policy(SET CMP0155 OLD)
cmake_policy(SET CMP0157 OLD)
include("${CMAKE_ROOT}/Modules/Internal/HeaderpadWorkaround.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/lee_eason/Programming/beatGame/CMakeFiles/CMakeScratch/TryCompile-W1wLOO")
add_executable(cmTC_2abb9)
target_sources(cmTC_2abb9 PRIVATE
  "/opt/homebrew/Cellar/cmake/3.29.3/share/cmake/Modules/CMakeCCompilerABI.c"
)
file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/cmTC_2abb9_loc"
     CONTENT $<TARGET_FILE:cmTC_2abb9>)
target_link_libraries(cmTC_2abb9 ${LINK_LIBRARIES})
