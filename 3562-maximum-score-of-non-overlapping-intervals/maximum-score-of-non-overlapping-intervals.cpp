class Solution {
public:
    struct State {
        long long score;
        vector<int> indices;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return lexicographical_compare(
            a.indices.begin(), a.indices.end(),
            b.indices.begin(), b.indices.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint
        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        // ends[i] = right endpoint of interval i
        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        /*
            prev[i] = number of intervals among [0 ... i-1]
                       that can come before interval i.

            We need:
                a[j].right < a[i].left

            upper_bound(left - 1) gives exactly that.
        */
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(ends.begin(), ends.end(), a[i][0])
                - ends.begin();
        }

        /*
            dp[i][k]:
            best answer using first i intervals,
            choosing at most k intervals.

            dp[i][k] considers intervals [0 ... i-1].
        */
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5, {0, {}})
        );

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip interval i-1
                State skip = dp[i - 1][k];

                // Option 2: take interval i-1
                State take = dp[prev[i - 1]][k - 1];

                take.score += a[i - 1][2];
                take.indices.push_back((int)a[i - 1][3]);

                // We need indices sorted for lexicographical comparison
                sort(take.indices.begin(), take.indices.end());

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[n][4].indices;
    }
};