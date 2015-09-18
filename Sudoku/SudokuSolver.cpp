#include <iostream>
#include "SudokuSolver.h"
using namespace std;

SudokuSolver::SudokuSolver() {

}

void SudokuSolver::solveSudoku(char board[9][9]) {
	int nextX = 0;
	int nextY = 0;
	while (board[nextX][nextY] != '-') {
		++nextX;
		if (nextX > 8) {
			if (nextY == 8) {
				nextX = nextY;
				break;
			}
			nextX = 0;
			nextY++;
		}
	}
	int possibleValue = 0;
	for (possibleValue = 1; possibleValue <= 9; ++possibleValue) {
		if (solveNext(nextX, nextY, (char)(possibleValue + 48), board)) {
			break;
		}

	}
}

bool SudokuSolver::solveNext(int locationX, int locationY, char value, char board[9][9]) {
	if (isValidSpot(locationX, locationY, value, board)) {
		int nextX = locationX;
		int nextY = locationY;
		board[locationX][locationY] = value;
		do {
			++nextX;
			if (nextX > 8) {
				nextX = 0;
				nextY++;
				if (nextY > 8) {
					return true;
				}
			}
		} while (board[nextX][nextY] != '-');
		int possibleValue = 0;

		for (possibleValue = 1; possibleValue <= 9; ++possibleValue) {
			if (solveNext(nextX, nextY, (char)(possibleValue + 48), board)) {
				return true;
			}
		}
		board[locationX][locationY] = '-';
		return false;
	}
	else {
		return false;
	}
}

bool SudokuSolver::isValidSpot(int locationX, int locationY, char value, char board[9][9]) {
	for (int y = 0; y < 9; y++) {
		if (board[locationX][y] == value) {
			return false;
		}
	}
	for (int x = 0; x < 9; x++) {
		if (board[x][locationY] == value) {
			return false;
		}
	}
	int startX = locationX / 3 * 3;
	int startY = locationY / 3 * 3;
	for (int x = startX; x < startX + 3; x++) {
		for (int y = startY; y < startY + 3; y++) {
			if (board[x][y] == value) {
				return false;
			}
		}
	}
	return true;
}

int SudokuSolver::testMethod() {
	return 1;
}

