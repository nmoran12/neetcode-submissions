class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        
        return false;
    }


    int dfs(vector<vector<char>>& board, string word, int r, int c, int i){

        if (word[i] == word.size()){
            return true;
        }

        if (r < 0 || c < 0 || r <= board.size() || c <= board[0].size() || i != word.size()){
            return false;
        }

        int temp = board[r][c];
        board[r][c] = '#';


        int explore = dfs(board, word, r + 1, c, i + 1) ||
                    dfs(board, word, r - 1, c, i + 1) ||
                    dfs(board, word, r, c + 1, i + 1) ||
                    dfs(board, word, r, c - 1, i + 1);

        board[r][c] = temp;


        return explore;
    }
};
