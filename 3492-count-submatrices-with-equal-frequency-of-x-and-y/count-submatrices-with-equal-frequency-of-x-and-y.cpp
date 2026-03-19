class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> colSum(n, 0);   // stores column-wise prefix sum
        vector<int> colX(n, 0);     // stores count of X in column

        int ans = 0;

        for (int i = 0; i < m; i++) {
            int currSum = 0;
            int currX = 0;

            for (int j = 0; j < n; j++) {

                int val = 0, x = 0;

                if (grid[i][j] == 'X') {
                    val = 1;
                    x = 1;
                } 
                else if (grid[i][j] == 'Y') {
                    val = -1;
                }

                // update column prefix
                colSum[j] += val;
                colX[j] += x;

                // build submatrix (0,0) → (i,j)
                currSum += colSum[j];
                currX += colX[j];

                // check conditions
                if (currSum == 0 && currX > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};