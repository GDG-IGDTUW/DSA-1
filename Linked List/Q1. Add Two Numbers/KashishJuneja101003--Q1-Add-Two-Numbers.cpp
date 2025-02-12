class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode();
        ListNode* temp = Head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
            ListNode* newNode = new ListNode((sum)%10);
            carry = sum/10;

            temp->next = newNode;
            temp = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            int sum = l1->val + carry;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            temp->next = newNode; temp = newNode;
            l1 = l1->next;
        }

        while(l2 != nullptr){
            int sum = l2->val + carry;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            temp->next = newNode; temp = newNode;
            l2 = l2->next;
        }

        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            temp->next = newNode; temp = newNode;
        }
        return Head->next;
    }
};
