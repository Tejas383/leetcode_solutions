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
    TreeNode* buildTreeHelper(map<int, int>& indices, vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int root = preorder[preStart];
        int index = indices[root];

        TreeNode* rootNode = new TreeNode(root);

        int leftSize = index - inStart;
        rootNode->left = buildTreeHelper(indices, preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        rootNode->right = buildTreeHelper(indices, preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);

        return rootNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> indices;
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }

        return buildTreeHelper(indices, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};