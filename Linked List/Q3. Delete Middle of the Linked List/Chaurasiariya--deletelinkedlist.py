class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def deleteMiddle(head: ListNode) -> ListNode:
    # If the list has only one node means empty list
    if not head or not head.next:
        return None
    
    # Initialize slow and fast pointers
    slow = head
    fast = head
    prev = None  # To keep track of the node before slow

    # Moving fast pointer twice as fast as the slow pointer
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
    
    # Removing the middle node
    prev.next = slow.next
    
    return head

#  function to create a linked list from a list
def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

#  function to convert a linked list to a list
def linked_list_to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

def main():

    head = create_linked_list([1, 2, 3, 4, 5])         #trying on an example
    print("Original list:", linked_list_to_list(head))
    new_head = deleteMiddle(head)
    print("After deleting middle:", linked_list_to_list(new_head))


if __name__ == "__main__":
    main()
