CC=g++ -std=c++17
WWW=-Wall -Werror -Wextra
GTEST=-lgtest -lgmock -pthread
SRC_TESTS=brick_game/BrickGame.cc brick_game/snake/Snake.cc tests/test.cc
CLI_SRC=auxilary/matrix/matrix.cc brick_game/BrickGame.cc brick_game/snake/Snake.cc\
		brick_game/tetris/tetris.cc gui/cli/gui.cc gui/cli/cli_menu.cc\
		controllers/BrickGameController.cc cli_app/main_cli_app.cc\

ALL_PROJECT_C_H_SRC=`find . -name "*.[cc, h]"`

all:

install: clean cli desktop

open_desktop:
	./bin/BrickGames
open_cli:
	./bin/cli.out

uninstall: clean

dvi:

dist:

cli:
	$(CC) $(WWW) $(CLI_SRC) -o bin/cli.out -lncurses

desktop:
	mkdir -p bin
	cd gui/desktop/BrickGames && qmake && make && make clean
	mv gui/desktop/BrickGames/BrickGames.app/Contents/MacOS/BrickGames bin

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
	rm -rf bin/*
	rm -rf *.out
	rm -rf tests/resources/snake_record.need_delete
	rm -rf *.gcda *.gcno test	
	rm -rf ./report test.info
	rm -rf gui/desktop/BrickGames/BrickGames.app gui/desktop/BrickGames/.qmake.stash
	rm -rf gui/desktop/BrickGames/BrickGames.pro.user
	rm -rf gui/desktop/BrickGames/*.o

