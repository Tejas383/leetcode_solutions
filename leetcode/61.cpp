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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) 
            return nullptr;
        if (k == 0)
            return head;
        
        ListNode* temp = head;
        ListNode* prev;
        int size = 0;
        while (temp) {
            prev = temp;
            temp = temp->next;
            size++;
        }
        prev->next = head;
        
        k %= size;
        int i = 1;
        while (i < size - k) {
            head = head->next;
            i++;
        }
        ListNode* tail = head;
        head = head->next;
        tail->next = nullptr;

        return head;
    }
};