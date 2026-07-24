class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int, int>> toVisit;

        // Directions: Up, Down, Left, Right
        vector<pair<int, int>> directions({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});



        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){

                if (grid[r][c] == 0){

                // Queue must hold COORDINATES, not grid values
                    toVisit.push({r, c});

                    while (!toVisit.empty()){

                        auto [currRow, currCol] = toVisit.front();
                        toVisit.pop();

                        for (auto dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;

                            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols){
                                continue;
                            }

                            if (grid[newRow][newCol] != INF){
                                continue;
                            }

                            // This sets the neighbour's cell distance to be 1 more than the current cell distance
                            // Because we are moving 1 forward, we need to make it current cell + 1
                            grid[newRow][newCol] = grid[currRow][currCol] + 1;
                            toVisit.push({newRow, newCol});
                        }

                    }
                }

            }
        }
        
    }
};
