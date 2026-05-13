class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


        unordered_set<char> rowsVect[9];
        unordered_set<char> colsVect[9];
        unordered_set<char> matrices[3][3];

        for (int i = 0; i < board.size(); i++){

            for (int j = 0; j < board.size(); j++){

                int rowsDiv = i / 3;
                int colsDiv = j / 3;

                if (board[i][j] == '.'){
                    continue;
                }


                if (rowsVect[i].count(board[i][j]) == 1){
                    return false;
                }
                rowsVect[i].insert(board[i][j]);


                if (colsVect[j].count(board[i][j])){
                    return false;
                }
                colsVect[j].insert(board[i][j]);



                if (matrices[rowsDiv][colsDiv].count(board[i][j]) == 1){
                    return false;
                }
                matrices[rowsDiv][colsDiv].insert(board[i][j]);
            }
        }
        
        return true;
    }
};
