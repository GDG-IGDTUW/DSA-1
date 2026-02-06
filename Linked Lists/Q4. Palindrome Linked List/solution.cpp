/*
Intuition:
A linked list is a palindrome if it reads the same forwards and backwards.
For example:
1 -> 2 -> 2 -> 1 is a palindrome.

To check if a linked list is a palindrome, we can do the following:
1. Find the middle of the linked list using slow and fast pointers.
2. Reverse the second half of the list.
3. Compare the first half and the reversed second half node by node.
4. If all nodes match, it's a palindrome. Otherwise, it's not.

This approach has:
- Time Complexity: O(n) where n is the number of nodes.
- Space Complexity: O(1) since we reverse the list in place.
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // A list with 0 or 1 node is always a palindrome

        // Step 1: Find the middle of the linked list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;        // move 1 step
            fast = fast->next->next;  // move 2 steps
        }
        // Now, slow points to the middle node

        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // prev is now the head of the reversed second half
        ListNode* secondHalf = prev;
        ListNode* firstHalf = head;

        // Step 3: Compare first half and reversed second half
        bool palindrome = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return palindrome;
    }
};
