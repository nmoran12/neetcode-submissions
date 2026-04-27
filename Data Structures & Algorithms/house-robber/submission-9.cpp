class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }

        if (nums.size() == 1){
            return nums[0];
        }

        int n = nums.size();

        vector<int> dp(n + 1);

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);


        // Rob it
        for (int i = 2; i < nums.size(); i++){

        if (dp[i-1] <= (dp[i - 2] + nums[i])){
            dp[i] = (dp[i - 2] + nums[i]);
        } else if (dp[i - 1] >= (dp[i - 2] + nums[i])){
            dp[i] = dp[i - 1];
        }
        }



        return dp[n - 1];
    }
};
