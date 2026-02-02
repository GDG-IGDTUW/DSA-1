class Solution {
    public List<Integer> topView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;

        Map<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, root));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            TreeNode node = p.node;
            int level = p.level;

            if (!map.containsKey(level))
                map.put(level, node.data);

            if (node.left != null) q.add(new Pair(level - 1, node.left));
            if (node.right != null) q.add(new Pair(level + 1, node.right));
        }

        ans.addAll(map.values());
        return ans;
    }
}

