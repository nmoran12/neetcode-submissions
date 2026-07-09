class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Base Cases:
        // If only one house to rob, just rob it
        if (n == 1){
            return nums[0];
        }

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++){
            int skipCurrent = dp[i - 1];
            int robCurrent = nums[i] + dp[i - 2];

            dp[i] = max(skipCurrent, robCurrent);
        }
        
        return dp[n - 1];
    }
};
