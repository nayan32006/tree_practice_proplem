#include <iostream>
#include <cmath>
#include <vector>

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
    int totalTilt = 0;

    // Helper function that calculates subtree sum and accumulates total tilt
    int calculateSumAndTilt(TreeNode* root) {
        if (!root) return 0;

        // Post-Order Traversal
        int leftSum = calculateSumAndTilt(root->left);
        int rightSum = calculateSumAndTilt(root->right);

        // Add absolute difference of left and right subtree sum to totalTilt
        totalTilt += abs(leftSum - rightSum);

        // Return total sum of subtree rooted at 'root'
        return root->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode* root) {
        totalTilt = 0;
        calculateSumAndTilt(root);
        return totalTilt;
    }
};

int main() {
    /*
        Test Case:
                 4
               /   \
              2     9
             / \     \
            3   5     7

        Tilt Calculation:
        - Leaf nodes (3, 5, 7): tilt = |0 - 0| = 0
        - Node 2: leftSum = 3, rightSum = 5 -> tilt = |3 - 5| = 2
        - Node 9: leftSum = 0, rightSum = 7 -> tilt = |0 - 7| = 7
        - Node 4: leftSum = (2 + 3 + 5) = 10, rightSum = (9 + 7) = 16 -> tilt = |10 - 16| = 6

        Total Tilt = 0 + 0 + 0 + 2 + 7 + 6 = 15
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    int ans = sol.findTilt(root);

    cout << "--- Binary Tree Tilt Result ---" << endl;
    cout << "Total Tree Tilt: " << ans << endl;

    return 0;
}