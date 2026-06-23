#include <iostream>
#include <queue>
#include <vector>

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

class solution {
public :
    bool isMirror(TreeNode* left , treeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        return (left->val == right->val) &&
              isMirror(left->left , right->right) &&
              isMirror(left->right , right-> left);
    }
}

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
        
        // Left Child ke liye input
        cout << "Enter left child of " << curr->val << " (-1 for NULL): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }
        
        // Right Child ke liye input
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
    cout << "--- Binary Tree Input (Level Order) ---\n";
    cout << "Example Symmetric Tree ke liye input: 1 fir 2, 2 fir 3, 4, 4, 3\n\n";
    
    TreeNode* root = buildTree();
    
    Solution solution;
    if (solution.isSymmetric(root)) {
        cout << "\nResult: Tree is Symmetric! ✅ (Mirror Image Hai)\n";
    } else {
        cout << "\nResult: Tree is NOT Symmetric! ❌ (Mirror Image Nahi Hai)\n";
    }
    
    return 0;
}