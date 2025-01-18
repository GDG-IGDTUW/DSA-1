class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        
        // Traverse the linked list
        while (head != nullptr) {
            // Shift the current result to the left (binary left shift)
            result = (result << 1) | head->val;
            // Move to the next node
            head = head->next;
        }
        
        return result;
    }
};
