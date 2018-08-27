all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf p299.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in-p299.txt
	@echo "\n---------------------"
	./elf < in-p299.txt > p299-OOOOOOUT.txt 
	colordiff -y p299-OOOOOOUT.txt true-p299.txt -W 100

small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-*.in ./
	@cp ./*-small-*.in p299-IIIIIIIIIN.txt
   
large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-*.in ./
	@cp ./*-large-*.in p299-IIIIIIIIIN.txt

clean:
	rm ./elf
