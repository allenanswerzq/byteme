#!/bin/bash
all: compile run
compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf p909.cpp --std=c++11 -O2

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	split_samples in-p909.txt
	run_samples in-p909.txt | tee log-p909.txt
	@echo
	diff -y result.txt true-p909.txt -W 100 | sed "s/ /-/g"

clean:
	rm ./elf
