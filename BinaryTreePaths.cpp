#include <iostream>
#include <vector>
#include <string>

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

class Solution {
public:
    void findPath(TreeNode* node, vector<string>& ans, string temp) {
        // वर्तमान नोड की वैल्यू को स्ट्रिंग में जोड़ें
        temp += to_string(node->val);
        
        // अगर लेफ्ट चाइल्ड है, तो लेफ्ट में जाएँ और "->" जोड़ें
        if (node->left) findPath(node->left, ans, temp + "->");  
        
        // अगर राइट चाइल्ड है, तो राइट में जाएँ और "->" जोड़ें
        if (node->right) findPath(node->right, ans, temp + "->");
        
        // अगर यह एक Leaf Node है, तो इस पाथ को आंसर में सेव करें
        if (!node->left && !node->right) ans.push_back(temp); 
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root) findPath(root, ans, "");  
        return ans;
    }
};


int main() {
    /* एक सैंपल बाइनरी ट्री बनाते हैं:
             1
            / \
           2   3
            \
             5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);

    // आउटपुट प्रिंट करना
    cout << "Binary Tree Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    // मेमोरी क्लीनअप (Good Practice)
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}