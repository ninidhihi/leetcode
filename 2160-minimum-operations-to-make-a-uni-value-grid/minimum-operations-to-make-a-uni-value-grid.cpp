class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        // Flatten grid
        for (auto &row : grid) {
            for (auto &val : row) {
                arr.push_back(val);
            }
        }
        
        // Check feasibility
        int rem = arr[0] % x;
        for (int val : arr) {
            if (val % x != rem) return -1;
        }
        
        // Sort and find median
        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];
        
        // Count operations
        int ops = 0;
        for (int val : arr) {
            ops += abs(val - median) / x;
        }
        
        return ops;
    }
};