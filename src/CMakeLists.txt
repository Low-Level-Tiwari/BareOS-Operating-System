cmake_minimum_required(VERSION 3.12)
set(NAME rtos) 
include(pico_sdk_import.cmake)
project(pico_freertos C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w) 

pico_sdk_init()
include(bareOS.cmake)
add_executable(${NAME}  
        blink.c
        )

target_link_libraries(${NAME} 
        pico_stdlib      
	pico_cyw43_arch_none	
        bareOS-Kernel
        )

target_include_directories(${NAME}  
        PRIVATE ${CMAKE_CURRENT_LIST_DIR}
        )
        
pico_enable_stdio_usb(${NAME}  1) 
pico_add_extra_outputs(${NAME})

