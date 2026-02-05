import java.util.*;

// Pair class to hold Node and its horizontal distance
class Pair {
    Node node;
    int level;

    Pair(Node node, int level) {
        this.node = node;
        this.level = level;
    }
}

class Solution {
    // Function to return a list of nodes visible from the top view
    public ArrayList<Integer> topView(Node root) {
    ArrayList<Integer> ans = new ArrayList<>();
    if (root == null) return ans;

    Map<Integer, Integer> map = new TreeMap<>();
    Queue<Pair> q = new LinkedList<>();
    q.add(new Pair(root, 0));

    while (!q.isEmpty()) {
        Pair p = q.poll();
        Node node = p.node;
        int level = p.level;

        if (!map.containsKey(level)) {
            map.put(level, node.data);
        }

        if (node.left != null) q.add(new Pair(node.left, level - 1));
        if (node.right != null) q.add(new Pair(node.right, level + 1));
    }

    // Add all values to ArrayList
    for (int val : map.values()) {
        ans.add(val);
    }

    return ans;
}
}