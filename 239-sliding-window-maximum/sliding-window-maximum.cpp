class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;
        vector<int> result;

        for(int i = 0; i < n; i++) {

            // Remove indices out of current window
            while(!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // Remove smaller elements
            while(!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            // Push current index
            deq.push_back(i);

            // Store answer
            if(i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};