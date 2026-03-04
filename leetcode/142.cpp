#include <bits/stdc++.h>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        bool cycle = false;
        while (fast && fast->next && !cycle) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                cycle = true;
            }
        }

        if (!cycle)
            return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};