class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Even indices
        string s1_even = {s1[0], s1[2]};
        string s2_even = {s2[0], s2[2]};
        
        // Odd indices
        string s1_odd = {s1[1], s1[3]};
        string s2_odd = {s2[1], s2[3]};
        
        sort(s1_even.begin(), s1_even.end());
        sort(s2_even.begin(), s2_even.end());
        sort(s1_odd.begin(), s1_odd.end());
        sort(s2_odd.begin(), s2_odd.end());
        
        return s1_even == s2_even && s1_odd == s2_odd;
    }
};