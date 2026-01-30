/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    public void dfs(TreeNode node, StringBuilder sb){
        if(node == null){
            sb.append("null");
            sb.append(" ");
            return;
        }
        sb.append(String.valueOf(node.val));
        sb.append(" ");
        dfs(node.left, sb);
        dfs(node.right, sb);
    }
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        dfs(root, sb);
        String s = sb.toString();
        
        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        System.out.println(data);
        String arr[] = data.split(" ");
        TreeNode root = formTree(arr);
        return root;
    }
    
    int ptr=0;
    public TreeNode formTree(String arr[]){
        String curr = arr[ptr++];
        if(curr.equals("null")){
            return null;
        }
        int val = Integer.valueOf(curr);
        TreeNode node = new TreeNode(val);
        node.left = formTree(arr);
        node.right = formTree(arr);
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
