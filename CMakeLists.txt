cmake_minimum_required(VERSION 3.15)
project(Embedded_Software C)

set(CMAKE_C_STANDARD 11)

add_executable(Embedded_Software main.c)
add_executable(Embedded_Software.out 200IQCalculator.c)
add_executable(Embedded_Software.val val.c)
add_executable(Embedded_Software.bug1 debugsuite/buggy1.c)
add_executable(Embedded_Software.bug2 debugsuite/buggy2.c)
add_executable(Embedded_Software.bug3 debugsuite/buggy3.c)
add_executable(Embedded_Software.bug4 debugsuite/buggy4.c)
add_executable(Embedded_Software.bug5 debugsuite/buggy5.c)
