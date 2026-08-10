class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int rangeLength = nums.size();

        for (int i = 0; i < rangeLength; i++){
            result += (i - nums[i]);
        }

        return result;
    }
};
