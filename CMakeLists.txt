cmake_minimum_required(VERSION 2.8)

project (LearnRedis)

link_directories(${PROJECT_SOURCE_DIR}/hiredis)
include_directories(${PROJECT_SOURCE_DIR}/hiredis)

add_subdirectory(connect)
