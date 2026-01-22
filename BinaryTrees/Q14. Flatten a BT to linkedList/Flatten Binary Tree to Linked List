class Solution {
    public void flatten(TreeNode root) {
        TreeNode curr=root;
        while(curr!=null) {
            if(curr.left!=null){
                TreeNode pred=curr.left;
                while(pred.right!=null){
                    pred=pred.right;
                }
                pred.right=curr.right;
                curr.right=curr.left;
                curr.left=null;
            }
            curr=curr.right;
        }
        return;
    }
}
