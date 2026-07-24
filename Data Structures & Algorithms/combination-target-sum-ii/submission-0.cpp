class Solution {
public:


    void helper(vector<int>& candidates, int target, int sum, int i, vector<int>& subset, vector<vector<int>>& mySubsets){
        // base case 1: If our iterator has hit the size of the candidates array, we have hit the last value we can add, just return
        if (i == candidates.size()){
            return;
        }

        if (sum == target){
            mySubsets.push_back(subset);
        }

        if (sum > target){
            return;
        }





        // Choice 1: Include
        subset.push_back(candidates[i]);
        helper(candidates, target, sum + nums[i], i + 1, subset, mySubsets);
        subset.pop_back();


        // Choice 2: Exclude
        // Fast-forward 'i' past any duplicates that exist in candidates before branching down right side
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]){
            i++;
        };

        helper(candidates, target, sum, i + 1, subset, mySubsets);


    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> mySubsets;
        vector<int> subset;

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, 0, subset, mySubsets);

        return mySubsets;
    }
};
