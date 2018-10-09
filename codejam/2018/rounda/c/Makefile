all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2018-rounda-c.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_2018-rounda-c.txt
	@echo "\n---------------------"
	./elf < in_2018-rounda-c.txt > out_2018-rounda-c.txt 
	colordiff -y out_2018-rounda-c.txt true_2018-rounda-c.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2018-rounda-c-small.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2018-rounda-c-small.txt

clean:
	rm ./elf
