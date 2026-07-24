class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentNum = 0;
        int runningTotal = 0;
        int maximumSum = 0;

        for (int i = 0; i < nums.size(); i++){

            if (runningTotal < 0){
                runningTotal = 0;
            } else {
                runningTotal += nums[i];
                maximumSum = max(runningTotal + nums[i], nums[i]);
            }


        }
        
        return maximumSum;
    }
};
