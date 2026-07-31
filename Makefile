CFLAGS = -Wall -std=c99 
CC = gcc

# Display info about solving 
DEBUG_ALG = -DDEBUG_ALG -ggdb3
RELEASE = -O2
PROFILING = -pg

TARGET = sudoku
SOURCE = sudoku.c

all: release

debug_alg: CFLAGS += $(DEBUG_ALG)
debug_alg: $(TARGET)

release: CFLAGS += $(RELEASE)
release: $(TARGET)

profiling: CFLAGS += $(PROFILING) 
profiling: $(TARGET)
 

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -vf $(TARGET)
