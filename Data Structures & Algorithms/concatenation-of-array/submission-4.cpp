class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int numsSize = nums.size();
        cout << "Nums Size" << numsSize << endl;
        vector<int> ans(2 * numsSize);
        for (int i = 0; i < numsSize; i++){
            ans[i] = nums[i];
            ans[i+numsSize] = nums[i];
            cout << "Array: " << nums[i] << endl;
        }
        return ans;
    }
};