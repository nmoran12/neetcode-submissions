class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_set<int> hashSet;

        for (int i = 0; i < nums.size(); i++){

            if (hashSet.count(nums[i])){
                return nums[i];
            }

            hashSet.insert(nums[i]);
        }



    }
};
