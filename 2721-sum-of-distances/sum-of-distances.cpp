class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        // Step 2: process each group
        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int k = pos.size();
            
            vector<long long> prefix(k + 1, 0);
            for (int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + pos[i];
            }
            
            for (int i = 0; i < k; i++) {
                long long left = (long long)i * pos[i] - prefix[i];
                long long right = (prefix[k] - prefix[i + 1]) - (long long)(k - i - 1) * pos[i];
                
                ans[pos[i]] = left + right;
            }
        }
        
        return ans;
    }
};