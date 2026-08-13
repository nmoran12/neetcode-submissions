class Solution {

    vector<int> memo;

public:


    int dfs(int i, vector<int> cost){
        if (i >= cost.size()) {
            return 0;
        }

        if (memo[i] != -1){
            return memo[i];
        }

        memo[i] = cost[i] + min(dfs(i + 1, cost), dfs(i + 2, cost));

        return memo[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {

        memo.assign(cost.size(), -1);

        return min(
            dfs(0, cost),
            dfs(1, cost)
        );
};
};
