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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, trees are identical up to this point
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // If only one node is null, structures do not match
        if (p == nullptr || q == nullptr) {
            return false;
        }
        // If values match, check left and right subtrees recursively
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        // Values do not match
        return false;
    }
};

// Helper function to safely clean up dynamic memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // --- TEST CASE 1: Identical Trees ---
    // Tree P1:     1         Tree Q1:     1
    //            /   \                  /   \
    //           2     3                 2     3
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    std::cout << "Test Case 1 (Identical): " 
              << (solution.isSameTree(p1, q1) ? "TRUE (Same Tree)" : "FALSE (Different)") 
              << std::endl;


    // --- TEST CASE 2: Structurally Different Trees ---
    // Tree P2:     1         Tree Q2:     1
    //            /                         \
    //           2                           2
    TreeNode* p2 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* q2 = new TreeNode(1, nullptr, new TreeNode(2));

    std::cout << "Test Case 2 (Different): " 
              << (solution.isSameTree(p2, q2) ? "TRUE (Same Tree)" : "FALSE (Different)") 
              << std::endl;

    // Clean up memory
    deleteTree(p1);
    deleteTree(q1);
    deleteTree(p2);
    deleteTree(q2);

    return 0;
}