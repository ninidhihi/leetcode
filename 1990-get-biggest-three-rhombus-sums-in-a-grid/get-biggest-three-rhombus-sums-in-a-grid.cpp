class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // size = 0 rhombus
                st.insert(grid[i][j]);

                for(int k = 1; ; k++) {

                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n)
                        break;

                    int sum = 0;

                    int x = i-k, y = j;

                    // top -> right
                    while(x < i && y < j+k) {
                        sum += grid[x][y];
                        x++; y++;
                    }

                    // right -> bottom
                    while(x < i+k && y > j) {
                        sum += grid[x][y];
                        x++; y--;
                    }

                    // bottom -> left
                    while(x > i && y > j-k) {
                        sum += grid[x][y];
                        x--; y--;
                    }

                    // left -> top
                    while(x > i-k && y < j) {
                        sum += grid[x][y];
                        x--; y++;
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans(st.rbegin(), st.rend());
        if(ans.size() > 3) ans.resize(3);
        return ans;
    }
};