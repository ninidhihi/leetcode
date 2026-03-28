class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        parent.resize(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        // Step 1: Union indices
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        // Step 2: Assign characters
        unordered_map<int, char> mp;
        char ch = 'a';

        string word(n, '#');

        for(int i = 0; i < n; i++) {
            int root = find(i);
            if(mp.find(root) == mp.end()) {
                if(ch > 'z') return "";
                mp[root] = ch++;
            }
            word[i] = mp[root];
        }

        // Step 3: Validate using DP
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(word[i] == word[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = 0;
                }

                if(dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return word;
    }
};