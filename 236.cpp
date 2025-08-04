#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& array) {
        if (!root)
            return false;
        
        array.push_back(root);
        if (root->val == node->val)
            return true;
        
        if (findPath(root->left, node, array) || findPath(root->right, node, array))
            return true;
        
        array.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> P;
        vector<TreeNode*> Q;

        findPath(root, p, P);
        findPath(root, q, Q);

        int i = 0;
        int j = 0;
        while (i < P.size() && j < Q.size() && P[i] == Q[j]) {
            i++;
            j++;
        }

        return Q[j - 1];
    }
};