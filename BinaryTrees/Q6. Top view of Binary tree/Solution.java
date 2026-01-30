// User function Template for Java

/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/
class Pair{
    int row, col;
    Node node;
    Pair(int row, int col, Node node){
        this.row = row;
        this.col = col;
        this.node = node;
    }
}
class Solution {
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    static ArrayList<Integer> topView(Node root) {
        Queue<Pair> q = new LinkedList<>();
        TreeMap<Integer, List<Integer>> map = new TreeMap<>();
        q.offer(new Pair(0, 0, root));
        while(!q.isEmpty()){
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++){
                Pair p = q.poll();
                int row = p.row;
                int col = p.col;
                Node node = p.node;
                if(!map.containsKey(row)){
                    map.put(row, new ArrayList<>());
                }
                List<Integer> list = map.get(row);
                list.add(node.data);
                if(node.left!=null)
                    q.offer(new Pair(row-1, col+1, node.left));
                if(node.right!=null)
                    q.offer(new Pair(row+1, col+1, node.right));
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        for(List<Integer> l : map.values())
            ans.add(l.get(0));
            
        return ans;
    }
}
