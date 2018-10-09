all: compile run

compile:
	g++ -o elf srm349-1-2.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_srm349-1-2.txt
	@echo "\n---------------------"
	./elf < in_srm349-1-2.txt 2>&1 > out_srm349-1-2.txt 
	colordiff -y out_srm349-1-2.txt true_srm349-1-2.txt -W 100

clean:
	rm ./elf
