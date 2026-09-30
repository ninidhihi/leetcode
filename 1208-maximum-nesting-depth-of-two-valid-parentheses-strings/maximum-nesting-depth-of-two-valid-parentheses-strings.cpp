class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer;
        
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;

                // Assign based on the new depth
                answer.push_back(depth % 2);
            } 
            else {
                // For ')' it belongs to the same depth
                // as the matching '('
                answer.push_back(depth % 2);

                depth--;
            }
        }

        return answer;
    }
};