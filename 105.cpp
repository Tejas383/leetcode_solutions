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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        
        int root = preorder[0];
        TreeNode* rootNode = new TreeNode(root);
        
        int index = -1;
        vector<int> inorderLeft;
        vector<int> inorderRight;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root)
                index = i;
            else {
                if (index == -1) {
                    inorderLeft.push_back(inorder[i]);
                } else {
                    inorderRight.push_back(inorder[i]);
                }
            }
        }

        vector<int> preorderLeft;
        for (int i = 1; i <= inorderLeft.size(); i++) {
            preorderLeft.push_back(preorder[i]);
        }

        vector<int> preorderRight;
        for (int i = inorderLeft.size() + 1; i < preorder.size(); i++) {
            preorderRight.push_back(preorder[i]);
        }

        rootNode->left = buildTree(preorderLeft, inorderLeft);
        rootNode->right = buildTree(preorderRight, inorderRight);

        return rootNode;
    }
};