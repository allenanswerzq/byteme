all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf b.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_b.txt
	@echo "\n---------------------"
	./elf < in_b.txt > out_b.txt 
	colordiff -y out_b.txt true_b.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in in.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in in.txt

clean:
	rm ./elf
