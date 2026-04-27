class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = m * n - 1;

        while (low <= high){

            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;


            if (target < matrix[row][col]){
                high = mid - 1;
            } else if (target > matrix[row][col]){
                low = mid + 1;
            } else{
                return true;
            }
        }


        return false;
    }

};
