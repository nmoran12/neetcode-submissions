class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = nums[0];
        int runningTotal = 0;
        int start = 0;

        for (int i = 0; i < nums.size(); i++){

            if (runningTotal < 0){
                runningTotal = 0;
            }

            runningTotal += nums[i];
            maxSum = max(maxSum, runningTotal);
        }


        return maxSum;
    }
};
