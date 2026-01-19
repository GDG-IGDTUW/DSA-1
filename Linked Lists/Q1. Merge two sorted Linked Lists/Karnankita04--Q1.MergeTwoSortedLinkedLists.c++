class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                ListNode* nxt = list1->next;
                temp->next = list1;
                temp = list1;
                list1 = nxt;
            }else{
                ListNode* nxt = list2->next;
                temp->next = list2;
                temp = list2;
                list2 = nxt;
            }
        }
        temp->next = list1 != nullptr ? list1 : list2;
        return dummy->next;
    }
};