#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> pres;
        ListNode* temp = head;
        while (temp && temp->next && !pres.count(temp)) {
            pres.insert(temp);
            temp = temp->next;
        }

        return (pres.count(temp));
    }
};