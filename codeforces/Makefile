#!/bin/bash
all: run
compile:
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 255a.cpp --std=c++11 -O2 -Wall

run: clean compile
	@chmod +x ./elf
	./elf

test: clean compile
	@chmod +x ./elf
	algo-split in-255a.txt
	algo-run in-255a.cpp
	@echo "====================" 
	diff -y result.txt true-255a.txt -W 100 | sed "s/ /-/g"

clean:
	@rm -f ./elf input_* output_* result.txt
