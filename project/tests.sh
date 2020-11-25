#!/bin/bash

C_FILES=`find . -mindepth 2 -name "*.c"`

gcc -g $C_FILES ./tests.c -lm -o ./tests.out  

./tests.out