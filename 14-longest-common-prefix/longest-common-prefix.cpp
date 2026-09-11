class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;

            // Compare prefix with current string
            while (j < prefix.size() &&
                   j < strs[i].size() &&
                   prefix[j] == strs[i][j]) {
                j++;
            }

            // Keep only the matching part
            prefix = prefix.substr(0, j);

            // No common prefix
            if (prefix.empty()) {
                return "";
            }
        }

        return prefix;
    }
};