class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF = 2147483647;

        // You push the cells that have neighbours that still need to be explored into this
        // So treasure chests need to be explored, so we push them in
        // But LAND that still needs to be explored, we push that in too.
        queue<pair<int, int>> toVisit;

        int rows = grid.size();
        int cols = grid[0].size();

        // Up, down, left, right
        vector<pair<int, int>> directions({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

        // Scan the grid
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 0){
                    toVisit.push({r, c});
                }
            }
        }


        // While there are still treasure chests to process
        while (!toVisit.empty()){

            auto [currRow, currCol] = toVisit.front();
            toVisit.pop();
            
            
            for (auto dir : directions){
                int newRow = currRow + dir.first;
                int newCol = currCol + dir.second;

                // If the next place we are going to BFS to is out of bounds, just skip it and go to next direction.
                // “This neighbour is invalid, skip it and try the next direction.”
                // Example: if current cell is (0, 0):
                // up    -> (-1, 0) invalid, continue
                // down  -> (1, 0) valid, process it
                // left  -> (0, -1) invalid, continue
                // right -> (0, 1) valid, process it
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols){
                    continue;
                }

                // If current location is not a land cell, just skip it and try the next direction
                // If this neighbour is not land, skip it.
                // Otherwise, it must be untouched land.
                if (grid[newRow][newCol] != INF){
                    continue;
                }
                    // So update its distance and add it to the queue.
                    grid[newRow][newCol] = grid[currRow][currCol] + 1;
                    toVisit.push({newRow, newCol});


            }




        }
        
    }
};
