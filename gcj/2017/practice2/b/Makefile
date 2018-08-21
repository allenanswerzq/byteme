all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2017-p2-b.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-2017-p2-b.txt
	@echo "\n---------------------"
	./elf < in-2017-p2-b.txt > 2017-p2-b-OOOOOOUT.txt 
	colordiff -y 2017-p2-b-OOOOOOUT.txt true-2017-p2-b.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2017-p2-b-SSSSSSmall.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2017-p2-b-SSSSSSmall.txt

clean:
	rm ./elf
