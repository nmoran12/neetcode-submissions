class Solution {
public:

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& isVisited, int r, int c, int previousHeight){

        // Base Case: If it goes out of bounds, is not land, or is already visited
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || heights[r][c] == 0 || isVisited[r][c]){
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

        vector<vector<int>> results;

        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticMatrix(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacificMatrix(rows, vector<bool>(cols, false));

        dfs(heights, isVisited, 0, 0, previousHeight);

        dfs(heights, isVisited, rows - 1, cols - 1, previousHeight);

        // Pacific Ocean Loops for its Borders (top and left)
        for (int c = 0; c < cols; c++){
            dfs(heights, isVisited, 0, c, heights[0][c]);
        }

        for (int r = 0; r < rows; r++){
            dfs(heights, isVisited, r, 0, heights[r][0]);
        }

        // Atlantic Ocean Loops for its Borders (bottom and right)
        for (int c = 0; c < cols; c++){
            dfs(heights, isVisited, rows - 1, c, heights[rows - 1][c]);
        }

        for (int r = 0; r < rows; r++){
            dfs(heights, isVisited, r, cols - 1, heights[r][cols - 1]);
        }

        return results;
    }
};
