all: compile run

compile:
	@echo
	@echo
	@echo default directory: $(shell pwd)
	@echo
	g++ -o elf d.cpp --std=c++11

run: 
	@chmod +x ./elf
	./elf

test: compile
	@chmod +x ./elf
	./elf < in_d.txt
	@echo "\n---------------------"
	./elf < in_d.txt > out_d.txt 
	colordiff -y out_d.txt true_d.txt -W 100

data_small:
	@echo "Making data.."
	@-mv ~/Downloads/*-small-practice.in ./
	@cp ./*-small-practice.in in.txt
   
data_large:
	@echo "Making data.."
	@-mv ~/Downloads/*-large-practice.in ./
	@cp ./*-large-practice.in in.txt

small: data_small
	while 1; clear && tmux clear-history; do make test; \
	echo "Press Enter to continue";  read newline; \
	clear && tmux clear-history; done

large: data_large
	while 1; clear && tmux clear-history; do make test; \
	echo "Press Enter to continue";  read newline; \
	clear && tmux clear-history; done

clean:
	rm ./elf
