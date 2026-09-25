class Solution {
public:

    string s;
    int i = 0;

    set<string> concat(set<string> A, set<string> B) {

        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    // Parses concatenation
    set<string> parseConcat() {

        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> current;

            if (s[i] == '{') {
                i++;  // skip {

                current = parseUnion();

                i++;  // skip }
            }
            else {
                current.insert(string(1, s[i]));
                i++;
            }

            result = concat(result, current);
        }

        return result;
    }

    // Parses union
    set<string> parseUnion() {

        set<string> result;

        while (true) {

            set<string> current = parseConcat();

            result.insert(current.begin(), current.end());

            if (i >= s.size() || s[i] == '}')
                break;

            // s[i] == ','
            i++;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        i = 0;

        set<string> ans = parseUnion();

        return vector<string>(ans.begin(), ans.end());
    }
};