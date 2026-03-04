#include <bits.stdc++.h>

class Solution {
public:
    ListNode* removeElements(ListNode* head, int data) {
        while (head) {
            if (head->val == data) 
                head = head->next;
            else
                break;
        }

        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->next->val == data)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};