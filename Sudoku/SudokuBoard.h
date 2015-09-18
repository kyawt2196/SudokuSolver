#include<iostream>
#include <string>

using namespace std;

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

class SudokuBoard {
public:
	char board[9][9];
	SudokuBoard::SudokuBoard(string);
	bool isValidSpot(int x, int y, char value);
	bool isValidSudoku();
	void drawBoard();
	bool solveSudoku();
	
};

#endif
