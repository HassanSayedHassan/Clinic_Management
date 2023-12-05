cmake_minimum_required(VERSION 3.26)
project(clinic_management C)

set(CMAKE_C_STANDARD 11)

add_executable(clinic_management main.c
        clinic.c
        clinic.h)
