class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // reversed value -> latest index
        int minDist = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            // check if current number matches any previous reversed
            if (mp.find(nums[j]) != mp.end()) {
                minDist = min(minDist, j - mp[nums[j]]);
            }

            // store reverse of current number
            int rev = reverseNum(nums[j]);
            mp[rev] = j;
        }

        return (minDist == INT_MAX) ? -1 : minDist;
    }
};