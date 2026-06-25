#include <iostream>
#include <limits>

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
    bool isValidBST(TreeNode* root) {
        return valid(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());        
    }

private:
    bool valid(TreeNode* node, long minimum, long maximum) {
        if (!node) return true;

        if (!(node->val > minimum && node->val < maximum)) return false;

        return valid(node->left, minimum, node->val) && 
               valid(node->right, node->val, maximum);
    }    
};

int main() {
    Solution solution;

    // --- CASE 1: Valid BST ---
    //      5
    //     / \
    //    1   4
    // Wait, 4 is smaller than 5, so let's make a proper one:
    //      5
    //     / \
    //    3   7
    TreeNode* validRoot = new TreeNode(5);
    validRoot->left = new TreeNode(3);
    validRoot->right = new TreeNode(7);

    std::cout << "Tree 1 (Valid BST) Result: " 
              << (solution.isValidBST(validRoot) ? "True (Valid)" : "False (Invalid)") 
              << std::endl;


    // --- CASE 2: Invalid BST ---
    //      5
    //     / \
    //    3   7
    //       /
    //      2   <-- Invalid! 2 is in the right subtree of 5, but 2 is not > 5.
    TreeNode* invalidRoot = new TreeNode(5);
    invalidRoot->left = new TreeNode(3);
    invalidRoot->right = new TreeNode(7);
    invalidRoot->right->left = new TreeNode(2); 

    std::cout << "Tree 2 (Invalid BST) Result: " 
              << (solution.isValidBST(invalidRoot) ? "True (Valid)" : "False (Invalid)") 
              << std::endl;

    return 0;
}