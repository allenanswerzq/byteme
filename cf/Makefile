#!/bin/bash
all: run
compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 1033a.cpp --std=c++11 -O2 -Wall

run: clean compile
	@chmod +x ./elf
	./elf

test: clean compile
	@chmod +x ./elf
	algo-split in-1033a.txt
	algo-run in-1033a.cpp
	@echo "====================" 
	diff -y result.txt true-1033a.txt -W 100 | sed "s/ /-/g"

clean:
	@rm -f ./elf input_* output_* result.txt
