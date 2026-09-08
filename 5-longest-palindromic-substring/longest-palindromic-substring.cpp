class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            // After the loop:
            // actual palindrome is from left + 1 to right - 1
            int len = right - left - 1;

            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expand(i, i);

            // Even length palindrome
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};