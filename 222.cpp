#include <bits/stdc++.h>
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
    int leftHeight(TreeNode* node) {
        if (!node)
            return 0;
        
        return 1 + leftHeight(node->left);
    }
    int rightHeight(TreeNode* node) {
        if (!node)
            return 0;
        
        return 1 + rightHeight(node->right);
    }
    
    int countNodes(TreeNode* root) {
        if (leftHeight(root) == rightHeight(root)) {
            int count = (1 << leftHeight(root)) - 1;
            return count;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};