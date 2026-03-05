class Solution {
public:
    int minOperations(string s) {
        int start0 = 0, start1 = 0;
        
        for(int i = 0; i < s.size(); i++) {
            // pattern starting with '0' -> 010101...
            if(s[i] != (i % 2 ? '1' : '0'))
                start0++;
            
            // pattern starting with '1' -> 101010...
            if(s[i] != (i % 2 ? '0' : '1'))
                start1++;
        }
        
        return min(start0, start1);
    }
};