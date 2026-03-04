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
    int calc(TreeNode* node, int& sum) {
        if (!node)
            return 0;
        
        int maxL = max(calc(node->left, sum), 0);
        int maxR = max(calc(node->right, sum), 0);
        
        sum = max(sum, node->val + maxL + maxR);
        
        return node->val + max(maxL, maxR);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        calc(root, sum);
        return sum;
    }
};