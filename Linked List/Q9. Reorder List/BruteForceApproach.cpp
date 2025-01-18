#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // Base case: If the list is empty or contains only one element, return
        if (!head || !head->next) return;

        // Step 1: Store all the nodes of the list in a vector
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Step 2: Reorder the list by alternating between nodes from the front and the back
        int i = 0, j = nodes.size() - 1;
        while (i < j) {
            nodes[i]->next = nodes[j];  
            i++;
            if (i == j) break;  
            nodes[j]->next = nodes[i];  
            j--;
        }

        // Step 3: Ensure the last node's next pointer is set to nullptr to terminate the list
        nodes[i]->next = nullptr;
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
    vector<int> values = {1, 2, 3, 4};
    ListNode* head = createList(values);
    Solution sol;
    sol.reorderList(head);
    printList(head);  
    return 0;
}
