class Solution {
public:
    int m, n;
    vector<vector<int>> vis;
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        vis[x][y] = 1;
        
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for (auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            
            if (!vis[nx][ny]) {
                if (dfs(grid, nx, ny, x, y)) return true;
            } 
            else if (!(nx == px && ny == py)) {
                return true; // cycle found
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};