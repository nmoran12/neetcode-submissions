class Solution {
public:

    int dfs(int rows, int cols, int i){
        // If our iterator is equal to length of word, we have reached end of word and thus have found every letter, return true
        if (i == word.length()){
            return 1;
        }

        // Check for ALL INVALID CASES
        if (r < 0 || c < 0 || r >= rows || c >= cols || word[i] != board[r][c] || board[r][c] == visitedIndexes.count(r)){
            return 0;
        }

        visitedIndexes.insert({r, c});
        int results = (dfs(r + 1, c, i + 1) || dfs(r - 1, c, i + 1) || dfs(r, c + 1, i + 1) || dfs(r, c - 1, i + 1));

        visitedIndexes.erase({r, c});



        return results;
    }


    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<int, int> visitedIndexes;
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (dfs(r, c, 0)){
                    return true;
                }
            }
        }


        return false;        
    }
};
