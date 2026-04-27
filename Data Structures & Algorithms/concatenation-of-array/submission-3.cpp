class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int lengthOfArray = 2 * nums.size();
        vector<int> ans(lengthOfArray);

        for (int i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
        }

        for (int i=0; i < nums.size(); i++){
            ans[i+nums.size()] = nums[i];
        }

        return ans;
    }
};