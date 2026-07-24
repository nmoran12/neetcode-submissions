class Solution {
public:

    void dfs(vector<vector<int>>& heights, int r, int c, int previousHeight, vector<vector<bool>> isVisited(rows, vector<bool>(cols, false))){
        // Base Case: If the node doesnt exist that we just traversed to, just return
        if (heights.empty()){
            return;
        }

        // If valid, mark it as visited
        if (!isVisited && heights[r][c] > previousHeights){
            isVisited[r][c] = true;
        }

        // Up
        dfs(heights, r - 1, c, previousHeight, isVisited);

        // Down
        dfs(heights, r + 1, c, previousHeight, isVisited);

        // Left
        dfs(heights, r, c - 1, previousHeight, isVisited);

        // Right
        dfs(heights, r, c + 1, previousHeight, isVisited);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        int previousHeight = 0;
        int rows = heights.size();
        int cols = heights[0].size();
        int r = 0;
        int c = 0;



        vector<pair<int, int>> results;

        vector<vector<int>> atlanticMatrix;
        vector<vector<int>> pacificMatrix;


        // Atlantic Matrix Loop: Rows: rows - 1, Cols: cols - 1
        // Bottom
        for (int r = 0; r < rows; r++){
            dfs(heights, rows - 1, c, heights[r][c], isVisited);
        }

        // Right Side
        for (int c = 0; c < cols; c++){
            dfs(heights, rows, cols - 1, heights[r][c], isVisited);
        }

        // Pacific Matrix Loop:
        // Top
        for (int r = 0; r < rows; r++){
            dfs(heights, 0, c, heights[r][c], isVisited);
        }

        // Left Side
        for (int c = 0; c < cols; c++){
            dfs(heights, r, 0, heights[r][c], isVisited);
        }




        // Check overlap
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (atlanticMatrix[r][c] == pacificMatrix[r][c]){
                    results.push_back({r, c});
                }
            }
        }
    }
};
