class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode result = new ListNode(0); //result node to build the first list
        ListNode dummy = result; //dummy node to remember the head of the first list
        ListNode secondList = new ListNode(0); //head node for the second list
        ListNode secondHead = secondList; //dummy node to remember the head of the second list.
        while(head!=null){
            if(head.val<x){
                result.next = head;
                result = result.next;
            }
            else{
                secondList.next = head;
                secondList = secondList.next;
            }
            head = head.next;
        }
        secondList.next = null;
        result.next = secondHead.next;
        return dummy.next;
    }
}

