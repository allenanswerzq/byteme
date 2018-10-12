#!/bin/bash
all: run
compile:
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 30b.cpp --std=c++11 -O2 -Wall

run: clean compile
	@chmod +x ./elf
	./elf

test: clean compile
	@chmod +x ./elf
	algo-split in-30b.txt
	algo-run in-30b.cpp
	@echo "====================" 
	diff -y result.txt true-30b.txt -W 100 | sed "s/ /-/g"

clean:
	@rm -f ./elf input_* log_* result.txt
