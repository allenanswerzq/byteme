all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2017-c-d.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-2017-c-d.txt
	@echo "\n---------------------"
	./elf < in-2017-c-d.txt > 2017-c-d-OOOOOOUT.txt 
	colordiff -y 2017-c-d-OOOOOOUT.txt true-2017-c-d.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2017-c-d-SSSSSSmall.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2017-c-d-SSSSSSmall.txt

clean:
	rm ./elf
