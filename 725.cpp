#include <bits/stdc++.h>

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        ListNode* temp = head;
        int len = 0;

        while (temp) {
            temp = temp->next;
            len++;
        }
        
        temp = head;
        int extra = len % k;
        int n = len / k;
        
        for (int i = 0; i < k; i++) {
            ListNode* prev;
            ans.push_back(temp);
            for (int i = 0; i < n; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (extra) {
                prev = temp;
                temp = temp->next;
                extra--;
            }
            if (prev && prev->next)
                prev->next = nullptr;
        }

        return ans;
    }
};