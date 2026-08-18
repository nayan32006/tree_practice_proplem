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
public:
    // 1. Recursive Approach
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }

    // 2. Iterative Approach (O(1) Auxiliary Space)
    TreeNode* searchBSTIterative(TreeNode* root, int val) {
        while (root && root->val != val) {
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};

// Helper function to print Inorder Traversal of a Subtree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
            4
           / \
          2   7
         / \
        1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;

    // Test Case 1: Search value 2 (Present)
    int val1 = 2;
    TreeNode* res1 = sol.searchBST(root, val1);
    cout << "--- Test Case 1: Search " << val1 << " ---" << endl;
    if (res1) {
        cout << "Subtree rooted at " << val1 << " (Inorder): [ ";
        printInorder(res1);
        cout << "]" << endl;
    } else {
        cout << "Node not found!" << endl;
    }
    cout << endl;

    // Test Case 2: Search value 5 (Absent)
    int val2 = 5;
    TreeNode* res2 = sol.searchBST(root, val2);
    cout << "--- Test Case 2: Search " << val2 << " ---" << endl;
    if (res2) {
        cout << "Subtree rooted at " << val2 << " (Inorder): [ ";
        printInorder(res2);
        cout << "]" << endl;
    } else {
        cout << "Node not found! (returns nullptr)" << endl;
    }

    return 0;
}