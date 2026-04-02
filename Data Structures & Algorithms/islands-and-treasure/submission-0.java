public class Solution {
    private int[][] directions = {{1, 0}, {-1, 0},
                                  {0, 1}, {0, -1}};
    private int INF = 2147483647;
    private int ROWS, COLS;

    private int bfs(int[][] grid, int r, int c) {
        Queue<int []>q = new ArrayDeque<>();
        boolean[][] visited = new boolean[ROWS][COLS];
        q.add(new int[]{r,c});
        visited[r][c] = true;
        int layer = 0;
        while(!q.isEmpty()){
            int level = q.size();
            for(int i =0;i<level;i++){
                int []current = q.poll();
                int crow = current[0];
                int ccol = current[1];
                if(grid[crow][ccol] == 0){
                    return layer;
                }
                for (int[] dir : directions) {
                    int nr = crow + dir[0], nc = ccol + dir[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                        !visited[nr][nc] && grid[nr][nc] != -1) {
                        visited[nr][nc] = true;
                        q.add(new int[]{nr, nc});
                    }
                }
            }
            layer++;
        }
        return INF;
    }

    public void islandsAndTreasure(int[][] grid) {
        ROWS = grid.length;
        COLS = grid[0].length;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == INF) {
                    grid[r][c] = bfs(grid, r, c);
                }
            }
        }
    }
}