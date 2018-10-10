#!/bin/bash
all: run
compile:
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf b.cpp --std=c++11 -O2 -Wall

run: clean compile
	@chmod +x ./elf
	./elf

test: clean compile
	@chmod +x ./elf
	algo-split in-b.txt
	algo-run in-b.cpp
	@echo "====================" 
	diff -y result.txt true-b.txt -W 100 | sed "s/ /-/g"

clean:
	@rm -f ./elf input_* output_* result.txt
