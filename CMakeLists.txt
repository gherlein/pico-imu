cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(pico_sdk_import.cmake)

project(main C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
#file(GLOB_RECURSE SH2 RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "sh2/*.[ch]")

pico_sdk_init()

add_executable(main    
    ${CMAKE_CURRENT_LIST_DIR}    
    src/main.cpp
)

pico_enable_stdio_usb(main 0)
pico_enable_stdio_uart(main 1)

target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        src
        pico-imulib/include
        pico-imulib/sh2
        pico-imulib/src
        pico-i2clib/include
)

#add_subdirectory(pico-i2clib)
#add_subdirectory(pico-imulib)
add_library(pico-i2clib STATIC IMPORTED )
set_property(TARGET pico-i2clib PROPERTY IMPORTED_LOCATION pico-i2clib/libpico-i2clib.a)
add_library( pico-imulib  STATIC IMPORTED)
set_property(TARGET pico-imulib PROPERTY IMPORTED_LOCATION pico-imulib/libpico-imulib.a)

target_link_libraries(main
	pico_stdlib
    pico_multicore
    hardware_irq
    hardware_i2c
    hardware_gpio
    pico-imulib
    pico-i2clib
	# other libs as needed
)

pico_add_extra_outputs(main)

add_custom_target(flash
    COMMAND /bin/bash ../flash main.elf
    DEPENDS main
)
add_custom_target(reset
    COMMAND /bin/bash ../reset
    DEPENDS main
)
