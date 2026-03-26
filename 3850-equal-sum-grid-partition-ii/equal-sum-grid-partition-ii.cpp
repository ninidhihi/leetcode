class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (auto& row : grid)
            for (int v : row) total += v;

        auto checkSection = [&](long long diff, int rows, int cols,
                                int r1, int r2, int c1, int c2,
                                unordered_map<int,int>& freq) -> bool {
            if (diff == 0) return true;
            if (diff > 100000) return false;
            if (rows == 1 && cols == 1) return false;
            if (rows == 1)
                return grid[r1][c1] == diff || grid[r1][c2] == diff;
            if (cols == 1)
                return grid[r1][c1] == diff || grid[r2][c1] == diff;
            return freq.count(diff) > 0;
        };

        // ---------- Horizontal cuts ----------
        unordered_map<int,int> topFreq, botFreq;
        for (auto& row : grid)
            for (int v : row) botFreq[v]++;

        long long topSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int v : grid[i]) {
                topSum += v;
                topFreq[v]++;
                if (--botFreq[v] == 0) botFreq.erase(v);
            }
            long long botSum = total - topSum;
            long long diff = abs(topSum - botSum);
            int topRows = i + 1, botRows = m - i - 1;

            if (topSum >= botSum) {
                if (checkSection(topSum - botSum, topRows, n, 0, i, 0, n-1, topFreq))
                    return true;
            }
            if (botSum >= topSum) {
                if (checkSection(botSum - topSum, botRows, n, i+1, m-1, 0, n-1, botFreq))
                    return true;
            }
        }

        // ---------- Vertical cuts ----------
        unordered_map<int,int> leftFreq, rightFreq;
        for (auto& row : grid)
            for (int v : row) rightFreq[v]++;

        long long leftSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                leftSum += grid[i][j];
                leftFreq[grid[i][j]]++;
                if (--rightFreq[grid[i][j]] == 0) rightFreq.erase(grid[i][j]);
            }
            long long rightSum = total - leftSum;
            int leftCols = j + 1, rightCols = n - j - 1;

            if (leftSum >= rightSum) {
                if (checkSection(leftSum - rightSum, m, leftCols, 0, m-1, 0, j, leftFreq))
                    return true;
            }
            if (rightSum >= leftSum) {
                if (checkSection(rightSum - leftSum, m, rightCols, 0, m-1, j+1, n-1, rightFreq))
                    return true;
            }
        }

        return false;
    }
};