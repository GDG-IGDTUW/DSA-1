package Snowscript;
import java.util.Scanner;

class Node{   // node class for structure of node
	Node next;
	int val;
	
	Node(int val){
		next=null;
		this.val=val;
	}
}

public class LinkedL4 {
	public static void main(String[]args) {
		Scanner s=new Scanner(System.in);
		System.out.println("Enter length of first linked list"); // taking len of first linked list
		int len1=s.nextInt();
		Node head1=create(len1);      
		System.out.println("Enter length of second linked list"); // similarly for second linked list
		int len2=s.nextInt();
		Node head2=create(len2);
		System.out.println("Enter a");
		int a=s.nextInt();
		System.out.println("Enter b");
		int b=s.nextInt();
		Node ans=merge(head1,head2,a,b);  // calling the merge function
		print(ans);
	}
	
	public static Node merge(Node head1, Node head2, int a, int b) { // function for merging the linked lists acc to the question
	    if (head1 == null || head2 == null || a > b) return head1;  // Edge case check
    
	    if (a == 0) { // Special case where replacement starts from the head ie a=0
	        Node temp1 = head1;
	        int c = 0;
	        while (c < b && temp1 != null) {
	            temp1 = temp1.next;
	            c++;
	        }
	        Node last;
	        if (temp1 != null) {
	            last = temp1.next; // Get node after temp1
	        } else {
	            last = null;
	        }
	        head1 = head2; // Replace head with head2
	        Node temp2 = head2;
	        while (temp2.next != null) { // Find last node of head2
	            temp2 = temp2.next;
	        }
	        temp2.next = last; // Connect end of head2 to remaining list
	        return head1;
	    }

    // cases for a!=0
	    int pos = 1;
	    Node temp = head1;
	    while (pos < a) { // Find node before `a`
	        temp = temp.next;
	        pos++;
	    }
	    Node temp1 = temp.next;

	    temp.next = head2; // Connect previous part to head2
	    Node temp2 = head2;
	    while (temp2.next != null) { // Find end of head2
	        temp2 = temp2.next;
	    }

	    int c = 1;
	    while (c <= b - a) { // Move temp1 to node after `b`
	        temp1 = temp1.next;
	        c++;
	    }
	    Node last = temp1.next;
	    temp1.next = null;
	    temp2.next = last; // Connect last node of head2 to remaining list

	    return head1;
	}
	
	public static void print(Node head) {  // function to print the linked list
		Node temp=head;
		System.out.print("Final merged list: ");
		while(temp!=null) {
			System.out.print(temp.val+" ");
			temp=temp.next;
		}
		System.out.println();
	}
	
	public static Node create(int len) { // function to create a linked list acc to user input
		Scanner s=new Scanner(System.in);
		Node head=null;
		Node temp=head;
		for(int i=1;i<=len;i++) {
			System.out.println("Enter node value");
			int val=s.nextInt();
			if(i==1) {
				head=new Node(val);
				temp=head;
			}
			else {
				Node x=new Node(val);
				temp.next=x;
				temp=x;
			}
		}
		return head;
	}
	
}
