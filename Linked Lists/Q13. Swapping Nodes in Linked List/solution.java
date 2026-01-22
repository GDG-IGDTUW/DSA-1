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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode a = head, c = head;
        int b = 1;
        while (b < k) {
            a = a.next;
            b++;
        }
        ListNode d = a;
        while (a.next != null) {
            a = a.next;
            c = c.next;
        }
        b = d.val;
        d.val = c.val;
        c.val = b;
        return head;
    }
}
