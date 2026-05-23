#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        // Count the number of "breaks" in the non-decreasing order.
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }

        // If there are zero breaks, the array is already sorted.
        // If there is one break, we must also check if the last element
        // is less than or equal to the first, to close the circle.
        if (count == 0) {
            return true;
        } else if (count == 1) {
            if (nums[n - 1] <= nums[0]) {
                return true;
            }
        }
        
        return false;
    }
};