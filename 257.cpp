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
    vector<vector<int>> paths;
    vector<int> path;

    void pathsHelper(TreeNode* node) {
        if (!node)
            return;
        
        path.push_back(node->val);
        if (!node->left && !node->right)
            paths.push_back(path);
        
        pathsHelper(node->left);
        pathsHelper(node->right);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        pathsHelper(root);
        
        for (int i = 0; i < paths.size(); i++) {
            string str = "";
            for (int j = 0; j < paths[i].size() - 1; j++) {
                str += to_string(paths[i][j]);
                str += "->";
            }
            str += to_string(paths[i][paths[i].size() - 1]);
            ans.push_back(str);
        }

        return ans;
    }
};