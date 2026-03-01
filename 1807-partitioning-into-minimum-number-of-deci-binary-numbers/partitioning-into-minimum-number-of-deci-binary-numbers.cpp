class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        
        for(char c : n) {
            maxDigit = max(maxDigit, c - '0');
            
            if(maxDigit == 9)   // early stop optimization
                return 9;
        }
        
        return maxDigit;
    }
};