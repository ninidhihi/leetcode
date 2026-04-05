class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, d = 0, l = 0, r = 0;
        
        for(char move : moves) {
            if(move == 'U') u++;
            else if(move == 'D') d++;
            else if(move == 'L') l++;
            else if(move == 'R') r++;
        }
        
        return (u == d && l == r);
    }
};