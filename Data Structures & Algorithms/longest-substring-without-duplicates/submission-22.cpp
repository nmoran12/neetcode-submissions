class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Stores: Letter : Frequency it occurs
        unordered_map<char, int> frequency;

        // Length of longest substring we have found so far
        int longestSubstr = 0;

        // Length of current substring we are looking at
        int currSubstr = 0;

        int left = 0;
        int right = s.length() - 1;

        for (right = 0; right < s.length(); right++){
            frequency[s[right]]++; // Increment that chars frequency by one

            while (frequency[s[right]] > 1){
                left++;
                frequency[s[left]]--; // For that value we just removed from sliding window, decremenet its frequency by 1
            }

            int sizeOfWindow = right - left + 1;
            longestSubstr = max(longestSubstring, sizeOfWindow);
        }


        return longestSubstr;
    }
};
