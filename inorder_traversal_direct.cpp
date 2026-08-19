#include <iostream>
#include <vector>
#include <stack>

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
    void inorderHelper(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorderHelper(root->left, res);
        res.push_back(root->val);
        inorderHelper(root->right, res);
    }

public:
    // 1. Recursive Approach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }

    // 2. Iterative Approach (Using Stack)
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }
};

void printResult(const string& label, const vector<int>& res) {
    cout << label << ": [ ";
    for (int x : res) cout << x << " ";
    cout << "]" << endl;
}

int main() {
    /*
             1
              \
               2
              /
             3
    */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;

    vector<int> resRecursive = sol.inorderTraversal(root);
    vector<int> resIterative = sol.inorderTraversalIterative(root);

    cout << "--- Test Case 1 ---" << endl;
    printResult("Recursive Inorder", resRecursive);
    printResult("Iterative Inorder", resIterative);
    cout << endl;

    /*
               4
             /   \
            2     5
           / \
          1   3
    */
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);

    vector<int> resRecursive2 = sol.inorderTraversal(root2);

    cout << "--- Test Case 2 (BST) ---" << endl;
    printResult("Recursive Inorder (Sorted)", resRecursive2);

    return 0;
}