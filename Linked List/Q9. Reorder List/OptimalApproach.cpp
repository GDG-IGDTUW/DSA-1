#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to find the middle of the list using slow and fast pointer technique
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move the slow pointer one step and the fast pointer two steps at a time
        // When the fast pointer reaches the end, the slow pointer will be at the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;  // Return the middle node
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // Base case: If the list is empty or contains only one element, return
        if (!head || !head->next) return;

        // Step 1: Find the middle of the list
        ListNode* mid = middle(head);

        // Step 2: Reverse the second half of the list
        ListNode* second = reverse(mid->next);
        mid->next = nullptr;  // Split the list into two halves

        // Step 3: Merge the two halves alternately
        ListNode* first = head;
        while (first && second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;  
            second->next = tmp1;  

            first = tmp1;
            second = tmp2;
        }
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* createList(vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for (int i = 1; i < values.size(); i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    Solution sol;
    sol.reorderList(head);
    printList(head);  
    return 0;
}
