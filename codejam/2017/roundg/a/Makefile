all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2017-g-a.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_2017-g-a.txt
	@echo "\n---------------------"
	./elf < in_2017-g-a.txt > 2017-g-a_OOOOOOUT.txt 
	colordiff -y 2017-g-a_OOOOOOUT.txt true_2017-g-a.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2017-g-a-SSSSSSmall.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2017-g-a-SSSSSSmall.txt

clean:
	rm ./elf
