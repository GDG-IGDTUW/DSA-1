import java.util.Scanner;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class solution {
    public static Node addTwoNumbers(Node l1, Node l2){
        if((l1 == null) && (l2 == null)){
            return null;
        }
        int carry = 0;
        Node newHead = new Node(0);
        Node temp = newHead;

        Node t1 = l1;
        Node t2 = l2;
        while((t1 != null) || (t2 != null) || (carry != 0)){
            int sum = 0;
            if(t1 != null){
                sum += t1.data;
                t1 = t1.next;
            }
            if(t2 != null){
                sum += t2.data;
                t2 = t2.next;
            }
            sum += carry;

            temp.next = new Node(sum % 10);
            temp = temp.next;

            carry = sum / 10;
        }

        return newHead.next;
    }

    // Utility function for creating a linked list
    public static Node createList(int number) {
        Node head = new Node(0);  // Dummy node to simplify creation
        Node temp = head;

        if (number == 0) {  // Special case for number 0
            return new Node(0);
        }

        while (number > 0) {
            int digit = number % 10;  // Get the last digit
            temp.next = new Node(digit);  // Create a new node with the digit
            temp = temp.next;
            number /= 10;  // Remove the last digit
        }
        return head.next;  // Return the actual head (skipping dummy node)
    }

    // Utility function for printing the list
    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " -> ");
            head = head.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for the first number
        System.out.println("Enter the first number:");
        int num1 = scanner.nextInt();
        Node l1 = createList(num1);

        // Input for the second number
        System.out.println("Enter the second number:");
        int num2 = scanner.nextInt();
        Node l2 = createList(num2);

        // Add the two numbers
        Node result = addTwoNumbers(l1, l2);

        // Print the result
        System.out.println("The sum of the numbers is:");
        printList(result);

        scanner.close();
    }
}
