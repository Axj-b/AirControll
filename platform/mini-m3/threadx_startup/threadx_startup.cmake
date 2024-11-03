
file(GLOB_RECURSE startup_files 
    ${CMAKE_CURRENT_LIST_DIR}/cortexm3_vectors.S
    ${CMAKE_CURRENT_LIST_DIR}/cortexm3_crt0.S
    ${CMAKE_CURRENT_LIST_DIR}/tx_initialize_low_level.S
    

)
