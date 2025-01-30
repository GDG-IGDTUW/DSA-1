class Solution {
        List<Integer> list = new ArrayList<>();
    public int kthSmallest(TreeNode root, int k) {
        inOrder(root, list);
        for(int i:list){
            System.out.println(i+" ");
        }
        return list.get(k-1);
    }
    void inOrder(TreeNode root, List<Integer> list){
        if(root==null){
            return;
        }
        inOrder(root.left, list);
        list.add(root.val);
        inOrder(root.right, list);
    }

}
