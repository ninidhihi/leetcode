class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case
        if (n == 1) return '0';
        
        int mid = 1 << (n - 1);  // 2^(n-1)
        
        if (k == mid) {
            return '1';
        }
        else if (k < mid) {
            return findKthBit(n - 1, k);
        }
        else {
            int mirrored = (1 << n) - k;
            char bit = findKthBit(n - 1, mirrored);
            
            // invert the bit
            return (bit == '0') ? '1' : '0';
        }
    }
};