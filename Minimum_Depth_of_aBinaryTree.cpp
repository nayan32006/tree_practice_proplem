#include <iostream>
#include <algorithm>

using namespace std;

// TreeNode की परिभाषा
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
    int minDepth(TreeNode* root) {
       if(root == nullptr) return 0;
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        
        // अगर यह लीफ नोड है
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        
        // अगर लेफ्ट सब-ट्री खाली है
        if(root->left == nullptr)
            return 1 + rightDepth;
            
        // 如果 अगर राइट सब-ट्री खाली है
        if(root->right == nullptr)
            return 1 + leftDepth;
            
        // अगर दोनों बच्चे मौजूद हैं
        return min(leftDepth, rightDepth) + 1;
    }
};

int main() {
    // एक टेस्ट ट्री बनाते हैं:
    //     3
    //    / \
    //   9   20
    //      /  \
    //     15   7
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Minimum Depth of the tree is: " << sol.minDepth(root) << endl; // आउटपुट: 2 (क्योंकि नोड 9 सबसे पास का लीफ है)

    return 0;
}