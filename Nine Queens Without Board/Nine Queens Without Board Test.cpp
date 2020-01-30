#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

int tests() {
    {
        Queen queen{3, 3};

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 3, 3))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 0, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 6, 6))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 3, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 3, 6))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 0, 3))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 6, 3))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 6, 0))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing safe positions: ";
        if (!isSafeFrom(queen, 0, 6))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        Board board;

        cout << "testing if empty board is valid: ";
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        Board board;

        cout << "testing valid boards: ";
        toggleQueenOn(board, 0, 0);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing valid boards: ";
        toggleQueenOn(board, 2, 1);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing valid boards: ";
        toggleQueenOn(board, 4, 2);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing valid boards: ";
        toggleQueenOn(board, 1, 3);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing valid boards: ";
        toggleQueenOn(board, 3, 4);
        if (valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }

    {
        Board board;

        cout << "testing invalid board detection: ";
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 8, 8);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing invalid board detection: ";
        toggleQueenOn(board, 0, 8);
        toggleQueenOn(board, 8, 0);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing invalid board detection: ";
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 8, 0);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing invalid board detection: ";
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 0, 8);
        if (!valid(board))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        Board board;

        cout << "testing Queen counter: ";
        if (howManyQueensIn(board) == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing Queen counter: ";
        toggleQueenOn(board, 3, 5);
        if (howManyQueensIn(board) == 1)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing Queen counter: ";
        toggleQueenOn(board, 3, 5);
        if (howManyQueensIn(board) == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing Queen counter: ";
        toggleQueenOn(board, 0, 0);
        if (howManyQueensIn(board) == 1)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing Queen counter: ";
        toggleQueenOn(board, 0, 0); //This one removes one queen!!!
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
        if (howManyQueensIn(board) == 14)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        Board board;

        vector<Board> solutions;
        cout << "Recursive Stop Condition: ";
        if (RecursiveBacktrack(board, 0, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "Recursive Stop Condition: ";
        toggleQueenOn(board, 0, 0);
        if (RecursiveBacktrack(board, 1, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "Recursive Stop Condition: ";
        toggleQueenOn(board, 1, 0);
        toggleQueenOn(board, 2, 0);
        toggleQueenOn(board, 3, 0);
        toggleQueenOn(board, 4, 0);
        toggleQueenOn(board, 5, 0);
        toggleQueenOn(board, 6, 0);
        if (RecursiveBacktrack(board, 7, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    {
        Board board;
        vector<Board> solutions;

        cout << "testing solution for solved boards: ";
        toggleQueenOn(board, 0, 0);
        if (solve(board, 1, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for solved boards: ";
        toggleQueenOn(board, 0, 0);
        toggleQueenOn(board, 1, 0);
        toggleQueenOn(board, 3, 1);
        toggleQueenOn(board, 0, 2);
        toggleQueenOn(board, 2, 3);
        if (solve(board, 4, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }

    {
        Board board;
        vector<Board> solutions;

        cout << "testing solution for empty boards: ";
        if (solve(board, 1, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board.clear();
        if (!solve(board, 2, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board.clear();
        if (!solve(board, 3, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board.clear();
        if (solve(board, 4, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board.clear();
        if (solve(board, 5, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board.clear();
        if (solve(board, 6, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board.clear();
        if (solve(board, 7, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing solution for empty boards: ";
        board.clear();
        if (solve(board, 8, solutions))
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }

    {
        Board board;
        vector<Board> solutions;

        cout << "testing if there are repeated solutions: ";
        board.clear();
        solve(board, 0, solutions);
        if (solutions.size() == 1)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board.clear();
        solve(board, 1, solutions);
        if (solutions.size() == 1)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board.clear();
        solve(board, 2, solutions);
        if (solutions.size() == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board.clear();
        solve(board, 3, solutions);
        if (solutions.size() == 0)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board.clear();
        solve(board, 4, solutions);
        if (solutions.size() == 2)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board.clear();
        solve(board, 5, solutions);
        if (solutions.size() == 10)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

        cout << "testing if there are repeated solutions: ";
        board.clear();
        solve(board, 6, solutions);
        if (solutions.size() == 4)
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;

    }
    return 0;
}
