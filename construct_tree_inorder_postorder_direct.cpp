#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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
    TreeNode* buildTreeHelper(const vector<int>& inorder, int inStart, int inEnd,
                              const vector<int>& postorder, int postStart, int postEnd,
                              unordered_map<int, int>& inMap) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        // 1. Root value is the last element of current postorder segment
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // 2. Find root index in inorder array
        int inIndex = inMap[rootVal];
        int numsLeft = inIndex - inStart; // Number of elements in left subtree

        // 3. Build Left and Right subtrees recursively
        root->left = buildTreeHelper(inorder, inStart, inIndex - 1,
                                     postorder, postStart, postStart + numsLeft - 1, inMap);

        root->right = buildTreeHelper(inorder, inIndex + 1, inEnd,
                                      postorder, postStart + numsLeft, postEnd - 1, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1, inMap);
    }
};

// Helper function to print Level-Order Traversal
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    cout << "[ ";
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << "]" << endl;
}

int main() {
    /*
        Test Case:
        Inorder   = [9, 3, 15, 20, 7]
        Postorder = [9, 15, 7, 20, 3]

        Constructed Tree:
                 3
                / \
               9  20
                 /  \
                15   7
    */
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "--- Constructed Tree (Level Order Verification) ---" << endl;
    printLevelOrder(root);

    return 0;
}