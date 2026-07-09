class Solution {
public:

    vector<int> memo;

    int dfs(int n){
        // Base Case:
        if (n <= 2){
            return n;
        }

        if (memo[n] != -1){
            return memo[n];
        }

        memo[n] = dfs(n - 1) + dfs(n - 2);

        return memo[n];
    }

    int climbStairs(int n) {
        

        memo.resize(n + 1, -1);

        return dfs(n);
    }
};
