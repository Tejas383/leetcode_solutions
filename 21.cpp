#include <bits/stdc++>h>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        
        ListNode* list = nullptr;
        ListNode* temp = list;
        while (list1 && list2) {
            int sm;
            if (list1->val < list2->val) {
                sm = list1->val;
                list1 = list1->next;
            } else {
                sm = list2->val;
                list2 = list2->next;
            }

            ListNode* node = new ListNode(sm);
            if (!list) {
                list = node;
                temp = list;
            } else {
                temp->next = node;
                temp = temp->next;
            }
        }

        while (list1) {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }

        while (list2) {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }

        return list;
    }
};