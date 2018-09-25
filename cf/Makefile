#!/bin/bash
all: compile run

compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 584a.cpp --std=c++11 -O2

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	split_samples in-584a.txt
	run_samples in-584a.txt
	@echo
	diff -y result.txt true-584a.txt -W 100 | sed 's/ /-/g'

clean:
	rm ./elf
