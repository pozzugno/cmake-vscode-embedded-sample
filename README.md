My embedded projects can be usually compiled in two ways (targets): simulator and embedded.
The embedded compilation generates the binary that will be flashed on the memory. It's the main goal of the project.
The simulator compilation runs on the developer machine, usually in DEBUG mode, simulating many hardware of the embedded device. The goal of the simulator is to speed up compilation, debugging and testing.

Indeed simulator and embedded binaries share 90% of application source code. Most of the time, fixing a bug in the simulator fixes the same bug in the embedded, in a fraction of time.

I usually used to work with an IDE for embedded (such as Atmel Studio or NXP MCUXpresso) and a different IDE for simulator (mainly Code::Blocks). This approach worked, but it was tedious to synchronize the compilation flags, search directories and so on.

So I started to explore CMake as a modern build system for my projects. I'm trying to use CMake presets to have multiple configurations. Not only simulator and embedded, but also a different product (in the sample, FULL/STANDARD/LITE).

CMake could be good as a command line tool, but I like to use an IDE. VSCode, with some extensions, seems a modern and good approach here.
