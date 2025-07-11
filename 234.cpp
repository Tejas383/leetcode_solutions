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
    bool isPalindrome(ListNode* head) {
        if (!head->next) 
            return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* tail;

        while (fast && fast->next) {
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail->next = prev;
        slow = prev;

        ListNode* temp = head;
        while (temp != slow) {
            if (temp->val != prev->val)
                return false;
            temp = temp->next;
            prev = prev->next;
        }

        return true;
    }
};