class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> vals;

            int top = layer, left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top row
            for (int j = left; j <= right; j++)
                vals.push_back(grid[top][j]);

            // right column
            for (int i = top + 1; i <= bottom - 1; i++)
                vals.push_back(grid[i][right]);

            // bottom row
            for (int j = right; j >= left; j--)
                vals.push_back(grid[bottom][j]);

            // left column
            for (int i = bottom - 1; i >= top + 1; i--)
                vals.push_back(grid[i][left]);

            int len = vals.size();
            int rot = k % len;

            vector<int> rotated(len);

            // counter-clockwise rotation
            for (int i = 0; i < len; i++) {
                rotated[i] = vals[(i + rot) % len];
            }

            int idx = 0;

            // put back top row
            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            // put back right column
            for (int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = rotated[idx++];

            // put back bottom row
            for (int j = right; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            // put back left column
            for (int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};