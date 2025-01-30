import java.util.Scanner;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class optimalSolution {
    public static boolean isPalindrome(Node head){
        if((head == null) || (head.next == null)){
            return true;
        }
        // 1. Finding the middle element
        Node slow = head;
        Node fast = head;
        while((fast != null) && (fast.next != null)){
            slow = slow.next;
            fast = fast.next.next;
        }
    
        // 2. Reversing the second half
        Node newHead = reverse(slow);

        // 3. Comparison
        Node first = head;
        Node second = newHead;

        while(second != null){
            if(first.data != second.data){
                reverse(newHead);
                return false;
            }
            first = first.next;
            second = second.next;
        }

        reverse(newHead);
        return true;
    }

    public static Node reverse(Node head){
        Node prev = null;
        Node curr = head;
        while(curr != null){
            Node front = curr.next;
            curr.next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    // Function to create the linked list from user input
    public static Node createList(Scanner scanner, int n) {
        Node head = null, tail = null;
        
        System.out.println("Enter the elements of the linked list:");
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            Node newNode = new Node(value);
            if (head == null) {
                head = newNode;
                tail = head;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the size of the linked list
        System.out.print("Enter the number of nodes in the linked list: ");
        int n = scanner.nextInt();

        if (n <= 0) {
            System.out.println("The list cannot be empty. Please enter a valid size.");
            return;
        }

        // Create the linked list using the createList function
        Node head = createList(scanner, n);

        System.out.println("Is the linked list a palindrome? " + isPalindrome(head));
    }
}


