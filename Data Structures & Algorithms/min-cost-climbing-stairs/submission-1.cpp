class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // Vector that holds the state i.e. the minimum cost to get to each step
        vector<int> dp(n + 1, 0);

        // Base Case: Our first two steps are 0 cost, cos we can start from index 0 or index 1
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++){
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        };

        return dp[n];
    }
};
