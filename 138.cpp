#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) 
            return nullptr;
        
        Node* temp = head;
        while (temp != nullptr) {
            int data = temp->val;
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;

            temp = temp->next->next;
        }

        temp = head;
        while (temp) {
            if (temp->random != nullptr)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        temp = head;
        Node* ans = temp->next;
        Node* it = ans;
        while (temp) {
            temp->next = temp->next->next;
            temp = temp->next;
            if (temp) {
                it->next = temp->next;
                it = it->next;
            }
        }

        return ans;
    }
};