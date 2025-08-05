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
    int widthOfBinaryTree(TreeNode* root) {
        // queue<pair<node, pair<level, index>>> q;
        queue<pair<TreeNode*, pair<int, unsigned long long>>> q;
        // map<level, indices> m;
        map<int, vector<unsigned long long>> m;

        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto select = q.front();
            q.pop();

            TreeNode* node = select.first;
            int level = select.second.first;
            unsigned long long index = select.second.second;

            m[level].push_back(index);

            if (node->left)
                q.push({node->left, {level + 1, (index * 2) + 1}});
            if (node->right)
                q.push({node->right, {level + 1, (index * 2) + 2}});
        }

        unsigned long long ans = 0;
        for (auto p : m) {
            // indices will be stored in ascending order, so we do not need to find max and min
            unsigned long long min_index = p.second[0];
            unsigned long long max_index = p.second[p.second.size() - 1];
            ans = max(ans, max_index - min_index + 1);
        }
        return static_cast<int>(ans);
        // https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/
    }
};