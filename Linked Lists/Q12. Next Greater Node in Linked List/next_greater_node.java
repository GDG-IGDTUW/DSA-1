import java.util.*;

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
    public int[] nextLargerNodes(ListNode head) {

        List<Integer> values = new ArrayList<>();

        // Step 1: Convert linked list to array
        while (head != null) {
            values.add(head.val);
            head = head.next;
        }

        int n = values.size();
        int[] answer = new int[n];
        Stack<Integer> stack = new Stack<>();

        // Step 2: Monotonic stack
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && values.get(i) > values.get(stack.peek())) {
                int idx = stack.pop();
                answer[idx] = values.get(i);
            }
            stack.push(i);
        }

        // Remaining indices have no greater element → default 0
        return answer;
    }
}
