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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        // If tree is empty, create new node
        if (root == null) {
            return new TreeNode(val);
        }

        // If val < root, insert into left subtree
        if (val < root.val) {
            root.left = insertIntoBST(root.left, val);
        } 
        // If val > root, insert into right subtree
        else {
            root.right = insertIntoBST(root.right, val);
        }

        return root; // return unchanged root
    }
}
