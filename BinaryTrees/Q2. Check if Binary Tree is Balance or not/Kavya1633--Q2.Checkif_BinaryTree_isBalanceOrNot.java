class Solution {

public boolean isBalanced(TreeNode root){

    if(heightOfTree(root)==-1) return false;
    return true;
}
// Determine the height of Tree
public int heightOfTree(TreeNode root){

    if(root==null) return 0;

    // recursive func to determine the child height
    int left_height=heightOfTree(root.left);
    int right_height=heightOfTree(root.right);

    // if subTree if imbalance then whole Tree is imbalance.
    if(left_height==-1 || right_height==-1) return -1;

        /* Treebalance condition- the absolute diff between
         leftH and rightH of tree must be<=1 */
    if(Math.abs(left_height-right_height)>1) return -1;

    // if the Tree is Balanced written Height of the Tree
    return 1+Math.max(left_height,right_height);
}
}