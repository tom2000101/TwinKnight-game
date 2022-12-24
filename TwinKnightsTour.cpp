#include <string>
#include <iostream>
#include <iomanip>
#include "TwinKnightsTour.h";
using namespace std;

TwinKnightsTour::TwinKnightsTour(int r1, int c1, int r2, int c2) {
	posR1 = r1; posC1 = c1; posR2 = r2;	posC2 = c2;
	steps1 = 0; steps2 = 0; consec1 = 0; consec2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = ".";
		}
	}
	board[posR1][posC1] = "A"; board[posR2][posC2] = "a";
}

void TwinKnightsTour::print() const {
	cout << "  ";
	for (int i = 0; i < N; i++)
		cout << setw(3) << i;
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << setw(2) << i;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == board[posR1][posC1])
				cout << setw(3) << "@";
			else if (board[i][j] == board[posR2][posC2])
				cout << setw(3) << "#";
			else
				cout << setw(3) << board[i][j];
		}	
		cout << endl;
	}
}

bool TwinKnightsTour::isValid(char knight, int r, int c) const {
	if (r < 0 || r >= N || c < 0 || c >= N) {
		return false;
	}
	if (board[r][c] != ".") {
		return false;
	}
	
	if (knight == '@') {
		if (consec1 >= 2)
			return false;
		else {
			if ((r == posR1 - 1) && (c == posC1 - 2)) {
				return true;
			}
			if ((r == posR1 - 2) && (c == posC1 - 1)) {
				return true;
			}
			if ((r == posR1 - 2) && (c == posC1 + 1)) {
				return true;
			}
			if ((r == posR1 - 1) && (c == posC1 + 2)) {
				return true;
			}
			if ((r == posR1 + 1) && (c == posC1 + 2)) {
				return true;
			}
			if ((r == posR1 + 2) && (c == posC1 + 1)) {
				return true;
			}
			if ((r == posR1 + 2) && (c == posC1 - 1)) {
				return true;
			}
			if ((r == posR1 + 1) && (c == posC1 - 2)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	if (knight == '#') {
		if (consec2 >= 2)
			return false;
		else {
			if ((r == posR2 - 1) && (c == posC2 - 2)) {
				return true;
			}
			if ((r == posR2 - 2) && (c == posC2 - 1)) {
				return true;
			}
			if ((r == posR2 - 2) && (c == posC2 + 1)) {
				return true;
			}
			if ((r == posR2 - 1) && (c == posC2 + 2)) {
				return true;
			}
			if ((r == posR2 + 1) && (c == posC2 + 2)) {
				return true;
			}
			if ((r == posR2 + 2) && (c == posC2 + 1)) {
				return true;
			}
			if ((r == posR2 + 2) && (c == posC2 - 1)) {
				return true;
			}
			if ((r == posR2 + 1) && (c == posC2 - 2)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool TwinKnightsTour::hasMoreMoves() const {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isValid('@', i, j) == true || isValid('#', i, j) == true) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool TwinKnightsTour::move(char knight, int r, int c) {
	char knight1_next, knight2_next;
	string knight1 = board[posR1][posC1];
	string knight2 = board[posR2][posC2];
	int knight1_len = knight1.length();
	int knight2_len = knight2.length();
	if (knight == '@') {
		if (isValid('@', r, c)) {
			//if the end of the string is Z
			if (knight1.at(knight1_len - 1) == 'Z') {
				//case2: from one to two letter
				if (knight1_len == 1) {
					string new_knight1 = "AA";
					knight1 = new_knight1;
				}
				//case4: special two letter (e.g. "AZ" -> "BA")
				if (knight1_len == 2) {
					char first = knight1[0];
					first++;
					string str_first;
					str_first = first;
					knight1 = str_first + "A";
				}
			}
			else {
				//case1: one letter
				if (knight1_len == 1) {
					knight1_next = knight1[0];
					knight1_next++;
					knight1 = knight1_next;
				}
				//case3: two letter increment
				if (knight1_len == 2) {
					char first = knight1[0];
					char second = knight1[1];
					second++;
					string str_first;
					str_first = first;
					string str_second;
					str_second = second;
					knight1 = str_first + str_second;
				}
			}
			steps1++; 
			consec1++;
			consec2 = 0;
			posR1 = r;
			posC1 = c;
			board[posR1][posC1] = knight1;
			return true;
		}
		else {
			return false;
		}
	}
	if (knight == '#') {
		if (isValid('#', r, c)) {
			//if the end of the string is z
			if (knight2.at(knight2_len - 1) == 'z') {
				//case2: from one to two letter
				if (knight2_len == 1) {
					string new_knight2 = "aa";
					knight2 = new_knight2;
				}
				//case4: special two letter (e.g. "az" -> "ba")
				if (knight2_len == 2) {
					char first = knight2[0];
					first++;
					string str_first;
					str_first = first;
					knight2 = str_first + "a";
				}
			}
			else {
				//case1: one letter
				if (knight2_len == 1) {
					knight2_next = knight2[0];
					knight2_next++;
					knight2 = knight2_next;
				}
				//case3: two letter increment
				if (knight2_len == 2) {
					char first = knight2[0];
					char second = knight2[1];
					second++;
					string str_first;
					str_first = first;
					string str_second;
					str_second = second;
					knight2 = str_first + str_second;
				}
			}
			steps2++;
			consec2++;
			consec1 = 0;
			posR2 = r;
			posC2 = c;
			board[posR2][posC2] = knight2;
			return true;
		}
		else {
			return false;
		}
	}

}