class Solution {
public:
    string ans = "";
    int count = 0;

    void backtrack(int n, int k, string &curr) {
        if(curr.size() == n) {
            count++;
            if(count == k) ans = curr;
            return;
        }

        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                backtrack(n, k, curr);
                curr.pop_back();
            }
            if(!ans.empty()) return; // stop early
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        backtrack(n, k, curr);
        return ans;
    }
};