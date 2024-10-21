CC=g++ -std=c++17
WWW=-Wall -Werror -Wextra
GTEST=-lgtest -lgmock -pthread
SRC_TESTS=brick_game/BrickGame.cc brick_game/snake/Snake.cc tests/test.cc
ALL_PROJECT_C_H_SRC=`find . -name "*.[cc, h]"`

all:

install:

uninstall:

dvi:

dist:

cli:
	g++ -std=c++17  auxilary/matrix/matrix.cc brick_game/BrickGame.cc brick_game/snake/Snake.cc gui/cli/gui.cc main.cc  -o a.out -lncurses

cli1:
	g++ -std=c++17 brick_game/tetris/tetris.c  auxilary/matrix/matrix.cc  gui/cli/gui.cc tetris_main.cc  -o a.out -lncurses


tests: clean
	mkdir -p build
	$(CC) $(WWW)  -pthread $(SRC_TESTS) -o ./build/test.out -lm -lgtest -lgmock
	./build/test.out
	rm -rf tests/resources/*.need_delete

gcov_report: clean
	$(CC) $(WWW) $(GTEST) $(SRC_TESTS) -fprofile-arcs -ftest-coverage -o ./build/test.out
	./build/test.out
	lcov -c -d . -o test.info --ignore-errors inconsistent --no-external
	genhtml -o report test.info --ignore-errors inconsistent 
	open ./report/index.html

check_style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(ALL_PROJECT_C_H_SRC)
	rm -rf .clang-format

correct_style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i $(ALL_PROJECT_C_H_SRC)
	rm -rf .clang-format

clean:
	rm -rf build/*
	rm -rf *.out
	rm -rf tests/resources/snake_record.need_delete
	rm -rf *.gcda *.gcno test	
	rm -rf ./report test.info


