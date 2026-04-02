class Solution {
    public int numIslands(char[][] grid) {
        Set<String> visited = new HashSet<>();
        int islands = 0;
        for(int row =0;row<grid.length; row++){
            for(int col=0; col < grid[0].length; col++){
                if(visited.contains(String.valueOf(row)+"-"+String.valueOf(col)) || grid[row][col] == '0'){
                    continue;
                }
                else{
                    dfs(grid,visited, row,col);
                    islands++;
                }
            }
        }
        return islands;
    }
    public void dfs(char[][] grid, Set<String> visited, int row, int col) {
        if(row < 0 || col < 0 || row >= grid.length || col >= grid[0].length){
            return;
        }
        String visitedStr = String.valueOf(row) +"-"+ String.valueOf(col);
        if(visited.contains(visitedStr) || grid[row][col] == '0'){
            return;
        }
        visited.add(visitedStr);
        dfs(grid,visited, row+1,col);
        dfs(grid,visited, row,col+1);
        dfs(grid,visited, row,col-1);
        dfs(grid,visited, row-1,col);
    }
}
