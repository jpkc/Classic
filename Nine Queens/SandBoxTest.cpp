#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

int tests() {
    vector<vector<bool>> board;

    {
        cout << "testing if null board is invalid: ";
        board = createEmptyBoardOfSide(0);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        cout << "testing if empty board is valid: ";
        board = createEmptyBoardOfSide(1);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if empty board is valid: ";
        board = createEmptyBoardOfSide(2);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if empty board is valid: ";
        board = createEmptyBoardOfSide(3);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if empty board is valid: ";
        board = createEmptyBoardOfSide(15);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }

    {
        cout << "testing if positions are inside board: ";
        board = createEmptyBoardOfSide(1);
        if (PositionIsInside(board, 0, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if positions are inside board: ";
        board = createEmptyBoardOfSide(1);
        if (!PositionIsInside(board, 1, 1))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if positions are inside board: ";
        board = createEmptyBoardOfSide(4);
        if (PositionIsInside(board, 0, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if positions are inside board: ";
        board = createEmptyBoardOfSide(4);
        if (!PositionIsInside(board, 0, 4))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if positions are inside board: ";
        board = createEmptyBoardOfSide(4);
        if (!PositionIsInside(board, 4, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if positions are inside board: ";
        board = createEmptyBoardOfSide(4);
        if (!PositionIsInside(board, -1, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if positions are inside board: ";
        board = createEmptyBoardOfSide(4);
        if (!PositionIsInside(board, 0, -1))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }


    {
        cout << "testing safe positions: ";
        board = createEmptyBoardOfSide(1);
        if (positionIsSafe(board, 0, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        board = createEmptyBoardOfSide(1);
        toggleQueenOn(board, 0, 0);
        if (positionIsSafe(board, 0, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        board = createEmptyBoardOfSide(8);
        toggleQueenOn(board, 3, 3);
        if (!positionIsSafe(board, 1, 1))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        board = createEmptyBoardOfSide(8);
        toggleQueenOn(board, 3, 3);
        if (!positionIsSafe(board, 3, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        board = createEmptyBoardOfSide(8);
        toggleQueenOn(board, 3, 3);
        if (!positionIsSafe(board, 0, 3))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        cout << "testing valid boards: ";
        board = createEmptyBoardOfSide(1);
        toggleQueenOn(board, 0, 0);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }

    {
        cout << "testing invalid board detection: ";
        board = createEmptyBoardOfSide(9);
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 8, 8);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing invalid board detection: ";
        board = createEmptyBoardOfSide(9);
        toggleQueenOn(board, 0, 8);
        toggleQueenOn(board, 8, 0);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing invalid board detection: ";
        board = createEmptyBoardOfSide(9);
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 8, 0);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing invalid board detection: ";
        board = createEmptyBoardOfSide(9);
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 0, 8);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        cout << "testing queen counter: ";
        board = createEmptyBoardOfSide(0);
        if (howManyQueensIn(board) == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing queen counter: ";
        board = createEmptyBoardOfSide(15);
        if (howManyQueensIn(board) == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing queen counter: ";
        board = createEmptyBoardOfSide(8);
        toggleQueenOn(board, 0, 0);
        if (howManyQueensIn(board) == 1)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing queen counter: ";
        board = createEmptyBoardOfSide(8);
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 1, 0);
        toggleQueenOn(board, 2, 0);
        toggleQueenOn(board, 3, 0);
        toggleQueenOn(board, 4, 0);
        toggleQueenOn(board, 5, 0);
        toggleQueenOn(board, 6, 0);
        toggleQueenOn(board, 7, 0);
        toggleQueenOn(board, 0, 1);
        toggleQueenOn(board, 0, 2);
        toggleQueenOn(board, 0, 3);
        toggleQueenOn(board, 0, 4);
        toggleQueenOn(board, 0, 5);
        toggleQueenOn(board, 0, 6);
        toggleQueenOn(board, 0, 7);
        if (howManyQueensIn(board) == 15)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }


    {
        vector<vector<vector<bool>>> solutions;
        cout << "Recursive Stop Condition: ";
        board = createEmptyBoardOfSide(0);
        if (RecursiveBacktrack(board, 0, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "Recursive Stop Condition: ";
        board = createEmptyBoardOfSide(1);
        if (RecursiveBacktrack(board, 1, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "Recursive Stop Condition: ";
        board = createEmptyBoardOfSide(7);
        if (RecursiveBacktrack(board, 7, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        vector<vector<vector<bool>>> solutions;
        cout << "testing solution for solved boards: ";
        board = createEmptyBoardOfSide(1);
        toggleQueenOn(board, 0, 0);
        if (solve(board, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for solved boards: ";
        board = createEmptyBoardOfSide(1);
        toggleQueenOn(board, 1, 0);
        toggleQueenOn(board, 3, 1);
        toggleQueenOn(board, 0, 2);
        toggleQueenOn(board, 2, 3);
        if (solve(board, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }

    {
        vector<vector<vector<bool>>> solutions;
        cout << "testing solution for empty boards: ";
        board = createEmptyBoardOfSide(1);
        if (solve(board, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board = createEmptyBoardOfSide(2);
        if (!solve(board, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board = createEmptyBoardOfSide(3);
        if (!solve(board, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board = createEmptyBoardOfSide(4);
        if (solve(board, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }

    {
        vector<vector<vector<bool>>> solutions;
        cout << "testing if there are repeated solutions: ";
        board = createEmptyBoardOfSide(0);
        solve(board, solutions);
        if (solutions.size() == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board = createEmptyBoardOfSide(1);
        solve(board, solutions);
        if (solutions.size() == 1)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board = createEmptyBoardOfSide(2);
        solve(board, solutions);
        if (solutions.size() == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board = createEmptyBoardOfSide(3);
        solve(board, solutions);
        if (solutions.size() == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board = createEmptyBoardOfSide(4);
        solve(board, solutions);
        if (solutions.size() == 2)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board = createEmptyBoardOfSide(5);
        solve(board, solutions);
        if (solutions.size() == 10)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board = createEmptyBoardOfSide(6);
        solve(board, solutions);
        if (solutions.size() == 4)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    //Bruteforce too slow for tables bigger than 6?
    }
    return 0;
}
