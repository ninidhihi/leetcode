class RangeModule {
public:
    map<int, int> mp;

    RangeModule() {
    }

    void addRange(int left, int right) {
        auto it = mp.lower_bound(left);

        // Check previous interval for overlap
        if (it != mp.begin()) {
            auto previous = prev(it);

            if (previous->second >= left) {
                left = min(left, previous->first);
                right = max(right, previous->second);
                it = previous;
            }
        }

        // Merge all overlapping intervals
        while (it != mp.end() && it->first <= right) {
            right = max(right, it->second);
            it = mp.erase(it);
        }

        mp[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);

        if (it == mp.begin())
            return false;

        --it;

        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = mp.lower_bound(left);

        // Check previous interval
        if (it != mp.begin()) {
            auto previous = prev(it);

            if (previous->second > left) {
                int oldStart = previous->first;
                int oldEnd = previous->second;

                it = mp.erase(previous);

                // Keep left part
                if (oldStart < left)
                    mp[oldStart] = left;

                // Keep right part
                if (right < oldEnd)
                    mp[right] = oldEnd;
            }
        }

        // Remove overlapping intervals
        while (it != mp.end() && it->first < right) {
            int oldEnd = it->second;

            it = mp.erase(it);

            // Keep right part
            if (oldEnd > right) {
                mp[right] = oldEnd;
                break;
            }
        }
    }
};