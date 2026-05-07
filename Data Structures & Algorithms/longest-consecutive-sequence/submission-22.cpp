class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int longest = 0;
        int currentStreak = 1;
        int currentValue = 1;

        for (int i = 0; i < nums.size(); i++){

            if (hashSet.count(nums[i] - 1) == 0){
                currentStreak = 1;
                currentValue = nums[i];

                while (hashSet.count(currentValue + 1)){
                    currentStreak++;
                    currentValue++;
                }

                longest = max(longest, currentStreak);
            }


        }





        return longest;
    }
};
