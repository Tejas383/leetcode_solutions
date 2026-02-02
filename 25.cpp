#include <bits/stdc++.h>

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base Condition: 
        // 1. if list size is 0 / 1
        if (!head || !head->next) 
            return head;

        // 2. length of list < k => in this case, we won't reverse
        ListNode* temp = head;
        int len = 0;
        while (temp && len < k) {
            len++;
            temp = temp->next;
        }
        if (len < k)
            return head;
        
        // reverse k elements
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        int count = 0;
        while (count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            count++;
        }

        // last element of reversed part is head
        // therefore, we attach it to head
        // head of remaining list is curr
        // hence, it is sent to the recursion call
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};