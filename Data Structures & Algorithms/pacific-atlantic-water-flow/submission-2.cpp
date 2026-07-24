class Solution {
public:

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& isVisited, int r, int c, int previousHeight){

        // Base Case: If it goes out of bounds, is not land, or is already visited
        if (r < 0 || r > heights.size() || c < 0 || c > heights[0].size() || heights[r][c] == 0 || isVisited[r][c]){
            return;
        }

        if (heights[r][c] < previousHeight){
            return;
        }

        // Mark it as visited
        isVisited[r][c] = true;

        // Recurse up, down, left, right
        dfs(heights, isVisited, r, c - 1, heights[r][c]); // Left
        dfs(heights, isVisited, r, c + 1, heights[r][c]); // Right
        dfs(heights, isVisited, r - 1, c, heights[r][c]); // Up
        dfs(heights, isVisited, r + 1, c, heights[r][c]); // Down

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int previousHeight = 0;

        vector<vector<bool>>& isVisited;

        vector<vector<bool>> atlanticMatrix(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacificMatrix(rows, vector<bool>(cols, false));

        dfs(heights, isVisited, 0, 0, previousHeight);

        dfs(heights, isVisited, rows - 1, cols - 1, previousHeight);

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if ((atlanticMatrix[r][c] && pacificMatrix[r][c]) == true){
                    results.push_back({r, c});
                }
            }
        }
        
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        vector<vector<int>> results;

        dfs(heights, isVisited, rows, cols, previousHeight);

        return results;
    }
};
