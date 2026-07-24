class Solution {
public:

    void helper(vector<int>& nums, int target, int i, int sum, vector<int> subset, vector<vector<int>> mySubsets){
        // base case 1: cannot be greater than target
        if (sum > target){
            return;
        }

        // base case 2: if sum == target
        if (sum == target){
            mySubsets.push_back(subset);
            return;
        }

        
        // base case 3: prevent out-of-bounds issues
        if (i >= nums.size()){
            return;
        }

        subset.push_back(nums[i]);

        helper(nums, target, i, sum + nums[i], subset, mySubsets);
        subset.pop_back();

        helper(nums, target, i + 1, sum, subset, mySubsets);


    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        vector<vector<int>> mySubsets;
        
        helper(nums, target, 0, 0, subset, mySubsets);


        return mySubsets;
    }
};
