class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        int n = s.size();

        // dp[i] = number of distinct subsequences
        // including the empty subsequence
        // using first i characters
        vector<long long> dp(n + 1, 0);

        dp[0] = 1; // empty subsequence

        // Last occurrence of each character
        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';

            // Add the new character to every existing subsequence
            dp[i] = (2 * dp[i - 1]) % MOD;

            // If this character appeared before,
            // remove the duplicate subsequences
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c]] + MOD) % MOD;
            }

            last[c] = i - 1;
        }

        // Remove the empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};