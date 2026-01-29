/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        // base condition
        if(root==null) return null;
        if(root==p) return p;
        if(root==q) return q;


        // chk for left and right child nodes
        TreeNode leftNode=lowestCommonAncestor(root.left,p,q);
        TreeNode rightNode=lowestCommonAncestor(root.right,p,q);

        // chk for the LCA of p & q on the same subtree
        if(leftNode==null) return rightNode;
        else if(rightNode==null) return leftNode;

            // both p & q TreeNode are found in left & right subtree
        else return root;


    }
}