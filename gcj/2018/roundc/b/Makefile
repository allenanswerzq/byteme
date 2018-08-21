all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2018-roundc-b.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_2018-roundc-b.txt
	@echo "\n---------------------"
	./elf < in_2018-roundc-b.txt > OOOOOUT_2018-roundc-b.txt 
	colordiff -y OOOOOUT_2018-roundc-b.txt true_2018-roundc-b.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2018-roundc-b-small.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2018-roundc-b-small.txt

clean:
	rm ./elf
