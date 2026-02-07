class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        first = head
        for _ in range(k - 1):
            first = first.next

        kth_from_start = first

        second = head
        while first.next:
            first = first.next
            second = second.next

        kth_from_end = second

        # swap values
        kth_from_start.val, kth_from_end.val = kth_from_end.val, kth_from_start.val

        return head
