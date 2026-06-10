class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // This just goes through the array, and if running sum is not less than 0, just simply add the current value to the running sum
        int runningTotal = 0;

        // This keeps track of the maximum total we have ever seen, and we must initialise it to first index to handle
        // scenarios where the answer is negative.
        int maximumSum = nums[0];

        for (int i = 0; i < nums.size(); i++){

            // If runningTotal is less than 0, we just reset (just set it to 0)
            if (runningTotal < 0){
                runningTotal = 0;
            }

            // Keep running total going, each time we have a new index just add it
                runningTotal += nums[i];

            // Keep track of the maximum sum, so just take the maximum of current max. and current running total.
                maximumSum = max(maximumSum, runningTotal);


        }
        
        return maximumSum;
    }
};
