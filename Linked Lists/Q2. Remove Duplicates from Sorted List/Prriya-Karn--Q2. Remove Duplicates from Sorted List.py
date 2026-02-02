# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head is None:
            return head

        arr = []
        t1 = head

        # Store values in array
        while t1 is not None:
            arr.append(t1.val)
            t1 = t1.next

        i = 0
        l2 = ListNode(arr[i])
        t2 = l2
        dummy = t2

        # Build new list without duplicates
        while i < len(arr) - 1:
            i += 1
            if arr[i] != l2.val:
                l2 = ListNode(arr[i])
                t2.next = l2
                t2 = l2

        return dummy
