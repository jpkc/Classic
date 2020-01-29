#include <iostream>
#include "Utils.h"

using namespace std;

vector<vector<bool>> createEmptyBoardOfSide(int side)
{
    vector<vector<bool>> board;
    vector<bool> tmp;

    for(int i = 0; i < side; ++i)
        tmp.push_back(false);

    for(int i = 0; i < side; ++i)
        board.push_back(tmp);

    return board;
}

void print(const vector<vector<bool>> &board, string title)
{
    int size = static_cast<int>(board.size());
    cout << title << endl << " \t";

    for(int j = 0; j < size; ++j)
        cout << j << ' ';

    cout << endl;

    for(int j = 0; j < size; ++j) {
        cout << j << '\t';

        for(int i = 0; i < size; ++i)
            board[j][i] ? cout << "Q " : cout << ". ";

        cout << endl;
    }
}

void print(const vector<vector<vector<bool>>> &solutions) {
    for(auto board : solutions)
        print(board, "Solution");

    return;
}

bool PositionIsInside(const std::vector<std::vector<bool>> &board, int column, int row)
{
    return (column >= 0) && (column < board.size()) && (row >= 0) && (row < board.size());
}

bool positionIsSafe(const std::vector<std::vector<bool>> &board, int column, int row)
{
    if(!PositionIsInside(board, column, row))
        return false;

    int currentPositionX;
    int currentPositionY;
    
    for(int offset = 1; offset < board.size(); ++offset) {
        //Cheking Up:
        currentPositionX = column + offset;
        currentPositionY = row;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;

        //Cheking Down:
        currentPositionX = column - offset;
        currentPositionY = row;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;

        //Cheking Left:
        currentPositionX = column;
        currentPositionY = row - offset;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;

        //Cheking Right:
        currentPositionX = column;
        currentPositionY = row + offset;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;

        //Cheking UpLeft:
        currentPositionX = column - offset;
        currentPositionY = row + offset;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;

        //Cheking UpRight:
        currentPositionX = column + offset;
        currentPositionY = row + offset;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;

        //Cheking DownLeft:
        currentPositionX = column - offset;
        currentPositionY = row - offset;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;

        //Cheking DownRight:
        currentPositionX = column + offset;
        currentPositionY = row - offset;
        if(PositionIsInside(board, currentPositionX, currentPositionY))
            if(board[currentPositionY][currentPositionX] == true)
                return false;
    }
    return true;
}

bool toggleQueenOn(vector<vector<bool>> &board, int column, int row)
{
    if(PositionIsInside(board, column, row)) {
        if(board[row][column] == false) {
            board[row][column] = true;
            return true;
        }
        else {
            board[row][column] = false;
            return false;
        }
    }
    return false;
}

bool valid(const vector<vector<bool>> &board)
{
    if(board.size() == 0)
        return false;

    for(int row = 0; row < board.size(); ++row)
        for(int column = 0; column < board.size(); ++column)
            if(board[row][column] == true)
                if(!positionIsSafe(board, column, row))
                    return false;
    return true;
}

int howManyQueensIn(const vector<vector<bool>> &board)
{
    int queenCounter = 0;
    for(int row = 0; row < board.size(); ++row)
        for(int column = 0; column < board.size(); ++column)
            if(board[row][column] == true)
                ++queenCounter;

    return queenCounter;
}

bool RecursiveBacktrack(vector<vector<bool>> &board, int queensInBoard, vector<vector<vector<bool>>> &solutions)
{
    bool haveSolution = false;

    if(queensInBoard == board.size()) {
        solutions.push_back(board);
        haveSolution = true;
    }
    else {
        int row = queensInBoard;    //there is only one queen in each row, so each recursive call manages only the respective row
        for(int column = 0; column < board.size(); ++column) {
            if(board[row][column] == false) {
                if(positionIsSafe(board, column, row)) {
                    toggleQueenOn(board, column, row);
                    if(RecursiveBacktrack(board, queensInBoard + 1, solutions)) {
                        haveSolution = true;
                    }
                    toggleQueenOn(board, column, row);
                }
            }
        }
    }

    return haveSolution;
}

bool solve(const std::vector<std::vector<bool>> &board,  vector<vector<vector<bool>>> &solutions)
{
    bool haveSolution = false;
    solutions.clear();

    if(!valid(board))
        return haveSolution;

    vector<vector<bool>> backTrakingBoard = board;
    if(RecursiveBacktrack(backTrakingBoard, howManyQueensIn(backTrakingBoard), solutions))
        haveSolution = true;

    removeRepeatedSolutions(solutions);
    return haveSolution;
}

bool removeRepeatedSolutions( std::vector<std::vector<std::vector<bool>>> &solutions) {
    for(auto j = solutions.begin(); j < solutions.end(); ++j) {
        for (auto i = j + 1; i != solutions.end();) {
            if (*j == *i)
                solutions.erase(i);
            else
                ++i;
        }
    }
    return false;
}
