class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int total = 0;
        int length = INT_MAX;


        for (int R = 0; R < nums.size(); R++){
            total = total + nums[R];

            while (total >= target){
                length = min(R - left + 1, length);
                total = total - nums[left];
                left++;
            }


        }

                    if (length == INT_MAX){
                return 0;
            }

        return length;
    }
};