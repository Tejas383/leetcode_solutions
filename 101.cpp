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
    void inverse(TreeNode* node) {
        if (!node)
            return;
        
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        inverse(node->left);
        inverse(node->right);
    }

    bool checkSame(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2)
            return true;
        
        if (!node1 || !node2)
            return false;

        if (node1->val != node2->val)
            return false;
        
        return checkSame(node1->left, node2->left) && checkSame(node1->right, node2->right);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right)
            return true;
        
        if (!root->left || !root->right)
            return false;

        inverse(root->right);
        
        return checkSame(root->left, root->right);
    }
};