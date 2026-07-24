class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int, int>> waitingRoom;

        // Directions: Down, Up, Right, Left
        vector<pair<int, int>> directions({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

        int maximumArea = 0;

        for (int r = 0; r < rows; r++){

            for (int c = 0; c < cols; c++){

                if (grid[r][c] == 1 && !visited[r][c]){
                    int currentArea = 0;
                    visited[r][c] = true;
                    waitingRoom.push({r, c});

                while (!waitingRoom.empty()){

                    currentArea++;

                    auto [currRow, currCol] = waitingRoom.front();

                    waitingRoom.pop();

                    waitingRoom.push(grid[r][c]);

                    for (auto dir : directions){
                        int newRow = currRow + dir.first;
                        int newCol = currCol + dir.second;


                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol] && grid[newRow][newCol] == '1'){
                            waitingRoom.push({newRow, newCol});
                            visited[newRow][newCol] = true;
                        }
                    };
                    };
                        maximumArea = max(maximumArea, currentArea);
                }
            }
        }
        

        return maximumArea;
    }
};
