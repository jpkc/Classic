#ifndef SANDBOX_UTILS_H
#define SANDBOX_UTILS_H

#include <vector>

std::vector<std::vector<bool>> createEmptyBoardOfSide(int side = 8);
void print(const std::vector<std::vector<bool>> &board, std::string title);
void print(const std::vector<std::vector<std::vector<bool>>> &solutions);
bool PositionIsInside(const std::vector<std::vector<bool>> &board, int column, int row);
bool positionIsSafe(const std::vector<std::vector<bool>> &board, int column, int row);
bool toggleQueenOn(std::vector<std::vector<bool>> &board, int column = 8, int row = 8);
bool valid(const std::vector<std::vector<bool>> &board);
int howManyQueensIn(const std::vector<std::vector<bool>> &board);
bool RecursiveBacktrack(std::vector <std::vector<bool>> &board, int queensInBoard, std::vector<std::vector<std::vector<bool>>> &solutions);
bool solve(const std::vector<std::vector<bool>> &board, std::vector<std::vector<std::vector<bool>>> &solutions);
bool removeRepeatedSolutions( std::vector<std::vector<std::vector<bool>>> &solutions);

int tests();

#endif //SANDBOX_UTILS_H