#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int rows, cols;

    bool dfs(int r, int c, int index, vector<vector<char>>& board, const string& word) {
        if (index == word.length()) return true;

        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(r + 1, c, index + 1, board, word) ||
                     dfs(r - 1, c, index + 1, board, word) ||
                     dfs(r, c + 1, index + 1, board, word) ||
                     dfs(r, c - 1, index + 1, board, word);

        board[r][c] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0] && dfs(r, c, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";


    cout << "Search 'ABCCED': " << (sol.exist(board, word1) ? "true" : "false") << endl;
    cout << "Search 'SEE':    " << (sol.exist(board, word2) ? "true" : "false") << endl;
    cout << "Search 'ABCB':   " << (sol.exist(board, word3) ? "true" : "false") << endl;

    return 0;
}