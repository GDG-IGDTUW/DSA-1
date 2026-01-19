/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector <int> nodes;
        ListNode *p;
        p = head;
        while(p!=NULL){
            nodes.push_back(p->val);
            p = p->next;
        }

        sort(nodes.begin(), nodes.end());
        // reset p to head
        p = head;
        int i = 0;
        while(p != NULL){
            p->val = nodes[i];
            i++;
            p=p->next;
        }
        return head;
    }
};