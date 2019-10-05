SHELL = /bin/bash -o pipefail
ALGOROOT = ${ALGO}
CXX = g++-8

CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2
CXXFLAGS += -Wfloat-equal -Wcast-qual -Wcast-align
CXXFLAGS += -Wconversion

RELEASE ?= 0
EXEC_TIME ?= 1
ifeq ($(RELEASE), 0)
	DEBUGFLAGS += -fsanitize=address -fsanitize=undefined
	DEBUGFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
	# Since this flag will case a AddressSantizer error on my debug
	# function `trace`, so here i just simply comment out this one.
	# -fstack-protector
	EXEC_TIME = 0
endif

# For local debug purpose
CXXFLAGS += -I/Users/jche/Code/algos
DEBUGFLAGS += -D_has_trace

TARGET := $(notdir $(CURDIR))

all: test

clean:
	@echo "Current:" $(CURDIR)
	@-rm -rf *.inp *.out

# Hacking to make it rebuilding when change debug flags.
% : %.cc Makefile
	@echo "cxx $<"
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $< $(LDFLAGS)  -o $@ >> /dev/null 2>&1

run: $(TARGET)
	./$(TARGET)

# Making samples.
samples: clean
	@-mv -f /tmp/algo-samples ./ins.in >> /dev/null 2>&1 || true
	algo-split ins.in

test.res: samples $(TARGET)
	@echo algo-run $(TARGET)
	@unbuffer algo-run $(TARGET) test.res $(EXEC_TIME) 2>&1 | tee test_run.log

# Compare my results with other person's correct real results.
comp.res: samples cmp
	@echo algo-run $(TARGET)
	@unbuffer algo-run cmp comp.rel $(EXEC_TIME) 2>&1 | tee comp_run.log
	@mv test.res comp.res

test: __diff_test

comp: __diff_comp

memo:
	ps aux | grep "[.]/$(TARGET)$$" | awk '{$$6=int($$6/1024)"M";}{print;}'

pygen: gen.py
	python3 gen.py | tee ins.in

# Ugly hacking to speed up the comiplation time of jngen library...
cppgen:
	g++ gen.cc --std=c++11 -I$(ALGOROOT)/third_party/jngen/includes -o gen
	./gen | tee ins.in

.PHONY: all clean run test comp

print-%:
	@echo $* = $($*)

__diff_%: %.res
	# think before code

# __diff_%: %.res
# 	@>&2 echo diff $*.res $*.rel
# 	@>&2 diff -y $*.res $*.rel
# 	@>&2 echo [1m[31mdiff successful!!![0m
