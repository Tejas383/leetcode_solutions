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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // queue<pair<node, pair<vert, level>>> 
        queue<pair<TreeNode*, pair<int, int>>> q;
        // map<vert, map<level, node>>
        map<int, map<int, multiset<int>>> m;

        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto triplet = q.front();
            q.pop();

            TreeNode* node = triplet.first;
            int vert = triplet.second.first;
            int level = triplet.second.second;

            m[vert][level].insert(node->val);
            if (node->left)
                q.push({node->left, {vert - 1, level + 1}});
            if (node->right)
                q.push({node->right, {vert + 1, level + 1}});
        }

        vector<vector<int>> ans;
        for (auto p : m) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};