cmake_minimum_required(VERSION 2.8)
project (connect)

add_executable(connect connect.cc)

target_link_libraries(connect libhiredis.a)

#install(TARGETS connect RUNTIME DESTINATION bin)

