//most frequent char shoukd be mapped first
//we can also use heapmap 
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counts(26, 0);

        // Count frequency of each letter
        for (char c : word) {
            counts[c - 'a']++;
        }

        // Sort frequencies in descending order
        sort(counts.begin(), counts.end(), greater<int>());

        int res = 0;

        // Calculate minimum pushes
        for (int i = 0; i < 26; i++) {
            res += counts[i] * (1 + i / 8);
        }

        return res;
    }
};