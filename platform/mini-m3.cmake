

set (PLATFORM_NAME mini-m3)
set (PLATFORM_CPU cortex-m0)
set (PLATFORM_STARTUP ${CMAKE_CURRENT_LIST_DIR}/${PLATFORM_NAME})
set (LINKER_SCRIPT ${PLATFORM_STARTUP}/ld/stm32f031x6.ld)



file(GLOB_RECURSE startup_files 
    ${PLATFORM_STARTUP}/startup/*.c 
    ${PLATFORM_STARTUP}/startup/*.cpp 
    ${PLATFORM_STARTUP}/startup/*.h
    ${PLATFORM_STARTUP}/startup/*.s
)

message(STATUS "USER PLATFORM ${PLATFORM_STARTUP}" )

link_directories(
    ${PLATFORM_STARTUP}
)
