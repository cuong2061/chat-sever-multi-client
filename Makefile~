CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SRC =src/main.cpp
OBJ=main.o
EXE = chat
OBJ_PATH := obj/

OBJS := $(patsubst %,$(OBJ_PATH)%,$(OBJ))

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@
	
$(OBJ_PATH)%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ_PATH)*.o
	rm $(EXE)
