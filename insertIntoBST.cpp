#include <iostream>

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

// Helper function to print the tree (In-order traversal: Left, Root, Right)
// For a valid BST, this will always print the numbers in sorted, ascending order.
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    Solution solution;
    
    // Creating a simple BST manually:
    //      4
    //     / \
    //    2   7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    std::cout << "Original tree (In-order): ";
    printInOrder(root);
    std::cout << std::endl;

    // Insert a new value (e.g., 5)
    int valueToInsert = 5;
    root = solution.insertIntoBST(root, valueToInsert);

    std::cout << "Tree after inserting " << valueToInsert << " (In-order): ";
    printInOrder(root);
    std::cout << std::endl;

    return 0;
}