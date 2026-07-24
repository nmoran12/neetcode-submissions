class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; i < rows; i++){
            for (int c = 0; j < cols; j++){
                if (dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        
        return false;
    }


    int dfs(vector<vector<int>> board, string word, int r, int c, int i){

        if (word[i] == word.size()){
            return true;
        }

        if (r < 0 || c < 0 || r <= rows || c <= cols || word[i] != board[r][c]){
            return false;
        }

        int temp = board[r][c];
        board[r][c] = '#';


        int explore = dfs((board, word, r + 1, c, 0)), dfs(board, word, r - 1, c, 0), dfs(board, word, r, c + 1, 0), dfs(board, word, r, c - 1, 0);

        board[r][c] = temp;


        return explore;
    }
};
