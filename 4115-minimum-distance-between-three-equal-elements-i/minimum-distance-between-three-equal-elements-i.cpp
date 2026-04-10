class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &p : mp) {
            vector<int> &v = p.second;
            int m = v.size();

            if (m < 3) continue;

            for (int i = 0; i < m; i++) {
                for (int k = i + 2; k < m; k++) { // at least 3 indices
                    int dist = 2 * (v[k] - v[i]);
                    ans = min(ans, dist);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};