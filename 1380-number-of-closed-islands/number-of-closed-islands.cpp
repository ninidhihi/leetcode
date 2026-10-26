
class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n ||
            grid[i][j] == 1) {
            return;
        }

        // Mark the land as visited
        grid[i][j] = 1;

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove all islands connected to the boundary
        for (int i = 0; i < m; i++) {
            dfs(i, 0, grid);
            dfs(i, n - 1, grid);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, grid);
            dfs(m - 1, j, grid);
        }

        int count = 0;

        // Count the remaining islands
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};
