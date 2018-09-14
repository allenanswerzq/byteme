#!/bin/bash
all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf b.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-b.txt
	@echo "\n---------------------"
	./elf < in-b.txt > b-OOOOOOUT.txt 
	colordiff -y b-OOOOOOUT.txt true-b.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in b-IIIIIIIIIN.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in b-IIIIIIIIIN.txt

clean:
	rm ./elf
