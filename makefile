# change application name here (executable output name)
TARGET=CSVParser

# compiler
CC=g++
# debug
#DEBUG=-g
# optimisation
#OPT=-O0

# warnings
WARN=-Wall -Wextra -Wpedantic -Werror -Wunused -Wconversion -pedantic-errors

#PTHREAD=-pthread

VERSION=-std=c++20

CCFLAGS=$(VERSION) $(WARN) $(PTHREAD) 

#linker
LD=g++

#LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=CSVParser.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
CSVParser.o: CSVParser.cpp 
	$(CC) -c $(CCFLAGS) CSVParser.cpp -o CSVParser.o
    
clean:
	rm -f *.o $(TARGET)
