#include <iostream>
#include "SudokuBoard.h"
#include "SudokuSolver.h"
//#include <string>
using namespace std;

int main()
{
	string fileName;
	cout << "enter Sudoku file Name" << endl;
	cin >> fileName;
	cout << "entered - " + fileName << endl;
	
	SudokuBoard sudoku(fileName);
	SudokuSolver solver;
	sudoku.drawBoard();

	solver.solveSudoku(sudoku.board);


	cout << "-------------------" << endl;
	sudoku.drawBoard();
	if (sudoku.isValidSudoku()) {
		cout << "Sudoku is valid!" << endl;
	}
}



