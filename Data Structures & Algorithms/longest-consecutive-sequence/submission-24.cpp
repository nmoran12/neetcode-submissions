class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> hashMap(nums.begin(), nums.end());

        int currentValue = 1;
        int currentStreak = 1;
        int longest = 0;
        

        for (int i = 0; i < nums.size(); i++){


            if (hashMap.count(nums[i] - 1) == 0){
                currentValue = nums[i];
                currentStreak = 1;

            while (hashMap.count(currentValue + 1) == 1){
                currentStreak++;
                currentValue++;
            }

            longest = max(longest, currentStreak);
            }



        }


        return longest;
    }
};
