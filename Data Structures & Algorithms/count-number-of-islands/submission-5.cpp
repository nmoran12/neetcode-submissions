class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islandCount = 0;

        queue<pair<int, int>> waitingRoom;

        // Up, down, left, right
        vector<pair<int, int>> directions({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

        vector<vector<bool>> visited;

        // Nested loop to loop through graph
        for (int r = 0; r < rows; r++){

            for (int c = 0; c < cols; c++){

                if (grid[r][c] == "1" && grid[r][c] != visited){
                    islandCount++;

                    waitingRoom.push(grid[r][c]);

                    while (!waitingRoom.empty()){

                        auto [currRow, currCol] = waitingRoom.front();
                        waitingRoom.pop();

                        for (int dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;

                            if (newRow <= rows && newCol <= cols && grid[newRow][newCol] == "1" && grid[newRow][newCol] != visited){
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
