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
class Solution {
    public int getDecimalValue(ListNode head) {
        int sum=0;String ok="";
        ListNode dummy=head;
        while(dummy!=null)
        {
           ok=ok+dummy.val;
            dummy=dummy.next;
        }
        int i=0;int bin=0;int n=ok.length();
        while(i!=n)
        {
            int bit= Character.getNumericValue(ok.charAt(ok.length()-1-i)); 
            bin = bin +((int)Math.pow(2,i)*bit);
         i++;
        }
        return bin;
    }
}
