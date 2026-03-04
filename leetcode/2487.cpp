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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        ListNode* curr = head;
        ListNode* next = curr->next;
        while (curr) {
            if (!next) {
                curr->next = nullptr;
                break;
            }
            if (next->val < curr->val) {
                next = next->next;
            } else {
                curr->next = next;
                curr = curr->next;
                next = curr->next;
            }
        }

        head = reverse(head);

        return head;
    }
};