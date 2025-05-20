# toolchain-atmel-arm.cmake

# Percorso alla toolchain
set(ARM_TOOLCHAIN_PATH "C:/Program Files (x86)/Atmel/Studio/7.0/toolchain/arm/arm-gnu-toolchain/bin")
set(TOOLCHAIN_PREFIX                arm-none-eabi-)

set(CMAKE_C_FLAGS_INIT              "-fdata-sections -ffunction-sections")
set(CMAKE_CPP_FLAGS_INIT            "-fno-rtti -fno-exceptions -fno-threadsafe-statics")
set(CMAKE_EXE_LINKER_FLAGS_INIT     "--specs=nosys.specs -Wl,--gc-sections")

# Compilatore C/C++
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Avoid compiler check
set(CMAKE_C_COMPILER_WORKS 1)

set(CMAKE_C_COMPILER "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}gcc.exe")
set(CMAKE_CXX_COMPILER "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}g++.exe")
set(CMAKE_ASM_COMPILER "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}as.exe")

# Per il linker
set(CMAKE_LINKER "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}ld.exe")
set(CMAKE_AR "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}ar.exe")
set(CMAKE_OBJCOPY "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}objcopy.exe")
set(CMAKE_OBJDUMP "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}objdump.exe")
set(CMAKE_SIZE "${ARM_TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}size.exe")

# Disabilita le librerie standard di sistema del compilatore host
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_EXECUTABLE_SUFFIX_ASM     ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_C       ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX     ".elf")