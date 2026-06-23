#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0; // Base case
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// Tree build karne ke liye helper function (Level Order Input)
TreeNode* buildTree() {
    cout << "Enter root node value (-1 for NULL): ";
    int val;
    cin >> val;
    
    if (val == -1) return nullptr;
    
    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // Left Child
        cout << "Enter left child of " << curr->val << " (-1 for NULL): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }
        
        // Right Child
        cout << "Enter right child of " << curr->val << " (-1 for NULL): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

int main() {
    cout << "--- Binary Tree Depth Calculator ---\n";
    cout << "Example Tree [3, 9, 20, -1, -1, 15, 7] try karne ke liye enter karein.\n\n";
    
    TreeNode* root = buildTree();
    
    Solution solution;
    int depth = solution.maxDepth(root);
    
    cout << "\nResult: Maximum Depth (Height) of Tree is: " << depth << " 🎯\n";
    
    return 0;
}