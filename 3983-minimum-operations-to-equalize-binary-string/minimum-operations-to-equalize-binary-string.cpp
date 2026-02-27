class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        
        int startZ = 0;
        for (char c : s)
            if (c == '0')
                startZ++;
        
        if (startZ == 0) return 0;
        
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        set<int> evenSet, oddSet;
        
        for (int i = 0; i <= n; i++) {
            if (i % 2 == 0) evenSet.insert(i);
            else oddSet.insert(i);
        }
        
        q.push(startZ);
        dist[startZ] = 0;
        
        if (startZ % 2 == 0)
            evenSet.erase(startZ);
        else
            oddSet.erase(startZ);
        
        while (!q.empty()) {
            int z = q.front();
            q.pop();
            
            int minF = max(0, k - (n - z));
            int maxF = min(k, z);
            
            int min_new_z = z + k - 2 * maxF;
            int max_new_z = z + k - 2 * minF;
            
            // parity of newZ = (z + k) % 2
            set<int>& currSet = ((z + k) % 2 == 0) ? evenSet : oddSet;
            
            auto it = currSet.lower_bound(min_new_z);
            
            while (it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;
                
                dist[newZ] = dist[z] + 1;
                
                if (newZ == 0)
                    return dist[newZ];
                
                q.push(newZ);
                
                it = currSet.erase(it);   // ⭐ CRITICAL FIX
            }
        }
        
        return -1;
    }
};