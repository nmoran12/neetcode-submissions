class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;

        unordered_map<char, int> freqMap;

        for (int right = 0; right < s.length(); right++){
            freqMap[s[right]];

            while (freqMap[s[right] > 1]){
                freqMap[s[left]]--;
                left++;
            }


            maxLength = max(maxLength, right - left + 1);
        }
        

        return maxLength;
    }
};
