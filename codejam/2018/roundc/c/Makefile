all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf 2018-roundc-c.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_2018-roundc-c.txt
	@echo "\n---------------------"
	./elf < in_2018-roundc-c.txt > OOOOOUT_2018-roundc-c.txt 
	colordiff -y OOOOOUT_2018-roundc-c.txt true_2018-roundc-c.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in 2018-roundc-c-SSSSSSmall.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in 2018-roundc-c-LLLLLLLarge.txt

clean:
	rm ./elf
