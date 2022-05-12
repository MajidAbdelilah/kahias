MKDIR   := mkdir
RM   := rm
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
BINARY     := $(BIN)/kahias
CFLAGS  := -I$(SRC) -Ofast -Wall #-g3 -g -Wall 
LDLIBS  := -lm -L./lib/ -l:libcjson.a
LDFLAGS :=  #-Ofast -Wall
#-Ofast -Wall
.PHONY: all run clean

all: $(BINARY)

$(BINARY): $(OBJS) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	$(MKDIR) $@

run: $(BINARY)
	$<

clean:
	$(RM) $(OBJ)/*.o $(BINARY)

ddd: $(BINARY)
	ddd $(BINARY)
valgrind: $(BINARY)
	valgrind $(BINARY)
