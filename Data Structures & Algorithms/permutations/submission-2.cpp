class Solution {
public:


    void helper(vector<int>& nums, vector<vector<int>>& mySubset, vector<int>& subset, vector<bool>& used){
        if (subset.size() == nums.size()){
            mySubset.push_back(subset);
            return;
        }


        for (int i = 0; i < nums.size(); i++){
            // If number is already in our current permutation, skip it
            if (used[i]){
                continue;
            }

        // 1. Choose
        used[i] = true;
        subset.push_back(nums[i]);

        // 2. Explore
        helper(nums, mySubset, subset, used);

        // 3. Undo
        subset.pop_back();
        used[i] = false;
        };



    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> mySubset;
        vector<int> subset;
        vector<bool> used(nums.size(), false);

        helper(nums, mySubset, subset, used);
        

        return mySubset;
    }
};
