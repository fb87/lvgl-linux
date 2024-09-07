# vim:tabstop=4 softtabstop=4 shiftwidth=4 colorcolumn=80 autoindent expandtab

cmake_minimum_required(VERSION 3.14)
include(FetchContent)

project(lvgl-linux-simulator LANGUAGES C CXX)

find_package(SDL2)

file(GLOB_RECURSE SRCS src/*.cc)

add_executable(lvgl-linux-simulator ${SRCS})

set(LV_CONF_PATH    "${CMAKE_CURRENT_SOURCE_DIR}/cfg/lv_conf.h")

FetchContent_Declare(lvgl 
    GIT_REPOSITORY  https://github.com/lvgl/lvgl.git
    GIT_TAG         v9.1.0)
FetchContent_MakeAvailable(lvgl)

target_link_libraries(lvgl-linux-simulator PRIVATE lvgl::lvgl SDL2)
