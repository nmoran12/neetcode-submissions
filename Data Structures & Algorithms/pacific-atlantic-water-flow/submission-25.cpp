class Solution {
public:

    void dfs(vector<vector<int>>& heights, int r, int c, int previousHeight, vector<vector<bool>>& isVisited){
        // Block 1: Base Cases
        // Base Case: If the node we traverse to is out of bounds or already visited, just return
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || isVisited[r][c]){
            return;
        }

        // We are working inwards, flowing UPHILL. so if previous height is larger than what we are going to,
        // we are not going uphill anymore, so must return.
        if (previousHeight > heights[r][c]){
            return;
        }


        // Block 2: The Mark (mark it as visited)
        isVisited[r][c] = true;

        // Block 3: Search in all 4 dimensions.
        // Up
        dfs(heights, r - 1, c, heights[r][c], isVisited);

        // Down
        dfs(heights, r + 1, c, heights[r][c], isVisited);

        // Left
        dfs(heights, r, c - 1, heights[r][c], isVisited);

        // Right
        dfs(heights, r, c + 1, heights[r][c], isVisited);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()){
            return {};
        }

        int previousHeight = 0;
        int rows = heights.size();
        int cols = heights[0].size();
        int r = 0;
        int c = 0;
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));



        vector<vector<int>> results;

        vector<vector<bool>> atlanticMatrix(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacificMatrix(rows, vector<bool>(cols, false));


        // Atlantic Matrix Loop: Rows: rows - 1, Cols: cols - 1
        // Bottom
        for (int c = 0; c < cols; c++){
            dfs(heights, rows - 1, c, heights[rows - 1][c], atlanticMatrix);
        }

        // Right Side
        for (int r = 0; r < rows; r++){
            dfs(heights, r, cols - 1, heights[r][cols - 1], atlanticMatrix);
        }

        // Pacific Matrix Loop:
        // Top
        for (int c = 0; c < cols; c++){
            dfs(heights, 0, c, heights[0][c], pacificMatrix);
        }

        // Left Side
        for (int r = 0; r < rows; r++){
            dfs(heights, r, 0, heights[r][0], pacificMatrix);
        }




        // Check overlap
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (atlanticMatrix[r][c] == pacificMatrix[r][c]){
                    results.push_back({r, c});
                }
            }
        }

        return results;
    }
};
