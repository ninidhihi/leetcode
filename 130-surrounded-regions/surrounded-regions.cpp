class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        // Direction vectors for up, right, down, left
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, n, m, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse the first and last rows
        for (int j = 0; j < m; j++) {
            // First row
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, n, m, board, vis);
            }
            // Last row
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, n, m, board, vis);
            }
        }

        // Traverse the first and last columns
        for (int i = 0; i < n; i++) {
            // First column
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, n, m, board, vis);
            }
            // Last column
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, n, m, board, vis);
            }
        }

        // Flip all 'O's that were not visited to 'X's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};