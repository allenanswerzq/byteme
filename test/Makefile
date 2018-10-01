#!/bin/bash
all: compile run
compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf b.cpp --std=c++11 -O2

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	split_samples in-b.txt
	run_samples in-b.txt | tee log-b.txt
	@echo
	diff -y result.txt true-b.txt -W 100 | sed "s/ /-/g"

clean:
	rm ./elf
