#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        // If string too short, impossible
        if (n < (1 << k)) 
            return false;
        
        unordered_set<string> st;
        
        for (int i = 0; i <= n - k; i++) {
            st.insert(s.substr(i, k));
            
            // Early exit optimization
            if (st.size() == (1 << k))
                return true;
        }
        
        return false;
    }
};