cmake_minimum_required(VERSION 3.22)

#set(CMAKE_TOOLCHAIN_FILE "../cmake/arm-none-eabi.cmake")


# project name
project(GatewayApp LANGUAGES C CXX ASM)



include(platform/mini-m3.cmake)

# select linker script
#set(LINKER_SCRIPT "${PLATFORM_NAME}/ld/stm32f031x6.ld")

# define CPU OPTIONS
set(CPU_OPTIONS -mthumb -mcpu=${PLATFORM_CPU})

# optimizations (-O0 -O1 -O2 -O3 -Os -Ofast -Og -flto)
set(CMAKE_C_FLAGS_DEBUG "-Og -g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_RELEASE "-Os -flto")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -flto")

add_compile_options(
    ${CPU_OPTIONS}
    $<$<COMPILE_LANGUAGE:C>:-std=c11>
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
    $<$<COMPILE_LANGUAGE:CXX>:-fms-extensions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
    -fstrict-volatile-bitfields
    -ffunction-sections
    -fno-threadsafe-statics

    -Werror
    -Wall
    -Wextra
    -Wcast-align
    -Wconversion
    -Wsign-conversion
    -Wold-style-cast
    -Wshadow
    -Wlogical-op
    -Wsuggest-override
    -Wsuggest-final-types
    -Wsuggest-final-methods
    -pedantic
)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/platform/mini-m3/CMSIS/CMSIS/Core/Include/
    ${CMAKE_CURRENT_LIST_DIR}/platform/mini-m3/CMSIS/CMSIS/Driver/Include
)

file(GLOB_RECURSE Gateway_files 
    apps/Gateway/*.h
    apps/Gateway/*.cpp
    apps/Gateway/*.c
)

file(GLOB cmsis_files
    ${CMAKE_CURRENT_LIST_DIR}/platform/mini-m3/CMSIS/CMSIS/Core/Include/*.h
)

# add_subdirectory(
#     ${CMAKE_CURRENT_LIST_DIR}/apps/Common/threadx
# )

# list of modules to build final firmware
add_executable(${PROJECT_NAME}
    ${startup_files}
    ${Gateway_files}
)



target_link_libraries(${PROJECT_NAME}
    ${CPU_OPTIONS}
    -T${LINKER_SCRIPT}
    -nostartfiles
    m
    # -nostdlib
    #threadx
)

set_property(TARGET ${PROJECT_NAME} PROPERTY LINK_DEPENDS ${LINKER_SCRIPT})

include("cmake/flash.cmake")



set_target_properties(GatewayApp PROPERTIES OUTPUT_NAME "GatewayApp.elf")

