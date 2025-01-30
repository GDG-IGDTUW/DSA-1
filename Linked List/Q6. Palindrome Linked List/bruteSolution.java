import java.util.Stack;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class bruteSolution {
    public static boolean isPalindrome(Node head){
        Stack<Integer> st = new Stack<>();
        Node temp = head;
        while(temp != null){
            st.push(temp.data);
            temp = temp.next;
        }

        temp = head;
        while(temp != null){
            if(temp.data != st.pop()){
                return false;
            }
            temp = temp.next;
        }
        return true;
    }
}
