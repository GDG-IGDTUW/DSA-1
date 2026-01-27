
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
public class Solution{

    public int maximumPathSum(TreeNode root){

        int[] sum=new int[1];
        sum[0]=Integer.MIN_VALUE;

        maxSum(root,sum);
        return sum[0];
    }

    private int maxSum(TreeNode root, int[] sum){
        // null node return 0 val
        if(root == null){
            return 0;
        }
        // To avoid neg Values
        int leftSum=Math.max(0,maxSum(root.left,sum));
        int rightSum=Math.max(0,maxSum(root.right,sum));

        // take the max path sum till now
        sum[0]=Math.max(sum[0],leftSum+rightSum+root.val);

        // return the maxPath sum subtree
        return Math.max(leftSum,rightSum)+root.val;

    }


}