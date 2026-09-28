class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (char c : s) {

            if (c == '(') {
                // Save what we have before '('
                st.push(curr);
                curr = "";
            }
            else if (c == ')') {
                // Reverse the content inside parentheses
                reverse(curr.begin(), curr.end());

                // Attach it to the previous string
                curr = st.top() + curr;
                st.pop();
            }
            else {
                // Normal character
                curr += c;
            }
        }

        return curr;
    }
};