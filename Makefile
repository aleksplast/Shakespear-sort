CC := g++
SRC := main.cpp functions.cpp
SRC_TEST := onegin.cpp test.cpp
DIR := C:\Users\USER\Documents\Onegin-sort

.PHONY: all clean

main: $(SRC)
	$(CC) $^ -o $(DIR)\$@

test: $(SRC_TEST)
	$(CC) $^ -o $(DIR)\$@

run: $(DIR)\main.exe
	$(DIR)\main.exe

clean:
	rm -rf *.exe
