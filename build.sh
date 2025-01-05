#!/bin/bash

current_path=$(pwd)
build_file=("$current_path"/*.c)
#filename=$1
filename=${build_file##*/}
filename=${filename%%.*}
port=$(arduino-cli board list | awk '$6 ~ /Arduino*/ {print $1}')

avr-gcc -Os -mmcu=atmega2560 -DF_CPU=16000000L "$current_path"/"$filename".c -o "$current_path"/"$filename".o

avr-objcopy -O ihex -j .text -j .data -R .eeprom "$current_path"/"$filename".o "$current_path"/"$filename".hex

avrdude -v -V -patmega2560 -cwiring -P"$port" -b115200 -D "-Uflash:w:$current_path/$filename.hex:i"

#rm *.eep *.hex *.elf *.o
