class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 12345;
        
        vector<long long> arr;
        
        // Flatten grid
        for (auto &row : grid) {
            for (auto &val : row) {
                arr.push_back(val % mod);
            }
        }
        
        int size = arr.size();
        vector<long long> res(size, 1);
        
        // Prefix
        long long prefix = 1;
        for (int i = 0; i < size; i++) {
            res[i] = prefix;
            prefix = (prefix * arr[i]) % mod;
        }
        
        // Suffix
        long long suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            res[i] = (res[i] * suffix) % mod;
            suffix = (suffix * arr[i]) % mod;
        }
        
        // Convert back to 2D
        vector<vector<int>> ans(n, vector<int>(m));
        int idx = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = res[idx++];
            }
        }
        
        return ans;
    }
};