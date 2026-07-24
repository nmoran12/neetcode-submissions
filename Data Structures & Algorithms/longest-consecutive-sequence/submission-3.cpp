class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int counter = 1;

        sort(nums.begin(), nums.end());

        if (nums.empty()){
            counter--;
            return counter;
        }


        for (int i = 0; i < nums.size(); i++){
            if (nums[i] + 1 == nums[i+1]){
                counter++;
            }


        }

        return counter;
    }
};
