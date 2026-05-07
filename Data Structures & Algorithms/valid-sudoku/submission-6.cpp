class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> hashSet;
        unordered_set<int> rowsSet[9];
        unordered_set<int> colsSet[9];
        unordered_set<int> matrices[3][3];

        for (int i = 0; i < board.size(); i++){

            for (int j = 0; j < board.size(); j++){

                int rowsBox = i / 3;
                int colsBox = j / 3;

                if (board[i][j] == '.'){
                    continue;
                }

                if (rowsSet[i].count(board[i][j])){
                    return false;
                } else {
                rowsSet[i].insert(board[i][j]);
                };

                if (colsSet[j].count(board[i][j])){
                    return false;
                } else {
                    colsSet[j].insert(board[i][j]);
                };

            if (matrices[rowsBox][colsBox].count(board[i][j])){
                return false;
            } else {
                matrices[rowsBox][colsBox].insert(board[i][j]);
            };
            };


        }



        return true;
    }
};
