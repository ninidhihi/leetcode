class Solution {
public:
    using ll = long long;

    int n;
    vector<vector<vector<ll>>> dp; // [prevTaken][prevHeight][col]
    vector<vector<ll>> colPrefSum;

    ll solve(bool prevTaken, int prevHeight, int col) {

        // ✅ BASE CASE
        if (col == n) return 0;

        // ✅ MEMO
        if (dp[prevTaken][prevHeight][col] != -1)
            return dp[prevTaken][prevHeight][col];

        ll result = 0;

        for (int height = 0; height <= n; height++) {

            ll prevColScore = 0;
            ll currColScore = 0;

            // contribution from previous column
            if (!prevTaken && col - 1 >= 0 && height > prevHeight) {
                prevColScore += colPrefSum[height][col - 1]
                              - colPrefSum[prevHeight][col - 1];
            }

            // contribution from current column
            if (prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col]
                              - colPrefSum[height][col];
            }

            ll take =
                currColScore + prevColScore +
                solve(true, height, col + 1);

            ll notTake =
                prevColScore +
                solve(false, height, col + 1);

            result = max({result, take, notTake});
        }

        return dp[prevTaken][prevHeight][col] = result;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        colPrefSum.assign(n + 1, vector<ll>(n, 0));

        // ✅ prefix sum (column-wise)
        for (int col = 0; col < n; col++) {
            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col];
            }
        }

        // dp init
        dp.assign(2, vector<vector<ll>>(n + 1, vector<ll>(n, -1)));

        return solve(false, 0, 0);
    }
};