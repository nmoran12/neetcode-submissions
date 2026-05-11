class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());
        

        for (int i = 0; i < nums.size(); i++){

            // skip duplicates, so if you have two values same value, just skip over
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0){
                    left++;
                } else if (sum > 0){
                    right--;
                } else{
                    results.push_back({nums[i], nums[left], nums[right]});

                    left++;

                    while (left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
            }
        }

        return results;
    }
};
