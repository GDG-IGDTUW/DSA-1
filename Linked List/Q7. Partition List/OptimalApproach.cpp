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
        ListNode* leftHead = new ListNode(0);  // Head of the "less than x" list
        ListNode* rightHead = new ListNode(0); // Head of the "greater than or equal to x" list
        
        ListNode* leftTail = leftHead;
        ListNode* rightTail = rightHead;
        
        // Traverse the original list and partition the nodes
        while (head) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = leftTail->next;
            } else {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }
        
        // Connect the two lists
        rightTail->next = nullptr;
        leftTail->next = rightHead->next;
        
        // Return the partitioned list
        return leftHead->next;
    }
};

