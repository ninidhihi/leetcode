class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[j][c] = max score at column j with cost c
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        dp[0][0] = 0; // starting point

        for (int i = 0; i < m; i++) {
            vector<vector<int>> new_dp(n, vector<int>(k + 1, -1));

            for (int j = 0; j < n; j++) {
                for (int cost = 0; cost <= k; cost++) {

                    int val = grid[i][j];
                    int add_score = val;
                    int add_cost = (val == 0 ? 0 : 1);

                    // From top
                    if (i > 0 && dp[j][cost] != -1) {
                        int new_cost = cost + add_cost;
                        if (new_cost <= k) {
                            new_dp[j][new_cost] = max(
                                new_dp[j][new_cost],
                                dp[j][cost] + add_score
                            );
                        }
                    }

                    // From left
                    if (j > 0 && new_dp[j - 1][cost] != -1) {
                        int new_cost = cost + add_cost;
                        if (new_cost <= k) {
                            new_dp[j][new_cost] = max(
                                new_dp[j][new_cost],
                                new_dp[j - 1][cost] + add_score
                            );
                        }
                    }

                    // Starting cell
                    if (i == 0 && j == 0) {
                        new_dp[0][0] = 0;
                    }
                }
            }

            dp = new_dp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][c]);
        }

        return ans;
    }
};