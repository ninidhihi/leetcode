class Solution {
public:
    vector<int> dp;
    vector<int> arr;
    int n, d;

    int dfs(int i) {
        if (dp[i] != -1) return dp[i];

        int ans = 1;

        // go left
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i]) break;

            ans = max(ans, 1 + dfs(j));
        }

        // go right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i]) break;

            ans = max(ans, 1 + dfs(j));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& a, int D) {
        arr = a;
        d = D;
        n = arr.size();

        dp.assign(n, -1);

        int answer = 1;

        for (int i = 0; i < n; i++) {
            answer = max(answer, dfs(i));
        }

        return answer;
    }
};