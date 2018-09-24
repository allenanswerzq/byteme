#!/bin/bash
all: compile run

compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 734a.cpp --std=c++11 -O2

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	split_samples in-734a.txt
	run_samples in-734a.txt
	@echo
	diff -y result.txt true-734a.txt -W 100 | sed 's/ /-/g'

clean:
	rm ./elf
