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
CFLAGS :=
CDFLAGS  := -I$(SRC)  -Wall -g -g3  
COFLAGS  := -I$(SRC)  -Wall -Ofast -flto 
PGO_GEN_FLAGS = -fprofile-generate 
PGO_USE_FLAGS = -fprofile-use 
LDLIBS  := -lm -L./lib/ -l:libcjson.a
LDFLAGS := #-Ofast -Wall
flags := 
#-Ofast -Wall
.PHONY: all run clean

all: debug

debug: CFLAGS += $(CDFLAGS)
debug: LDFLAGS += $(CDFLAGS)
debug: $(BIN)/$(BINARY)

release: CFLAGS += $(COFLAGS)
release: LDFLAGS += $(COFLAGS)
release: $(BIN)/$(BINARY)

pgogen: CFLAGS += $(COFLAGS) $(PGO_GEN_FLAGS)
pgogen: LDFLAGS += $(COFLAGS) $(PGO_GEN_FLAGS)
pgogen: $(BIN)/$(BINARY)

pgouse: CFLAGS += $(COFLAGS) $(PGO_USE_FLAGS)
pgouse: LDFLAGS += $(COFLAGS) $(PGO_USE_FLAGS)
pgouse: $(BIN)/$(BINARY)


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
