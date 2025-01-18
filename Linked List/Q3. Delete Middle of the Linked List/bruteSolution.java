class Node{
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class bruteSolution{
    // Function to delete the middle node of the linked list
    public static Node deleteMiddleNode(Node head){
        // Handling edge case
        if((head == null) || (head.next == null)){
            return null;
        }

        // Step 1
        int count = 0;
        Node temp = head;
        while(temp != null){
            count++;
            temp = temp.next;
        }

        // Step 2
        int index = 0;
        temp = head;
        while(temp != null){
            index++;
            if(index == (count / 2)){
                temp.next = temp.next.next;
                break;
            }
            temp = temp.next;
        }

        return head;
    }

    // Utility function to print the linked list
    public static void printList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    // Utility function to create a linked list from an array
    public static Node createList(int[] arr) {
        if (arr.length == 0) {
            return null;
        }

        Node head = new Node(arr[0]);
        Node current = head;

        for (int i = 1; i < arr.length; i++) {
            current.next = new Node(arr[i]);
            current = current.next;
        }

        return head;
    }

    // Main function to test the deleteMiddleNode method
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4, 5};
        int[] arr2 = {1, 2, 3, 4, 5, 6};
        int[] arr3 = {1};

        Node head1 = createList(arr1);
        Node head2 = createList(arr2);
        Node head3 = createList(arr3);

        System.out.print("Original List 1: ");
        printList(head1);
        head1 = deleteMiddleNode(head1);
        System.out.print("After Deletion 1: ");
        printList(head1);

        System.out.print("Original List 2: ");
        printList(head2);
        head2 = deleteMiddleNode(head2);
        System.out.print("After Deletion 2: ");
        printList(head2);

        System.out.print("Original List 3: ");
        printList(head3);
        head3 = deleteMiddleNode(head3);
        System.out.print("After Deletion 3: ");
        printList(head3);
    }
}