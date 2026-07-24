class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()){
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>> directions({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        int islandCount = 0;


        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> toBeVisited;

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){

                if (grid[r][c] == '1' && !isVisited[r][c]){
                    islandCount++;
                    toBeVisited.push({r, c});
                    // Make sure to push the first index, otherwise the while loop will fail.
                    isVisited[currRow][currCol] = true;

                    while (!toBeVisited.empty()){

                        auto [currRow, currCol] = toBeVisited.front();
                        toBeVisited.pop();

                        for (dir : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currCol + dir.second;
                        }

                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && isVisited[newRow][newCol] && grid[newRow][newCol] == '1'){
                            // i think im forgetting something here, but cant remember
                            isVisited[newRow][newCol] = true;
                            toBeVisited.push({newRow, newCol});
                        }
                
                    }
                };
            }
        }
        

        return islandCount;
    }
};
