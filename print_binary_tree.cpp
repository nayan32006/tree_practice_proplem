#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int getHeight(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(TreeNode* root, int r, int c, int height, vector<vector<string>>& res) {
        if (!root) return;

        res[r][c] = to_string(root->val);

        if (root->left) {
            fill(root->left, r + 1, c - (1 << (height - r - 1)), height, res);
        }
        if (root->right) {
            fill(root->right, r + 1, c + (1 << (height - r - 1)), height, res);
        }
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;

        vector<vector<string>> res(m, vector<string>(n, ""));
        fill(root, 0, (n - 1) / 2, height, res);

        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution sol;
    vector<vector<string>> result = sol.printTree(root);

    for (const auto& row : result) {
        cout << "[ ";
        for (const auto& cell : row) {
            if (cell.empty()) cout << "\"\" ";
            else cout << "\"" << cell << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}