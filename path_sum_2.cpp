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
private:
    void dfs(TreeNode* root, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!root) return;

        // Add current node to path
        currentPath.push_back(root->val);

        // Check if it's a leaf node and target sum matches
        if (!root->left && !root->right && targetSum == root->val) {
            result.push_back(currentPath);
        } else {
            // Recurse left and right subtrees
            dfs(root->left, targetSum - root->val, currentPath, result);
            dfs(root->right, targetSum - root->val, currentPath, result);
        }

        // Backtrack
        currentPath.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, result);
        return result;
    }
};

// Helper function to build tree from level order vector (-1 represents NULL)
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

    int targetSum;
    cout << "Enter target sum: ";
    cin >> targetSum;

    TreeNode* root = buildTree(nodes);

    Solution sol;
    vector<vector<int>> paths = sol.pathSum(root, targetSum);

    cout << "\nMatching Paths:\n";
    if (paths.empty()) {
        cout << "No path found!" << endl;
    } else {
        for (const auto& path : paths) {
            cout << "[ ";
            for (int val : path) {
                cout << val << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}