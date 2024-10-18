# Gateway Application CMake configuration

# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

# Project name and languages used
project(GatewayApp LANGUAGES C CXX ASM)


include_directories(
    
    ${CMAKE_CURRENT_LIST_DIR}/../Common
    ${CMAKE_CURRENT_LIST_DIR}/apps/Gateway
)

add_executable(GatewayApp ${SOURCES})

set_target_properties(GatewayApp PROPERTIES OUTPUT_NAME "GatewayApp.elf")


