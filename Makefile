CC = g++
CFLAGS = -static-libstdc++
LIBS = -lboost_unit_test_framework
EXEC = ps1a
OBJECTS = test.o FibLFSR.o

all: test.o FibLFSR.o
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC) $(LIBS)
FibLFSR.o: FibLFSR.h
	$(CC) $(CFLAGS) -c FibLFSR.cpp
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
clean:
	rm -f $(OBJECTS) $(EXEC)
