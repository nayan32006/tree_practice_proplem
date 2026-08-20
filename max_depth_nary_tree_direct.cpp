#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a N-ary tree node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // DFS Recursive Approach
    int maxDepth(Node* root) {
        if (!root) return 0; // Base Case

        int maxChildDepth = 0;
        for (Node* child : root->children) {
            maxChildDepth = max(maxChildDepth, maxDepth(child));
        }

        return 1 + maxChildDepth;
    }
};

int main() {
    /*
               1
            /  |  \
           3   2   4
          / \
         5   6
    */

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);

    Node* root = new Node(1, {node3, node2, node4});

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "--- Maximum Depth of N-ary Tree ---" << endl;
    cout << "Tree Maximum Depth: " << depth << endl;

    return 0;
}