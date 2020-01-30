#include <iostream>
#include <algorithm>
#include "Utils.h"

using namespace std;

Board createEmptyBoard()
{
    return Board();
}

void print(const Board &board, const string &label, int side)
{
    for(auto currentQueen : board) {
        if(side < currentQueen.row)
            side = currentQueen.row;
        if(side < currentQueen.column)
            side = currentQueen.column;
    }

    cout << label << endl << "\t";
    for(int column = 0; column < side; ++column)
        cout << ' ' << column;
    cout << endl;

    for(int row = 0; row < side; ++row) {
        cout << row << '\t';
        for(int column = 0; column < side; ++column) {
            auto pos = find(board.begin(), board.end(), Queen {row, column});
            if(pos == board.end())
                cout << " .";
            else
                cout << " Q";
        }
        cout << endl;
    }
}

void print(const vector<Board> &solutions) {
    for(auto board : solutions)
        print(board, "Solution", board.size());
}

bool isSafeFrom(const Queen &queen, int row, int column)
{
    //Checking column:
    if(queen.column == column)
        return false;

    //Checking row:
    if(queen.row == row)
        return false;

    //Checking climbing diagonal:
    if(queen.row - row == queen.column - column)
        return false;

    //Checking descending diagonal:
    if(queen.row - row == -(queen.column - column))
        return false;

    return true;
}

bool toggleQueenOn(Board &board, int row, int column) {
    auto pos = find(board.begin(), board.end(), Queen {row, column});
    if (pos == board.end()) {
        board.insert({row, column});
        return true;
    } else {
        board.erase({row, column});
        return false;
    }
}

bool valid(const Board &board)
{
    for(auto queenA = board.begin(); queenA != board.end(); ++queenA)
        for(auto queenB = queenA; ++queenB != board.end(); )
            if(!isSafeFrom(*queenA, queenB->row, queenB->column))
                return false;

    return true;
}

int howManyQueensIn(const Board &board)
{
    return board.size();
}

bool RecursiveBacktrack(Board &board, int boardSide, vector<Board> &solutions)
{
    bool haveSolution = false;

    if(howManyQueensIn(board) == boardSide) {
        solutions.push_back(board);
        haveSolution = true;
    }
    else {
        int row = howManyQueensIn(board);    //there is only one Queen in each row, so each recursive call manages only the respective row
        for(int column = 0; column < boardSide; ++column) {
            bool safe = true;
            for(auto queen : board) {
                if(!isSafeFrom(queen, row, column)) {
                    safe = false;
                    break;
                }
            }
            if(safe) {
                toggleQueenOn(board, row, column);
                if(RecursiveBacktrack(board, boardSide, solutions)) {
                    haveSolution = true;
                }
                toggleQueenOn(board, row, column);
            }
        }
    }
    return haveSolution;
}

bool solve(const Board &board, int boardSide, vector<Board> &solutions)
{
    bool haveSolution = false;
    solutions.clear();

    if(valid(board)) {
        Board scrapBoard = board;
        if (RecursiveBacktrack(scrapBoard, boardSide, solutions))
            haveSolution = true;
    }
    return haveSolution;
}
