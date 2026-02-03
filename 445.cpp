 #include <bits/stdc++.h>
 
 /*
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        
        h1 = reverse(h1);
        h2 = reverse(h2);
        
        ListNode* sumHead = nullptr;
        ListNode* sumTail = nullptr;
        
        int carry = 0;
        int val;
        
        while (h1 && h2) {
            val = h1->val + h2->val + carry;
            if (val > 9) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode* newListNode = new ListNode(val);
            if (!sumHead) {
                sumHead = newListNode;
                sumTail = newListNode;
            } else {
                sumTail->next = newListNode;
                sumTail = sumTail->next;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        
        while (h1) {
            val = h1->val + carry;
            if (val > 9) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode* newListNode = new ListNode(val);
            if (!sumHead) {
                sumHead = newListNode;
                sumTail = newListNode;
            } else {
                sumTail->next = newListNode;
                sumTail = sumTail->next;
            }
            h1 = h1->next;
        }
        
        while (h2) {
            val = h2->val + carry;
            if (val > 9) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode* newListNode = new ListNode(val);
            if (!sumHead) {
                sumHead = newListNode;
                sumTail = newListNode;
            } else {
                sumTail->next = newListNode;
                sumTail = sumTail->next;
            }
            h2 = h2->next;
        }
        
        if (carry) {
            ListNode* newListNode = new ListNode(carry);
            sumTail->next = newListNode;
            sumTail = sumTail->next;
        }
        
        ListNode* sum = reverse(sumHead);
        
        return sum;
    }
};