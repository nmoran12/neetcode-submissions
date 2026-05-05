class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;
        int currentStreak = 1;
        int currentNum = 0;
        unordered_set<int> hashMap(nums.begin(), nums.end());

        if (hashMap.empty() == 1){
            return 0;
        }


        for (auto& num : hashMap){
            if ((hashMap.count(num - 1)) == 0){
                currentNum = num;
                currentStreak = 1;

            while (hashMap.count(currentNum + 1) == 1){
                currentNum++;
                currentStreak++;
            }
            }

        longest = max(longest, currentStreak);
        }

        

        return longest;
    }
};
