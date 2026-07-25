#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void solve(TreeNode* root, int level, vector<int>& result) {
        if (root == NULL) return;

        if (level == result.size()) {
            result.push_back(root->val);
        }

        solve(root->right, level + 1, result);
        solve(root->left, level + 1, result);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        solve(root, 0, result);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> ans = sol.rightSideView(root);

    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}