all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2017-c-c.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-2017-c-c.txt
	@echo "\n---------------------"
	./elf < in-2017-c-c.txt > 2017-c-c-OOOOOOUT.txt 
	colordiff -y 2017-c-c-OOOOOOUT.txt true-2017-c-c.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2017-c-c-SSSSSSmall.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2017-c-c-SSSSSSmall.txt

clean:
	rm ./elf
