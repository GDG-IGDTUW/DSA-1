
class Solution {

    public List<List<Integer>> levelOrder(TreeNode root) {
        // to add traversal
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        Queue<TreeNode> queue=new LinkedList<TreeNode>();

        // check if root==null (no tree)
        if(root==null) return ans;

        // add the root node
        queue.add(root);

        while(!queue.isEmpty()){
            // curr nodes in the queue
            int size=queue.size();

            // to store nodes level wise
            List<Integer> list=new ArrayList<>();
            for(int i=0;i<size;i++){

                // adding left & right child of curr node only if they are present
                if(queue.peek().left!=null) queue.add(queue.peek().left);
                if(queue.peek().right!=null) queue.add(queue.peek().right);

                // adding the curr node into the list while remove from the queue
                list.add(queue.remove().val);
            }
            // adding the level traversal into the ans list
            ans.add(list);
        }
        return ans;

    }
}