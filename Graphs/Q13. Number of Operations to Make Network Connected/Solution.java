class DisjointSet{
    int size[];
    int parent[];
    DisjointSet(int n){
        size = new int[n+1];
        Arrays.fill(size, 1);
        parent = new int[n+1];
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }
    public int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    public boolean union (int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return true;
        if(size[pu]>=size[pv]){
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        return false;
    }
}
class Solution {
    public int makeConnected(int n, int[][] connections) {
        int cables = connections.length;
        DisjointSet ds = new DisjointSet(n);
        int rem, used;
        used=0;
        for(int c[] : connections){
            if(!ds.union(c[0], c[1])){
                used++;
            }
        }
        rem = cables-used;
        int components=0;
        HashSet<Integer> set = new HashSet<>();
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i)
                components++;
        }
        if(rem>=components-1)
            return components-1;
        return -1;
    }
}
