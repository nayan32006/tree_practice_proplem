#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, path, ans);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;

    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;

    vector<vector<int>> res1 = sol.combinationSum2(candidates1, target1);
    cout << "Test 1 Output (Target 8):" << endl;
    for (const auto& comb : res1) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]" << endl;
    }

    vector<vector<int>> res2 = sol.combinationSum2(candidates2, target2);
    cout << "\nTest 2 Output (Target 5):" << endl;
    for (const auto& comb : res2) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}