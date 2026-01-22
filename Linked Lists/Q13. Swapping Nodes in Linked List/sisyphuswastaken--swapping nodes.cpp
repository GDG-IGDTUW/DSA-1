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
 // brute
class Solution {
public:
    int length(ListNode *head){
        int c = 0;
        ListNode *p;
        p = head;
        while(p!=NULL){
            p = p->next;
            c++;
        }
        return c;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int n = length(head);
        ListNode *p;
        ListNode *q;
        p = head;
        q = head;
        for(int i = 1; i <=k-1; i++){
            p = p->next;
        }
        for(int i = 1; i <= n-k; i++){
            q = q->next;
        }

        int x = p->val;
        int y = q->val;

        p->val = y;
        q->val = x;

        return head;
    }
};