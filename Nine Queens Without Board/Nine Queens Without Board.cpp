#include <iostream>
#include <set>
#include <unordered_set>
#include "Utils.h"

using namespace std;

int main() {
    tests();

    int boardSide = 8;
    Board board;
    vector<Board> solutions;

    print(board, "Initial layout", boardSide);
    cout << "Board have solution: " << std::boolalpha << solve(board, boardSide, solutions) << endl;
    print(solutions);
    cout << "Total number of solutions: " << solutions.size() << endl;

    return 0;
}
