project(
    demo
    VERSION     0.0.1
    LANGUAGES   C ASM CXX
    DESCRIPTION "Hardware Abstraction Layer for STM32CubeXX based project"
)

if(NOT (CMAKE_SYSTEM_PROCESSOR STREQUAL "arm"))
    message(FATAL_ERROR "${PROJECT_NAME} can only compile with a suitable ARM cross compiler; no target build.")
endif()
if(NOT DEFINED STM32_DEVICE)
    message(FATAL_ERROR "${PROJECT_NAME} can only compile with a STM32 device definition")
endif()
if(NOT DEFINED ARMCMSIS_DEVICE)
    message(FATAL_ERROR "${PROJECT_NAME} can only compile with a valid ARMCMx definition")
endif()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../cubemx/Core/Src/main.c
    # The interrupts need to be reintroduced here since the weak functions are redefined in the vectors.c
    ${CMAKE_CURRENT_LIST_DIR}/../cubemx/Core/Src/stm32h7xx_it.c
    ${CMAKE_CURRENT_LIST_DIR}/../__vectors/__vectors.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../cubemx/Core/Inc
    ${CMAKE_CURRENT_LIST_DIR}/../__vectors
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        USE_HAL_DRIVER
        ${STM32_DEVICE}
#        __UVISION_VERSION="537"
#        _RTE_
)

target_link_libraries(${PROJECT_NAME}
    core-hal
)

set(${PROJECT_NAME}_LLVM_LINKER_SCRIPT "llvm_arm.ld")
set(${PROJECT_NAME}_LLVM_LINKER_PATH "${CMAKE_CURRENT_LIST_DIR}/../__linker")

setTargetCompileOptions(PROJECT_NAME)
setTargetLinkOptions(PROJECT_NAME)
