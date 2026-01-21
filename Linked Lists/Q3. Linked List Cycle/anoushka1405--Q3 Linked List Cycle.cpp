/**
Intuition
Think of walking through the list:

If there’s no cycle, you eventually reach null.
If there is a cycle, you could keep walking forever.

Like running around a circular track—you never reach the end.
So our goal is to detect if we ever “loop back” to a node we've already visited.

Brute Force Solution (Using Hash Set)
Idea: Store visited nodes in a unordered_set. If we see a node again, there’s a cycle.

Complexity:

Time: O(n)
Space: O(n)

Code:
**/
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;
    ListNode* current = head;
    
    while (current != nullptr) {
        if (visited.find(current) != visited.end())
            return true; // cycle detected
        visited.insert(current);
        current = current->next;
    }
    
    return false; // no cycle
}

/**
Optimised Solution:
(Floyd’s Tortoise and Hare)
Idea: Two pointers moving at different speeds. fast pointer moves 2 steps and a time and then slow pointer moves 1 step at a time.
The fast pointer will eventually “lap” the slow pointer if there’s a cycle.

Complexity:

Time: O(n)
Space: O(1)

Code:
**/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // move slow by 1
        fast = fast->next->next;     // move fast by 2
        
        if (slow == fast)
            return true; // cycle detected
    }
    
    return false; // no cycle
}


