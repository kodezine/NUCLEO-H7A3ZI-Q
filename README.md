# The NUCLEO-144 based STM32H7A3ZI-Q board STM32CubeMX based drivers
This is a repository that uses the IOC file generated from STM32CubeMX driver generation tool for the Nucleo-144 [STM32H7A3ZI-Q](https://www.st.com/en/evaluation-tools/nucleo-h7a3zi-q.html) board.

## STM32CubeMX generation options
The following options are used while configuration of STM32CubeMX IOC project:
* generates for STM32CubeIDE (tested on version 1.13.1)
* generate low level drivers (stm32h7xx_hal_...) as links rather than files to make the driver more portable
* use the [STM32CubeH7](https://github.com/STMicroelectronics/STM32CubeH7) firmware repository on GitHub as the low level drivers
* enforce the cubemx [generated hal configuration file](/cubemx/Core/Inc/stm32h7xx_hal_conf.h) to guide the low level compilation
> :warning: **LLVM Fails to find `NULL`**
>
> The auto generated file [sysmem.c](./cubemx/Core/Src/sysmem.c) uses `NULL` in the source without including `string.h` header file. This has to be re-introduced each time for a successful build.

## CMake definitions
The following CMake definitions are required for a successful build on [ARM based llvm](https://github.com/ARM-software/LLVM-embedded-toolchain-for-Arm).
| Type | Name | Value | Description |
| -- | -- | -- | -- |
| Environment | **`LLVM_CLANG_ROOT_FOLDER`** | *toolchain path* | absolute path to the folder location of the toolchain as a string |
| Environment | **`CORTEX_TYPE`** | **`cm7`** | Cortex M7 family name of the ARM controller to be used in cross compiler toolchain |
| CMake Cache Variable | **`DEMO`** | *boolean* | String value of `true` sets the build to include blinky application to work that lights up the *LD1* and *LD3* on the board alternatively at *50ms* interval. |
| CMake Cache Variable | **`CMAKE_BUILD_TYPE`** | *Debug/Release* | String for debug optimised build. |
| CMake Cache Variable | **`CMAKE_TOOLCHAIN_FILE`** | *path to cross compiler recepie* | String value that provides path where the toolchain recepie is set, usually one of the cmake files in the [toolchain repositiory](https://github.com/kodezine/cmake-toolchains). |
| CMake Cache Variable | **`GITHUB_BRANCH_TOOLCHAIN`** | *string* | String value of the GitHub branch or tag of the [toolchain repoitory](https://github.com/kodezine/cmake-toolchains). |
| CMake Variable | **`STM32_TYPE`** | **`h7`** | String value of STM32 family. |
| CMake Variable | **`STM32_DEVICE`** | **`STH32H7A3xxQ`** | _Case Sensitive_ string value of STM32 Device. |
| CMake Cache Variable | **`STM32_HAL_CONFIGURATION`** | _path to autogenerated HAL config file_ | Absolute path to the autogenerated [stm32h7xx_hal_conf.h](/cubemx/Core/Inc/stm32h7xx_hal_conf.h) file to be used for correct configuration of the HAL layer, specially the clocks. |

## CMake Project structure
![Alt text](/.readme/config.svg)
