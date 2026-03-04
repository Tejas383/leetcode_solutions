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
    int dia = 0;

    int calcHeight(TreeNode* root) {
        if (!root)
            return 0;
        
        int leftHeight = calcHeight(root->left);
        int rightHeight = calcHeight(root->right);

        dia = max(dia, (leftHeight + rightHeight));

        return (1 + max(leftHeight, rightHeight));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        calcHeight(root);
        return dia;
    }
};