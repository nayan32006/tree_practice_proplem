#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                // Fill value based on direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight; // Toggle direction for next level
        }

        return result;
    }
};

// Helper function to build tree from level order array (-1 represents NULL)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    cout << "Enter number of level-order elements (use -1 for NULL): ";
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> nodes(n);
    cout << "Enter level-order elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    Solution sol;
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    cout << "\nZigzag Level Order Traversal:\n";
    for (const auto& level : ans) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}