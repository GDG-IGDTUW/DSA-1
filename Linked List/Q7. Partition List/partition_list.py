class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def partition(head: ListNode, x: int) -> ListNode:
    before_head = ListNode(0)  # Dummy node for the list of nodes < x
    before = before_head
    after_head = ListNode(0)   # Dummy node for the list of nodes >= x
    after = after_head
    
    while head:
        if head.val < x:
            before.next = head
            before = before.next
        else:
            after.next = head
            after = after.next
        head = head.next
    
    after.next = None  # Ensure the last node of 'after' list doesn't form a cycle
    before.next = after_head.next  # Connect the two lists
    
    return before_head.next
