class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }

        int total = 0;
        int current = 0;
        int start = 0;

        for (int i = 0; i < nums.size(); i++){
            current += nums[i];

            total = max(total, current);

            if (current < 0){
                start = i + 1;
                total = max(total, current);
                current = 0;
            }
        }


        return total;
    }
};
