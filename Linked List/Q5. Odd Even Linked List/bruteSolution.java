import java.util.ArrayList;

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}
public class bruteSolution{
    public static Node oddEvenList(Node head){
        if(head == null){
            return null;
        }

        ArrayList<Integer> list = new ArrayList<>();

        // adding odd-indexed elements
        Node temp = head;
        while((temp != null) && (temp.next != null)){
            list.add(temp.data);
            temp = temp.next.next;
        }
        if(temp != null){
            list.add(temp.data);
        }

        // adding even-indexed lists
        temp = head.next;
        while((temp != null) && (temp.next != null)){
            list.add(temp.data);
            temp = temp.next.next;
        } 
        if(temp != null){
            list.add(temp.data);
        }

        // Data replacing
        temp = head;
        int i = 0;
        while(temp != null){
            temp.data = list.get(i);
            i++;
            temp = temp.next;
        }
        return head;
    }
}