class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> uniqueTriplets;


        for (int i = 0; i < nums.size(); i++){

            for (int j = i + 1; j < nums.size(); j++){

                for (int k = j + 1; k < nums.size(); k++){
                    if (nums[i] + nums[j] + nums[k] == 0){

                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());

                        uniqueTriplets.insert(triplet);


                    }
                }
            }
        }
        
        vector<vector<int>> results(uniqueTriplets.begin(), uniqueTriplets.end());
        return results;
    }
};
