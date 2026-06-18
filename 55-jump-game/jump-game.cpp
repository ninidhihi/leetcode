class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxx)
                return false;

            maxx = max(maxx, i + nums[i]);

            if (maxx >= nums.size() - 1)
                return true;
        }

        return true;
    }
};