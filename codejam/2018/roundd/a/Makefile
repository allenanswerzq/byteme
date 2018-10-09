all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2018-d-a.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-2018-d-a.txt
	@echo "\n---------------------"
	./elf < in-2018-d-a.txt > 2018-d-a-OOOOOOUT.txt 
	colordiff -y 2018-d-a-OOOOOOUT.txt true-2018-d-a.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in 2018-d-a-SSSSSSmall.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in 2018-d-a-SSSSSSmall.txt

clean:
	rm ./elf
