cmake_minimum_required(VERSION 3.18)

project(Hello World version 1.0)

add_executable(main helloworld.cpp)
configure_file(helloworld.cpp in helloworld.cpp)
