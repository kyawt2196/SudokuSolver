#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include "SudokuBoard.h"
using namespace std;

SudokuBoard::SudokuBoard(std::string name) {
	for (int i = 0; i < 9; i++) {
		for (int n = 0; n < 9; n++) {
			board[i][n] = '+';
		}
	}
	ifstream myfile(name);
	string line;
	if (myfile.is_open()) {
		int y = 0;
		while (getline(myfile, line)) {
			for (int x = 0; x < 9; x++) {
				board[x][y] = line[x];
			}
			y++;
		}
		myfile.close();
	}
	else {
		  cout << "Unable to open file";
	}
}

bool SudokuBoard::isValidSpot(int locationX, int locationY, char value) {
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
	}while(board[nextX][nextY] != '-');
	int possibleValue = 0;

	for (possibleValue = 1; possibleValue <= 9; ++possibleValue) {
		if (isValidSpot(nextX, nextY, (char)(possibleValue + 48))) {
			break;
		}
		
	}
	if (possibleValue > 9) {
		board[locationX][locationY] = '-';
		return false;
	}
	drawBoard();
	cout << "----------------------------------" << endl;
	return true;
}


bool SudokuBoard::isValidSudoku() {
	//check vertical
	unordered_set<char> myset;
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (board[x][y] != '-') {
				if (myset.find(board[x][y]) != myset.end()) {
					return false;
				}
				else {
					myset.insert(board[x][y]);
				}
			}
		}
		myset.clear();
	}
	//check horizontal
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (board[x][y] != '-') {
				if (myset.find(board[x][y]) != myset.end()) {
					return false;
				}
				else {
					myset.insert(board[x][y]);
				}
			}
		}
		myset.clear();
	}
	//checks groups
	for (int startX = 0; startX<9; startX += 3) {
		for (int startY = 0; startY<9; startY += 3) {
			for (int x = startX; x<startX + 3; x++) {
				for (int y = startY; y<startY + 3; y++) {
					if (board[x][y] != '-') {
						if (myset.find(board[x][y]) != myset.end()) {
							return false;
						}
						else {
							myset.insert(board[x][y]);
						}
					}
				}
			}
			myset.clear();
		}
	}
	return true;
}


void SudokuBoard::drawBoard() {
	for (int y = 0; y<9; y++) {
		if (y % 3 == 0 && y != 0) {
			cout << "" << endl;
		}
		for (int x = 0; x < 9; x++) {
			if (x % 3 == 0 && x != 0) {
				cout << "  ";
				cout << board[x][y];
			}
			else {
				cout << board[x][y];
			}
		}
		cout << "" << endl;
	}
}

bool SudokuBoard::solveSudoku() {
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
		if (isValidSpot(nextX, nextY, (char)(possibleValue + 48))) {
			break;
		}

	}
	return possibleValue <= 9;
}

