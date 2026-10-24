
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

    void backtrack(vector<string>& ans, string curr,
                   int open, int close, int n) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if we still have opening brackets available
        if (open < n) {
            backtrack(ans, curr + '(', open + 1, close, n);
        }

        // Add ')' only if it won't make the string invalid
        if (close < open) {
            backtrack(ans, curr + ')', open, close + 1, n);
        }
    }
};
