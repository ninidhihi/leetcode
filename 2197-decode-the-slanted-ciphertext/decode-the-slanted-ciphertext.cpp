class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.size();
        int cols = n / rows;
        
        // Step 1: build matrix
        vector<vector<char>> mat(rows, vector<char>(cols));
        int idx = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }
        
        // Step 2: read diagonally
        string result = "";
        
        for (int j = 0; j < cols; j++) {
            int i = 0, k = j;
            while (i < rows && k < cols) {
                result += mat[i][k];
                i++;
                k++;
            }
        }
        
        // Step 3: remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};