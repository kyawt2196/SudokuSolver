#include<iostream>
#include <string>

using namespace std;

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

class SudokuBoard {
public:
	char board[9][9];
	SudokuBoard::SudokuBoard(string);
	bool isValidSudoku();
	void drawBoard();
};

#endif
