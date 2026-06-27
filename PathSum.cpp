#include <iostream>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base Case 1: अगर नोड NULL है
        if(root == NULL){
           return false;
        }

        // Base Case 2: अगर लीफ नोड मिल गया, तो वैल्यू मैच करें
        if(root->left == NULL && root->right == NULL){
             return targetSum == root->val;
        }
        
        // बची हुई वैल्यू को आगे भेजें (Left और Right दोनों तरफ)
        bool left = hasPathSum(root->left , targetSum - root->val);  
        bool right = hasPathSum(root->right , targetSum - root->val);

        // अगर किसी भी एक तरफ से true मिले, तो true रिटर्न करें
        return left || right;
    }
};


int main() {
    /* एक सैंपल बाइनरी ट्री बनाते हैं:
             5
            / \
           4   8
          /
         11
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);

    Solution sol;
    
    // टेस्ट 1: पाथ 5 -> 4 -> 11 का सम = 20 होता है।
    int target1 = 20;
    cout << "Has path sum " << target1 << "? " << (sol.hasPathSum(root, target1) ? "Yes" : "No") << endl;

    // टेस्ट 2: ऐसा कोई पाथ नहीं जिसका सम 10 हो।
    int target2 = 10;
    cout << "Has path sum " << target2 << "? " << (sol.hasPathSum(root, target2) ? "Yes" : "No") << endl;

    // मेमोरी क्लीनअप
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}