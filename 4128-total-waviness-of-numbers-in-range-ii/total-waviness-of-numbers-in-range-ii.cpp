class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][3][11][11];
    bool vis[20][3][11][11];

    Node dfs(int pos, bool tight, int state, int prev2, int prev1) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][state][prev2][prev1]) {
            return dp[pos][state][prev2][prev1];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (state == 0) {
                if (d == 0) {
                    Node nxt = dfs(pos + 1, ntight, 0, 10, 10);
                    ans.cnt += nxt.cnt;
                    ans.sum += nxt.sum;
                } else {
                    Node nxt = dfs(pos + 1, ntight, 1, 10, d);
                    ans.cnt += nxt.cnt;
                    ans.sum += nxt.sum;
                }
            }
            else if (state == 1) {
                Node nxt = dfs(pos + 1, ntight, 2, prev1, d);
                ans.cnt += nxt.cnt;
                ans.sum += nxt.sum;
            }
            else { // state == 2 (have at least two digits)
                int add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;

                Node nxt = dfs(pos + 1, ntight, 2, prev1, d);

                ans.cnt += nxt.cnt;
                ans.sum += nxt.sum + nxt.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][state][prev2][prev1] = true;
            dp[pos][state][prev2][prev1] = ans;
        }

        return ans;
    }

    long long solve(long long N) {
        if (N < 0) return 0;

        s = to_string(N);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};