class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> randi(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                randi[i] = randi[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                randi[i] = max(randi[i], randi[i + 1] + 1);
            }
        }

        int total = 0;
        for (int c : randi)
            total += c;

        return total;
    }
};

