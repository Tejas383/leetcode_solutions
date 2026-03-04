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

    int dia = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return -1;
        
        int leftHeight = calcHeight(root->left);
        int rightHeight = calcHeight(root->right);
        
        dia = max(dia, (leftHeight + rightHeight));

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);

        return dia;
    }
};