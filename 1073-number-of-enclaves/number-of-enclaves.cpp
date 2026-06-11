class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // A 2D array to keep track of visited cells
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        // A queue for BFS traversal
        queue<pair<int, int>> q;
        
        // Push all '1's on the border into the queue and mark as visited
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        
        // Directions for moving to adjacent cells
        int delrow[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
        int delcol[] = {0, 1, 0, -1};
        
        // Perform BFS to find all land cells connected to the border
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Explore all 4 adjacent directions
            for (int i = 0; i < 4; ++i) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                // Check if the new cell is within bounds, unvisited, and is a land cell
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        
        // Count the number of '1's that were not visited (enclaves)
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};