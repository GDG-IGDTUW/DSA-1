//OPTIMAL-APPROACH : Two-Pointer (Tortoise and Hare) with Reversal
//The problem is to check if a singly linked list is a palindrome. The Two-Pointer (Tortoise and Hare) technique efficiently finds the middle of the list, allowing us to split it into two halves. 
//By reversing the second half and comparing it with the first half, we can determine if the list is a palindrome.

//CODE: 
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
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

// Function to check if a linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true; // Single node or empty list is always a palindrome

    // Step 1: Use Tortoise and Hare to find the middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode* secondHalf = reverseList(slow);

    // Step 3: Compare the first half and reversed second half
    ListNode* firstHalf = head;
    ListNode* temp = secondHalf; // To restore the list later if needed
    while (temp) {
        if (firstHalf->val != temp->val) {
            return false; // Mismatch found
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Step 4: Restore the list (optional)
    reverseList(secondHalf);

    return true; // Palindrome confirmed
}

// function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}
int main() {
    // Test case 1
    vector<int> values1 = {1, 2, 2, 1};
    ListNode* head1 = createList(values1);
    cout << (isPalindrome(head1) ? "True" : "False") << endl;

    // Test case 2
    vector<int> values2 = {1, 2};
    ListNode* head2 = createList(values2);
    cout << (isPalindrome(head2) ? "True" : "False") << endl;

    return 0;
}
