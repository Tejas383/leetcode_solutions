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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> nodes;
        map<TreeNode*, TreeNode*> parentMap;
        nodes.push(root);
        while (!nodes.empty()) {
            auto curr = nodes.front();
            nodes.pop();
            
            if (curr->left) {
                parentMap[curr->left] = curr;
                nodes.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                nodes.push(curr->right);
            }
        }

        nodes.push(target);
        int dist = 0;
        map<TreeNode*, bool> visited;
        while (!nodes.empty() && dist < k) {
            int n = nodes.size();

            for (int i = 0; i < n; i++) {
                TreeNode* curr = nodes.front();
                nodes.pop();

                if (parentMap.count(curr) && !visited.count(parentMap[curr]))
                    nodes.push(parentMap[curr]);
                if (curr->left && !visited.count(curr->left))
                    nodes.push(curr->left);
                if (curr->right && !visited.count(curr->right))
                    nodes.push(curr->right);
                
                visited[curr] = true;
            }
            dist++;
        }

        vector<int>ans;
        while (!nodes.empty()) {
            ans.push_back(nodes.front()->val);
            nodes.pop();
        }

        return ans;
    }
};