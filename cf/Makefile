#!/bin/bash
all: compile run
compile:
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 519c.cpp --std=c++11 -O2

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	split_samples in-519c.txt
	run_samples in-519c.txt | tee log-519c.txt
	@echo
	diff -y result.txt true-519c.txt -W 100 | sed "s/ /-/g"

clean:
	rm ./elf
