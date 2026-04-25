#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can(vector<long long>& extended, int n, int k, long long d, long long L) {
        for (int i = 0; i < n; i++) {
            int count = 1;
            long long pos = extended[i];
            int idx = i;

            for (int cnt = 1; cnt < k; cnt++) {
                long long target = pos + d;

                auto it = lower_bound(extended.begin() + idx + 1,
                                      extended.begin() + i + n,
                                      target);

                if (it == extended.begin() + i + n) {
                    count = -1;
                    break;
                }

                idx = it - extended.begin();
                pos = extended[idx];
                count++;
            }

            // circular check
            if (count == k && (extended[i] + L - pos) >= d)
                return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;
        long long L = 4LL * side;

        // map to perimeter
        for (auto &p : points) {
            int x = p[0], y = p[1];

            if (y == 0) arr.push_back(x);
            else if (x == side) arr.push_back(side + y);
            else if (y == side) arr.push_back(2LL * side + (side - x));
            else arr.push_back(3LL * side + (side - y));
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();

        // extend for circular handling
        vector<long long> extended = arr;
        for (auto x : arr) extended.push_back(x + L);

        long long low = 0, high = L, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (can(extended, n, k, mid, L)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};