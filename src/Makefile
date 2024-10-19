CC=g++ -std=c++17
WWW=-Wall -Werror -Wextra
GTEST=-lgtest -lgmock -pthread
SRC_TESTS=brick_game/BrickGame.cc brick_game/snake/Snake.cc tests/test.cc
CLEAN=`find . -name "*.[c, out, need_delete]"`
all:

install:

uninstall:

dvi:

dist:

tests: clean
	mkdir -p build
	$(CC)  -pthread $(SRC_TESTS) -o ./build/test.out -lm -lgtest -lgmock
	./build/test.out
	rm -rf tests/resources/*.need_delete

clean:
	rm -rf build/*
	rm -rf $(CLEAN)

