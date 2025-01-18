public class AvwalKaur_Q6_MaximumPathSum {
    class Node{
        int data;
        Node left;
        Node right;
        Node(int data) {
            this.data=data;
            this.left=null;
            this.right=null;
        }
    }

    static int diameter=Integer.MIN_VALUE; // global variable
    public int maximumPathSum(Node root) {
        if(root==null) return 0;
        
        int leftSum=maximumPathSum(root.left);
        int rightSum=maximumPathSum(root.right);
        // if either or both of the leftsum and rightsum values are negative
        // they will tend to decrease the overall sum 
        // therefore if they are found negative make them equal to zero
        if(leftSum<0) leftSum=0;  
        if(rightSum<0) rightSum=0;

        // pick the maximum out of current diameter and self diameter(leftSum+rightSum+root.data)
        // self diameter is the diameter passing through the root node
        diameter=Math.max(diameter, leftSum+rightSum+root.data);
        
        // at every step, from the two paths, we will consider the maximum out if two and add root value in it
        return Math.max(leftSum, rightSum)+root.data;
    }
}