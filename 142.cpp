#include <bits/stdc++.h>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> present;
        ListNode* temp = head;

        while (temp) {
            if (present.count(temp))
                return temp;
            present.insert(temp);
            temp = temp->next;
        }

        return nullptr;
    }
};