#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

int main() {
    tests();

    int side = 8;
    vector<vector<bool>> board = createEmptyBoardOfSide(side);
    vector<vector<vector<bool>>> solutions;

    print(board, "Initial layout");
    cout << "Board have solution: " << std::boolalpha << solve(board, solutions) << endl;
    print(solutions);
    cout << "Total number of solutions: " << solutions.size() << endl;

    return 0;
}
