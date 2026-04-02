class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        DSU n = new DSU(edges.length);
        int[] ans = new int[2];
        for(int[] edge:edges){
            if(n.union(edge[0],edge[1])==false){
                return edge;
            }
        }

        return ans;

    }
}
class DSU {
    int parent[];
    int rank[];
    public DSU(int n) {
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    public int find(int n){
        int cur = n;
        while(cur!=parent[cur]){
            parent[cur] = parent[parent[cur]];
            cur=parent[cur];
        }
        return cur;
    }

    public boolean union(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv){
            return false;
        }
        if(pu<pv){
            int temp = pu;
            pu=pv;
            pv = temp;
        }
        rank[pu] += rank[pu];
        parent[pv] = pu;
        return true;
    }
}