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
    int countNodes(TreeNode* root) {
        int count = 0;
        if (!root)
            return count;
        
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            auto curr = nodes.front();
            nodes.pop();

            if (curr->left)
                nodes.push(curr->left);
            if (curr->right)
                nodes.push(curr->right);
            
            count++;
        }
        
        return count;
    }
};