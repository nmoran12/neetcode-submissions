class Solution {
public:

    vector<vector<int>> results;
    vector<int> subset;

    void dfs(int nums, int i){
        if (i == nums.size()){
            results.append(subset);
        }

        // Decide to include nums[i]
        subset.push_back(nums[i]);
        dfs(i + 1); // Going down the branch to include all subsets that have [1] at the start e.g. [1, 2, 3], [1, 2], [1, 3], etc.

        // Decide to exclude nums[i]
        subset.pop();
        dfs(i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int i = 0;

        dfs(nums, i);

        return results;
    }
};