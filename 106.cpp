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
    TreeNode* buildTreeHelper(map<int, int>& indices, vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) 
            return nullptr;
        
        int rootVal = postorder[postEnd];
        int index = indices[rootVal];
        int leftSize = index - inStart;

        TreeNode* root = new TreeNode(rootVal);

        root->left = buildTreeHelper(indices, inorder, inStart, index - 1, postorder, postStart, postStart + leftSize - 1);
        root->right = buildTreeHelper(indices, inorder, index + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> indices;
        for (int i = 0; i < inorder.size(); i++)
            indices[inorder[i]] = i;
        
        int inStart, inEnd, postStart, postEnd;
        inStart = postStart = 0;
        inEnd = postEnd = inorder.size() - 1;

        return buildTreeHelper(indices, inorder, inStart, inEnd, postorder, postStart, postEnd);
    }
};