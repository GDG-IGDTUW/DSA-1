#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;

        ListNode* lessHead = new ListNode(0);  // Head of the "less than x" list
        ListNode* greaterHead = new ListNode(0); // Head of the "greater than or equal to x" list
        
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        
        // Traverse the original list and partition the nodes
        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        // Terminate the greater list
        greater->next = nullptr;
        
        // Merge the two partitions
        less->next = greaterHead->next;
        
        // Return the partitioned list
        return lessHead->next;
    }
};