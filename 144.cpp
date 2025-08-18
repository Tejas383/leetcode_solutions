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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                traversal.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && (prev->right != curr)) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = curr;
                    traversal.push_back(curr->val);
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return traversal;
    }
};