class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int largest = 0;
        
        while (left < right){

            int height = min(heights[left], heights[right]);
            int length = right - left;
            int rnArea = height * length;
            largest = max(largest, rnArea);


            if (heights[left] < heights[right]){
                left++;
            } else {
                right--;
            }


        }

        return largest;

    }
};
