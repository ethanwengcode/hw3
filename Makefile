CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) -o llrec-test llrec.o llrec-test.o

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 