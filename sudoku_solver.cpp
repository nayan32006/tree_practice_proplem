#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool rows[9][10] = {false};
    bool cols[9][10] = {false};
    bool boxes[9][10] = {false};

    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    int box_idx = (r / 3) * 3 + (c / 3);

                    for (int digit = 1; digit <= 9; digit++) {
                        if (!rows[r][digit] && !cols[c][digit] && !boxes[box_idx][digit]) {
                            board[r][c] = digit + '0';
                            rows[r][digit] = cols[c][digit] = boxes[box_idx][digit] = true;

                            if (solve(board)) return true;

                            board[r][c] = '.';
                            rows[r][digit] = cols[c][digit] = boxes[box_idx][digit] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int digit = board[r][c] - '0';
                    int box_idx = (r / 3) * 3 + (c / 3);
                    rows[r][digit] = cols[c][digit] = boxes[box_idx][digit] = true;
                }
            }
        }
        solve(board);
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };


    sol.solveSudoku(board);

    for (int r = 0; r < 9; r++) {
        if (r > 0 && r % 3 == 0) cout << "---------------------" << endl;
        for (int c = 0; c < 9; c++) {
            if (c > 0 && c % 3 == 0) cout << "| ";
            cout << board[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}