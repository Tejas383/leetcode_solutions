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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumList = nullptr;
        ListNode* it = sumList;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;
        while (temp1 != nullptr && temp2 != nullptr) {
            int tot = temp1->val + temp2->val + carry;
            carry = tot / 10;
            tot = tot % 10;

            ListNode* sum = new ListNode(tot);
            if (sumList == nullptr) {
                sumList = sum;
                it = sumList;
            } else {
                it->next = sum;
                it = it->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 != nullptr) {
            while (temp1 != nullptr) {
                int tot = temp1->val + carry;
                carry = tot / 10;
                tot = tot % 10;

                ListNode* sum = new ListNode(tot);
                it->next = sum;
                it = it->next;

                temp1 = temp1->next;
            }
        }

        if (temp2 != nullptr) {
            while (temp2 != nullptr) {
                int tot = temp2->val + carry;
                carry = tot / 10;
                tot = tot % 10;

                ListNode* sum = new ListNode(tot);
                it->next = sum;
                it = it->next;

                temp2 = temp2->next;
            }
        }

        if (carry) {
            int tot = carry;
            ListNode* sum = new ListNode(tot);
            it->next = sum;
            it = it->next;
        }

        return sumList;
    }
};