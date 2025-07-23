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
    int calcHeight(TreeNode* node) {
        if (!node)
            return 0;
        return (1 + max(calcHeight(node->left), calcHeight(node->right)));
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        int leftHeight = calcHeight(root->left);
        int rightHeight = calcHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1)
            return false;
        
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);
        if (!leftBalanced || !rightBalanced)
            return false;
        
        return true;
    }
};