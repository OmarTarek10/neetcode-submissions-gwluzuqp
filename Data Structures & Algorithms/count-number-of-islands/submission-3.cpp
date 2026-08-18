class Solution {
        int directions[4][2] = {{1, 0}, {-1, 0},
                            {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount =0;
        for(int row=0; row < grid.size(); row++){
            for(int col=0; col < grid[0].size(); col++){
                    if(grid[row][col]=='1'){
                        bfs(grid, row,col);
                        islandCount++;
                    }
            }            
        }

        return islandCount;
    }

    // void dfs(vector<vector<char>>& grid, int row, int col){

    //     if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
    //         return;
    //     }

    //     if(grid[row][col]=='0'){
    //         return;
    //     }

    //     grid[row][col] = '0';
    //     dfs(grid, row,col+1);
    //     dfs(grid, row+1,col);
    //     dfs(grid, row-1,col);
    //     dfs(grid, row,col-1);
    // }


    void bfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int,int>> myQ;
        myQ.push({row,col});
        grid[row][col]='0';

        while(myQ.size()!=0){
            pair<int, int> current = myQ.front();
            myQ.pop();
            int r = current.first;
            int c = current.second;

            for(int i=0;i<4;i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() &&
                        nc < grid[0].size() && grid[nr][nc] == '1'){
                            grid[nr][nc] = '0';
                            myQ.push({nr,nc});
                }
            }
        }
        
    }
};
