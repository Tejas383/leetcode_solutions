#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodes;
        ListNode* temp = head;
        while (temp) {
            nodes.push_back(temp->val);
            temp = temp->next;
        }

        int n = nodes.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nodes[i] >= st.top())
                st.pop();
            
            nge[i] = st.empty() ? 0 : st.top();
            st.push(nodes[i]);
        }

        return nge;
    }
};