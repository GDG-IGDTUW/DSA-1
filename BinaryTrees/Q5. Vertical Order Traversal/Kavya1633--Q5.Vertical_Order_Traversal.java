/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    // to store the row,col,node
    class tuple{

        int vertical;
        int level;
        TreeNode node;

        tuple(int v,int l,TreeNode n){
            this.vertical=v;
            this.level=l;
            this.node=n;
        }
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {

        Queue<tuple> q=new LinkedList<>();

        // using TreeMap to store the keys in sorted order
        TreeMap<Integer,TreeMap<Integer,PriorityQueue<Integer>>> tree=new TreeMap<>();

        // adding rootNode (vertical=0, level=0)
        q.add(new tuple(0,0,root));

        while(!q.isEmpty()){

            int col=q.peek().vertical;
            int level=q.peek().level;
            TreeNode tmp=q.peek().node;

            q.remove();

            // adding left and right child nodes if it exist
            if(tmp.left!=null) q.add(new tuple(col-1,level+1,tmp.left));
            if(tmp.right!=null) q.add(new tuple(col+1,level+1,tmp.right));

            // check if treeMap has that vertical
            if(!tree.containsKey(col)){
                tree.put(col,new TreeMap<>());
            }
            // check if treeMap has that level
            if(!tree.get(col).containsKey(level)){
                tree.get(col).put(level,new PriorityQueue<>());
            }
            // add the node val to the treeMap at that vertical,level
            tree.get(col).get(level).offer(tmp.val);

        }


        List<List<Integer>> result=new ArrayList<>();

        // traverse through the TreeMap to store the Vertical Order Traversal of the Tree
        for(TreeMap<Integer,PriorityQueue<Integer>> level: tree.values()){

            // add the new ArrayList to the store the data
            result.add(new ArrayList<>());

            for(PriorityQueue<Integer> data: level.values()){

                while(!data.isEmpty()){
                    result.get(result.size()-1).add(data.poll()); // add the values in the newly added ArrayList in the result
                }
            }
        }
        return result;

    }
}