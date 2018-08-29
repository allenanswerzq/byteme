#!/bin/bash
all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf P21.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-P21.txt
	@echo "\n---------------------"
	./elf < in-P21.txt > P21-OOOOOOUT.txt 
	colordiff -y P21-OOOOOOUT.txt true-P21.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in P21-IIIIIIIIIN.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in P21-IIIIIIIIIN.txt

clean:
	rm ./elf
