SHELL = /bin/bash -o pipefail
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align
# DEBUGFLAGS = -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fstack-protector -lmcheck -D_FORTIFY_SOURCE=2

TARGET := $(notdir $(CURDIR))

all: test

clean:
	@echo "current directory: " $(CURDIR)
	@echo
	-rm -rf $(TARGET) *.log cmp

% : %.cpp
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

run: $(TARGET)
	./$(TARGET)

test : clean $(TARGET)
	-mv /tmp/algo-samples ./ins > /dev/null 2>&1
	algo-split ins
	algo-run $(TARGET) test.res | tee test.log
	@echo "--------------------"
	ls test.res true >> /dev/null 2>&1 && diff -y test.res true

comp : clean cmp
	ls cmp.cpp > /dev/null || touch cmp.cpp
	algo-split ./ins
	algo-run cmp comp.res | tee comp.log
	@echo "---------------------"
	# ls test.res comp.res >> /dev/null 2>&1 && diff -y test.res comp.res
	diff -y test.res comp.res

.PHONY: all clean run test comp

print-%:
	@echo $* = $($*)
