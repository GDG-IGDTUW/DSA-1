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
        // Step 1: Find the node at index a-1 (pre) and the node at index b+1 (post)
        ListNode* pre = nullptr;
        ListNode* post = nullptr;
        ListNode* current = list1;
        int index = 0;
        
        // Traverse to find pre and post
        while (current) {
            if (index == a - 1) pre = current; // node before the removal part
            if (index == b + 1) post = current; // node after the removal part
            current = current->next;
            index++;
        }

        // Step 2: Connect pre to the head of list2
        if (pre) pre->next = list2;
        
        // Step 3: Find the last node of list2
        current = list2;
        while (current && current->next) {
            current = current->next;
        }
        // Step 4: Connect the last node of list2 to post
        if (current) current->next = post;

        return list1; // Return the modified list1
    }
};

// use helper functions to create and print linked lists
ListNode* createList(vector<int>& nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> list1_vals = {0, 1, 2, 3, 4, 5};
    vector<int> list2_vals = {1000000, 1000001, 1000002};
    
    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);
    
    Solution sol;
    ListNode* result = sol.mergeInBetween(list1, 3, 4, list2);
    printList(result);
    
    return 0;
}
