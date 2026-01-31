class Solution {

    private int checkHeight(TreeNode node) {
        if (node == null) return 0;

        int lh = checkHeight(node.left);
        if (lh == -1) return -1;

        int rh = checkHeight(node.right);
        if (rh == -1) return -1;

        if (Math.abs(lh - rh) > 1) return -1;

        return 1 + Math.max(lh, rh);
    }

    public boolean isBalanced(TreeNode root) {
        return checkHeight(root) != -1;
    }
}
