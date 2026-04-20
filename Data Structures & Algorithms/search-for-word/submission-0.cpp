class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index) {
        if (index == word.size()) return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;

        if (board[row][col] != word[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '#'; // mark as visited

        for (auto& dir : directions) {
            int nrow = row + dir[0];
            int ncol = col + dir[1];
            if (dfs(board, nrow, ncol, word, index + 1)) {
                return true;
            }
        }

        board[row][col] = temp; // backtrack
        return false;
    }
};