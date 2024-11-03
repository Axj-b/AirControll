
project(MiniM3_BSP)


file(GLOB_RECURSE peripheral_files 
${CMAKE_CURRENT_LIST_DIR}/CMSIS/Core/*.c 
${CMAKE_CURRENT_LIST_DIR}/CMSIS/Core/Include/*.h 
${CMAKE_CURRENT_LIST_DIR}/STM32F10x_StdPeriph_Driver/src/*.c
${CMAKE_CURRENT_LIST_DIR}/STM32F10x_StdPeriph_Driver/inc/*.h
${CMAKE_CURRENT_LIST_DIR}/uart/*.h
${CMAKE_CURRENT_LIST_DIR}/uart/*.c
)


add_library(MiniM3_BSP STATIC)

target_sources(MiniM3_BSP PUBLIC
${peripheral_files}
)

target_include_directories(MiniM3_BSP 
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/boardConfig
    ${CMAKE_CURRENT_LIST_DIR}/CMSIS/Core/Include
    ${CMAKE_CURRENT_LIST_DIR}/STM32F10x_StdPeriph_Driver/inc
    ${CMAKE_CURRENT_LIST_DIR}/uart
    

)


