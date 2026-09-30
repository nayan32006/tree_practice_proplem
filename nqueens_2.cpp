#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int count = 0;

    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue;
            }

            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;

            backtrack(row + 1, n, cols, diag1, diag2);

            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;
        }
    }

public:
    int totalNQueens(int n) {
        count = 0;

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, cols, diag1, diag2);

        return count;
    }
};

int main() {
    Solution sol;

    int n1 = 4;
    int n2 = 1;


    cout << "Total solutions for n = " << n1 << ": " << sol.totalNQueens(n1) << endl;
    cout << "Total solutions for n = " << n2 << ": " << sol.totalNQueens(n2) << endl;

    return 0;
}