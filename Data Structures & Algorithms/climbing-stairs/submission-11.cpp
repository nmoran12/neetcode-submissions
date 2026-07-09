class Solution {
public:

    // This stores answers you have already calculated
    // So memo[n] is the number of ways to reach step 'n'.
    vector<int> memo;

    int dfs(int n){
        // Base Case:
        // If n = 1, there is 1 way to climb those stairs
        // If n = 2, there is 2 ways to climb those stairs
        if (n <= 2){
            return n;
        }

        // If we have already solved this dfs(n), just get the answer from memo
        if (memo[n] != -1){
            return memo[n];
        }

        memo[n] = dfs(n - 1) + dfs(n - 2);

        return memo[n];
    }

    int climbStairs(int n) {
        

        memo.resize(n + 1, -1);

        // dfs(n) is the number of ways to climb 'n' stairs
        return dfs(n);
    }
};
