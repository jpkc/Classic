#ifndef SANDBOX_UTILS_H
#define SANDBOX_UTILS_H

#include <unordered_set>
#include <vector>
#include <string>

class Queen {
public:
    inline bool operator == (const Queen& rhs) const {
        return (row == rhs.row) && (column == rhs.column);
    }

    int row;
    int column;
};

typedef std::unordered_set<Queen> Board;

void print(const Board &board, const std::string &label, int side);
void print(const Board &board, const std::string &title, int side);
void print(const std::vector<Board> &solutions);
bool isSafeFrom(const Queen &queen, int row, int column);
bool valid(const Board &board);
bool toggleQueenOn(Board &board, int row, int column);
int howManyQueensIn(const Board &board);
bool RecursiveBacktrack(Board &board, int boardSide, std::vector<Board> &solutions);
bool solve(const Board &board, int boardSide, std::vector<Board> &solutions);

int tests();

#endif //SANDBOX_UTILS_H