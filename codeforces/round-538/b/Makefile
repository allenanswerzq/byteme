SHELL = /bin/bash -o pipefail
CXX = clang++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2
CXXFLAGS += -Wfloat-equal -Wcast-qual -Wcast-align
# CXXFLAGS += -Wconversion

DEBUGFLAGS = -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
DEBUGFLAGS += -fsanitize=address -fsanitize=undefined -fstack-protector
# DEBUGFLAGS += -lmcheck

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
	-rm -rf *.log

% : %.cpp
	@echo "clang++ $^"
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $^ $(LDFLAGS)  -o $@

run: $(TARGET)
	./$(TARGET)

samples :
	-mv -f /tmp/algo-samples ./ins >> /dev/null 2>&1 || true

test : clean samples $(TARGET)
	algo-split ins
	algo-run $(TARGET) test.res | tee test.log
	diff -y test.res true | tee -a test.log

comp : clean cmp
	ls cmp.cpp > /dev/null 2>&1 || touch cmp.cpp
	algo-split ./ins
	algo-run cmp comp.res | tee comp.log
	diff -y test.res comp.res | tee -a comp.log

memo :
	ps aux | grep "[.]/$(TARGET)" | awk '{$$6=int($$6/1024)"M";}{print;}'

.PHONY: all clean run test comp

print-%:
	@echo $* = $($*)
