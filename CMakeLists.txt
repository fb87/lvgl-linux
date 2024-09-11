# vim:tabstop=4 softtabstop=4 shiftwidth=4 colorcolumn=80 autoindent expandtab

cmake_minimum_required(VERSION 3.14)
include(FetchContent)

project(lvgl-linux-simulator LANGUAGES C CXX)

find_package(SDL2)

file(GLOB_RECURSE SRCS src/*.cc)

add_executable(lvgl-linux-simulator ${SRCS})

set(LV_CONF_PATH    "${CMAKE_CURRENT_SOURCE_DIR}/cfg/lv_conf.h")
set(LV_USE_DRAW_SW_COMPLEX_GRADIENTS    ON)

# getch and build the lvgl based on the config specified above
message(STATUS "Fetching LVGL...")
FetchContent_Declare(lvgl
    URL https://github.com/lvgl/lvgl/archive/refs/tags/v9.2.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP OLD)
FetchContent_MakeAvailable(lvgl)

target_link_libraries(lvgl-linux-simulator PRIVATE lvgl::lvgl SDL2)
