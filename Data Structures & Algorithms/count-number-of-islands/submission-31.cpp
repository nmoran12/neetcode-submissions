class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int, int>> myQueue;
        int islandCount = 0;

        vector<vector<int>> directions({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){

                if (grid[r][c] == '1' && !visited[r][c]){
                    
                    visited[r][c] = true;
                    myQueue.push({r, c});
                    islandCount++;

                    while (!myQueue.empty()){

                        myQueue.front();
                        myQueue.pop();

                        for (auto [currRow, currCol] : directions){
                            int newRow = currRow + dir.first;
                            int newCol = currRow + dir.second;

                            if (newRow > 0 && newRow <= rows && newCol > 0 && newCol <= cols && !visited[newRow][newCol] && grid[newRow][newCol] == '1'){
                                myQueue.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }

        return islandCount;
    }
};
