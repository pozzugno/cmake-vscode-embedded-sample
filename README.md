# Intro

My embedded projects can be usually compiled in two ways (targets): simulator and embedded.
The embedded compilation generates the binary that will be flashed on the memory. It's the main goal of the project.
The simulator compilation runs on the developer machine, usually in DEBUG mode, simulating many hardware of the embedded device. The goal of the simulator is to speed up compilation, debugging and testing.

Indeed simulator and embedded binaries share 90% of application source code. Most of the time, fixing a bug in the simulator fixes the same bug in the embedded, in a fraction of time.

I usually used to work with an IDE for embedded (such as Atmel Studio or NXP MCUXpresso) and a different IDE for simulator (mainly Code::Blocks). This approach worked, but it was tedious to synchronize the compilation flags, search directories and so on.

So I started to explore CMake as a modern build system for my projects. I'm trying to use CMake presets to have multiple configurations. Not only simulator and embedded, but also a different product (in the sample, FULL/STANDARD/LITE).

CMake could be good as a command line tool, but I like to use an IDE. VSCode, with some extensions, seems a modern and good approach here.

# Why CMake

## Why not Makefile

I initially started trying to create a suitable Makefile for my embedded projects. After some tests, I found a good approach. I could build simulator with:

    make -DCONFIG=FULL TARGET=simulator
    make -DCONFIG=LITE TARGET=embedded

All worked well. The build output files were written to an out-of-source folder (typically build/FULL/embedded). With the usual gcc tricks, C dependecies are correctly managed. However there was a big con for me. Bad integration with IDE, for example VSCode.

As I wrote, I came from Atmel Studio, MCUXpresso, Code::Blocks and other similar IDEs. I usually select a build configuration in the IDE (FULL/embedded or LITE/simulator) and use the Build/Debug/Run shortcuts during developing loops.

Makefile doesn't support build configuration natively. make doesn't know that your project has 3 or 6 possible configurations. The same for IDE that reads the Makefile.

VSCode has tasks, so you could write one build task for each build configuration. However one is the default build task that is launched with the shortcut (Ctrl+Shift+B). If I wanted to change the current configuration, I should have changed the default build task in the tasks.json.

I read there are other tricks to manage build configurations in VSCode for projects based on Makefiles. But they are tricks, not real and elegant solutions.

So I decided to give a chance to another little monster... CMake.

## CMake Presets

# Integration with VSCode

# How to launch VSCode

I'm not a fan of changing the PATH of my system everytime I install a new software, toolchain, and so on. Moreover I don't like to include absolute paths in the repository that should be indipendent from the developer machine.

I think the best way to launch VSCode such that it (and cmake) can find all the tools is from a terminal, after setting the PATH. For example, in my Windows machine with Atmel Studio installed, I can set the PATH in this way:

    SET PATH=C:\WINDOWS\SYSTEM32;C:\WINDOWS\SYSTEM;C:\MSYS64\USR\BIN;C:\MSYS64\MINGW64\BIN
    SET PATH=C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin;%PATH%

This way VScode will be able to find native gcc compiler (mingw64 of msys2) and avr-gcc (Atmel Studio).

In the toolchain CMake file toolchain_atmel_avr you won't find absolute path, but only the prefix avr-.
