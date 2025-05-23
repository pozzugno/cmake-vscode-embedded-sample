avr-gcc -mmcu=atmega328p -DF_CPU=8000000 -DCONFIG_FULL -g3 -c src/main.c -I src -I src/module1 -I src/ports/avr -o build/temp/main.o
avr-gcc -mmcu=atmega328p -DF_CPU=8000000 -DCONFIG_FULL -g3 -c src/module1/module1.c -I src -I src/module1 -I src/ports/avr -o build/temp/module1.o
avr-gcc -mmcu=atmega328p -DF_CPU=8000000 -DCONFIG_FULL -g3 -c src/ports/avr/bsp.c -I src -I src/module1 -I src/ports/avr -o build/temp/bsp.o
avr-gcc -mmcu=atmega328p -DF_CPU=8000000 -DCONFIG_FULL -g3 -Wl,-Map=build/temp/hello.map build/temp/main.o build/temp/module1.o build/temp/bsp.o -o build/temp/hello.elf
