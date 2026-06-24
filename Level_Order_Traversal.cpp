#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Binary Tree Node की परिभाषा
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans; // अगर Tree खाली है
        
        queue<TreeNode*> q;
        q.push(root); // सबसे पहले root को queue में डालेंगे
        
        while (!q.empty()) {
            int s = q.size(); // इस समय level में जितने नोड्स हैं, उनका साइज
            vector<int> v;
            
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                // अगर Left या Right बच्चा है, तो उसे Queue में डालो
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                
                v.push_back(node->val); // नोड की वैल्यू को करंट लेवल की लिस्ट में डालो
            }
            ans.push_back(v); // इस लेवल की लिस्ट को फाइनल आंसर में डालो
        }
        return ans;
    }
};

// VS Code में टेस्ट करने के लिए Main फंक्शन
int main() {
    // एक सैंपल Tree बनाते हैं:
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   7
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // आउटपुट प्रिंट करने के लिए
    cout << "[" << endl;
    for (const auto& level : result) {
        cout << "  [";
        for (size_t i = 0; i < level.size(); ++i) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}