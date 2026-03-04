#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Level Order TRaversal
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        
        string str = "";
        // str += to_string(root->val);
        // str += ".";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (!curr)
                str.append("x.");
            else {
                str.append(to_string(curr->val) + ".");
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;

        stringstream str(data);
        string s;
        getline(str, s, '.');

        TreeNode* root = new TreeNode(stoi(s));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            getline(str, s, '.');
            if (s == "x")
                node->left = nullptr;
            else {
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }

            getline(str, s, '.');
            if (s == "x")
                node->right = nullptr;
            else {
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));