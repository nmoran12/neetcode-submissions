class Solution {
public:

    vector<vector<int>> results;
    vector<int> subset;

    void dfs(int start, vector<int>& nums){
        results.push_back(subset);

        for (int i = start; i < nums.size(); i++){

                if (i > start && nums[i] == nums[i-1]){ continue;
                };
            
            subset.push_back(nums[i]);
            dfs(i + 1, nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        

        std::sort(nums.begin(), nums.end());
        dfs(0, nums);



        return results;
    }
};
