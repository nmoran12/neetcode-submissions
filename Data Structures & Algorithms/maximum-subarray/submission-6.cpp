class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int total, current, start = 0;

        for (int i = 0; i < nums.size(); i++){
            current += nums[i];

            total = max(total, current);

            if (current < 0){
                start = i + 1;
                current = 0;
            }
        }


        return total;
    }
};
