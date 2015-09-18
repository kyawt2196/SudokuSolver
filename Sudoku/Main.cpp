#include <iostream>
#include "SudokuBoard.h"

//#include <string>
using namespace std;

int main()
{
	string fileName;
	cout << "enter Sudoku file Name" << endl;
	cin >> fileName;
	cout << "entered - " + fileName << endl;
	
	SudokuBoard sudoku(fileName);
	sudoku.drawBoard();
	sudoku.solveSudoku();
	cout << "-------------------" << endl;
	sudoku.drawBoard();
	cout << sudoku.isValidSudoku() << endl;
}



