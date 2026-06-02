class Solution {
public:
    vector<vector<int>> results;
    vector<int> subset;

    vector<vector<int>> subsets(vector<int>& nums) {

        backtracking(nums, 0);

        return results;
    }


    void backtracking(vector<int>& backNums, int i){


        // Base case:
        // Is 'have I made a decision for every number?'
        // Because if we have nums = [1, 2, 3], we must decide to add or not add each number, then we are finished when we have
        // decided that for every number
        if (i == backNums.size()){
            results.push_back(subset);
            return;
        }

        // Choice 1: Don't include the value
        backtracking(backNums, i + 1);


        // Choice 2: Include the value
        subset.push_back(backNums[i]);
        backtracking(backNums, i + 1);
        subset.pop_back();
    }
};
