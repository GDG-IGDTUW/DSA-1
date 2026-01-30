class Solution {
    public ListNode sortList(ListNode head) {
        
        if(head==null || head.next==null) return head;
        boolean swapped=true;
        while(swapped){
            swapped=false;
            ListNode temp=head;

            while(temp.next!=null){
                if(temp.val>temp.next.val){
                    int swap=temp.val;
                    temp.val=temp.next.val;
                    temp.next.val=swap;
                    swapped=true;
                }
                temp=temp.next;
            }
        }
        return head;
    }
}
