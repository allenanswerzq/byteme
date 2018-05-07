all: compile run

compile:
	g++ -o elf srm211-1-2.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_srm211-1-2.txt
	@echo "\n---------------------"
	./elf < in_srm211-1-2.txt 2>&1 > out_srm211-1-2.txt 
	colordiff -y out_srm211-1-2.txt true_srm211-1-2.txt -W 100

clean:
	rm ./elf
