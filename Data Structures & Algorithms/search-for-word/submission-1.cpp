class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Try to start the word search from every single cell on the board
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int i) {
        // Base Case 1: Successfully matched every letter in the word
        if (i == word.length()) {
            return true;
        }
        
        // Base Case 2: Out of bounds OR character mismatch
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i]) {
            return false;
        }
        
        // Step 1: Mark the current cell as visited by saving and changing its character
        char temp = board[r][c];
        board[r][c] = '#'; 
        
        // Step 2: Explore all 4 adjacent directions (Down, Up, Right, Left)
        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);
        
        // Step 3: Backtrack - restore the original character for other search paths
        board[r][c] = temp;
        
        return found;
    }
};