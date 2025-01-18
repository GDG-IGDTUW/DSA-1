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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pre = nullptr;
        ListNode* post = nullptr;
        ListNode* current = list1;
        int index = 0;
        
        // Traverse the list to find the node just before index 'a' (pre) 
        // and the node just after index 'b' (post)
        while (current) {
            if (index == a - 1) pre = current; // Node before index 'a'
            if (index == b + 1) post = current; // Node after index 'b'
            current = current->next;
            index++;
        }

        // Connect pre to the head of list2
        if (pre) pre->next = list2;

        // Traverse list2 to find its last node
        while (list2 && list2->next) list2 = list2->next;

        // Connect the last node of list2 to post
        if (list2) list2->next = post;

        return list1;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(vector<int>& nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Initialize list1 and list2
    vector<int> list1_vals = {0, 1, 2, 3, 4, 5};
    vector<int> list2_vals = {1000000, 1000001, 1000002};
    
    // Create the linked lists from vectors
    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);
    
    // Instantiate Solution class and merge the lists
    Solution sol;
    ListNode* result = sol.mergeInBetween(list1, 3, 4, list2);
    
    printList(result); 
    
    return 0;
}
