

//User function Template for Java
class Pair{
    int row;
    Node node;
    Pair(int row, Node node){
        this.row = row;
        this.node = node;
    }
}

class Solution
{
    //Function to return a list containing the bottom view of the given tree.
    public ArrayList <Integer> bottomView(Node root)
    {
        Queue<Pair> q = new LinkedList<>();
        TreeMap<Integer, Integer> map = new TreeMap<>();
        q.offer(new Pair(0, root));
        while(!q.isEmpty()){
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++){
                Pair p = q.poll();
                int row = p.row;
                Node node = p.node;
                map.put(row, node.data);
                if(node.left!=null)
                    q.offer(new Pair(row-1, node.left));
                if(node.right!=null)
                    q.offer(new Pair(row+1, node.right));
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        for(int val : map.values())
            ans.add(val);
            
        return ans;
    }
}
