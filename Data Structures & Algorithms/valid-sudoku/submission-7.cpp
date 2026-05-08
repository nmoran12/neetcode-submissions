class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<int> hashSet;
        unordered_set<int> rowsSet[9];
        unordered_set<int> colsSet[9];
        unordered_set<int> matrix[3][3];

        for (int i = 0; i < board.size(); i++){


            for (int j = 0; j < board.size(); j++){

                if (board[i][j] == '.'){
                    continue;
                }

                int rowsDiv = i / 3;
                int colsDiv = j / 3;

                if (rowsSet[i].count(board[i][j])){
                    return false;
                }
                rowsSet[i].insert(board[i][j]);

                if (colsSet[j].count(board[i][j])){
                    return false;
                }
                colsSet[j].insert(board[i][j]);

                if (matrix[rowsDiv][colsDiv].count(board[i][j])){
                    return false;
                }
                matrix[rowsDiv][colsDiv].insert(board[i][j]);


            }
        }
        
        return true;
    }
};
