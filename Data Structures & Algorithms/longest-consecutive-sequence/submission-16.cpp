class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int counter = 1;
        int currentStreak = 1;
        int longestStreak = 1;

        sort(nums.begin(), nums.end());

        if (nums.empty()){
            currentStreak--;
            return currentStreak;
        }


        for (int i = 1; i < nums.size(); i++){

        if (nums[i] == nums[i-1]){
        continue;
        }
        
        else if (nums[i] == nums[i-1] + 1){
        currentStreak++;


        } else if (nums[i] != nums[i-1]){
        longestStreak = max(longestStreak, currentStreak);
        currentStreak = 1;
        }
    };

        return max(longestStreak, currentStreak);
    };
};