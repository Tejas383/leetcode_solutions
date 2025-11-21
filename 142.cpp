#include <bits/stdc++.h>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool cycle = false;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                cycle = true;
                break;
            }
        } 

        if (cycle) {
            fast = head;
            while (true) {
                if (fast == slow)
                    return fast;
                fast = fast->next;
                slow = slow->next;
            }
        }

        return nullptr;
    }
};