#!/bin/bash
all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf p880.cpp --std=c++11

run:
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-p880.txt
	@echo "\n---------------------"
	./elf < in-p880.txt > p880-OOOOOOUT.txt
	colordiff -y p880-OOOOOOUT.txt true-p880.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in p880-IIIIIIIIIN.txt

large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in p880-IIIIIIIIIN.txt

clean:
	rm ./elf
