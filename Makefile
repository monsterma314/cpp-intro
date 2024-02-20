CPP := g++

HELLO_SRC := hello.cpp
HELLO_EXE := hello.exe

NAMESPACE_SRC := namespace.cpp
NAMESPACE_EXE := namespace.exe

SCOPE_SRC := scope.cpp
SCOPE_EXE := scope.exe

STRING_SRC := string.cpp
STRING_EXE := string.exe

CLASS_SRC := class.cpp
CLASS_EXE := class.exe

FILEIO_SRC := fileio.cpp
FILEIO_EXE := fileio.exe

QUESTION0_SRC := question0.cpp
QUESTION0_EXE := question0.exe

MEMORY_SRC := memory.cpp
MEMORY_EXE := memory.exe

ARGV_SRC := argv.cpp
ARGV_EXE := argv.exe

RAND_SRC := rand.cpp
RAND_EXE := rand.exe

SRCS := $(NAMESPACE_SRC) $(SCOPE_SRC) $(STRING_SRC) $(CLASS_SRC) $(FILEIO_SRC) $(QUESTION0_SRC) test_hello.cpp
OBJS := $(SRCS:.cpp=.o)

.PHONY: testall name test-name scope test-scope string test-string class test-class fileio test-fileio memory test-memory hello test-hello argv test-argv rand test-rand

# generate a .o file from a .cpp file
%.o: %.cpp
	@$(CPP) -c $*.cpp -o $*.o

help:
	@echo '============ make target guide ============'
	@echo 'make testall             Run all test cases'
	@echo 'make test-hello          Run hello world'
	@echo 'make test-name           Run namespace.cpp'
	@echo 'make test-scope          Run scope.cpp'
	@echo 'make test-string         Run string.cpp'
	@echo 'make test-class          Run class.cpp'
	@echo 'make test-fileio         Run fileio.cpp'
	@echo 'make test-question0      Run question0.cpp'
	@echo 'make test-memory         Run memory.cpp'
	@echo 'make test-argv           Run argv.cpp'
	@echo 'make clean               Clean up'

hello: hello.o
	@$(CPP) $@.o -o $@.exe
test-hello:
	@echo '=== $@ ==='
	@./$(HELLO_EXE)

namespace: namespace.o
	@$(CPP) $@.o -o $@.exe
test-name: namespace
	@echo '=== $@ ==='
	@./$(NAMESPACE_EXE)

scope: scope.o
	@$(CPP) $@.o -o $@.exe
test-scope: scope
	@echo '=== $@ ==='
	@./$(SCOPE_EXE)

string: string.o
	@$(CPP) $@.o -o $@.exe
test-string: string
	@echo '=== $@ ==='
	@./$(STRING_EXE)

class: class.o
	@$(CPP) $@.o -o $@.exe
test-class: class
	@echo '=== $@ ==='
	@./$(CLASS_EXE)

fileio: fileio.o
	@$(CPP) $@.o -o $@.exe
test-fileio: fileio
	@echo '=== $@ ==='
	@./$(FILEIO_EXE)

question0: question0.o
	@$(CPP) $@.o -o $@.exe
test-q0: question0
	@echo '=== $@ ==='
	@./$(QUESTION0_EXE)

memory: memory.o
	@$(CPP) $@.o -o $@.exe
test-memory: memory
	@echo '=== $@ ==='
	@./$(MEMORY_EXE)

argv: argv.o
	@$(CPP) $@.o -o $@.exe
test-argv: argv
	@echo '=== $@ ==='
	@./$(ARGV_EXE)

rand: rand.o
	@$(CPP) $@.o -o $@.exe
test-rand: rand
	@echo '=== $@ ==='
	@./$(RAND_EXE)


testall: test-name test-string test-scope test-class test-fileio test-q0 rand test-rand

clean:
	rm -f $(OBJS)
	rm -f $(NAMESPACE_EXE)
	rm -f $(SCOPE_EXE)
	rm -f $(STRING_EXE)
	rm -f $(CLASS_EXE)
	rm -f $(FILEIO_EXE)
	rm -f $(QUESTION0_EXE)
	rm -f $(HELLO_EXE)
	rm -f $(MEMORY_EXE)
	rm -f $(ARGV_EXE)
	rm -f $(RAND_EXE)