class Solution {
public:
    int maxArea(vector<int>& heights) {
        int volume = 0;
        int onePointer = 0;
        int twoPointer = heights.size() - 1;
        int currentHeight = 0;
        int maxVolume = 0;


        while (onePointer < twoPointer){
            int width = twoPointer - onePointer;
            currentHeight = min(heights[onePointer], heights[twoPointer]);

            volume = width * currentHeight;

            maxVolume = max(maxVolume, volume);

            if (heights[twoPointer] < heights[onePointer]){
                twoPointer--;
            } else {
                onePointer++;
            };


        }
        

        return maxVolume;
    }
};
