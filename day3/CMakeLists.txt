cmake_minimum_required(VERSION 2.8.9)
project(Day3)

include_directories(include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(day3 ${SOURCES})
