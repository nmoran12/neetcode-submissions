class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int counter = 1;
        int currentStreak = 0;

        sort(nums.begin(), nums.end());

        if (nums.empty()){
            counter--;
            return counter;
        }


        for (int i = 0; i < nums.size(); i++){
            if (nums[i] + 1 == nums[i+1]){
                counter++;
                currentStreak++;
                if (currentStreak > counter){
                    counter = currentStreak;
                }
            } else if (nums[i] + 1 != nums[i+1]){
                currentStreak = 0;
            }


        }

        return counter;
    }
};
