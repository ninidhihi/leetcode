#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(int a, int b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        
        if (countA == countB)
            return a < b;   // If same number of 1s, sort normally
        
        return countA < countB;  // Sort by number of 1s
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};