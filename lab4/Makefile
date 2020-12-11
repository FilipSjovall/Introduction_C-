# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -g -Wall -Wextra -pedantic-errors -Wold-style-cast # -O2 to be added later for optimization
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++
# Targets
PROGS = html_tester primes #date_test

all: $(PROGS)

test: html_tester
	./html_tester
	#date_test
	#./date_test
# Targets rely on implicit rules for compiling and linking
html_tester: html_tester.o TagRemover.o
TagRemover: TagRemover.o TagRemover.h
primes: primes.o
#date_test: date_test.o date.o
#date: date.o date.h
# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
