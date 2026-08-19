#include <iostream>
#include <unordered_map>
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
    int count = 0;
    unordered_map<long long, int> prefixMap;

    void dfs(TreeNode* node, long long currentSum, int targetSum) {
        if (!node) return;

        // Current Path Sum
        currentSum += node->val;

        // Check if a prefix sum exists that makes path equal to targetSum
        if (prefixMap.find(currentSum - targetSum) != prefixMap.end()) {
            count += prefixMap[currentSum - targetSum];
        }

        // Add currentSum to prefixMap for children
        prefixMap[currentSum]++;

        // Recursive Calls
        dfs(node->left, currentSum, targetSum);
        dfs(node->right, currentSum, targetSum);

        // Backtrack: Remove currentSum as we leave this node
        prefixMap[currentSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        prefixMap.clear();
        prefixMap[0] = 1; // Base case

        dfs(root, 0, targetSum);
        return count;
    }
};

int main() {
    /*
                 10
                /  \
               5   -3
              / \    \
             3   2   11
            / \   \
           3  -2   1
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution sol;

    // Test Case 1: targetSum = 8
    int target1 = 8;
    cout << "--- Test Case 1 ---" << endl;
    cout << "Target Sum: " << target1 << endl;
    cout << "Total Valid Paths: " << sol.pathSum(root, target1) << endl << endl;

    // Test Case 2: targetSum = 3
    int target2 = 3;
    cout << "--- Test Case 2 ---" << endl;
    cout << "Target Sum: " << target2 << endl;
    cout << "Total Valid Paths: " << sol.pathSum(root, target2) << endl;

    return 0;
}