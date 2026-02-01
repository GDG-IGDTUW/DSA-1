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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        int carry = 0;
        int res = 0;
        ListNode* t3 = new ListNode();
        ListNode* dummy = t3;

        while(t1!=nullptr || t2!=nullptr){
            if(t1!=nullptr && t2!=nullptr){
                 res = carry + t1->val + t2->val;
            }else if(t1!=nullptr && t2==nullptr){
                res = carry + t1->val;
            }else if(t1==nullptr && t2!=nullptr){
                res = carry + t2->val;
            }
           
            carry = res/10;
            res = res%10;
            if(t1!=nullptr){
                  t1 = t1->next;
            }

            if(t2!=nullptr){
                 t2 = t2->next;
            }
          
           

            ListNode* l3 = new ListNode(res);
            t3->next = l3;
            t3 = l3;
            

        }


        if(carry!=0){
            ListNode* l4 = new ListNode(carry);
            t3->next = l4;
        }

        return dummy->next;
        
    }
};