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
    int getDecimalValue(ListNode* head) {
        int ans=0,cnt=0,i=0;
        ListNode* temp=head;
        ListNode* temp2=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        while(temp2!=NULL){
            ans+=temp2->val*pow(2,cnt-1-i);
            i++;
            temp2=temp2->next;
        }
        return ans;
    }
};