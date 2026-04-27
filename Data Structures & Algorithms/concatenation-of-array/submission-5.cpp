class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int length = 2*nums.size();
        vector<int> ans(length);
        int k = 0;

        for (int i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
            ans[i+nums.size()] = nums[i];
            cout << "newArr: " << ans[i] << endl;
        }


        return ans;
    }
};