
class Solution {
public:
    int m, n;

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n ||
            grid[i][j] == 0) {
            return 0;
        }

        // Store the value and mark this cell as visited
        long long sum = grid[i][j];
        grid[i][j] = 0;

        // Explore all 4 directions
        sum += dfs(i + 1, j, grid);
        sum += dfs(i - 1, j, grid);
        sum += dfs(i, j + 1, grid);
        sum += dfs(i, j - 1, grid);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
