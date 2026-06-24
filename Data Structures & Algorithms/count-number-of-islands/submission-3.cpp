class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        // Stores [row][col] of visited land.
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        // int, int because we are storing [row][col] of a node to visit
        queue<pair<int, int>> waitingRoom;
        int islandCount = 0;

        // Directions: down, up, left, right
        vector<pair<int, int>> directions({{1, 0}, {-1, 0}, {0, -1}, {0, 1}});

        // Loop through the grid to find a cell is that both an island, and not in visited yet
        for (int r = 0; r < grid.size(); r++){

            for (int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == '1' && !visited[r][c]){
                    islandCount++;
                    
                    visited[r][c] = true;

                    waitingRoom.push({r, c});
                    // Now we can execute searching up, down, left, right

                    while (!waitingRoom.empty()){
                        auto [currRow, currCol] = waitingRoom.front();
                        waitingRoom.pop();

                        for (auto dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;

                            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                                visited[newRow][newCol] = true;
                                waitingRoom.push({newRow, newCol});
                            }
                        }
                    }


                }
            }
        }
        

        return islandCount;
    }
};
