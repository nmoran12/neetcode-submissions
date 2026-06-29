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

                if (grid[r][c] == '1' && !visited[r][c]){
                    islandCount++;

                    // We push {r, c} NOT grid[r][c] because {r, c} gives you the coordinates/location of where it is on the grid, whereas
                    // grid[r][c] just gives you the value i.e. grid[r][c] would be '1' or '0'
                    // We want the coordinate in our waiting room so we know exactly where to look, if we just put '1' or '0' into waiting room
                    // it would have no idea where we still actually have to look.
                    // By pushing {r, c} into the queue, you are saying, "Remember to go back and check the neighbors of the house at Row 2, Column 3."
                    waitingRoom.push({r, c});
                    visited[r][c] = true;

                    while (!waitingRoom.empty()){

                        auto [currRow, currCol] = waitingRoom.front();
                        waitingRoom.pop();

                        for (auto dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;

                            if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                                waitingRoom.push({newRow, newCol});
                                visited[newRow][newCol] = true;
                            }
                        }
                    }
                }
            }
        }
        

        return islandCount;
    }
};
