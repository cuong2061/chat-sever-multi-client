CC = g++
CFLAGS = -c -Wall
LFLAGS =
SRC =src/main.cpp
HEADER= -I
OBJS=$(SRC:.c=.o)
EXE = chat

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@
	
.c.o:
	$(CC) $(CFLAGS) -o $@ $< -I

clean:
	rm $(EXE)
