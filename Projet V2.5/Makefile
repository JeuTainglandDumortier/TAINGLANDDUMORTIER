SRC_EXT=c
HDR_EXT=h
SRC=$(shell ls | grep -E '*\.$(SRC_EXT)')
HDR=$(shell ls | grep -E '*\.$(HDR_EXT)')
BIN=projav

$(BIN): $(SRC) $(HDR) 
	gcc -Wall -std=gnu99 $(SRC) -lm -lSDL2 -o $(BIN)

clean:
	rm -f $(BIN)