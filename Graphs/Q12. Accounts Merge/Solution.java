class Solution {

    int[] p;

    int f(int a) {
        if (p[a] != a)
            p[a] = f(p[a]);
        return p[a];
    }

    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a != b)
            p[b] = a;
    }

    public List<List<String>> accountsMerge(List<List<String>> acc) {

        int n = acc.size();
        p = new int[n];

        for (int i = 0; i < n; i++)
            p[i] = i;

        Map<String, Integer> m = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < acc.get(i).size(); j++) {
                String s = acc.get(i).get(j);
                if (!m.containsKey(s)) {
                    m.put(s, i);
                } else {
                    u(i, m.get(s));
                }
            }
        }

        Map<Integer, TreeSet<String>> g = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int r = f(i);
            g.putIfAbsent(r, new TreeSet<>());
            for (int j = 1; j < acc.get(i).size(); j++) {
                g.get(r).add(acc.get(i).get(j));
            }
        }

        List<List<String>> res = new ArrayList<>();

        for (int k : g.keySet()) {
            List<String> a = new ArrayList<>();
            a.add(acc.get(k).get(0));
            a.addAll(g.get(k));
            res.add(a);
        }

        return res;
    }
}
