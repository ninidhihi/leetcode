class Solution {
public:
    void dfs(int row, int col,
             vector<vector<int>>& ans,
             const vector<vector<int>>& originalImage,
             int newColor,
             int initialColor,
             const int delRow[],
             const int delCol[])
    {
        ans[row][col] = newColor;

        int n = originalImage.size();
        int m = originalImage[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                originalImage[nrow][ncol] == initialColor &&
                ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, originalImage, newColor, initialColor, delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];

        vector<vector<int>> ans = image;

        const int delRow[] = {-1, 0, +1, 0};
        const int delCol[] = {0, +1, 0, -1};

        if (initialColor == color) {
            return image;
        }

        dfs(sr, sc, ans, image, color, initialColor, delRow, delCol);

        return ans;
    }
};