class Solution {
    public boolean validTree(int n, int[][] edges) {
        DSU m=new DSU(n);
        if(edges.length > n-1){
            return false;
        }
        for(int []edge:edges){
            m.union(edge[0],edge[1]);
        }

        return m.count()==1;
    }
}


class DSU {
    int parent[];
    int rank[];
    int count;

    public DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        count = n;
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    public int find(int node){
        int cur = node;
        while(cur != parent[cur]){
            parent[cur] = parent[parent[cur]];
            cur=parent[cur];
        }
        return cur;
    }

    public boolean union(int u, int v){
        int pv = find(v), pu=find(u);
        if(pu==pv){
            return false;
        }
        if(rank[pu]<rank[pv]){
            int temp = pu;
            pu=pv;
            pv=temp;
        }
        count--;
        rank[pu] += rank[pv];
        parent[pv]=pu;
        return true;
    }

    public int count(){
        return count;
    }


}