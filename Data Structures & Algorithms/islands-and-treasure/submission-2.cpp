class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i =0; i < grid.size();i++){
            for (int j =0; j < grid[0].size(); j++){
                if(grid[i][j]== 0){
                    q.push({i,j});
                }
            }
        }


        vector<vector<int>> directions {
            {0,1}, {0,-1}, {-1,0}, {1,0}
        };

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || grid[nr][nc] != INT_MAX){
                    continue;
                }
                grid[nr][nc] = grid[r][c]+1;
                q.push({nr,nc});
            }
        }

    }
};
