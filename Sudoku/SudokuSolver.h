#include<iostream>

using namespace std;

#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

class SudokuSolver {
public:
	SudokuSolver::SudokuSolver();
	void solveSudoku(char board[9][9]);
	int testMethod();
private:
	bool solveNext(int locationX, int locationY, char value, char board[9][9]);
	bool isValidSpot(int x, int y, char value, char board[9][9]);

};
#endif
