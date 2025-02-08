# Helper function to create a linked list from a list
def create_linked_list(lst):
    dummy = ListNode()
    curr = dummy
    for val in lst:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

# Helper function to print a linked list
def print_linked_list(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

# Creating input lists
list1 = create_linked_list([0, 1, 2, 3, 4, 5, 6])
list2 = create_linked_list([100, 101, 102])
a, b = 2, 4

# Merging lists
new_head = mergeInBetween(list1, a, b, list2)

# Printing the merged list
print_linked_list(new_head)
