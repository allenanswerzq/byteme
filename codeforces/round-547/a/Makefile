SHELL = /bin/bash -o pipefail
CXX = clang++

CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2
CXXFLAGS += -Wfloat-equal -Wcast-qual -Wcast-align
# CXXFLAGS += -Wconversion

RELEASE ?= 0
EXEC_TIME ?= 1
ifeq ($(RELEASE), 0)
	DEBUGFLAGS = -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
	DEBUGFLAGS += -fsanitize=address -fsanitize=undefined -fstack-protector
	EXEC_TIME = 0
	# DEBUGFLAGS += -lmcheck
endif

# For local debug purpose
CXXFLAGS += -I/Users/jche/Code/algos
DEBUGFLAGS += -D__has_trace

ifeq ($(shell ls /usr/local/opt/llvm/bin/clang > /dev/null && echo $$?), 0)
	# We are using a homebrew clang, need new flags
	CXX = /usr/local/opt/llvm/bin/clang++
	LDFLAGS += -L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib
	CXXFLAGS += -I/usr/local/opt/llvm/include -I/usr/local/opt/llvm/include/c++/v1/
endif

TARGET := $(notdir $(CURDIR))

all: test

clean:
	@echo "current directory: " $(CURDIR)
	@echo
	-rm -rf *.log *.inp *.out

# Hacking to make it rebuilding when change debug flags.
% : %.cpp Makefile
	@echo "clang++ $<"
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $< $(LDFLAGS)  -o $@

run: $(TARGET)
	./$(TARGET)

# Making samples.
samples: clean
	-mv -f /tmp/algo-samples ./ins.in >> /dev/null 2>&1 || true
	algo-split ins.in

test.res: samples $(TARGET)
	algo-run $(TARGET) test.res $(EXEC_TIME) | tee test.log

# Compare my results with other person's correct real results.
comp.res: samples cmp
	algo-run cmp comp.rel | tee comp.log
	@mv test.res comp.res

test: __diff_test

comp: __diff_comp

memo:
	ps aux | grep "[.]/$(TARGET)$$" | awk '{$$6=int($$6/1024)"M";}{print;}'

pygen: gen.py
	python3 gen.py | tee ins.in

# Ugly hacking to speed up the comiplation time of jngen library...
cppgen:
	g++ gen.cpp --std=c++11 -I/Users/jche/Code/algos/third_party/jngen/includes -o gen
	./gen | tee ins.in

.PHONY: all clean run test comp

print-%:
	@echo $* = $($*)

__diff_%: %.res
	# diff -y $*.res $*.rel | tee -a $*.log
	# @echo [1m[31mdiff successful!!![0m
