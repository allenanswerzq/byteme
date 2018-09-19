#!/bin/bash
all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf p884.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-p884.txt
	@echo "\n---------------------"
	./elf < in-p884.txt > p884-OOOOOOUT.txt 
	colordiff -y p884-OOOOOOUT.txt true-p884.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in p884-IIIIIIIIIN.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in p884-IIIIIIIIIN.txt

clean:
	rm ./elf
