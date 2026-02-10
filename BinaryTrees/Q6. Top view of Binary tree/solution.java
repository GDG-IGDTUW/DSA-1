import java.util.*;

class Solution {
    
    // Helper class to store node with its horizontal distance
    static class Pair {
        Node node;
        int hd;
        
        Pair(Node node, int hd) {
            this.node = node;
            this.hd = hd;
        }
    }
    
    // Function to return top view of binary tree
    static ArrayList<Integer> topView(Node root) {
        
        ArrayList<Integer> result = new ArrayList<>();
        if (root == null) return result;
        
        // TreeMap to store first node at each horizontal distance
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        // Queue for level order traversal
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, 0));
        
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            Node node = current.node;
            int hd = current.hd;
            
            // Store only first node for each horizontal distance
            map.putIfAbsent(hd, node.data);
            
            if (node.left != null) {
                queue.offer(new Pair(node.left, hd - 1));
            }
            if (node.right != null) {
                queue.offer(new Pair(node.right, hd + 1));
            }
        }
        
        // Extract values from TreeMap (left to right)
        for (int val : map.values()) {
            result.add(val);
        }
        
        return result;
    }
}
