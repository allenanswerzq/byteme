#!/bin/bash
all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf p386.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-p386.txt
	@echo "\n---------------------"
	./elf < in-p386.txt > p386-OOOOOOUT.txt 
	colordiff -y p386-OOOOOOUT.txt true-p386.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in p386-IIIIIIIIIN.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in p386-IIIIIIIIIN.txt

clean:
	rm ./elf
