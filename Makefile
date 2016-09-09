CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
SRC =src/main.cpp
OBJS=$(SRC:.cpp=.o)
EXE = chat

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@
	
src/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm src/*.o
	rm $(EXE)
