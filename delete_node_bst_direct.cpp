#include <iostream>
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
    // Right Subtree का सबसे छोटा नोड ढूँढने का फ़ंक्शन (Inorder Successor)
    TreeNode* findMin(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // 1. Search for the node to delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node Found! Handling 3 cases:

            // Case 1 & Case 2: No left child or No right child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has two children
            // Find Inorder Successor (Minimum node in Right Subtree)
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val; // Successor की वैल्यू कॉपी करें
            
            // Right Subtree से Inorder Successor को Delete करें
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
};

// Helper Function: Inorder Traversal (Sorted Output)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
             5
            / \
           3   6
          / \   \
         2   4   7
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << "Original BST (Inorder): [ ";
    printInorder(root);
    cout << "]" << endl << endl;

    // Test Case 1: Delete node with 2 children (Key = 3)
    int key1 = 3;
    root = sol.deleteNode(root, key1);
    cout << "--- After Deleting Node " << key1 << " ---" << endl;
    cout << "BST Inorder: [ ";
    printInorder(root);
    cout << "]" << endl << endl;

    // Test Case 2: Delete Leaf Node (Key = 7)
    int key2 = 7;
    root = sol.deleteNode(root, key2);
    cout << "--- After Deleting Node " << key2 << " ---" << endl;
    cout << "BST Inorder: [ ";
    printInorder(root);
    cout << "]" << endl;

    return 0;
}