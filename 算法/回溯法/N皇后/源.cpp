#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector <vector<string>> result;

    void backtracking(int n, int row, vector <string> &chessboard);

    bool isValid(int row, int col, vector <string> &chessboard, int n);

public:
    vector <vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector <std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

void Solution::backtracking(int n, int row, vector <string> &chessboard) {
    // n 为输入的棋盘大小
    // row 是当前递归到棋盘的第几行了
    if (row == n) {
        result.push_back(chessboard);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) {                               // 验证合法就可以放
            chessboard[row][col] = 'Q'; // 放置皇后
            backtracking(n, row + 1, chessboard);
            chessboard[row][col] = '.'; // 回溯，撤销皇后
        }
    }
}

bool Solution::isValid(int row, int col, vector <string> &chessboard, int n) {
    // 检查列
    for (int i = 0; i < row; i++) { // 这是一个剪枝
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // 检查 135度角是否有皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

vector <vector<string>> Solution::solveNQueens(int n) {
    result.clear();
    std::vector <std::string> chessboard(n, std::string(n, '.'));
    backtracking(n, 0, chessboard);
    return result;
}