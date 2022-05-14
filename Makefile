MKDIR   := mkdir
RM   := rm
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
BINARY     := kahias
CFLAGS  := -I$(SRC)  -Wall -g -g3 
LDLIBS  := -lm -L./lib/ -l:libcjson.a
LDFLAGS := #-Ofast -Wall
flags := 
#-Ofast -Wall
.PHONY: all run clean

all: $(BIN)/$(BINARY)

$(BIN)/$(BINARY): $(OBJS) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	$(MKDIR) $@

run: $(BIN)/$(BINARY)
	cd $(BIN) && ./$(BINARY) $(flags)

clean:
	$(RM) $(OBJ)/*.o $(BIN)/$(BINARY)

ddd: $(BINARY)
	ddd $(BINARY)
valgrind: $(BINARY)
	valgrind $(BINARY)
