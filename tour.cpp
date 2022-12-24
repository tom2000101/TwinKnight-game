#include <string>
#include <iostream>
#include <iomanip>
#include "TwinKnightsTour.h";
using namespace std;
#include <assert.h>

int main() {
    int row1, col1, row2, col2;
    while (true) {
        cout << "Knight's starting positions (row1 col1 row2 col2): ";
        cin >> row1 >> col1 >> row2 >> col2;
        if (row1 < 0 || col1 < 0 || row2 < 0 || col2 < 0 ||
            row1 >= TwinKnightsTour::N || col1 >= TwinKnightsTour::N ||
            row2 >= TwinKnightsTour::N || col2 >= TwinKnightsTour::N) {
            cout << "Invalid position(s)!" << endl;
            continue;
        }
        else if ((row1 == row2) && (col1 == col2)) {
            cout << "Invalid position(s)!" << endl;
            continue;
        }
        else
            break;
    }
    
    TwinKnightsTour tour(row1, col1, row2, col2);
    tour.print();
    char knight;
    int row, col;
    while (tour.hasMoreMoves() == true) {
        cout << "Move (knight row col): ";
        cin >> knight >> row >> col;
        if (tour.isValid(knight, row, col) == false) {
            cout << "Invalid move!" << endl;
            continue;
        }
        else if (tour.isValid(knight, row, col) == true) {
            tour.move(knight, row, col);
            tour.print();
        }
    }

    cout << "No more moves!";
}

/*
string board[8][8];
    cout << "  ";
    for (int i = 0; i < 8; i++)
        cout << setw(3) << i;
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << setw(2) << i ;
        for (int j = 0; j < 8; j++)
            cout << board[i][j] << setw(3) << ".";
        cout << endl;
    }
*/

//test move()
    /*
    bool res = tour.move('@', 0, 1);
    assert(res == false);
    tour.print();
    res = tour.move('@', 10, 2);
    assert(res == false);
    tour.print();
    res = tour.move('@', 1, 2);
    assert(res == true);
    tour.print();
    res = tour.move('@', 0, 4);
    assert(res == true);
    tour.print();
    res = tour.move('@', 2, 5);
    assert(res == false);
    tour.print();
    res = tour.move('#', 1, 4);
    assert(res == true);
    tour.print();
    res = tour.move('#', 2, 2);
    assert(res == true);
    tour.print();
    res = tour.move('#', 3, 0);
    cout << res << endl;
    assert(res == false);
    tour.print();
    */

    //test isValid()
    /*
    bool res = tour.isValid('@', 0, 1);
    cout << res << endl;
    assert(res == false);
    res = tour.isValid('@', 2, 1);
    cout << res << endl;
    assert(res == true);
    res = tour.isValid('@', 1, 2);
    cout << res << endl;
    assert(res == true);
    res = tour.isValid('#', 1, 4);
    cout << res << endl;
    assert(res == true);
    res = tour.isValid('#', 2, -1);
    cout << res << endl;
    assert(res == false);
    */