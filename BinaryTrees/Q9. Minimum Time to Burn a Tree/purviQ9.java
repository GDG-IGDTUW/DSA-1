class Solution {

    public int amountOfTime(TreeNode root, int target) {

        // Map to store parent of each node
        Map<TreeNode, TreeNode> parent = new HashMap<>();

        TreeNode targetNode = null;

        // BFS to map parents and find target node
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode curr = queue.poll();

            if (curr.val == target) {
                targetNode = curr;
            }

            if (curr.left != null) {
                parent.put(curr.left, curr);
                queue.offer(curr.left);
            }

            if (curr.right != null) {
                parent.put(curr.right, curr);
                queue.offer(curr.right);
            }
        }

        // BFS to simulate burning
        Set<TreeNode> visited = new HashSet<>();
        queue.offer(targetNode);
        visited.add(targetNode);

        int time = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean burned = false;

            for (int i = 0; i < size; i++) {
                TreeNode curr = queue.poll();

                // left child
                if (curr.left != null && !visited.contains(curr.left)) {
                    visited.add(curr.left);
                    queue.offer(curr.left);
                    burned = true;
                }

                // right child
                if (curr.right != null && !visited.contains(curr.right)) {
                    visited.add(curr.right);
                    queue.offer(curr.right);
                    burned = true;
                }

                // parent
                TreeNode par = parent.get(curr);
                if (par != null && !visited.contains(par)) {
                    visited.add(par);
                    queue.offer(par);
                    burned = true;
                }
            }

            if (burned) time++;
        }

        return time;
    }
}
