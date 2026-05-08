class Solution {
public:
    vector<int> spf;

    void sieve(int mx) {
        spf.resize(mx + 1);
        for (int i = 0; i <= mx; i++) spf[i] = i;

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    bool isPrime(int x) {
        return x >= 2 && spf[x] == x;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());
        sieve(mx);

        unordered_map<int, vector<int>> divisible;

        // store indices by prime factors
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> factors;

            while (x > 1) {
                int p = spf[x];
                factors.insert(p);
                while (x % p == 0) x /= p;
            }

            for (int p : factors) {
                divisible[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1) return d;

            // adjacent moves
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // teleport
            int val = nums[i];

            if (isPrime(val) && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for (int nxt : divisible[val]) {
                    if (nxt != i && dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        return -1;
    }
};