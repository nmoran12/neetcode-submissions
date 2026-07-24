class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();

        // A fruit is visited if it is rotten
        queue<pair<int, int>> toVisit;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        vector<pair<int, int>> directions({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

        int minutes = 0;
        int freshFruit = 0;

        // Phase 1: Scan the grid to find fresh fruit and rotten fruits.
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){

                if (grid[r][c] == 1){
                    freshFruit++;
                }


                if (grid[r][c] == 2){
                    toVisit.push({r, c});
                    visited[r][c] = true;
                };
            };
        };

        while (!visited.empty() && freshFruit > 0){
        

                    int layerSize = toVisit.size();

                    for (int i = 0; i < layerSize; i++){

                        auto [currRow, currCol] = toVisit.front();
                        toVisit.pop();
                        for (auto dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;


                            if (newRow < rows && newRow > 0 && newCol < cols && newCol > 0 && !visited[newRow][newCol]){
                                visited[newRow][newCol] = true;
                                freshFruit--;
                                toVisit.push({newRow, newCol});
                            }
                        }
                    }
                    minutes++;
            }
            return minutes;
        }

    };
