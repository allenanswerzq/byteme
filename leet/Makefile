all: compile run

compile:
	g++ -o elf p830.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_p830.txt
	@echo "\n---------------------"
	./elf < in_p830.txt 2>&1 > out_p830.txt 
	colordiff -y out_p830.txt true_p830.txt -W 100

clean:
	rm ./elf
