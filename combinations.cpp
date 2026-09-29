#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void backtrack(int start, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        int upper_bound = n - (k - path.size()) + 1;

        for (int i = start; i <= upper_bound; i++) {
            path.push_back(i);
            backtrack(i + 1, n, k, path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(1, n, k, path, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    int n1 = 4, k1 = 2;
    int n2 = 1, k2 = 1;

    vector<vector<int>> res1 = sol.combine(n1, k1);
    cout << "Combinations for n = 4, k = 2:" << endl;
    for (const auto& comb : res1) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]" << endl;
    }

    vector<vector<int>> res2 = sol.combine(n2, k2);
    cout << "\nCombinations for n = 1, k = 1:" << endl;
    for (const auto& comb : res2) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}