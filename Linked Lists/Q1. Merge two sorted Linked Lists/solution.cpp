
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(curr1!=NULL && curr2!=NULL) {
            if(curr1->val<=curr2->val) {
                temp->next=curr1;
                curr1=curr1->next;
            }
            else {
                temp->next=curr2;
                curr2=curr2->next;
            }
            temp=temp->next;
        }

        while(curr1!=NULL) {
            temp->next=curr1;
            curr1=curr1->next;
            temp=temp->next;
        }
        while(curr2!=NULL) {
            temp->next=curr2;
            curr2=curr2->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }
};