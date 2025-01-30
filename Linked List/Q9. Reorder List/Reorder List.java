class Solution {
    void reorderList(ListNode head){
        ListNode temp = head;
        ListNode fast = head;
        ListNode slow = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode secondList = slow.next;
        slow.next = null;

        secondList = reverse(secondList);
        while(secondList!=null){
            ListNode temp1 = head.next;
            ListNode temp2 = secondList.next;
            head.next = secondList;
            secondList.next = temp1;
            head = temp1;
            secondList = temp2;
        }
    }
    public ListNode reverse(ListNode start){
        ListNode prev = null;
        ListNode curr = start;
        while(curr!=null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
         return prev;
    }
}
