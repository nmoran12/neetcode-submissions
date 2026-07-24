class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();

        int islandCount = 0;

        queue<pair<int, int>> waitingRoom;

        // Up, down, left, right
        vector<pair<int, int>> directions({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

        // REMEMBER: We have a vector<bool> of size cols, initialised to false, then we create a number of rows of that
        // So we have [false, false, false]
        // and then if 'rows' was 3 it becomes:
        // [false, false, false]
        // [false, false, false]
        // [false, false, false]
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Nested loop to loop through graph
        for (int r = 0; r < rows; r++){

            for (int c = 0; c < cols; c++){

                if (grid[r][c] == '1' && grid[r][c] != visited[r][c]){
                    islandCount++;

                    waitingRoom.push({r, c});
                    visited[r][c] = true;

                    while (!waitingRoom.empty()){

                        auto [currRow, currCol] = waitingRoom.front();
                        waitingRoom.pop();

                        for (auto dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;

                            if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && grid[newRow][newCol] == '1' && grid[newRow][newCol] != visited[r][c]){
                                waitingRoom.push(grid[newRow][newCol]);
                            }
                        }
                    }
                }
            }
        }
        

        return islandCount;
    }
};
