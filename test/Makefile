#!/bin/bash
all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf a.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-a.txt
	@echo "\n---------------------"
	./elf < in-a.txt > a-OOOOOOUT.txt 
	colordiff -y a-OOOOOOUT.txt true-a.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in a-IIIIIIIIIN.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in a-IIIIIIIIIN.txt

clean:
	rm ./elf
