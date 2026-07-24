class Solution {
public:

    void capture(vector<vector<char>>& board, int r, int c){
        // Base Case 1: If we go out of bounds or if current cell is NOT an 'O'
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O'){
            return;
        }

        // Mark
        board[r][c] = 'T';

        capture(board, r, c - 1); // left
        capture(board, r, c + 1); // right
        capture(board, r - 1, c); // up
        capture(board, r + 1, c); // down

    }


    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // 1. (DFS) Capture unsurrounded regions (O -> T)
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                // Check if we are on the borders
                if (board[r][c] == 'O' && ((board[0][c] || board[rows - 1][c]) || (board[r][0] || board[r][cols - 1]))){
                    capture(board, r, c);
                }

            }
        }




        // 2. Capture surrounded regions (O -> X)
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }


        // 3. Change all T's back to O's
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (board[r][c] == 'T'){
                    board[r][c] = 'O';
                }
            }
        }
    }
};
