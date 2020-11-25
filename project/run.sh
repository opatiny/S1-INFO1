#!/bin/bash

C_FILES=`find . -mindepth 2 -name "*.c"`

gcc -g $C_FILES ./main.c -lm -o ./main.out  

./main.out