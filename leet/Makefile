#!/bin/bash
all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf p135.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-p135.txt
	@echo "\n---------------------"
	./elf < in-p135.txt > p135-OOOOOOUT.txt 
	colordiff -y p135-OOOOOOUT.txt true-p135.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in p135-IIIIIIIIIN.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in p135-IIIIIIIIIN.txt

clean:
	rm ./elf
