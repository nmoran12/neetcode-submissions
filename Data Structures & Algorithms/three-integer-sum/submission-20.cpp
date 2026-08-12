class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> results;

        // Sort
        sort(nums.begin(), nums.end());

    // This outer for loop handles the third pointer, the 'i'
    for (int i = 0; i < nums.size(); i++){

        // If i is a duplicate, just skip
        if (i > 0 && nums[i] == nums[i - 1]){
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;


            while (left < right){
                
                if ((nums[i] + nums[left] + nums[right]) > 0){
                    right--;
                } else if ((nums[i] + nums[left] + nums[right]) < 0){
                    left++;
                } else if ((nums[i] + nums[left] + nums[right]) == 0) {
                    results.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                }
            }
        
    };
        return results;
    }
};
