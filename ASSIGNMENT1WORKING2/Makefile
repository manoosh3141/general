CC=gcc
CFLAGS=-g -Wall -std=c99 -Iinclude -lm
LIBS=
TARGET=trig

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
_DEPS = trig.h
_OBJS = trig.o main.o checkInput.o getInput.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)