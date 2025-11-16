#include <bits/stdc++.h>

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for (int n : nums) {
            s.insert(n);
        }

        while (head) {
            if (s.count(head->val))
                head = head->next;
            else
                break;
        }
        ListNode* temp = head;
        while (temp && temp->next) {
            if (s.count(temp->next->val))
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }

        return head;
    }
};