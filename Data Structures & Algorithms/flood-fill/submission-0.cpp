class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor) {
        int rows = image.size();
        int cols = image[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols) return;
        if (image[r][c] != originalColor) return;

        image[r][c] = newColor;

        dfs(image, r + 1, c, originalColor, newColor);
        dfs(image, r - 1, c, originalColor, newColor);
        dfs(image, r, c + 1, originalColor, newColor);
        dfs(image, r, c - 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if (originalColor == color) return image;

        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};