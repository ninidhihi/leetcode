class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        // Process each query
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        // Compute XOR of final array
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};