#!/bin/bash
all: compile run

compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 4a.cpp --std=c++11 -O2

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	run_samples in-4a.txt
	@echo
	colordiff -y result.txt true-4a.txt -W 100

clean:
	rm ./elf
