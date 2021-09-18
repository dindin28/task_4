cmake_minimum_required(VERSION 3.10)

project(task_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#========================
#PVS-Studio option
#========================
option(ANALYZE "Analyze code with PVS-Studio" OFF)

#========================
#SHOW_CONSTRUCTORS option
#========================
option(SHOW_CONSTRUCTORS "Show constructors" OFF)

if(SHOW_CONSTRUCTORS)
  add_compile_definitions(SHOW_CONSTRUCTORS)
endif()

#========================
#Headers
#========================
set(headers_path "${PROJECT_SOURCE_DIR}/include")

#========================
#Sources
#========================
file(GLOB srcs "src/*.cpp")

include_directories("src/")

#========================
#Building executable
#========================
add_executable(${PROJECT_NAME} ${srcs})

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
    ${headers_path}
)


if(ANALYZE)
  include(PVS-Studio.cmake)
  pvs_studio_add_target(TARGET analyze.target ALL
                        OUTPUT FORMAT errorfile
                        ANALYZE ${PROJECT_NAME}
                        MODE GA:1,2
                        LOG target.err)
endif()