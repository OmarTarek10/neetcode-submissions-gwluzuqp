class Solution {
    int max=0;
    int current=0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i =0 ;i < grid.size();i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    current = 0;
                    dfs(grid, i, j);
                    if(current > max){
                        max = current;
                    }
                }
            }
        }
        return max;
    }

    void dfs(vector<vector<int>>& grid, int row, int col){
        
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return;
        }
        if(grid[row][col] == 0){
            return;
        }

        grid[row][col] = 0;
        current++;
        dfs(grid, row+1,col);
        dfs(grid, row,col-1);
        dfs(grid, row-1,col);
        dfs(grid, row,col+1);
    }
};
