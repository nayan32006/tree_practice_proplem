#include <iostream>
#include <queue>

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        // Recursively invert the subtrees
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        // Swap the left and right pointers
        root->left = right;
        root->right = left;

        return root;
    }
};

// Helper function to print the tree level by level (BFS)
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (current != nullptr) {
            std::cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;
}

// Helper function to clean up memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    /*
          Constructing the following sample tree:
                    4
                   / \
                  2   7
                 / \ / \
                1  3 6  9
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    std::cout << "Original Tree (Level Order): ";
    printLevelOrder(root);

    // Invert the tree
    root = solution.invertTree(root);

    std::cout << "Inverted Tree (Level Order): ";
    printLevelOrder(root);

    /*
          Expected Output Tree structure:
                    4
                   / \
                  7   2
                 / \ / \
                9  6 3  1
    */

    // Clean up dynamic memory
    deleteTree(root);

    return 0;
}