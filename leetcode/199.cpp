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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        map<int, int> m;

        if (root)
            q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int level = p.second;
            m[level] = node->val;

            if (node->left) 
                q.push({node->left, level + 1});
            if (node->right) 
                q.push({node->right, level + 1});
        }

        vector<int> rightView;
        for (pair<int, int> p : m) 
            rightView.push_back(p.second);
        
        return rightView;
    }
};