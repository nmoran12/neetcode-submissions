class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;


        // The outer loop represents the TARGET AMOUNT (i) that we are trying to solve for.
        // So its all amounts from 1 to amount, because we already know 0.
        for (int i = 1; i < amount + 1; i++){
            for (int j = 0; j < coins.size(); j++){
                // Check if coin fits into current target amount (i)
                if (coins[j] <= i){
                    // Get min of all coin in coins - amount left
                    // e.g. if we want $8, then its $8 - $1, so we check dp[7].
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        

        if (dp[amount] > amount){
            return -1;
        } else {
            return dp[amount];
        }
    }
};
