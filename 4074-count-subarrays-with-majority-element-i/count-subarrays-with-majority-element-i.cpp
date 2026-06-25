class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                // +1 for target, -1 for others
                if (nums[j] == target)
                    sum++;
                else
                    sum--;

                // target is majority iff transformed sum > 0
                if (sum > 0)
                    ans++;
            }
        }

        return ans;
    }
};