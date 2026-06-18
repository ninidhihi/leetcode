class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int end = 0;
        int lastt = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            lastt = max(lastt, i + nums[i]);

            if (i == end) {
                jump++;
                end = lastt;
            }
        }

        return jump;
    }
};
