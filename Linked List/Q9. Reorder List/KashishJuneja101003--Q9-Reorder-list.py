class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head:
            return None
        
        
        fast, slow = head, head
        
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            
        mid = slow
        
    
        prev, cur = None, mid
        
        while cur:
            cur.next, prev, cur = prev, cur, cur.next
        
        head_of_second_rev = prev
          
        first, second = head, head_of_second_rev
        
        while second.next:
            
            next_hop = first.next
            first.next = second
            first = next_hop
            
            next_hop = second.next
            second.next = first
            second = next_hop
