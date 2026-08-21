#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int helper(TreeNode* root, bool isLeft) {
        if (!root) return 0; // Base Case

        // Check if current node is a leaf node
        if (!root->left && !root->right) {
            return isLeft ? root->val : 0;
        }

        // Recursively calculate sum for left and right subtrees
        return helper(root->left, true) + helper(root->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false); // Root node is not a left child of anything
    }
};

int main() {
    /*
             3
            / \
           9   20
              /  \
             15   7
       Left leaves: 9 and 15 -> Sum = 24
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << "--- Test Case 1 ---" << endl;
    cout << "Sum of Left Leaves: " << sol.sumOfLeftLeaves(root) << endl << endl;

    /*
             1
            /
           2
          Left leaf: 2 -> Sum = 2
    */
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    cout << "--- Test Case 2 ---" << endl;
    cout << "Sum of Left Leaves: " << sol.sumOfLeftLeaves(root2) << endl;

    return 0;
}