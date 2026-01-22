/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Pointer to iterate through the linked list
        ListNode* temp = head;
        
        // Unordered Map to record which nodes we've already visited
        // Key: pointer to a ListNode
        // Value: to record the frequency, we return true the moment we find that the node already exists in the map
        unordered_map<ListNode*, int> mpp;
        
        // Traverse until we reach the end (nullptr)
        while (temp != nullptr) {
            // If current node already exists in the map,
            // it means we have encountered it before therefore a cycle is found
            if (mpp.find(temp) != mpp.end()) {
                return true;
            }
            
            //Insert the current node into the map and mark its frequency as 1
            mpp[temp] = 1;
            
            // Move to the next node in the list
            temp = temp->next;
        }
        
        // If we reach nullptr without finding a repeat,
        // there is no cycle
        return false;
    }
};

//Complexity Analysis
// ->Time Complexity = Big O(N)
// ->Space Complexity = Big O(N)
// In the worst case scenario, i.e. no node present, we end up storing all the nodes in the ordered map
