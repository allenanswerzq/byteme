SHELL = /bin/bash -o pipefail
CXX = clang++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2
CXXFLAGS += -Wfloat-equal -Wcast-qual -Wcast-align
# CXXFLAGS += -Wconversion

DEBUGFLAGS = -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
DEBUGFLAGS += -fsanitize=address -fsanitize=undefined -fstack-protector
# DEBUGFLAGS += -lmcheck

# For local debug purpose
CXXFLAGS += -I$ALGOLIB
DEBUGFLAGS += -DTRACE

ifeq ($(shell ls /usr/local/opt/llvm/bin/clang | grep -c clang), 1)
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
	algo-run $(TARGET) test.res | tee test.log

# Compare my results with other person's correct real results.
comp.res: samples cmp
	algo-run cmp comp.rel | tee comp.log
	@mv test.res comp.res

__diff_%: %.res
	diff -y $*.res $*.rel | tee -a $*.log

test: __diff_test

comp: __diff_comp

memo:
	ps aux | grep "[.]/$(TARGET)$$" | awk '{$$6=int($$6/1024)"M";}{print;}'

gen: gen.py
	python3 gen.py | tee ins.in

.PHONY: all clean run test comp

print-%:
	@echo $* = $($*)
