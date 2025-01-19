//Optimal Solution--** Two-Pointer Technique **
//This approach leverages the two-pointer technique to efficiently find the k-th node from the start and from the end in a single traversal.
//Algorithm:
//Find the k-th Node from the Beginning: -Use a pointer temp to traverse the list k−1 steps to locate the k-th node from the beginning.
//Store its reference in first.
//Find the k-th Node from the End Using Two Pointers: -Start a second pointer second at the head. Move temp (from step 1) until the end of the list, simultaneously moving second.
//When temp reaches the end, second will point to the k-th node from end. then Swap the val fields of first and second.
//Time Complexity: O(n)  &  Space Complexity: O(1)

//CODE: 
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        ListNode* temp = head;

        // Step 1: Locate the k-th node from the beginning
        for (int i = 1; i < k; ++i) {
            temp = temp->next;
        }
        first = temp;

        // Step 2: Locate the k-th node from the end
        second = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            second = second->next;
        }

        // Step 3: Swap the values of the nodes
        swap(first->val, second->val);

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    // Create a linked list: [1, 2, 3, 4, 5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int k = 2;
    head = solution.swapNodes(head, k);

    // Output the modified list
    printList(head); 

    return 0;
}
