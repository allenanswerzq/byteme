#!/bin/bash
all: run
compile:
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf n.cpp --std=c++11 -O2 -Wall

run: clean compile
	@chmod +x ./elf
	./elf

test: clean compile
	@chmod +x ./elf
	algo-split in-n.txt
	algo-run in-n.cpp | tee log-n.txt
	@echo "====================" 
	diff -y result.txt true-n.txt -W 100 | sed "s/ /-/g"

clean:
	@rm -f ./elf input_* log_* result.txt
