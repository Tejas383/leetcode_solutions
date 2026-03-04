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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        head = reverseList(head);

        if (n == 1) {
            head = head->next;
            head = reverseList(head);
            return head;
        }
        
        ListNode* temp = head;
        int i = 1;
        while (i < n-1) {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;

        head = reverseList(head);

        return head;
    }
};