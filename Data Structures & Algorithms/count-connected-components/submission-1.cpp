class Solution {
    unordered_map<int, vector<int>> mp;
    unordered_set<int> visited;

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i =0; i < n; i ++){
            mp[i]={};
        }

        int count = 0;

        for(auto edge: edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++){
            if (!visited.count(i)){
                dfs(i);
                count++;
            }
        }
        return count;

    }

    void dfs(int node){
        visited.insert(node);
        for(auto &nei: mp[node]){
            if(!visited.count(nei)){
                dfs(nei);
            }
        }
    }
};
