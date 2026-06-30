class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();

        // A fruit gets put in 'toVisit' if its rotten, because we need to go to it and then BFS to spread its rottenness
        queue<pair<int, int>> toVisit;

        // Also contains rotten fruit, but its the ones we have already processed, or are waiting to be processed
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

        // Phase 2: BFS out from rotten fruit to infect fresh fruits
        while (!toVisit.empty() && freshFruit > 0){
        

                    int layerSize = toVisit.size();

                    for (int i = 0; i < layerSize; i++){

                        auto [currRow, currCol] = toVisit.front();
                        toVisit.pop();
                        for (auto dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;


                            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
                            !visited[newRow][newCol] && grid[newRow][newCol] == 1){
                                visited[newRow][newCol] = true;
                                grid[newRow][newCol] = 2;
                                freshFruit--;
                                toVisit.push({newRow, newCol});
                            }
                        }
                    }
                    minutes++;
            }
                                if (toVisit.empty() && freshFruit > 0){
                        return -1;
                    } else {
                        return minutes;
                    }
        }

    };
