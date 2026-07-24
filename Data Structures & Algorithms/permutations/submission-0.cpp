class Solution {
public:


    void helper(vector<int>& nums, int i, vector<vector<int>>& mySubset, vector<int>& subset){
        if (i == nums.size()){
            mySubset.push_back(nums);
            return;
        }


        subset.push_back(nums[i]);
        helper(nums, i + 1, mySubset, subset);
        subset.pop_back();

        helper(nums, i + 1, mySubset, subset);




    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> mySubset;
        vector<int> subset;

        helper(nums, 0, mySubset, subset);
        

        return mySubset;
    }
};
