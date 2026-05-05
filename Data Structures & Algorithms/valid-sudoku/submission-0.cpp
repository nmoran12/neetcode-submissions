class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowsSet[9];
        unordered_set<char> colsSet[9];

        unordered_set<char> boxes[3][3];



        // Outer For Loop checks rows, inner for loop checks cols
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                // if an index just contains the empty placeholder '.', just skip it
                if (board[i][j] == '.'){
                    continue;
                }

                // if value already exists in rows unordered_set (therefore it is a duplicate) return false
                if (rowsSet[i].count(board[i][j]) == 1){
                    return false;
                }
                // add value to rowsSet
                rowsSet[i].insert(board[i][j]);


                    int boxRows = i / 3;
                    int boxCols = j / 3;

                // if value already exists in cols unordered_set (therefore it is a duplicate) return false
                if (colsSet[j].count(board[i][j]) == 1){
                    return false;
                }
                // add value to colsSet
                colsSet[j].insert(board[i][j]);

                // If the current index at i and j, both divided by 3 to get the box it is in, already exists, we have duplicate
                // so return false
                if (boxes[boxRows][boxCols].count(board[i][j]) == 1){
                    return false;
                }

                // otherwise add it to the boxes hash set.
                boxes[boxRows][boxCols].insert(board[i][j]);


            }
        }


        return true;
    }
};
