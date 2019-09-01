SHELL = /bin/bash -o pipefail
ALGOROOT = ${ALGO}
CXX = g++-8

CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2
CXXFLAGS += -Wfloat-equal -Wcast-qual -Wcast-align -fvisibility=hidden
# CXXFLAGS += -Wconversion

RELEASE ?= 0
EXEC_TIME ?= 1
NO_DIFF ?= 0
ifeq ($(RELEASE), 0)
	DEBUGFLAGS += -fsanitize=address -fsanitize=undefined
	# DEBUGFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
	# Since this flag will case a AddressSantizer error on my debug
	# function `trace`, so here i just simply comment out this one.
	# -fstack-protector
	EXEC_TIME = 0
endif

# For local debug purpose
CXXFLAGS += -I$(ALGOROOT)
DEBUGFLAGS += -DLOCAL

TARGET := $(notdir $(CURDIR))

all: test

clean:
	@echo "Current:" $(CURDIR)
	@-rm -rf *.inp

# Hacking to make it rebuilding when change debug flags.
% : %.cc Makefile
	@echo "cxx $<"
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $< $(LDFLAGS)  -o $@

run: $(TARGET)
	./$(TARGET)

# Making samples.
samples: clean
	@-mv -f /tmp/algo-samples ./c.in >> /dev/null 2>&1 || true
	algo-split c.in

test: samples $(TARGET)
	@echo algo-run $(TARGET)
	@unbuffer algo-run $(TARGET) test.res $(EXEC_TIME) $(NO_DIFF) 2>&1 | tee test_run.log

# Compare my results with other person's correct real results.
comp: samples cmp
	@echo algo-run cmp
	@unbuffer algo-run cmp comp.rel $(EXEC_TIME) $(NO_DIFF) 2>&1 | tee comp_run.log

memo:
	ps aux | grep "[.]/$(TARGET)$$" | awk '{$$6=int($$6/1024)"M";}{print;}'

pygen: gen.py
	python3 gen.py | tee tests.in

# Ugly hacking to speed up the compilation time of jngen library...
cppgen:
	g++ gen.cc --std=c++11 -I$(ALGOROOT)/third_party/jngen/includes -o gen
	./gen | tee tests.in

.PHONY: all clean run test comp

print-%:
	@echo $* = $($*)
