class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac (rows, vector<bool>(cols, false));
        vector<vector<bool>> atl (rows, vector<bool>(cols, false));

        for(int i =0; i < rows; i++){
            dfs(i,cols-1,heights,atl);
            dfs(i,0,heights,pac);
        }

        for(int j=0; j< cols;j++){
            dfs(0,j,heights,pac);
            dfs(rows-1,j,heights,atl);
        }

        vector<vector<int>> res;
        for(int row=0;row<rows;row++){
            for (int col=0;col < cols; col++){
                if(pac[row][col] && atl[row][col] ){
                    res.push_back({row,col});
                }
            }
        }
        return res;

    }

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>> &ocean){
        ocean[row][col] = true;
        for(auto [dr,dc]: directions){
            int nr = row+dr;
            int nc = col+dc;
            if (nr >= 0 && nr < heights.size() &&
                nc >= 0 && nc < heights[0].size() &&
                heights[nr][nc]>=heights[row][col] && !ocean[nr][nc]){
                    dfs(nr,nc,heights,ocean);
                }
        }
    }
};
