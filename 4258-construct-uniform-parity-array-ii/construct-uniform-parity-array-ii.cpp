class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }

        // If there are no odd numbers,
        // all numbers are already even.
        if (minOdd == INT_MAX) {
            return true;
        }

        // Try to make everything odd.
        for (int x : nums1) {
            if (x % 2 == 0) {
                // even - odd = odd
                // Need a smaller odd number.
                if (minOdd >= x) {
                    return false;
                }
            }
        }

        return true;
    }
};