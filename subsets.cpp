#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(path);
            return;
        }

        path.push_back(nums[index]);
        backtrack(index + 1, nums, path, ans);
        path.pop_back();

        backtrack(index + 1, nums, path, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, nums, path, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(nums);


    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}