/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
 import java.util.Stack;
class Solution {
    public ListNode rev(ListNode head){
        ListNode a=null, b=head, c=null;
        while(b!=null){
            c=b.next;
            b.next=a;
            a=b;
            b=c;
        }
        return a;
    }
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        ListNode s = head, f=head;
        while(f!=null && f.next!=null){
            s=s.next;
            f=f.next.next;
        }
        s=rev(s);
        f=head;
        while(s!=null){
            if(f.val!=s.val){
               return false;
            }
            else{
                f=f.next;
                s=s.next;
            }
        }
        return true;
    }
}
