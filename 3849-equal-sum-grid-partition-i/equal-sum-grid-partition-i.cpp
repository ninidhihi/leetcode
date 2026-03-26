class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        long long totalSum = 0;  // 🔥 FIX
        
        for (auto &row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }
        
        if (totalSum % 2 != 0) return false;
        
        // 🔹 Horizontal cut
        long long topSum = 0;  // 🔥 FIX
        
        for (int i = 0; i < m - 1; i++) {
            long long rowSum = 0;  // 🔥 FIX
            
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            
            topSum += rowSum;
            
            if (topSum == totalSum - topSum)
                return true;
        }
        
        // 🔹 Vertical cut
        long long leftSum = 0;  // 🔥 FIX
        
        for (int j = 0; j < n - 1; j++) {
            long long colSum = 0;  // 🔥 FIX
            
            for (int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }
            
            leftSum += colSum;
            
            if (leftSum == totalSum - leftSum)
                return true;
        }
        
        return false;
    }
};