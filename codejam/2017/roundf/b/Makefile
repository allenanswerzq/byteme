all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2017-f-b.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_2017-f-b.txt
	@echo "\n---------------------"
	./elf < in_2017-f-b.txt > 2017-f-b_OOOOOOUT.txt 
	colordiff -y 2017-f-b_OOOOOOUT.txt true_2017-f-b.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2017-f-b-SSSSSSmall.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2017-f-b-SSSSSSmall.txt

clean:
	rm ./elf
