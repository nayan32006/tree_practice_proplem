#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // LeetCode 107: Binary Tree Level Order Traversal II
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        // 1. Standard BFS (Top to Bottom)
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(currentLevel);
        }

        // 2. Reverse result vector to get Bottom-to-Top order
        reverse(result.begin(), result.end());

        return result;
    }
};

void printLevelOrder(const vector<vector<int>>& result) {
    cout << "[\n";
    for (const auto& level : result) {
        cout << "  [ ";
        for (int val : level) cout << val << " ";
        cout << "]\n";
    }
    cout << "]" << endl;
}

int main() {
    /*
             3
            / \
           9   20
              /  \
             15   7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> res = sol.levelOrderBottom(root);

    cout << "--- Level Order Traversal II (Bottom-Up BFS) ---" << endl;
    printLevelOrder(res);

    return 0;
}