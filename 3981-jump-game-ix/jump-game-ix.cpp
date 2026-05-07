class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int l = 0;

        while (l < n) {
            int r = l;

            while (r < n - 1 && prefMax[r] > suffMin[r + 1]) {
                r++;
            }

            int mx = 0;

            for (int i = l; i <= r; i++) {
                mx = max(mx, nums[i]);
            }

            for (int i = l; i <= r; i++) {
                ans[i] = mx;
            }

            l = r + 1;
        }

        return ans;
    }
};