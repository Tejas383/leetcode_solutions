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
        int left = calcHeight(node->left);
        int right = calcHeight(node->right);
        if (abs(left - right) > 1) 
            return -1;
        if (left == -1 || right == -1)
            return -1;
        return (1 + max(left, right));
    }

    bool isBalanced(TreeNode* root) {
        if (calcHeight(root) == -1)
            return false;
        return true;
    }
};