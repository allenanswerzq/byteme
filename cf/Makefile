#!/bin/bash
all: compile run

compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 588a.cpp --std=c++11 -O2

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	split_samples in-588a.txt
	run_samples in-588a.txt
	@echo
	diff -y result.txt true-588a.txt -W 100 | sed 's/ /-/g'

clean:
	rm ./elf
